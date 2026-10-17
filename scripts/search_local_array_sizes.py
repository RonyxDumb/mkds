"""Test inferred local-array extents; accept only complete linked-byte identity."""
from batch_matching import *
import itertools

def main():
 ctx=MatchingContext(ROOT,ROOT/'baseline')
 runner=Search(ctx,ROOT/'tools/mwccarm/1.2/sp2p3/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/local-array41',['-O4,p','-O2','-O3','-O4,s'])
 out={'exact':[],'near_misses':[]};done=set();count=0
 for c in candidates(ctx,minimum=64):
  if c.address in done:continue
  arrays=list(re.finditer(r'\b(local_[0-9a-f]+)\s*\[\s*([2-9]|[1-9][0-9])\s*\]\s*;',c.source))
  if not arrays:continue
  options=[]
  for x in arrays:
   uses=re.findall(r'\b'+x[1]+r'\s*\[\s*(\d+)\s*\]',c.source[x.end():]);minimum=max([int(i)+1 for i in uses]+[1]);options.append(sorted(set([minimum,1,2,3])&set(range(minimum,int(x[2])))))
  if any(not o for o in options):continue
  for extents in itertools.islice(itertools.product(*options),27):
   src=c.source
   for match,size in reversed(list(zip(arrays,extents))):src=src[:match.start()]+match.group(0).replace('['+match[2]+']','['+str(size)+']')+src[match.end():]
   ca=Candidate(c.module,c.name,c.mode,c.address,c.size,'local-array-extents',src,c.original)
   _,results=runner.run(ca);count+=1
   exact=next((r for r in results if r['outcome']=='exact'),None)
   if exact:
    out['exact'].append(dict(module=c.module,address=hex(c.address),name=c.name,mode=c.mode,size=c.size,variant=ca.variant,source=exact['source'],optimization=exact['optimization']));done.add(c.address);print('EXACT',c.tag,c.size,flush=True);break
  if count%100==0:print('Attempted',count,flush=True)
  atomic_json(ROOT/'build/local-array41.json',out)
 print('New exact',len(done),'attempts',count,flush=True)

if __name__=='__main__':main()
