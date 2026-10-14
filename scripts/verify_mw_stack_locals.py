"""Generate ARM flow C candidates; accept only whole text equality with zero relocations."""
from pathlib import Path
import os,re,csv,json,subprocess,hashlib,io,importlib.util
zig=Path(importlib.util.find_spec("ziglang").origin).parent/"zig"
from capstone import *
from capstone.arm import *
from elftools.elf.elffile import ELFFile
# Reuse the audited relocation resolver without executing its search loop.
exec((Path(__file__).parent/'verify_resolved_calls.py').read_text().split("out=root/'verification/resolved-calls'")[0])
unrelocated_registry=root/'verification/local-byte-exact.tsv';unrelocated_rows=list(csv.DictReader(unrelocated_registry.open(),delimiter='\t'))
registry=root/'verification/local-linked-byte-exact.tsv';rows=list(csv.DictReader(registry.open(),delimiter='\t'));known.update((r['module'],int(r['address'],16)) for r in rows)
out=root/'verification/resolved-calls';temporary=root.parent/'control-flow-candidates';temporary.mkdir(exist_ok=True)
md=Cs(CS_ARCH_ARM,CS_MODE_ARM);md.detail=True
signs={ARM_CC_EQ:'==',ARM_CC_NE:'!=',ARM_CC_HS:'>=',ARM_CC_LO:'<',ARM_CC_HI:'>',ARM_CC_LS:'<=',ARM_CC_GE:'>=',ARM_CC_LT:'<',ARM_CC_GT:'>',ARM_CC_LE:'<='}
accepted=0;tested=0
for (mod,addr),(name,mode,size) in sorted(inventory.items()):
 if mode!='arm' or size>2048 or (mod,addr) in known:continue
 target=original(mod,addr,size);allins={i.address:i for i in md.disasm(target,addr)};reachable=set();pending=[addr]
 while pending:
  pc=pending.pop()
  if pc in reachable or pc not in allins:continue
  inst=allins[pc];reachable.add(pc)
  isreturn=(inst.mnemonic.startswith('bx') and inst.op_str=='lr') or (inst.mnemonic.startswith(('pop','ldm')) and 'pc' in inst.op_str and (inst.mnemonic.startswith('pop') or inst.op_str.startswith('sp!')))
  branch=inst.id==ARM_INS_B
  if branch and inst.operands[0].type==ARM_OP_IMM:pending.append(inst.operands[0].imm)
  if not (isreturn or branch) or inst.cc not in [ARM_CC_AL,ARM_CC_INVALID]:pending.append(pc+inst.size)
 ins=[allins[a] for a in sorted(reachable)];addresses=reachable;defined={'r0','r1','r2','r3'};statements=[];externs={};has_cmp=False;flag_zero=False;push_bytes=0;extra_params=set();frame_n=next((i.operands[2].imm for i in ins if i.mnemonic=='sub' and i.op_str.startswith('sp, sp, #')),0);stack_slots=set()
 def reg(r):
  n=md.reg_name(r)
  if n not in defined:raise ValueError('unmodelled incoming register')
  return n
 def operand(o):
  if o.type==ARM_OP_IMM:return f'0x{o.imm&0xffffffff:x}u'
  if o.type!=ARM_OP_REG:raise ValueError('operand')
  value=reg(o.reg)
  if o.shift.type:
   n=o.shift.value
   if not 0<n<32:raise ValueError('shift')
   if o.shift.type==ARM_SFT_LSL:value=f'({value} << {n})'
   elif o.shift.type==ARM_SFT_LSR:value=f'({value} >> {n})'
   elif o.shift.type==ARM_SFT_ASR:value=f'((unsigned int)((int){value} >> {n}))'
   else:raise ValueError('shift type')
  return value
 try:
  for i in ins:
   op=i.mnemonic;args=i.operands;condition=None
   if i.cc not in [ARM_CC_AL,ARM_CC_INVALID]:
    if not has_cmp or i.cc not in signs or (flag_zero and i.cc not in [ARM_CC_EQ,ARM_CC_NE]):raise ValueError('flags')
    signed=i.cc in [ARM_CC_GE,ARM_CC_LT,ARM_CC_GT,ARM_CC_LE];cast='(int)' if signed else ''
    condition=f'({cast}cmp_a {signs[i.cc]} {cast}cmp_b)';op=op[:-2]
   stmt=None
   if op=='bx' and i.op_str=='lr':stmt='return r0;'
   elif op in ['add','sub'] and i.op_str.startswith('sp, sp, #'):continue
   elif op=='push' or (op=='stmdb' and i.op_str.startswith('sp!')):
    if condition:raise ValueError('conditional push')
    push_bytes+=4*(len(args)-(1 if op=='stmdb' else 0));continue
   elif op=='pop' or (op in ['ldm','ldmia'] and i.op_str.startswith('sp!')):
    if 'pc' in i.op_str:stmt='return r0;'
    else:continue
   elif op=='cmp':
    if condition:raise ValueError('conditional compare')
    stmt=f'cmp_a = {operand(args[0])}; cmp_b = {operand(args[1])};';has_cmp=True;flag_zero=False
   elif op=='tst':
    if condition:raise ValueError('conditional tst')
    stmt=f'cmp_a = {operand(args[0])} & {operand(args[1])}; cmp_b = 0;';has_cmp=True;flag_zero=True
   elif op=='b':
    dest=args[0].imm
    if dest not in addresses:
     found=[n for (m,a),(n,t,z) in inventory.items() if m==mod and a==dest and t=='arm']
     if len(found)!=1:raise ValueError('external branch symbol')
     fn=found[0];callee=root/'src'/mod/f'{dest:08x}_{fn}.c'
     signature=re.search(r'\b'+re.escape(fn)+r'\s*\(([^()]*)\)',callee.read_text()) if callee.exists() else None
     params=signature.group(1).strip() if signature else None
     arity=0 if params in ['', 'void'] else len(params.split(',')) if params is not None else 4
     if arity>4:raise ValueError('stack tail arguments')
     externs[fn]=f'extern unsigned int {fn}('+(', '.join(['unsigned int']*arity) or 'void')+');'
     stmt='return '+fn+'('+','.join('r'+str(j) for j in range(arity))+');'
    else:stmt=f'goto L_{dest:x};'
   elif op in ['bl','blx']:
    if condition:raise ValueError('conditional call')
    dest=args[0].imm;found=[n for (m,a),(n,t,z) in inventory.items() if m==mod and a==dest ]
    if len(found)!=1:raise ValueError('call symbol')
    fn=found[0]
    if not re.fullmatch(r'[A-Za-z_]\w*',fn):raise ValueError('symbol syntax')
    for r in ['r0','r1','r2','r3']:
     if r not in defined:raise ValueError('call inputs')
    callee=root/'src'/mod/f'{dest:08x}_{fn}.c'
    signature=re.search(r'\b'+re.escape(fn)+r'\s*\(([^()]*)\)',callee.read_text()) if callee.exists() else None
    params=signature.group(1).strip() if signature else None
    arity=0 if params in ['', 'void'] else len(params.split(',')) if params is not None else 4
    if arity>12:raise ValueError('too many call arguments')
    for j in range(max(0,arity-4)):stack_slots.add(f'stack_{4*j}')
    externs[fn]=f'extern unsigned int {fn}('+(', '.join(['unsigned int']*arity) or 'void')+');'
    stmt='r0 = '+fn+'('+','.join('r'+str(j) if j<4 else 'stack_'+str(4*(j-4)) for j in range(arity))+');';has_cmp=False
   else:
    sets_zero=False
    if i.update_flags:
     if op not in ['subs','adds','ands','movs']:raise ValueError('unmodelled arithmetic flags')
     op=op[:-1];sets_zero=True
    dst=md.reg_name(args[0].reg)
    if dst not in ['r0','r1','r2','r3','r4','r5','r6','r7','r8','sb','sl','fp','ip','lr'] or i.writeback:raise ValueError('destination/stack')
    if op in ['mov','mvn']:value=operand(args[1]);value=f'~({value})' if op=='mvn' else value
    elif op in ['lsl','lsr','asr','ror']:
     x=operand(args[1]);n=args[2].imm
     if args[2].type!=ARM_OP_IMM or not 0<n<32:raise ValueError('variable shift')
     value=f'({x} << {n})' if op=='lsl' else f'({x} >> {n})' if op=='lsr' else f'((unsigned int)((int){x} >> {n}))' if op=='asr' else f'(({x} >> {n}) | ({x} << {32-n}))'
    elif op in ['add','sub','rsb','and','orr','eor','bic','mul']:
     x,y=operand(args[1]),operand(args[2]);sign={ 'add':'+','sub':'-','and':'&','orr':'|','eor':'^','mul':'*'}.get(op)
     value=f'({y}-{x})' if op=='rsb' else f'({x}&~({y}))' if op=='bic' else f'({x}{sign}{y})'
    elif op in ['ldr','ldrb','ldrh','ldrsb','ldrsh','str','strb','strh']:
     mem=args[1].mem
     if mem.index and args[1].subtracted:raise ValueError('negative indexed memory')
     if md.reg_name(mem.base)=='sp':
      if mem.index or mem.disp%4 or op not in ['ldr','str']:raise ValueError('unsupported stack access')
      off=mem.disp-frame_n-push_bytes
      if off>=0:
       if op!='ldr' or off>28:raise ValueError('incoming stack store/range')
       param=4+off//4;extra_params.update(range(4,param+1));value=f'a{param}'
      else:
       if not 0<=mem.disp<frame_n:raise ValueError('saved register access')
       slot=f'stack_{mem.disp}';stack_slots.add(slot)
       if op=='ldr':value=slot
       else:stmt=f'{slot} = {reg(args[0].reg)};';value=None
     elif md.reg_name(mem.base)=='pc' and op=='ldr':
      location=i.address+8+mem.disp;raw=original(mod,location,4);value=f'0x{int.from_bytes(raw,"little"):x}u'
     else:
      basevalue=reg(mem.base);typ={'ldr':'unsigned int','str':'unsigned int','ldrb':'unsigned char','strb':'unsigned char','ldrsb':'signed char','ldrh':'unsigned short','strh':'unsigned short','ldrsh':'short'}[op]
      offset=f'{mem.disp}'
      if mem.index:
       ix=reg(mem.index)
       if args[1].shift.type:
        if args[1].shift.type!=ARM_SFT_LSL or not 0<args[1].shift.value<32:raise ValueError('memory shift')
        ix=f'({ix} << {args[1].shift.value})'
       offset=f'({offset} + {ix})'
      access=f'*({typ} *)((unsigned char *){basevalue} + {offset})'
      if op.startswith('str'):stmt=f'{access} = ({typ}){reg(args[0].reg)};';value=None
      else:value=f'(unsigned int)({access})'
    else:raise ValueError('opcode')
    if stmt is None:stmt=f'{dst} = {value};';defined.add(dst)
    if sets_zero:
     stmt+=f' cmp_a = {dst}; cmp_b = 0;';has_cmp=True;flag_zero=True
   if condition:stmt=f'if ({condition}) {{ {stmt} }}'
   statements.append(f'L_{i.address:x}: {stmt}')
 except (ValueError,IndexError,KeyError,StopIteration):continue
 if not stack_slots:continue
 declarations='unsigned int '+','.join(sorted((defined-{'r0','r1','r2','r3'})|{'cmp_a','cmp_b'}|stack_slots))+';'
 source='\n'.join(externs.values())+f'\nunsigned int {name}(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3'+''.join(',unsigned int a'+str(j) for j in sorted(extra_params))+f')\n{{\n{declarations}\n'+'\n'.join(statements)+'\n}\n'
 tag=f'{mod}_{addr:08x}';src=temporary/(tag+'.c');obj=temporary/(tag+'.o');src.write_text(source);tested+=1
 for optimization in ['-O4,p','-O3','-O2','-O4,s','-O1','-O0']:
  processor='arm7tdmi' if mod=='arm7' else 'arm946e';p=subprocess.run([os.environ['WIBO'],os.environ['MWCCARM'],optimization,'-lang','c99','-enum','int','-char','signed','-interworking','-proc',processor,'-gccext,on','-c',str(src),'-o',str(obj)],capture_output=True,timeout=30)
  if p.returncode:continue
  try:code,relocs=linked(obj.read_bytes(),mod,name,addr)
  except (ValueError,StopIteration,KeyError):continue
  if code!=target:continue
  dest=root/'src'/mod/f'{addr:08x}_{name}.c';backup=root/'verification/previous_drafts'/mod/dest.name;backup.parent.mkdir(exist_ok=True,parents=True)
  if not backup.exists():backup.write_bytes(dest.read_bytes())
  dest.write_text('/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */\n'+source)
  (out/(tag+'.o')).write_bytes(obj.read_bytes());(out/(tag+'.linked.hex')).write_text(code.hex()+'\n');(out/(tag+'.relocations.json')).write_text(json.dumps(relocs,indent=2)+'\n')
  row=dict(module=mod,name=name,mode=mode,address=f'0x{addr:08x}',size=size,sha256=hashlib.sha256(code).hexdigest(),source_sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),relocations=len(relocs),optimization=optimization,processor=processor,status='EXACT_LOCAL_LINKED_BYTES' if relocs else 'EXACT_LOCAL_BYTES')
  if relocs:rows.append(row)
  else:
   row['kind']='arm_control_flow';unrelocated_rows.append(row)
   leafs=root/'verification/leafs';(leafs/(tag+'.c')).write_text(source);(leafs/(tag+'.original.hex')).write_text(code.hex()+'\n')
  known.add((mod,addr));accepted+=1
  with unrelocated_registry.open('w',newline='') as checkpoint_file:
   writer=csv.DictWriter(checkpoint_file,fieldnames=list(unrelocated_rows[0]),delimiter='\t');writer.writeheader();writer.writerows(unrelocated_rows)
  with registry.open('w',newline='') as checkpoint_file:
   writer=csv.DictWriter(checkpoint_file,fieldnames=list(rows[0]),delimiter='\t');writer.writeheader();writer.writerows(rows)
  print('MATCH',tag,size,optimization,flush=True);break

 if tested%100==0:print('Candidates',tested,'new matches',accepted,flush=True)
with registry.open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]),delimiter='\t');w.writeheader();w.writerows(rows)
with unrelocated_registry.open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(unrelocated_rows[0]),delimiter='\t');w.writeheader();w.writerows(unrelocated_rows)
print(json.dumps(dict(tested=tested,new_matches=accepted,total_linked=len(rows),linked_bytes=sum(int(r['size']) for r in rows))))
