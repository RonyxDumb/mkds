from batch_matching import *
import concurrent.futures
ctx=MatchingContext(ROOT,ROOT/'baseline');runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/dependencies36',['-O4,p','-O4,s','-O2','-O1','-O3'])
by_name={n:(m,a) for (m,a),(n,mode,size) in ctx.inventory.items() if m=='arm9'}
seeds={('arm9',int(x['address'],16)) for x in json.loads((ROOT/'verification/character-select-family.json').read_text())['functions']}
closure=set(seeds);layers=[seeds]
for depth in range(3):
 following=set()
 for m,a in layers[-1]:
  name=ctx.inventory[m,a][0];p=ROOT/'src'/m/f'{a:08x}_{name}.c'
  if not p.exists():continue
  text=re.sub(r'/\*.*?\*/|//[^\n]*','',p.read_text(),flags=re.S)
  for call in re.findall(r'\b([A-Za-z_]\w*)\s*\(',text):
   if call in by_name:following.add(by_name[call])
 following-=closure;closure|=following;layers.append(following)
pool=[c for c in candidates(ctx,modules=['arm9']) if (c.module,c.address) in closure]
print('DEPENDENCIES',len(closure),'CANDIDATES',len(pool),flush=True)
out={'exact':[],'near':[],'attempts':0,'candidates':len(pool)}
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as ex:
 for ca,res in ex.map(runner.run,pool):
  out['attempts']+=len(res)
  best=min((v for v in res if v['outcome']=='mismatch'),key=lambda v:v['differing_bytes'],default=None)
  if best:out['near'].append(dict(address=hex(ca.address),name=ca.name,size=ca.size,diff=best['differing_bytes'],source=best['source'],optimization=best['optimization']))
  for v in res:
   if v['outcome']=='exact':
    out['exact'].append(dict(module=ca.module,name=ca.name,mode=ca.mode,address=hex(ca.address),size=ca.size,variant=ca.variant,source=v['source'],optimization=v['optimization']));print('EXACT',hex(ca.address),ca.size,flush=True)
  atomic_json(ROOT/'build/dependencies36.json',out)
print('DONE',out['attempts'],flush=True)
