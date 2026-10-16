"""Recompile pinned donor candidates with the explicitly selected compiler.

Writes search objects only; verify_sdk_sources.py remains the byte acceptance gate.
"""
import argparse, concurrent.futures, hashlib, json, os, subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
p=argparse.ArgumentParser(description=__doc__);p.add_argument('donor',type=Path);p.add_argument('config',type=Path);p.add_argument('--output',required=True);p.add_argument('--both-inline',action='store_true');a=p.parse_args()
cfg=json.loads(a.config.read_text());donor=a.donor.resolve();out=ROOT/a.output;out.mkdir(parents=True,exist_ok=True)
jobs={}
for value in cfg['objects'].values():
 for inline in (['on,noauto','on,auto'] if a.both_inline and '-inline' in value['flags'] else [None]):
  flags=list(value['flags'])
  if inline:flags[flags.index('-inline')+1]=inline
  item=dict(source=value['source'],flags=flags)
  name=hashlib.sha256(json.dumps(item,sort_keys=True).encode()).hexdigest()[:24]+'.o';jobs[name]=item
def run(pair):
 name,v=pair
 result=subprocess.run([os.environ['WIBO'],os.environ['MWCCARM'],*v['flags'],'-c',str(donor/v['source']),'-o',str(out/name)],cwd=ROOT,capture_output=True,timeout=30)
 return name,v,result.returncode,(result.stdout+result.stderr).decode(errors='replace')[-1500:]
objects={};errors=[]
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
 for i,(n,v,code,error) in enumerate(pool.map(run,jobs.items()),1):
  if not code:objects[n]=v
  else:errors.append(dict(source=v['source'],error=error))
  if i%200==0:print('Compiler profile',i,'/',len(jobs),flush=True)
cfg.update(objects=objects,object_directory=str(out.relative_to(ROOT)),complete_translation_unit=True,allow_observed_call_targets=True)
(out/'config.json').write_text(json.dumps(cfg,indent=2)+'\n');(out/'build-errors.json').write_text(json.dumps(errors,indent=2)+'\n')
print(json.dumps(dict(attempted=len(jobs),compiled=len(objects),failed=len(errors))),flush=True)
