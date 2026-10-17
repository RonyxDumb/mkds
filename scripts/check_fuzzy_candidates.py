"""Recompile parked C drafts and compare all resolved bytes without accepting proofs."""
from batch_matching import *
import argparse

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--report',type=Path,default=ROOT/'build/fuzzy-candidates-recheck.json');args=p.parse_args()
 ctx=MatchingContext(ROOT,ROOT/'baseline');config=json.loads((ROOT/'verification/fuzzy-candidates.json').read_text());results=[]
 known=set()
 for name in ['local-byte-exact.tsv','local-linked-byte-exact.tsv']:
  known.update((r['module'],int(r['address'],16)) for r in csv.DictReader((ROOT/'verification'/name).open(),delimiter='\t'))
 for row in config['candidates']:
  mod,a=row['module'],int(row['address'],16)
  if (mod,a) in known:raise ValueError('Already exact: remove stale fuzzy entry')
  n,m,z=ctx.inventory[mod,a];source=(ROOT/row['source']).read_text();original=ctx.original(mod,a,z)
  assert digest(source.encode())==row['source_sha256'] and digest(original)==row['reference_sha256']
  compiler=ROOT/row['compiler'];assert digest(compiler.read_bytes())==row['compiler_sha256']
  runner=Search(ctx,compiler,ROOT/'tools/wibo',ROOT/'build/fuzzy-recheck',[row['optimization']])
  c=Candidate(mod,n,m,a,z,'parked-fuzzy',source,original);v=runner.compile(c,row['optimization'],use_cache=False)
  if v['outcome']!='mismatch' or v['bytes']!=z or v['differing_bytes']!=row['differing_bytes']:raise ValueError('Fuzzy comparison changed: '+c.tag)
  results.append(dict(module=mod,address=hex(a),bytes=z,differing_bytes=v['differing_bytes'],equal_byte_percent=100*(z-v['differing_bytes'])/z,exact=False))
 out=dict(candidates=results,tested=len(results),passed=len(results),matching_claim=False,semantic_equivalence_verified=False,full_rom_link_verified=False)
 atomic_json(args.report,out);print(json.dumps(dict(tested=len(results),passed=len(results),matching_claim=False)))

if __name__=='__main__':main()
