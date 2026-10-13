"""Recover simple leaf functions, accepting only exact, unrelocated byte identity."""
from pathlib import Path
import re,json,subprocess,io,hashlib,csv,concurrent.futures,os
from capstone import Cs,CS_ARCH_ARM,CS_MODE_ARM,CS_MODE_THUMB,CS_OP_REG,CS_OP_IMM,CS_OP_MEM
from capstone.arm import ARM_CC_AL,ARM_CC_INVALID,ARM_CC_EQ,ARM_CC_NE,ARM_CC_HS,ARM_CC_LO,ARM_CC_HI,ARM_CC_LS,ARM_CC_GE,ARM_CC_LT,ARM_CC_GT,ARM_CC_LE
from capstone.arm import ARM_SFT_LSL,ARM_SFT_LSR,ARM_SFT_ASR,ARM_SFT_ROR
from elftools.elf.elffile import ELFFile
work=Path(__file__).resolve().parents[1];root=work.parent;baseline=Path(os.environ.get('MKDS_BASELINE',str(root/'recovery/MarioKartDS-EUR-analysis')));manifest=json.loads((baseline/'manifest.json').read_text())
sections={m['name']:[(s['base'],(baseline/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
def target_bytes(module,a,n):
 for base,b in sections[module]:
  if base<=a and a+n<=base+len(b):return b[a-base:a-base+n]
 return None
existing=list(csv.DictReader((work/'verification/local-byte-exact.tsv').open(),delimiter='\t')); known={(r['module'],int(r['address'],16)) for r in existing}
linked_path=work/'verification/local-linked-byte-exact.tsv'
if linked_path.exists():known.update((r['module'],int(r['address'],16)) for r in csv.DictReader(linked_path.open(),delimiter='\t'))
funcs=[]
preamble="""typedef unsigned char uint8_t; typedef unsigned short uint16_t; typedef unsigned int uint32_t; typedef unsigned long long uint64_t;
typedef signed char int8_t; typedef short int16_t; typedef int int32_t; typedef long long int64_t; typedef unsigned int uintptr_t; typedef int intptr_t;
#define bool _Bool
#define true 1
#define false 0
#define UINT32_MAX 0xffffffffU
#define INT32_MAX 0x7fffffff
#define INT32_MIN (-2147483647-1)
#define __attribute__(x)
extern int __builtin_clz(unsigned int);
"""
compat=re.sub(r'^#(?:include|pragma).*$', '',(work/'src/ghidra_compat.h').read_text(),flags=re.M)
for sf in (baseline/'symbols').glob('*.txt'):
 module=sf.stem
 for line in sf.read_text().splitlines():
  m=re.match(r'^(\S+) kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\) addr:0x([0-9a-fA-F]+)',line)
  if not m:continue
  name,mode,n,a=m.groups();size=int(n,16);addr=int(a,16)
  if (module,addr) in known or size<=2048 or size>32768:continue
  src=work/'src'/module/f'{addr:08x}_{name}.c'
  if not src.exists():continue
  original=target_bytes(module,addr,size)
  if original is None:continue
  types=re.sub(r'^#(?:include|pragma).*$', '',(work/'src'/module/'types.h').read_text(),flags=re.M)
  deps=work/'src'/module/'deps'/(src.stem+'.h')
  declarations=re.sub(r'^#(?:include|pragma).*$', '',deps.read_text(),flags=re.M) if deps.exists() else ''
  body=re.sub(r'^#include.*$', '',src.read_text(),flags=re.M)
  source=preamble+compat+types+declarations+body
  funcs.append(dict(module=module,name=name,mode=mode,address=addr,size=size,original=original,source=source,kind='decompiled_control_flow'))
print('Candidates',len(funcs),flush=True)
cc=Path(os.environ.get('MWCCARM',str(root/'tooling/mwccarm/1.2/sp2p3/mwccarm.exe')));wibo=Path(os.environ.get('WIBO',str(root/'tooling/wibo')));flags='-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc'.split()
cands=root/'leaf-candidates';cands.mkdir(exist_ok=True);out=work/'verification/leafs';out.mkdir(parents=True,exist_ok=True)
def verify(f):
 tag=f['module']+'_'+format(f['address'],'08x');src=cands/(tag+'.c');obj=cands/(tag+'.o');src.write_text(f['source'])
 for optimization in ['-O0','-O1','-O2','-O3','-O4,s','-O4,p']:
  try:p=subprocess.run([str(wibo),str(cc),optimization,*flags[1:],*(['-proc','arm7tdmi'] if f['module']=='arm7' else []),*(['-thumb'] if f['mode']=='thumb' else []),'-c',str(src),'-o',str(obj)],capture_output=True,text=True,timeout=30)
  except subprocess.TimeoutExpired:continue
  if p.returncode or not obj.exists():continue
  elf=ELFFile(io.BytesIO(obj.read_bytes()));symtab=elf.get_section_by_name('.symtab');sym=next((s for s in symtab.iter_symbols() if s.name==f['name']),None)
  if sym is None or not isinstance(sym['st_shndx'],int):continue
  index=sym['st_shndx'];start=sym['st_value']&~1;size=sym['st_size'];code=elf.get_section(index).data()[start:start+size]
  relocs=[]
  for sec in elf.iter_sections():
   if sec['sh_type'] in ['SHT_REL','SHT_RELA'] and sec['sh_info']==index:
    relocs.extend(r for r in sec.iter_relocations() if start<=r['r_offset']<start+size)
  if relocs or code!=f['original']:continue
  break
 else:return None
 row={k:f[k] for k in ['module','name','mode','address','size','kind']};row['optimization']=optimization;row['processor']='arm7tdmi' if f['module']=='arm7' else 'arm946e';row['address']=f"0x{f['address']:08x}";row['sha256']=hashlib.sha256(code).hexdigest();row['relocations']=0;row['status']='EXACT_LOCAL_BYTES'
 # Preserve drafts; install verified high-level C without assembler or opaque byte arrays.
 dest=work/'src'/f['module']/f"{f['address']:08x}_{f['name']}.c"
 if dest.exists():
  backup=work/'verification/previous_drafts'/f['module'];backup.mkdir(parents=True,exist_ok=True);
  if not (backup/dest.name).exists():(backup/dest.name).write_bytes(dest.read_bytes())
  dest.write_text('/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.\n * No relocations. Full ROM linking remains unverified. */\n'+f['source'])
 row['source_sha256']=hashlib.sha256(dest.read_bytes()).hexdigest()
 (out/(tag+'.c')).write_text(f['source']);(out/(tag+'.original.hex')).write_text(code.hex()+'\n');return row
rows=existing.copy()
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
 for i,r in enumerate(pool.map(verify,funcs),1):
  if r:rows.append(r)
  if i%100==0:print('Checked',i,'exact',len(rows),flush=True)
with (work/'verification/local-byte-exact.tsv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=['module','name','mode','address','size','kind','sha256','relocations','status','source_sha256','optimization','processor'],delimiter='\t');w.writeheader();w.writerows(rows)
meta={'new_exact_functions':len(rows)-len(existing),'candidates':len(funcs),'exact_functions':len(rows),'exact_code_bytes':sum(int(r['size']) for r in rows),'compiler':'mwccarm 1.2/sp2p3 (Version 2.0 build 82)','flags':flags,'verification':'Identical entire function byte sequence, equal length, zero relocations; no byte masking; no inline assembly; full ROM link not verified'}
(work/'verification/summary.json').write_text(json.dumps(meta,indent=2)+'\n');print(json.dumps(meta),flush=True)
