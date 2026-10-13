"""Recover simple leaf functions, accepting only exact, unrelocated byte identity."""
from pathlib import Path
import re,json,subprocess,io,hashlib,csv,concurrent.futures,os
from capstone import Cs,CS_ARCH_ARM,CS_MODE_ARM,CS_MODE_THUMB,CS_OP_REG,CS_OP_IMM,CS_OP_MEM
from capstone.arm import ARM_SFT_LSL,ARM_SFT_LSR,ARM_SFT_ASR,ARM_SFT_ROR
from elftools.elf.elffile import ELFFile
work=Path(__file__).resolve().parents[1];root=work.parent;baseline=Path(os.environ.get('MKDS_BASELINE',str(work/'baseline')));manifest=json.loads((baseline/'manifest.json').read_text())
sections={m['name']:[(s['base'],(baseline/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
def target_bytes(module,a,n):
 for base,b in sections[module]:
  if base<=a and a+n<=base+len(b):return b[a-base:a-base+n]
 return None
funcs=[];pat=re.compile(r'^(\S+) kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\) addr:0x([0-9a-fA-F]+)')
for sf in (baseline/'symbols').glob('*.txt'):
 module=sf.stem
 if module=='arm7':continue
 for line in sf.read_text().splitlines():
  m=pat.match(line)
  if not m:continue
  name,mode,size,addr=m.groups();size=int(size,16);addr=int(addr,16)
  if size>48 or not re.fullmatch(r'[A-Za-z_]\w*',name):continue
  b=target_bytes(module,addr,size)
  if b is None:continue
  md=Cs(CS_ARCH_ARM,CS_MODE_THUMB if mode=='thumb' else CS_MODE_ARM);md.detail=True;ins=list(md.disasm(b,addr))
  # Interpret a short, straight-line leaf. No branches, calls, incoming flags or inline assembly.
  stop=next((j for j,i in enumerate(ins) if i.mnemonic=='bx' and i.op_str=='lr'),None)
  if stop is None or stop>7:continue
  codeins=ins[:stop];regs={f'r{j}':f'p{j}' for j in range(4)};used=set();statements=[];modified=set();valid=True;stores=False
  def regval(name):
   if name not in regs:raise ValueError('unmodelled register')
   v=regs[name]
   used.update(int(x) for x in re.findall(r'\bp([0-3])\b',v));return v
  def operand(op,inst):
   if op.type==CS_OP_IMM:return f'0x{op.imm&0xffffffff:x}u'
   if op.type!=CS_OP_REG:raise ValueError('operand')
   v=regval(inst.reg_name(op.reg));sh=op.shift
   if sh.type:
    n=sh.value
    if not 0<n<32:raise ValueError('shift')
    if sh.type==ARM_SFT_LSL:v=f'(({v}) << {n})'
    elif sh.type==ARM_SFT_LSR:v=f'(({v}) >> {n})'
    elif sh.type==ARM_SFT_ASR:v=f'((unsigned int)((int)({v}) >> {n}))'
    elif sh.type==ARM_SFT_ROR:v=f'((({v}) >> {n}) | (({v}) << {32-n}))'
    else:raise ValueError('shift kind')
   return v
  try:
   for inst in codeins:
    op=inst.mnemonic;args=inst.operands;dst=inst.reg_name(args[0].reg) if args and args[0].type==CS_OP_REG else ''
    if dst not in ['r0','r1','r2','r3','ip']:raise ValueError('destination')
    if inst.writeback:raise ValueError('writeback')
    if op in ['ldr','ldrb','ldrh','ldrsb','ldrsh','str','strb','strh']:
     if len(args)!=2 or args[1].type!=CS_OP_MEM:raise ValueError('memory operand')
     mem=args[1].mem;base=inst.reg_name(mem.base)
     if mem.index:raise ValueError('indexed access')
     if base=='pc' and op=='ldr':
      pc=((inst.address+4)&~3) if mode=='thumb' else inst.address+8
      lit=target_bytes(module,pc+mem.disp,4)
      if lit is None:raise ValueError('literal')
      value=f'0x{int.from_bytes(lit,"little"):x}u'
     else:
      typ={'ldr':'unsigned int','ldrb':'unsigned char','ldrh':'unsigned short','ldrsb':'signed char','ldrsh':'short','str':'unsigned int','strb':'unsigned char','strh':'unsigned short'}[op]
      width=1 if 'b' in op else 2 if 'h' in op else 4
      if mem.disp%width:raise ValueError('alignment')
      bv=regval(base);address=f'((unsigned char *)(unsigned int)({bv}) + {mem.disp})'
      if op.startswith('str'):
       statements.append(f'*({typ} *){address} = ({typ})({regval(dst)});');stores=True;continue
      value=f'((unsigned int)*(const {typ} *){address})'
    elif op in ['mov','movs','mvn','mvns']:
     value=operand(args[1],inst)
     if op.startswith('mvn'):value=f'(~({value}))'
    elif op in ['add','adds','sub','subs','rsb','rsbs','and','ands','orr','orrs','eor','eors','bic','bics','mul','muls']:
     if len(args)==3:x,y=operand(args[1],inst),operand(args[2],inst)
     elif len(args)==2:x,y=regval(dst),operand(args[1],inst)
     else:raise ValueError('arity')
     baseop=op[:-1] if op.endswith('s') else op
     signs={'add':'+','sub':'-','and':'&','orr':'|','eor':'^','mul':'*'}
     if baseop=='rsb':value=f'(({y})-({x}))'
     elif baseop=='bic':value=f'(({x})&~({y}))'
     else:value=f'(({x}){signs[baseop]}({y}))'
    elif op in ['lsl','lsls','lsr','lsrs','asr','asrs','ror','rors']:
     if len(args)!=3 or args[2].type!=CS_OP_IMM:raise ValueError('variable shift')
     x=operand(args[1],inst);n=args[2].imm
     if not 0<n<32:raise ValueError('shift range')
     if op.startswith('lsl'):value=f'(({x}) << {n})'
     elif op.startswith('lsr'):value=f'(({x}) >> {n})'
     elif op.startswith('asr'):value=f'((unsigned int)((int)({x}) >> {n}))'
     else:value=f'((({x}) >> {n}) | (({x}) << {32-n}))'
    else:raise ValueError('unsupported instruction')
    regs[dst]=value;modified.add(dst)
   if not stores:
    value=regval('r0');statements.append(f'return {value};');ret='unsigned int'
   else:
    if 'r0' in modified:raise ValueError('mixed return and stores')
    ret='void'
   count=max(used)+1 if used else 0;params=', '.join(f'unsigned int p{j}' for j in range(count)) or 'void'
   sig=f'{ret} {name}({params})';body='\n    '.join(statements);kind='linear_leaf'
  except (ValueError,IndexError,KeyError):continue
  if body:funcs.append({'module':module,'name':name,'mode':mode,'address':addr,'size':size,'original':b,'source':sig+'\n{\n    '+body+'\n}\n','kind':kind})
print('Candidates',len(funcs),flush=True)
cc=Path(os.environ.get('MWCCARM',str(work/'tools/mwccarm/1.2/sp2p3/mwccarm.exe')));wibo=Path(os.environ.get('WIBO',str(work/'tools/wibo')));flags='-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc'.split()
cands=work/'build/leaf-candidates';cands.mkdir(exist_ok=True);out=work/'verification/leafs';out.mkdir(parents=True,exist_ok=True)
def verify(f):
 tag=f['module']+'_'+format(f['address'],'08x');src=cands/(tag+'.c');obj=cands/(tag+'.o');src.write_text(f['source'])
 try:p=subprocess.run([str(wibo),str(cc),*flags,*(['-thumb'] if f['mode']=='thumb' else []),'-c',str(src),'-o',str(obj)],capture_output=True,text=True,timeout=30)
 except subprocess.TimeoutExpired:return None
 if p.returncode or not obj.exists():return None
 elf=ELFFile(io.BytesIO(obj.read_bytes()));symtab=elf.get_section_by_name('.symtab');sym=next((s for s in symtab.iter_symbols() if s.name==f['name']),None)
 if sym is None or not isinstance(sym['st_shndx'],int):return None
 index=sym['st_shndx'];start=sym['st_value']&~1;size=sym['st_size'];code=elf.get_section(index).data()[start:start+size]
 relocs=[]
 for sec in elf.iter_sections():
  if sec['sh_type'] in ['SHT_REL','SHT_RELA'] and sec['sh_info']==index:
   relocs.extend(r for r in sec.iter_relocations() if start<=r['r_offset']<start+size)
 if relocs or code!=f['original']:return None
 row={k:f[k] for k in ['module','name','mode','address','size','kind']};row['address']=f"0x{f['address']:08x}";row['sha256']=hashlib.sha256(code).hexdigest();row['relocations']=0;row['status']='EXACT_LOCAL_BYTES'
 # Preserve drafts; install verified high-level C without assembler or opaque byte arrays.
 dest=work/'src'/f['module']/f"{f['address']:08x}_{f['name']}.c"
 if dest.exists():
  backup=work/'verification/previous_drafts'/f['module'];backup.mkdir(parents=True,exist_ok=True);
  if not (backup/dest.name).exists():(backup/dest.name).write_bytes(dest.read_bytes())
  dest.write_text('/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.\n * No relocations. Full ROM linking remains unverified. */\n'+f['source'])
 (out/(tag+'.c')).write_text(f['source']);(out/(tag+'.original.hex')).write_text(code.hex()+'\n');return row
rows=[]
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
 for i,r in enumerate(pool.map(verify,funcs),1):
  if r:rows.append(r)
  if i%100==0:print('Checked',i,'exact',len(rows),flush=True)
with (work/'verification/local-byte-exact.tsv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=['module','name','mode','address','size','kind','sha256','relocations','status'],delimiter='\t');w.writeheader();w.writerows(rows)
meta={'candidates':len(funcs),'exact_functions':len(rows),'exact_code_bytes':sum(r['size'] for r in rows),'compiler':'mwccarm 1.2/sp2p3 (Version 2.0 build 82)','flags':flags,'verification':'Identical entire function byte sequence, equal length, zero relocations; no byte masking; no inline assembly; full ROM link not verified'}
(work/'verification/summary.json').write_text(json.dumps(meta,indent=2)+'\n');print(json.dumps(meta),flush=True)
