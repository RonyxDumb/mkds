"""Freshly compare the unaccepted initializer candidate; never register it implicitly."""
from batch_matching import *
ctx=MatchingContext(ROOT,ROOT/'baseline');a=0x2026910;n,m,z=ctx.inventory['arm9',a]
s=(ROOT/'scripts/inputs/character-select/initializer-candidate.c').read_text()
c=Candidate('arm9',n,m,a,z,'unaccepted-initializer',s,ctx.original('arm9',a,z))
r=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/initializer-residual38',['-O4,p'])
v=r.compile(c,'-O4,p',use_cache=False)
if v['outcome'] not in ['mismatch','exact']:raise RuntimeError(v.get('diagnostic',v['outcome']))
code,relocs=ctx.linked(Path(v['object']).read_bytes(),'arm9',n,a)
diffs=[hex(a+i) for i in range(min(len(code),len(c.original))) if code[i]!=c.original[i]]
print(json.dumps(dict(outcome=v['outcome'],compiled_bytes=len(code),reference_bytes=len(c.original),differing_bytes=v['differing_bytes'],addresses=diffs,source_sha256=digest(s.encode()),compiler_sha256=digest(r.compiler.read_bytes()),registered=False),indent=2))
