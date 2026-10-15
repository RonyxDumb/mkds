"""Recompile every registered function and reject relocations or any byte difference."""
from pathlib import Path
import csv,os,subprocess,io,hashlib,json,concurrent.futures,importlib.util
from elftools.elf.elffile import ELFFile
from matching_compiler import compiler_for
root=Path(__file__).resolve().parents[1]
base=Path(os.environ['MKDS_BASELINE']);manifest=json.loads((base/'manifest.json').read_text())
sections={m['name']:[(s['base'],(base/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
rows=list(csv.DictReader((root/'verification/local-byte-exact.tsv').open(),delimiter='\t'))
out=root/'verification/mw-objects';out.mkdir(exist_ok=True)
def verify(r):
 addr=int(r['address'],16);size=int(r['size']);src=root/'src'/r['module']/f"{addr:08x}_{r['name']}.c"
 assert hashlib.sha256(src.read_bytes()).hexdigest()==r['source_sha256']
 original=next(b[addr-a:addr-a+size] for a,b in sections[r['module']] if a<=addr and addr+size<=a+len(b))
 assert hashlib.sha256(original).hexdigest()==r['sha256']
 obj=out/f"{r['module']}_{addr:08x}.o";processor='arm7tdmi' if r['module']=='arm7' else 'arm946e'
 if r.get('kind')=='sdk_source':
  meta=json.loads((root/'verification/sdk-source-proofs.json').read_text())[f"{r['module']}_{addr:08x}"]
  subprocess.run([os.environ['WIBO'],compiler_for(root,meta),*meta['flags'],'-c',str(src),'-o',str(obj)],cwd=root,check=True,capture_output=True)
  elf=ELFFile(io.BytesIO(obj.read_bytes()));sym=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==r['name']);idx=sym['st_shndx'];start=sym['st_value']&~1;code=elf.get_section(idx).data()[start:start+sym['st_size']]
  assert sym['st_size']==size and code==original
  assert not any(start<=x['r_offset']<start+size for sec in elf.iter_sections() if sec['sh_type'] in ['SHT_REL','SHT_RELA'] and sec['sh_info']==idx for x in sec.iter_relocations())
  return r
 if r.get('kind','').startswith('clang_'):
  zig=Path(importlib.util.find_spec('ziglang').origin).parent/'zig'
  flags=['-target','arm-freestanding-eabi','-mcpu='+('arm7tdmi' if r['module']=='arm7' else 'arm946e_s'),r['optimization'],'-std=gnu11','-fno-builtin','-mthumb' if r['mode']=='thumb' else '-marm']
  subprocess.run([str(zig),'cc',*flags,'-c',str(src),'-o',str(obj)],check=True,capture_output=True)
  elf=ELFFile(io.BytesIO(obj.read_bytes()));sym=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==r['name']);idx=sym['st_shndx'];code=elf.get_section(idx).data()
  assert (sym['st_value']&~1)==0 and sym['st_size']==len(code)==size
  assert not any(sec['sh_type'] in ['SHT_REL','SHT_RELA'] and sec['sh_info']==idx and sec['sh_size'] for sec in elf.iter_sections())
  assert code==original
  return r
 for opt in [r.get('optimization') or '-O4,p','-O0','-O1','-O2','-O3','-O4,s']:
  args=[os.environ['WIBO'],os.environ['MWCCARM'],opt,'-enum','int','-lang','c99','-char','signed','-interworking','-proc',processor,'-gccext,on','-msgstyle','gcc']
  if r['mode']=='thumb':args+=['-thumb']
  p=subprocess.run(args+['-c',str(src),'-o',str(obj)],capture_output=True,timeout=30)
  if p.returncode:continue
  elf=ELFFile(io.BytesIO(obj.read_bytes()));sym=next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==r['name']);idx=sym['st_shndx'];start=sym['st_value']&~1
  code=elf.get_section(idx).data()[start:start+sym['st_size']]
  reloc=[x for sec in elf.iter_sections() if sec['sh_type'] in ['SHT_REL','SHT_RELA'] and sec['sh_info']==idx for x in sec.iter_relocations() if start<=x['r_offset']<start+sym['st_size']]
  if not reloc and code==original:
   r['optimization']=opt;r['processor']=processor;return r
 raise AssertionError('Mismatch: '+str(src))
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:verified=list(pool.map(verify,rows))
summary={'tested':len(verified),'passed':len(verified),'exact_code_bytes':sum(int(r['size']) for r in verified),'relocations':0,'full_rom_link_verified':False,'compiler':'Per-function recorded MWCC variants (SHA-256 checked); default 1.2/sp2p3; Clang for explicitly tagged proofs','verification':'Fresh compilation of current source; complete function bytes and length identical to original decompressed section; no masking or relocations.'}
(root/'verification/matching-audit.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary))
