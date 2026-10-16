"""Compile new optimization profiles of previously vetted pure-C donor units.

No proof is installed here. verify_sdk_sources.py must independently reconstruct,
compile and resolve each complete candidate before accepting any byte.
"""
from pathlib import Path
import argparse, concurrent.futures, hashlib, json, os, subprocess
ROOT=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('donor',type=Path)
p.add_argument('configs',type=Path,nargs='+')
p.add_argument('--output',default='build/donor-optimization-variants')
p.add_argument('--optimization',action='append')
a=p.parse_args();donor=a.donor.resolve()
assert subprocess.check_output(['git','-C',str(donor),'rev-parse','HEAD'],text=True).strip()=='c6e18fa4b346643b74c402b605a84b43cba16c01'
assert not subprocess.check_output(['git','-C',str(donor),'status','--porcelain'],text=True).strip()
out=ROOT/a.output;out.mkdir(parents=True,exist_ok=True);jobs={}
for cp in a.configs:
 cfg=json.loads(cp.read_text());assert cfg.get('complete_translation_unit')
 for v in cfg['objects'].values():
  for opt in a.optimization or ['-O4,s','-O2','-O3','-O1']:
   flags=[opt if f.startswith('-O') else f for f in v['flags']]
   value=dict(source=v['source'],flags=flags)
   name=hashlib.sha256(json.dumps(value,sort_keys=True).encode()).hexdigest()[:24]+'.o'
   jobs[name]=value
def compile_one(item):
 name,v=item;dest=out/name
 result=subprocess.run([os.environ['WIBO'],os.environ['MWCCARM'],*v['flags'],'-c',str(donor/v['source']),'-o',str(dest)],cwd=ROOT,capture_output=True,timeout=30)
 return name,v,result.returncode
objects={};failures=0
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
 for i,(n,v,code) in enumerate(pool.map(compile_one,jobs.items()),1):
  if code==0:objects[n]=v
  else:failures+=1
  if i%500==0:print('Compiled',i,'/',len(jobs),flush=True)
cfg=dict(object_directory=str(out.relative_to(ROOT)),objects=objects,complete_translation_unit=True,target_modules=['arm9'])
(out/'config.json').write_text(json.dumps(cfg,indent=2)+'\n')
print(json.dumps(dict(attempted=len(jobs),compiled=len(objects),failed=failures)),flush=True)
