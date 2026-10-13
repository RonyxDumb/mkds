"""Measure local byte-exact coverage, weighted by Ghidra function-body byte counts.
This is an identified-function inventory, not a verified whole-ROM link metric.
"""
from pathlib import Path
import csv,json,hashlib,struct
root=Path(__file__).resolve().parents[1];base=root/'baseline'
proofs={(x['module'],int(x['address'],16)):x for x in csv.DictReader((root/'verification/local-byte-exact.tsv').open(),delimiter='\t')}
build={(x['module'],Path(x['file']).stem):x for x in csv.DictReader((root/'checks/arm-build.tsv').open(),delimiter='\t')}
manifest=json.loads((base/'manifest.json').read_text());sections={m['name']:[(s['base'],(base/'binaries'/s['file']).read_bytes()) for s in m['sections']] for m in manifest['modules']}
def read(mod,addr,size):
 for start,data in sections[mod]:
  if start<=addr and addr+size<=start+len(data):return data[addr-start:addr-start+size]
 raise ValueError((mod,hex(addr),size))
def object_text(path):
 data=path.read_bytes();assert data[:6]==b'\x7fELF\x01\x01';assert struct.unpack_from('<H',data,18)[0]==40
 shoff=struct.unpack_from('<I',data,32)[0];entsize,count,stridx=struct.unpack_from('<HHH',data,46)
 sections=[struct.unpack_from('<10I',data,shoff+i*entsize) for i in range(count)];st=sections[stridx];strings=data[st[4]:st[4]+st[5]];text=[]
 for sec in sections:
  name=strings[sec[0]:].split(b'\0')[0]
  if sec[1] in [4,9] and sec[5]:raise ValueError('Unexpected relocation')
  if name.startswith(b'.text') and sec[5]:text.append(data[sec[4]:sec[4]+sec[5]])
 return b''.join(text)
modules=[];found=set()
for mod in ['arm9','arm9_ov000','arm9_ov001','arm9_ov003','arm7']:
 functions=[]
 for x in csv.DictReader((base/'pseudocode'/mod/'index.tsv').open(),delimiter='\t'):
  addr=int(x['address'],16);size=int(x['bytes']);name=x['name'];f=root/'src'/mod/f'{addr:08x}_{name}.c';b=build[(mod,f.stem)];proof=proofs.get((mod,addr));status=1 if b['status']=='ARM_OBJECT' else 2
  if proof:
   assert size==int(proof['size']);assert hashlib.sha256(f.read_bytes()).hexdigest()==proof['source_sha256']
   original=read(mod,addr,size);assert hashlib.sha256(original).hexdigest()==proof['sha256']
   archived=bytes.fromhex((root/'verification/leafs'/f'{mod}_{addr:08x}.original.hex').read_text());assert archived==original
   obj=root/'build/leaf-candidates'/f'{mod}_{addr:08x}.o'
   if obj.exists():assert object_text(obj)==original
   found.add((mod,addr));status=0
  functions.append([name,size,status,f'{addr:08x}'])
 modules.append(dict(name=mod,functions=functions,bytes=sum(x[1] for x in functions),exact_bytes=sum(x[1] for x in functions if x[2]==0),compiled_bytes=sum(x[1] for x in functions if x[2] in [0,1]),function_count=len(functions),exact_functions=sum(x[2]==0 for x in functions)))
assert found==proofs.keys()
total=sum(m['bytes'] for m in modules);exact=sum(m['exact_bytes'] for m in modules);n=sum(m['function_count'] for m in modules);compiled=sum(x[2] in [0,1] for m in modules for x in m['functions'])
data=dict(checkpoint=6,scope='Identified Ghidra function bodies across ARM9, overlays and ARM7; sum of function-body sizes, not unique ROM bytes or all assets.',identified_function_bytes=total,local_byte_exact_bytes=exact,local_byte_exact_percent=100*exact/total,identified_functions=n,local_byte_exact_functions=len(proofs),local_byte_exact_function_percent=100*len(proofs)/n,compilable_functions=compiled,compilable_function_percent=100*compiled/n,full_rom_link_verified=False,verification='Current source hashes and archived proof bytes checked against extracted ROM sections. MW object text rechecked when present; otherwise rely on historical local byte-exact proof.',modules=modules)
(root/'reports/progress-measured.json').write_text(json.dumps(data,separators=(',',':'))+'\n');print(json.dumps({k:v for k,v in data.items() if k!='modules'},indent=2))
lines=['# Copertura misurata — checkpoint 6','','**0,4561% dei byte attribuiti alle funzioni identificate è verificato localmente byte per byte.**','','8.728 / 1.913.676 byte. Denominatore: somma delle dimensioni dei corpi funzione nell’inventario Ghidra, incluse ARM9, overlay e ARM7. Non è la dimensione della ROM: risorse e dati non sono codice. L’inventario può avere funzioni mancanti, falsi positivi, dati nei corpi e byte condivisi fra funzioni; non è una certificazione del codice intero del gioco.','','| Modulo | Byte funzioni | Byte locali identici | Copertura |','|---|---:|---:|---:|']
for m in modules:lines.append(f"| {m['name']} | {m['bytes']} | {m['exact_bytes']} | {100*m['exact_bytes']/m['bytes']:.4f}% |")
lines+=['','613 / 12.038 funzioni: 5,0922% per numero di funzioni. Non usare questa misura come percentuale per dimensione: le funzioni verificate sono prevalentemente piccole.','','7.598 / 12.038 file compilabili: 63,1168%. Compilabilità e matching sono misure distinte.','','Ricontrollati hash sorgente e prove hex archiviate rispetto alle sezioni della ROM. Gli oggetti MW, se presenti in build/leaf-candidates, vengono confrontati nuovamente; altrimenti la verifica compilatore resta quella storica documentata. ROM completa, ABI globale e comportamento in gioco non verificati. Non si può ancora assegnare una percentuale esatta alla decompilazione funzionalmente corretta nonmatching.']
(root/'reports/MISURA-DECOMP.md').write_text('\n'.join(lines)+'\n')
