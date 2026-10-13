"""Verify complete locally linked ARM function bytes. No relocation is ignored."""
from pathlib import Path
import re,os,csv,json,hashlib,io,subprocess
from elftools.elf.elffile import ELFFile
from capstone import Cs,CS_ARCH_ARM,CS_MODE_THUMB,CS_MODE_ARM
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
    if (word&0x0e000000)!=0x0a000000:raise ValueError('branch type')
    delta=target+add-(addr+off)
    if thumb:
     if (word&0xff000000) not in [0xeb000000,0xfa000000,0xfb000000]:raise ValueError('interworking requires unconditional call')
     if delta%2 or not -(1<<25)<=delta<(1<<25):raise ValueError('BLX range')
     value=0xfa000000|((delta>>2)&0xffffff)|((delta&2)<<23)
     decoded=list(Cs(CS_ARCH_ARM,CS_MODE_ARM).disasm(value.to_bytes(4,'little'),addr+off))
     if len(decoded)!=1 or decoded[0].mnemonic!='blx' or int(decoded[0].op_str.lstrip('#'),0)!=target:raise ValueError('independent ARM BLX target check')
    else:
     if delta%4 or not -(1<<25)<=delta<(1<<25):raise ValueError('branch range')
     value=(word&0xff000000)|((delta>>2)&0xffffff)
   elif typ==10:
    if not thumb:raise ValueError('Thumb interworking requires a verified veneer')
    hi=word&0xffff;lo=word>>16
    if hi&0xf800!=0xf000 or lo&0xf800!=0xf800:raise ValueError('not Thumb BL')
    delta=target+add-(addr+off)
    if delta%2 or not -(1<<22)<=delta<(1<<22):raise ValueError('Thumb BL range')
    value=(0xf000|((delta>>12)&0x7ff))|((0xf800|((delta>>1)&0x7ff))<<16)
    decoded=list(Cs(CS_ARCH_ARM,CS_MODE_THUMB).disasm(value.to_bytes(4,'little'),addr+off))
    if len(decoded)!=1 or decoded[0].mnemonic!='bl' or int(decoded[0].op_str.lstrip('#'),0)!=target:raise ValueError('independent Thumb target check')
   elif typ==2:value=(target+(1 if thumb else 0)+add)&0xffffffff
   else:raise ValueError('relocation type '+str(typ))
   code[off:off+4]=value.to_bytes(4,'little');records.append(dict(offset=off,type=typ,symbol=symbol.name,target=target,thumb=thumb,addend=add,value=value))
 return bytes(code),records
rows=list(csv.DictReader((root/'verification/local-linked-byte-exact.tsv').open(),delimiter='\t'))
for r in rows:
 addr=int(r['address'],16);n=int(r['size']);dest=root/'src'/r['module']/f"{addr:08x}_{r['name']}.c"
 assert hashlib.sha256(dest.read_bytes()).hexdigest()==r['source_sha256']
 proof=root/'verification/resolved-calls'/f"{r['module']}_{addr:08x}.o"
 args=[os.environ['WIBO'],os.environ['MWCCARM'],r['optimization'],'-enum','int','-lang','c99','-char','signed','-interworking','-proc',r['processor'],'-gccext,on','-msgstyle','gcc','-c',str(dest),'-o',str(proof)]
 if r['mode']=='thumb':args.insert(-4,'-thumb')
 p=subprocess.run(args,capture_output=True,timeout=30);assert p.returncode==0,p.stderr
 code,relocs=linked(proof.read_bytes(),r['module'],r['name'],addr)
 assert code==original(r['module'],addr,n)
 assert hashlib.sha256(code).hexdigest()==r['sha256']
 assert len(relocs)==int(r['relocations'])
summary=dict(tested=len(rows),passed=len(rows),bytes=sum(int(r['size']) for r in rows),resolved_relocations=sum(int(r['relocations']) for r in rows),full_rom_link_verified=False)
(root/'verification/linked-matching-audit.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary))
