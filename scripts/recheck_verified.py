from pathlib import Path
import csv,subprocess,importlib.util,concurrent.futures,json,struct
root=Path(__file__).resolve().parents[1];zig=Path(importlib.util.find_spec('ziglang').origin).parent/'zig';proofs=list(csv.DictReader((root/'verification/local-byte-exact.tsv').open(),delimiter='\t'));linked=root/'verification/local-linked-byte-exact.tsv'
if linked.exists():proofs+=list(csv.DictReader(linked.open(),delimiter='\t'))
out=root.parent/'verified-arm-objects';out.mkdir(exist_ok=True)
def run(r):
 f=root/'src'/r['module']/(r['address'][2:]+'_'+r['name']+'.c');obj=out/(r['module']+'_'+f.stem+'.o')
 p=subprocess.run([str(zig),'cc','-target','arm-freestanding-eabi','-mcpu='+('arm7tdmi' if r['module']=='arm7' else 'arm946e_s'),'-std=gnu11','-O1','-fno-builtin','-Werror=implicit-function-declaration','-Werror=return-type','-Werror=incompatible-pointer-types','-Werror=int-conversion','-c',str(f),'-o',str(obj)],capture_output=True,text=True)
 if p.returncode:return {'function':r['name'],'error':p.stderr}
 b=obj.read_bytes();assert b[:4]==b'\x7fELF' and b[4:6]==b'\x01\x01' and struct.unpack_from('<H',b,18)[0]==40
 return None
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:errors=[r for r in pool.map(run,proofs) if r]
(root/'verification/clang-recheck.json').write_text(json.dumps({'tested':len(proofs),'passed':len(proofs)-len(errors),'errors':errors},indent=2)+'\n');print('Rechecked',len(proofs),'errors',len(errors));assert not errors
