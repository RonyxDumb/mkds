"""Prepare independently verified C donor candidates, never trusting donor metrics."""
from pathlib import Path
import concurrent.futures, hashlib, json, os, re, subprocess, sys
ROOT=Path(__file__).resolve().parents[1]
donor=Path(sys.argv[1]).resolve()
assert subprocess.check_output(['git','-C',str(donor),'rev-parse','HEAD'],text=True).strip()=='c6e18fa4b346643b74c402b605a84b43cba16c01'
assert not subprocess.check_output(['git','-C',str(donor),'status','--porcelain'],text=True).strip()
out=ROOT/'build/mkds-candidates';out.mkdir(parents=True,exist_ok=True)
vendor=ROOT/'vendor/mkds-donor';vendor.mkdir(parents=True,exist_ok=True)
(vendor/'LICENSE').write_bytes((donor/'LICENSE').read_bytes())
(vendor/'README.md').write_text('Derived C: https://github.com/ai-tdd-labs/mkds-decomp\nCommit c6e18fa4b346643b74c402b605a84b43cba16c01.\nOnly independently compiled and fully resolved local matches installed.\nAssembly, includes, initialized opaque arrays, ROM, BIOS and assets excluded.\nSource comments and donor license preserved.\n')
jobs=[];seen=set();excluded=[]
for line in (donor/'ai/tus.txt').read_text().splitlines():
 f=line.split('\t');p=donor/f[0]
 if p in seen or not p.is_file():continue
 seen.add(p);clean=re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"','',p.read_text(),flags=re.S)
 if re.search(r'\b(?:asm|__asm|__asm__)\b|^\s*#\s*include',clean,re.M) or re.search(r'\[[^\]]*\]\s*=\s*\{',clean):excluded.append(str(p.relative_to(donor)));continue
 mode=f[2] if len(f)>2 and f[2] else 'arm'
 assert mode in ('arm','thumb');jobs.append((p,mode))
def run(job):
 p,mode=job;name=p.stem+'.'+hashlib.sha256(str(p.relative_to(donor)).encode()).hexdigest()[:12]+'.'+mode+'.o'
 flags=['-O4,p','-enum','int','-lang','c99','-char','signed','-interworking','-proc','arm946e','-gccext,on','-msgstyle','gcc']+(['-thumb'] if mode=='thumb' else [])
 obj=out/name;obj.unlink(missing_ok=True)
 r=subprocess.run([os.environ['WIBO'],os.environ['MWCCARM'],*flags,'-c',str(p),'-o',str(obj)],capture_output=True,timeout=30)
 return name,{'source':str(p.relative_to(donor)),'flags':flags,'returncode':r.returncode,'error':(r.stdout+r.stderr).decode(errors='replace')[:1000]}
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:results=list(pool.map(run,jobs))
objects={n:{k:r[k] for k in ['source','flags']} for n,r in results if r['returncode']==0}
(out/'config.json').write_text(json.dumps({'object_directory':str(out.relative_to(ROOT)),'objects':objects,'complete_translation_unit':True,'target_modules':['arm9']},indent=2)+'\n')
(out/'build-results.json').write_text(json.dumps({'results':dict(results),'excluded':excluded},indent=2)+'\n')
print(json.dumps({'candidate_sources':len(jobs),'compiled_objects':len(objects)}))
