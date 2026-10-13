"""Reproduce automatic analysis; requires Ghidra 11.3.2 and JDK 21."""
import json, os, pathlib, subprocess, sys
root=pathlib.Path(__file__).resolve().parents[1]
ghidra=pathlib.Path(os.environ['GHIDRA_HOME'])
headless=ghidra/'support'/('analyzeHeadless.bat' if os.name=='nt' else 'analyzeHeadless')
work=root/'work_projects';work.mkdir(exist_ok=True)
manifest=json.loads((root/'manifest.json').read_text())
for m in manifest['modules']:
 s=m['sections'][0]
 args=[str(headless),str(work),m['name'],'-import',str(root/'binaries'/s['file']),'-overwrite','-processor',m['language'],'-loader','BinaryLoader','-loader-baseAddr',hex(s['base']),'-scriptPath',str(root/'scripts'),'-preScript','PrepareMKDS.java',str(root),m['name'],'-postScript','ExportMKDS.java',str(root),m['name'],'-analysisTimeoutPerFile','300','-max-cpu','2']
 print('Analyzing',m['name'],flush=True)
 subprocess.run(args,check=True)
 subprocess.run([str(headless),str(work),m["name"],"-process",s["file"],"-noanalysis","-scriptPath",str(root/"scripts"),"-postScript","PackMKDS.java",str(root),m["name"]],check=True)
