"""Verify complete locally linked ARM function bytes. No relocation is ignored."""
from pathlib import Path
import re,os,csv,json,hashlib,io,subprocess
from elftools.elf.elffile import ELFFile
root=Path(__file__).resolve().parents[1];base=Path(os.environ['MKDS_BASELINE']);manifest=json.loads((base/'manifest.json').read_text())
sections={m['name']:[(s['base'],(base/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
local={};allsyms={};inventory={}
for sf in (base/'symbols').glob('*.txt'):
 mod=sf.stem;local[mod]={}
 for line in sf.read_text().splitlines():
  m=re.match(r'^(\S+).* addr:0x([0-9a-fA-F]+)',line)
  if not m:continue
  name,a=m.groups();a=int(a,16);thumb='function(thumb,' in line
  local[mod][name]=(a,thumb);allsyms.setdefault(name,set()).add((a,thumb))
  f=re.search(r'kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)',line)
  if f:inventory[(mod,a)]=(name,f[1],int(f[2],16))
known={(r['module'],int(r['address'],16)) for r in csv.DictReader((root/'verification/local-byte-exact.tsv').open(),delimiter='\t')}
def original(mod,a,n):
 return next(b[a-start:a-start+n] for start,b in sections[mod] if start<=a and a+n<=start+len(b))
def resolve(mod,name):
 if name in local[mod]:return local[mod][name]
 choices=allsyms.get(name,set())
 if len(choices)!=1:raise ValueError('unresolved or ambiguous symbol '+name)
 return next(iter(choices))
def linked(data,mod,name,addr):
 elf=ELFFile(io.BytesIO(data));sym=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==name);idx=sym['st_shndx'];start=sym['st_value']&~1;n=sym['st_size'];code=bytearray(elf.get_section(idx).data()[start:start+n]);records=[]
 for sec in elf.iter_sections():
  if sec['sh_type'] not in ['SHT_RELA','SHT_REL'] or sec['sh_info']!=idx:continue
  symbols=elf.get_section(sec['sh_link'])
  for r in sec.iter_relocations():
   off=r['r_offset']-start
   if not 0<=off<n:continue
   if sec['sh_type']!='SHT_RELA' or off+4>n:raise ValueError('unsupported relocation')
   symbol=symbols.get_symbol(r['r_info_sym']);target,thumb=resolve(mod,symbol.name);word=int.from_bytes(code[off:off+4],'little');add=r['r_addend'];typ=r['r_info_type']
   if typ==1:
    if thumb or (word&0x0e000000)!=0x0a000000:raise ValueError('interworking/branch type')
    delta=target+add-(addr+off)
    if delta%4 or not -(1<<25)<=delta<(1<<25):raise ValueError('branch range')
    value=(word&0xff000000)|((delta>>2)&0xffffff)
   elif typ==2:value=(target+(1 if thumb else 0)+add)&0xffffffff
   else:raise ValueError('relocation type '+str(typ))
   code[off:off+4]=value.to_bytes(4,'little');records.append(dict(offset=off,type=typ,symbol=symbol.name,target=target,thumb=thumb,addend=add,value=value))
 return bytes(code),records
out=root/'verification/resolved-calls';out.mkdir(exist_ok=True)
registry=root/'verification/local-linked-byte-exact.tsv'
rows=list(csv.DictReader(registry.open(),delimiter='\t')) if registry.exists() else []
known.update((r['module'],int(r['address'],16)) for r in rows)
for obj in sorted((root.parent/'leaf-candidates').glob('*.o')):
 m=re.match(r'(.+)_([0-9a-f]{8})$',obj.stem)
 if not m:continue
 mod=m[1];addr=int(m[2],16)
 if (mod,addr) in known or (mod,addr) not in inventory:continue
 name,mode,n=inventory[(mod,addr)]
 if mode!='arm':continue
 try:
  target=original(mod,addr,n);code,relocs=linked(obj.read_bytes(),mod,name,addr)
  if not relocs or code!=target:continue
  src=obj.with_suffix('.c');proof=out/(obj.stem+'.o');processor='arm7tdmi' if mod=='arm7' else 'arm946e'
  args=[os.environ['WIBO'],os.environ['MWCCARM'],'-O4,p','-enum','int','-lang','c99','-char','signed','-interworking','-proc',processor,'-gccext,on','-msgstyle','gcc','-c',str(src),'-o',str(proof)]
  p=subprocess.run(args,capture_output=True,timeout=30)
  if p.returncode:continue
  code,relocs=linked(proof.read_bytes(),mod,name,addr)
  if code!=target:continue
  dest=root/'src'/mod/f'{addr:08x}_{name}.c';backup=root/'verification/previous_drafts'/mod/dest.name;backup.parent.mkdir(exist_ok=True,parents=True)
  if not backup.exists():backup.write_bytes(dest.read_bytes())
  dest.write_text('/* Complete local bytes verified after resolving every code relocation.\n * Full ROM linking and caller ABI remain unverified. */\n'+src.read_text())
  (out/(obj.stem+'.relocations.json')).write_text(json.dumps(relocs,indent=2)+'\n');(out/(obj.stem+'.linked.bin')).write_bytes(code)
  rows.append(dict(module=mod,name=name,mode=mode,address=f'0x{addr:08x}',size=n,sha256=hashlib.sha256(code).hexdigest(),source_sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),relocations=len(relocs),optimization='-O4,p',processor=processor,status='EXACT_LOCAL_LINKED_BYTES'))
 except (ValueError,StopIteration,KeyError):continue
if rows:
 with (root/'verification/local-linked-byte-exact.tsv').open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(rows[0]),delimiter='\t');w.writeheader();w.writerows(rows)
print(json.dumps(dict(exact_functions=len(rows),exact_code_bytes=sum(r['size'] for r in rows),resolved_relocations=sum(r['relocations'] for r in rows))))
