import pathlib, json, hashlib, shutil, ndspy.rom, ndspy.codeCompression, subprocess, struct
root=pathlib.Path(__file__).resolve().parents[1]
rompath=pathlib.Path(__import__('sys').argv[1]); r=ndspy.rom.NintendoDSRom.fromFile(rompath)
modules=[]
for cpu in ['Arm9','Arm7']:
 m=getattr(r,'load'+cpu)(); name=cpu.lower()
 sections=[]
 for i,s in enumerate(m.sections):
  p=root/'binaries'/f'{name}_{i}.bin';p.write_bytes(s.data)
  sections.append(dict(file=p.name,base=s.ramAddress,size=len(s.data),bss=s.bssSize))
 if m.codeSettingsOffs is not None:
  full=ndspy.codeCompression.decompress(getattr(r,name))
  start,end=struct.unpack_from("<2I",full,m.codeSettingsOffs+12)
  if start==sections[0]["base"]+sections[0]["size"]: sections[0]["bss"]=end-start
 modules.append(dict(name=name,sections=sections,entry=getattr(r,name+'EntryAddress'),language='ARM:LE:32:v5t' if cpu=='Arm9' else 'ARM:LE:32:v4t'))
 for i,o in getattr(r,'load'+cpu+'Overlays')().items():
  p=root/'binaries'/f'{name}_ov{i:03}.bin';p.write_bytes(o.data)
  modules.append(dict(name=p.stem,sections=[dict(file=p.name,base=o.ramAddress,size=len(o.data),bss=o.bssSize)],entry=None,language='ARM:LE:32:v5t'))
(root/'manifest.json').write_text(json.dumps(dict(sha1=hashlib.sha1(rompath.read_bytes()).hexdigest(),modules=modules),indent=2))
for m in modules:
 lines=[]
 for s in m['sections'][1:]: lines.append(f"{s['file']}\t{s['base']:x}\t{s['bss']:x}")
 s=m['sections'][0];lines.append(f"BSS\t{s['base']+s['size']:x}\t{s['bss']:x}")
 (root/'symbols'/f"{m['name']}.blocks.tsv").write_text('\n'.join(lines)+'\n')
print(json.dumps(modules,indent=2))
