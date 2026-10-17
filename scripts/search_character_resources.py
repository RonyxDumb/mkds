"""Compile typed resource-loader reconstructions guided by REA graphics40 output."""
from batch_matching import *
import itertools

def main():
 ctx=MatchingContext(ROOT,ROOT/'baseline'); candidates=[]
 def name(a):return ctx.inventory['arm9',a][0]
 def word(a):return int.from_bytes(ctx.original('arm9',a,4),'little')
 def add(a,s):
  n,m,z=ctx.inventory['arm9',a];candidates.append(Candidate('arm9',n,m,a,z,'character-resources',s,ctx.original('arm9',a,z)))
 for a,loader in [(0x2025884,0x2025854),(0x2025904,0x20258d4)]:
  callees=[0x20b496c,0x20b4a7c,0x20b4810] if a==0x2025884 else [0x20b4934,0x20b4a44,0x20b47d8]
  for typ in ['int *','unsigned char *']:
   pre=''.join(f'extern void {name(x)}(void *,void *);\n' for x in callees)
   ptr=lambda idx: f'out+{idx}' if typ=='int *' else f'out+{idx}*4'
   add(a,pre+f'void {name(a)}({typ}out,int characters,int palette,int screen,int layer,void *(*load)(int)){{'+
       f'if(characters){name(callees[0])}({ptr("layer")},load(characters));'+
       f'if(palette){name(callees[1])}({ptr("4")},load(palette));'+
       f'if(screen){name(callees[2])}({ptr("5+layer")},load(screen));'+'}')
  pre=f'extern void {name(a)}(void *,int,int,int,int,void *(*)(int));\nextern void {name(0x2025954)}(int,void *,int);\n'
  add(loader,pre+f'void {name(loader)}(int sub,void *out,int characters,int palette,int screen,int layer,void *(*load)(int)){{{name(a)}(out,characters,palette,screen,layer,load);{name(0x2025954)}(sub,out,layer);}}')
 a=0x2025f90
 for layout in ['array','locals']:
  pre=f'extern void *{name(0x2047a28)}(const void *);\n'+''.join(f'extern void {name(x)}(void *,void *);\n' for x in [0x20b49f4,0x20b48ec,0x20b4a7c])
  body='int data[3]={0,0,0};' if layout=='array' else 'int chars=0,palette=0,cells=0;'
  for i,k in enumerate([0,2,1,0,2,1,0,2,0,2]):
   ptr=f'&data[{k}]' if layout=='array' else '&'+['chars','palette','cells'][k]
   body+=f'{name([0x20b49f4,0x20b4a7c,0x20b48ec][k])}({ptr},{name(0x2047a28)}((const void *){word(0x2026030+i*4):#x}u));'
  add(a,pre+f'void {name(a)}(void){{'+body+'}')
 a=0x2025a00
 for typ in ['int *','unsigned char *']:
  pre=f'extern int {name(0x21243ac)}(int,int,int,int,int,int,int,int,int,int);\nextern void {name(0x21241c0)}(int,int,int,int,int);\n'
  at=lambda i:f'graphics[{i}]' if typ=='int *' else f'*(int *)(graphics+{i*4})'
  add(a,pre+f'int {name(a)}(int sub,int heap,{typ}graphics,short *entry,int extra){{int result={name(0x21243ac)}(heap,entry[0],{at(5)},(unsigned short)entry[1],(unsigned short)entry[2],entry[3],{at(2)},{at(3)},{at(6)},extra);{name(0x21241c0)}(sub,entry[0],{at(5)},{at(3)},{at(6)});return result;}}')
 a=0x2025954
 for typ,init in itertools.product(['int *','unsigned char *'],['','=0']):
  at=lambda i:f'graphics[{i}]' if typ=='int *' else f'*(int *)(graphics+({i})*4)'
  pre=f'extern void {name(0x2016468)}(int,int,int,int);\n'
  body=f'int screen,charReserve{init},mapReserve{init};if(sub==0){{screen=15;switch(layer){{'+''.join(f'case {i}:charReserve={4+i};mapReserve={8+i};break;' for i in range(4))+'}}else{screen=31;switch(layer){'+''.join(f'case {i}:charReserve={20+i};mapReserve={24+i};break;' for i in range(4))+'}}'
  body+=f'{name(0x2016468)}(charReserve,0,((int *){at("layer")})[5],((int *){at("layer")})[4]);'
  body+=f'{name(0x2016468)}(screen,0,((int *){at("4")})[3],{word(0x20259fc)});'
  body+=f'{name(0x2016468)}(mapReserve,0,{at("5+layer")}+12,((int *){at("5+layer")})[2]);'
  add(a,pre+f'void {name(a)}(int sub,{typ}graphics,int layer){{'+body+'}')
 # Preserve the original first-argument register for unspecified layer values.
 for c in list(candidates):
  if c.address==0x2025954:
   src=c.source.replace('int screen,charReserve,mapReserve;', 'int screen,mapReserve;').replace('charReserve','sub')
   if src!=c.source:
    add(c.address,src)
    add(c.address,src.replace('graphics+(5+layer)*4','graphics+layer*4+20').replace('graphics[5+layer]','*(int *)((char *)graphics+layer*4+20)'))
 for c in list(candidates):
  if c.address==0x2025954 and 'graphics+layer*4+20' in c.source:
   for expr in ['(graphics+20)+layer*4','(unsigned char *)((int *)graphics+layer)+20','graphics+(unsigned int)layer*4+20','graphics+(layer<<2)+20']:
    add(c.address,c.source.replace('graphics+layer*4+20',expr))
 runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/character-resources40',['-O4,p','-O4,s','-O2','-O1','-O3'])
 summary={'exact':[],'near_misses':[]};done=set()
 for c in candidates:
  if c.address in done:continue
  _,results=runner.run(c)
  for r in results:
   if r['outcome']=='exact':
    summary['exact'].append(dict(module=c.module,name=c.name,mode=c.mode,address=hex(c.address),size=c.size,variant=c.variant,source=r['source'],optimization=r['optimization']));done.add(c.address);print('EXACT',hex(c.address),c.size,flush=True);break
  else:
   valid=[r for r in results if r['outcome']=='mismatch']
   if valid:
    r=min(valid,key=lambda x:x['differing_bytes']);summary['near_misses'].append(dict(address=hex(c.address),differing_bytes=r['differing_bytes'],source=r['source'],optimization=r['optimization']))
 atomic_json(ROOT/'build/character-resources40.json',summary)
 print('Exact resources:',len(done),flush=True)

if __name__=='__main__':main()
