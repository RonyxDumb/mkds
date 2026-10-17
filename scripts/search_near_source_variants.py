"""Refine close C drafts through small type and local-alias hypotheses."""
from batch_matching import *

def main():
 ctx=MatchingContext(ROOT,ROOT/'baseline');runner=Search(ctx,ROOT/'tools/mwccarm/1.2/sp2p3/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/near-source41',['-O4,p','-O2','-O3','-O4,s']);out={'exact':[],'near_misses':[]};known=set()
 for fn in ['local-byte-exact.tsv','local-linked-byte-exact.tsv']:
  known.update((x['module'],int(x['address'],16)) for x in csv.DictReader((ROOT/'verification'/fn).open(),delimiter='\t'))
 for row in json.loads((ROOT/'build/target17-fuzzy-assessment.json').read_text())['candidates']:
  mod,a=row['module'],int(row['address'],16)
  if (mod,a) in known:continue
  n,m,z=ctx.inventory[mod,a];s=Path(row['source']).read_text();variants=[]
  for mt in re.finditer(r'\b(?:int|uint|short|ushort|undefined4|undefined2)\s+([iu]Var\d+)\s*;',s):
   for typ in ['int','uint','short','ushort']:
    variants.append(s[:mt.start()]+typ+' '+mt[1]+';'+s[mt.end():])
   # Explicit comparison promotions retain the loaded width.
   for cmp in re.finditer(r'\b'+mt[1]+r'\s*(?:<|>|<=|>=)',s[mt.end():]):
    p=mt.end()+cmp.start();variants.append(s[:p]+'(unsigned int)'+s[p:])
  for mt in re.finditer(r'\b([pu]iVar\d+)\s*=\s*(\(\(int \*\)0x[0-9a-f]+u\));',s):
   v=s[:mt.start()]+s[mt.end():];v=re.sub(r'\*'+mt[1]+r'\b','*'+mt[2],v);variants.append(v)
  for mt in re.finditer(r'\b([a-zA-Z_]\w*)\(([^,;]+),([0-9]+)\);\s*([iu]Var\d+)\s*=\s*\(extraout_r1 \+ -1\) \* 0x10000 >> 0x10;',s):
   variants.append(s[:mt.start()]+mt[4]+'=(short)(('+mt[2]+') % '+mt[3]+' - 1);'+s[mt.end():])
  for src in variants:
   ca=Candidate(mod,n,m,a,z,'near-source-types',src,ctx.original(mod,a,z));_,rs=runner.run(ca)
   ex=next((x for x in rs if x['outcome']=='exact'),None)
   if ex:
    out['exact'].append(dict(module=mod,address=hex(a),name=n,mode=m,size=z,variant=ca.variant,source=ex['source'],optimization=ex['optimization']));print('EXACT',ca.tag,z,flush=True);break
  atomic_json(ROOT/'build/near-source41.json',out)
 print('Exact',len(out['exact']),flush=True)

if __name__=='__main__':main()
