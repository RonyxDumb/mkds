"""Verify complete locally linked ARM function bytes. No relocation is ignored."""
from pathlib import Path
import re,os,csv,json,hashlib,subprocess
from matching_resolver import MatchingContext
root=Path(__file__).resolve().parents[1];base=Path(os.environ['MKDS_BASELINE'])
context=MatchingContext(root,base)
sections,local,allsyms,inventory=context.sections,context.local,context.allsyms,context.inventory
linked,resolve,original=context.linked,context.resolve,context.original
known={(r['module'],int(r['address'],16)) for r in csv.DictReader((root/'verification/local-byte-exact.tsv').open(),delimiter='\t')}
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
 # Both ARM and Thumb are verified.
 try:
  target=original(mod,addr,n);code,relocs=linked(obj.read_bytes(),mod,name,addr)
  if not relocs or code!=target:continue
  src=obj.with_suffix('.c');proof=out/(obj.stem+'.o');processor='arm7tdmi' if mod=='arm7' else 'arm946e'
  args=[os.environ['WIBO'],os.environ['MWCCARM'],'-O4,p','-enum','int','-lang','c99','-char','signed','-interworking','-proc',processor,'-gccext,on','-msgstyle','gcc','-c',str(src),'-o',str(proof)]
  if mode=='thumb':args.insert(-4,'-thumb')
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
print(json.dumps(dict(exact_functions=len(rows),exact_code_bytes=sum(int(r['size']) for r in rows),resolved_relocations=sum(int(r['relocations']) for r in rows))))
