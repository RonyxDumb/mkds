"""Resolve the final source-level differences in character-controller C."""
from batch_matching import *
import itertools
ctx=MatchingContext(ROOT,ROOT/'baseline');a=0x2026120;n,m,z=ctx.inventory['arm9',a]
s=(ROOT/'scripts/inputs/character-select/controller-near.c').read_text()
runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/controller-finish38',['-O4,p'])
out={'exact':[],'attempts':[]}
for order,table,coords,init in itertools.product(itertools.permutations(['scan','hit','current','row']),['int','short *'],range(3),[False,True]):
 t=s.replace('int scan;int hit;int current;', ''.join((table if v=='row' else 'int')+' '+v+';' for v in order))
 start=t.index('      if (hit >= 0)');end=t.index('        func_020270fc(previous)',start);b=t[start:end].replace('offset','row')
 if table=='short *':b=b.replace('row = DAT_020264a8','row = (short *)DAT_020264a8').replace('*(short *)(row + 6)','row[3]').replace('row = row + 8','row = row + 4')
 if init:
  assignment='row = (short *)DAT_020264a8;' if table=='short *' else 'row = DAT_020264a8;'
  b=b.replace(assignment,'').replace('        if (0 <',assignment+'if (0 <')
 t=t[:start]+b+t[end:]
 if coords==1:
  t=t.replace('x = *(undefined2 *)((unsigned char *)DAT_020264a0 + offset);\n      y = *(undefined2 *)((unsigned char *)DAT_020264a4 + offset);','y = *(undefined2 *)((unsigned char *)DAT_020264a4 + offset);x = *(undefined2 *)((unsigned char *)DAT_020264a0 + offset);')
 if coords==2:t=t.replace('*(undefined2 *)((unsigned char *)DAT_020264a0','*(volatile unsigned short *)((unsigned char *)DAT_020264a0').replace('*(undefined2 *)((unsigned char *)DAT_020264a4','*(volatile unsigned short *)((unsigned char *)DAT_020264a4')
 c=Candidate('arm9',n,m,a,z,'controller-finish',t,ctx.original('arm9',a,z));_,rr=runner.run(c)
 for v in rr:
  out['attempts'].append(dict(address=hex(a),outcome=v['outcome'],diff=v.get('differing_bytes'),bytes=v.get('bytes'),source=v.get('source'),key=v.get('key'),optimization=v.get('optimization'),diagnostic=v.get('diagnostic')))
  if v['outcome']=='exact':out['exact'].append(dict(module=c.module,name=c.name,mode=c.mode,address=hex(a),size=z,variant=c.variant,source=v['source'],optimization=v['optimization']));print('EXACT',hex(a),flush=True)
 if out['exact']:break
atomic_json(ROOT/'build/controller-finish38.json',out)
print('attempts',len(out['attempts']),'best',min((r['diff'] for r in out['attempts'] if r['diff'] is not None),default=None))
