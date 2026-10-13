"""Replace byte-pointer declarations with function pointers only for proven PC literals.
Call arguments and function bodies are not altered; no permissive prototypes are added.
"""
from pathlib import Path
import csv,re,json,struct
from capstone import Cs,CS_ARCH_ARM,CS_MODE_ARM,CS_MODE_THUMB,CS_OP_MEM
root=Path(__file__).resolve().parents[1];base=root/'baseline';manifest=json.loads((base/'manifest.json').read_text());secs={m['name']:[(s['base'],(base/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
entries={};sizes={};modes={}
for p in (root/'src').iterdir():
 if not p.is_dir():continue
 for r in csv.DictReader((p/'index.tsv').open(),delimiter='\t'):
  if r['status']=='OK':entries[(p.name,int(r['address'],16))]=(r['name'],p/r['file'])
 for r in csv.DictReader((base/'pseudocode'/p.name/'index.tsv').open(),delimiter='\t'):sizes[(p.name,int(r['address'],16))]=int(r['bytes'])
for p in (base/'symbols').glob('*.txt'):
 for line in p.read_text().splitlines():
  m=re.search(r'kind:function\((arm|thumb),size=.*addr:0x([0-9a-fA-F]+)',line)
  if m:modes[(p.stem,int(m[2],16))]=m[1]
def read(mod,a,n):
 for b,d in secs[mod]:
  if b<=a and a+n<=b+len(d):return d[a-b:a-b+n]
 return None
def prototype(name,path):
 text=re.sub(r'/\*.*?\*/|//[^\n]*','',path.read_text(),flags=re.S);text=re.sub(r'^\s*#.*$','',text,flags=re.M)
 m=re.search(r'\b([A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*\**\s*'+re.escape(name)+r'\s*\([^{};]*\))\s*\{',text)
 if not m:return None
 sig=' '.join(m[1].split())+';'
 # Avoid unknown custom types leaking between modules in this mechanical pass.
 if '[' in sig or 'struct ' in sig or '...' in sig:return None
 return sig
macro=re.compile(r'^#define (\w+) \(\*\(undefined \*\*\)\(uintptr_t\)0x([0-9a-fA-F]+)u\)$',re.M)
changes=[]
for (mod,a),(caller,f) in entries.items():
 h=f.parent/'deps'/f.name.replace('.c','.h')
 if not h.exists():continue
 text=h.read_text();body=f.read_text();n=sizes.get((mod,a),0);code=read(mod,a,min(n,65536))
 if not code:continue
 candidates=[]
 for m in macro.finditer(text):
  variable,pool=m[1],int(m[2],16)
  if not re.search(r'\(\*'+re.escape(variable)+r'\)\s*\(',body):continue
  literal=read(mod,pool,4)
  if literal is None:continue
  target=struct.unpack('<I',literal)[0];key=(mod,target&~1)
  if key not in entries and mod.startswith('arm9'):key=('arm9',target&~1)
  if key not in entries:continue
  name,path=entries[key];sig=prototype(name,path)
  if not sig:continue
  found=False
  for mode in ([modes[(mod,a)]] if (mod,a) in modes else ['arm','thumb']):
   md=Cs(CS_ARCH_ARM,CS_MODE_THUMB if mode=='thumb' else CS_MODE_ARM);md.detail=True
   for i in md.disasm(code,a):
    if i.mnemonic not in ['ldr','ldrne','ldreq'] or len(i.operands)!=2 or i.operands[1].type!=CS_OP_MEM:continue
    mem=i.operands[1].mem
    if i.reg_name(mem.base)!='pc' or mem.index:continue
    pc=((i.address+4)&~3) if mode=='thumb' else i.address+8
    if pc+mem.disp==pool:found=True;break
   if found:break
  if not found:continue
  old=m[0];new=f'#define {variable} (*(__typeof__({name}) **)(uintptr_t)0x{pool:x}u)'
  candidates.append((old,new,sig,variable,pool,target,name))
 if not candidates:continue
 backup=root/'verification/pointer_typing/previous_headers'/mod;backup.mkdir(parents=True,exist_ok=True);saved=backup/h.name
 if not saved.exists():saved.write_text(text)
 for old,new,sig,var,pool,target,name in candidates:
  text=text.replace(old,new)
  if sig not in text:text=text.replace('/* Function-specific inferred declarations. */','/* Function-specific inferred declarations. */\n'+sig)
  changes.append({'module':mod,'caller':caller,'file':str(f.relative_to(root)),'variable':var,'literal_address':f'0x{pool:08x}','target_address':f'0x{target:08x}','target_name':name,'prototype':sig,'evidence':'PC-relative literal load points to an indexed function; preserve actual call arguments'})
 h.write_text(text)
out=root/'verification/pointer_typing';out.mkdir(parents=True,exist_ok=True)
with (out/'changes.tsv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(changes[0]) if changes else ['file'],delimiter='\t');w.writeheader();w.writerows(changes)
print('Typed pointers',len(changes),'functions',len({r['file'] for r in changes}),flush=True)
