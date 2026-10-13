"""Declare address-named calls using indexed definitions; never change argument lists."""
from pathlib import Path
import csv,re,json
root=Path(__file__).resolve().parents[1]
entries={}
for module in (root/'src').iterdir():
 if not module.is_dir():continue
 entries[module.name]={}
 for r in csv.DictReader((module/'index.tsv').open(),delimiter='\t'):
  if r['status']!='OK':continue
  f=module/r['file']; t=re.sub(r'/\*.*?\*/|//[^\n]*','',f.read_text(),flags=re.S);t=re.sub(r'^\s*#.*$','',t,flags=re.M)
  m=re.search(r'\b([A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)*\s*\**\s*'+re.escape(r['name'])+r'\s*\([^{};]*\))\s*\{',t)
  if m and not any(x in m[1] for x in ['struct ','[','...']):entries[module.name][int(r['address'],16)]=(r['name'],' '.join(m[1].split())+';')
out=root/'verification/address_calls';out.mkdir(exist_ok=True);changes=[]
for mod in entries:
 for f in (root/'src'/mod).glob('*.c'):
  h=f.parent/'deps'/f.name.replace('.c','.h');t=h.read_text();add=[]
  for alias,addr in re.findall(r'\b(func_0x([0-9a-fA-F]+))\s*\(',f.read_text()):
   a=int(addr,16)&~1;target=entries[mod].get(a)
   if not target and mod.startswith('arm9'):target=entries['arm9'].get(a)
   if not target:continue
   name,sig=target
   if re.search(r'\b'+alias+r'\b',t):continue
   add.extend([sig,f'#define {alias} {name}']);changes.append(dict(module=mod,file=f.name,alias=alias,target=name,address=hex(a),prototype=sig))
  if add:
   backup=out/'previous_headers'/mod;backup.mkdir(parents=True,exist_ok=True);(backup/h.name).write_text(t)
   h.write_text(t+'\n/* Address resolved to indexed definition; inferred ABI remains provisional. */\n'+'\n'.join(dict.fromkeys(add))+'\n')
(out/'changes.json').write_text(json.dumps(changes,indent=2)+'\n');print('Declarations',len(changes))
