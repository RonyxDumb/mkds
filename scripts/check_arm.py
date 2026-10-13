from pathlib import Path
import csv,subprocess,concurrent.futures,importlib.util,sys,os,json,struct
root=Path(__file__).resolve().parents[1];spec=importlib.util.find_spec('ziglang');zig=Path(spec.origin).parent/('zig.exe' if os.name=='nt' else 'zig')
objects=Path(sys.argv[1] if len(sys.argv)>1 else root/'build_objects');objects.mkdir(parents=True,exist_ok=True);errors=root/'checks/errors';errors.mkdir(parents=True,exist_ok=True)
files=sorted((root/'src').glob('*/*.c'));flags=['-target','arm-freestanding-eabi','-std=gnu11','-O1','-fno-builtin','-Werror=implicit-function-declaration','-Werror=return-type','-Werror=incompatible-pointer-types','-Werror=int-conversion']
def compile_one(f):
 cpu='arm7tdmi' if f.parent.name=='arm7' else 'arm946e_s';dest=objects/f.parent.name;dest.mkdir(exist_ok=True);obj=dest/(f.stem+'.o')
 try:
  p=subprocess.run([str(zig),'cc',*flags,'-mcpu='+cpu,'-c',str(f),'-o',str(obj)],capture_output=True,text=True,timeout=60);ok=p.returncode==0;log=p.stderr
 except subprocess.TimeoutExpired:ok=False;log='Compiler timeout'
 if ok:
  b=obj.read_bytes();assert b[:4]==b'\x7fELF' and b[4]==1 and b[5]==1 and struct.unpack_from('<H',b,18)[0]==40
 else:(errors/(f.parent.name+'_'+f.stem+'.txt')).write_text(log.replace(str(root),'C-WORK'))
 diagnostic=next((s for s in log.splitlines() if 'error:' in s),log.splitlines()[0] if log else '')
 return {'module':f.parent.name,'file':str(f.relative_to(root)),'status':'ARM_OBJECT' if ok else 'NEEDS_REPAIR','ghidra_warning':'WARNING:' in f.read_text() or 'Bad instruction' in f.read_text(),'compiler_warnings':log.count('warning:'),'diagnostic':diagnostic.replace(str(root),'C-WORK') if not ok else ''}
rows=[]
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
 for i,r in enumerate(pool.map(compile_one,files),1):
  rows.append(r)
  if i%1000==0:print('Checked',i,'built',sum(r['status']=='ARM_OBJECT' for r in rows),flush=True)
with (root/'checks/arm-build.tsv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]),delimiter='\t');w.writeheader();w.writerows(rows)
meta={'compiler':'Zig 0.14.1 bundled Clang','flags':flags,'cpus':{'arm9':'arm946e_s','arm7':'arm7tdmi'},'tested':len(rows),'built':sum(r['status']=='ARM_OBJECT' for r in rows),'needs_repair':sum(r['status']=='NEEDS_REPAIR' for r in rows)}
(root/'checks/summary.json').write_text(json.dumps(meta,indent=2)+'\n');print(json.dumps(meta),flush=True)
