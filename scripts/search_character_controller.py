"""Repair observed call-site omissions in the character controller; exact-only search."""
from batch_matching import *
ctx=MatchingContext(ROOT,ROOT/'baseline');pool=[]
for c in candidates(ctx,modules=['arm9']):
 if c.address!=0x2026120:continue
 s=c.source
 s=s.replace('_s32_div_f((10 - *(int *)(iVar4 + 0x68)) * 0x1000)', '_s32_div_f((10 - *(int *)(iVar4 + 0x68)) * 0x1000,10)')
 s=re.sub(r'undefined8 _s32_div_f\([^;]*\);','int _s32_div_f(int,int);',s)
 s=s.replace('void func_02025ebc(int param_1);','int func_02025ebc(int param_1);')
 s=s.replace('void func_02027424(void);','void func_02027424(int);')
 s=s.replace('func_02025ebc(*DAT_02026840 + 0xf8);\n  func_0202728c();','uVar7=func_02025ebc(*DAT_02026840 + 0xf8);\n  func_0202728c(uVar7);')
 # Literal variants rename the pointer slot, so preserve the call result
 # independently of the data expression when it is the preceding call.
 s=re.sub(r'(?<![=\w])func_02025ebc\(([^;]+)\);\s*func_0202728c\(\);',r'uVar7=func_02025ebc(\1);func_0202728c(uVar7);',s)
 pool.append(Candidate(c.module,c.name,c.mode,c.address,c.size,'observed-controller-calls',s,c.original))
runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/controller36',['-O4,p','-O4,s','-O2','-O1','-O3'])
out={'exact':[],'attempts':[]}
for c in pool:
 _,rr=runner.run(c)
 for v in rr:
  out['attempts'].append(dict(address=hex(c.address),variant=c.variant,outcome=v['outcome'],diff=v.get('differing_bytes'),diagnostic=v.get('diagnostic')))
  if v['outcome']=='exact':out['exact'].append(dict(module=c.module,name=c.name,mode=c.mode,address=hex(c.address),size=c.size,variant=c.variant,source=v['source'],optimization=v['optimization']));print('EXACT',hex(c.address),flush=True)
atomic_json(ROOT/'build/controller36.json',out)
print(out['attempts'])
