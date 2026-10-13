"""Recover simple leaf functions, accepting only exact, unrelocated byte identity."""
from pathlib import Path
import re,json,subprocess,io,hashlib,csv,concurrent.futures,os
from capstone import Cs,CS_ARCH_ARM,CS_MODE_ARM,CS_MODE_THUMB,CS_OP_REG,CS_OP_IMM,CS_OP_MEM
from elftools.elf.elffile import ELFFile
root=Path(__file__).resolve().parents[2];work=root/'c-work';baseline=root/'recovery/MarioKartDS-EUR-analysis';manifest=json.loads((baseline/'manifest.json').read_text())
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
  if size>16 or not re.fullmatch(r'[A-Za-z_]\w*',name):continue
  b=target_bytes(module,addr,size)
  if b is None:continue
  md=Cs(CS_ARCH_ARM,CS_MODE_THUMB if mode=='thumb' else CS_MODE_ARM);md.detail=True;ins=list(md.disasm(b,addr))
  # Require a two-instruction leaf with a single unconditional BX LR.
  if len(ins)!=2 or ins[1].mnemonic!='bx' or ins[1].op_str!='lr':continue
  i=ins[0];body=None;sig=None;kind=None
  if i.mnemonic in ['mov','movs'] and len(i.operands)==2 and i.reg_name(i.operands[0].reg)=='r0' and i.operands[1].type==CS_OP_IMM:
   value=i.operands[1].imm&0xffffffff;sig=f'unsigned int {name}(void)';body=f'return 0x{value:x}u;';kind='constant_return'
  if i.mnemonic in ['ldr','ldrb','ldrh','ldrsb','ldrsh','str','strb','strh'] and len(i.operands)==2 and i.operands[1].type==CS_OP_MEM:
   dest=i.reg_name(i.operands[0].reg);mem=i.operands[1].mem
   if i.reg_name(mem.base)=='r0' and not mem.index and not i.writeback:
    types={'ldr':'unsigned int','ldrb':'unsigned char','ldrh':'unsigned short','ldrsb':'signed char','ldrsh':'short','str':'unsigned int','strb':'unsigned char','strh':'unsigned short'};typ=types[i.mnemonic];offset=mem.disp
    width=1 if 'b' in i.mnemonic else 2 if 'h' in i.mnemonic else 4
    if offset%width:continue
    if i.mnemonic.startswith('ldr') and dest=='r0':
     ret='int' if i.mnemonic in ['ldrsb','ldrsh'] else 'unsigned int';sig=f'{ret} {name}(const void *ptr)';body=f'return *(const {typ} *)((const unsigned char *)ptr + {offset});';kind='field_getter'
    elif i.mnemonic.startswith('str') and dest=='r1':sig=f'void {name}(void *ptr, unsigned int value)';body=f'*({typ} *)((unsigned char *)ptr + {offset}) = ({typ})value;';kind='field_setter'
  if body:funcs.append({'module':module,'name':name,'mode':mode,'address':addr,'size':size,'original':b,'source':sig+'\n{\n    '+body+'\n}\n','kind':kind})
print('Candidates',len(funcs),flush=True)
cc=root/'tooling/mwccarm/1.2/sp2p3/mwccarm.exe';wibo=root/'tooling/wibo';flags='-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc'.split()
cands=root/'leaf-candidates';cands.mkdir(exist_ok=True);out=work/'verification/leafs';out.mkdir(parents=True,exist_ok=True)
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
  backup=work/'verification/previous_drafts'/f['module'];backup.mkdir(parents=True,exist_ok=True);(backup/dest.name).write_bytes(dest.read_bytes())
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
