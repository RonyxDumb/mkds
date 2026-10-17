"""Target the six remaining controller routines; accept no approximate matches."""
from batch_matching import *
import itertools
ctx=MatchingContext(ROOT,ROOT/'baseline')
def word(a):return int.from_bytes(ctx.original('arm9',a,4),'little')
PRE='''typedef struct State {unsigned char pad[0x60]; int cursor,previous,timer,phase,alpha; unsigned short value; unsigned char pad76[6]; int count,mode; short neighbors[4]; int transition; struct {int character;short cell,pad;} entries[12];} State;
extern State *data_02174e14;
#define state data_02174e14
#define system_mode (*(unsigned short *)0x27ffc40u)
extern short data_02153554[];
'''
items=[]
def add(a,s,pre=PRE):
 n,m,z=ctx.inventory['arm9',a];items.append(Candidate('arm9',n,m,a,z,'character-remaining',pre+s,ctx.original('arm9',a,z)))
for before,cast in itertools.product([False,True],[False,True]):
 gfx='unsigned char *gfx=(unsigned char *)s+0x38;'
 ptr=lambda k:'*(void **)(gfx+'+str(k)+')'
 call=lambda sel,k:'func_02124748('+sel+'->entries['+sel+'->cursor].cell,'+ptr(8)+','+('*(void **)((unsigned char *)s+0x38)' if cast else ptr(0))+','+ptr(12)+',0,'+str(k)+',*(int *)((unsigned char *)s+8),*(int *)((unsigned char *)s+12));'
 for first in ['s','state']:
  add(0x202721c,'void func_0202721c(void){State *s=state;'+(gfx if before else '')+'if(*(int *)((unsigned char *)s+296)==0){'+('' if before else gfx)+call(first,2)+call('state',1)+'}}',PRE+'extern void func_02124748(int,void*,void*,void*,int,int,int,int);\n')
for itime,ttime,loop in itertools.product(['before','after'],['before','after'],['for','do']):
 head='void func_020272ec(void){if(system_mode!=2){unsigned char *gfx=(unsigned char *)state+0x1c;int i;short *entry;'
 ini='i=0;';tab='entry=data_02153554;'
 body='*(int *)(*(unsigned char **)(gfx+24)+1536)=0;*(int *)(*(unsigned char **)(gfx+24)+1600)=1;'
 clear='*(unsigned short *)(*(unsigned char **)(gfx+24)+entry[1]*64+4)=0;*(unsigned short *)(*(unsigned char **)(gfx+24)+entry[1]*64+6)=0;entry+=4;'
 add(0x20272ec,head+(ini if itime=='before' else '')+(tab if ttime=='before' else '')+body+(ini if itime=='after' else '')+(tab if ttime=='after' else '')+('for(;i<12;i++){'+clear+'}' if loop=='for' else 'do{'+clear+'i++;}while(i<12);')+'}}')
for init,cond in itertools.product([False,True],['s','state']):
 body='void func_0202734c(int visible){State *s=state;unsigned char *gfx=(unsigned char *)s+0x1c;if(system_mode!=2){int i=0;short *entry;'+('entry=data_02153554;' if init else '')+'if('+cond+'->count>0){'+('' if init else 'entry=data_02153554;')+'do{'
 for dst,src in [(2,None),(1,2),(0,1)]:body+='*(int *)(*(unsigned char **)(gfx+24)+entry['+str(dst)+']*64)='+('visible' if src is None else '*(int *)(*(unsigned char **)(gfx+24)+entry['+str(src)+']*64)')+';'
 body+='entry+=4;i++;}while(i<state->count);}*(int *)(*(unsigned char **)(gfx+24)+1600)=visible;}}'
 add(0x202734c,body)
pre=PRE+'extern void G2x_SetBlendAlpha_(void*,int,int,int,int);extern void func_0202ba14(void);\n'
for vol,op,local in itertools.product(['','volatile '],['=25','|=1'],[False,True]):
 ptr=lambda a,t:f'(*({vol}{t} *){word(a):#x}u)'
 body='void func_02026058(void){int flags=24;G2x_SetBlendAlpha_((void*)'+hex(word(0x20260c4))+'u,0,63,6,10);'+('State *s=state;' if local else '')+'if('+('s' if local else 'state')+'->phase!=9||'+('s' if local else 'state')+'->transition!=2)flags'+op+';'
 for adr,v in [(0x20260cc,'flags<<8'),(0x20260d4,hex(word(0x20260d8))+'u')]:body+=ptr(adr,'unsigned int')+'=('+ptr(adr,'unsigned int')+'&'+hex(word(0x20260d0))+'u)|('+v+');'
 body+=ptr(0x20260dc,'unsigned short')+'=('+ptr(0x20260dc,'unsigned short')+'&~3)|1;if(*(int *)((unsigned char *)state+'+str(word(0x20260e0))+'))func_0202ba14();}'
 add(0x2026058,body,pre)
extra=[]
for ca in items:
 if ca.address not in [0x20272ec,0x202734c]:continue
 for typ,order,ctr in itertools.product(['unsigned char *','void *','struct Gfx *'],range(4),['int','unsigned int','short']):
  t=ca.source
  t=t.replace('unsigned char *gfx=',typ+'gfx=')
  if typ=='struct Gfx *':t=t.replace('*(unsigned char **)(gfx+24)','gfx->icons').replace('struct Gfx *gfx=(unsigned char *)','struct Gfx *gfx=(struct Gfx *)')
  else:t=t.replace('*(unsigned char **)(gfx+24)','*(unsigned char **)((unsigned char *)gfx+24)')
  if order==1:t=t.replace(typ+'gfx=',ctr+' i;'+typ+'gfx=').replace('int i;short *entry;','short *entry;').replace('int i=0;short *entry;','i=0;short *entry;')
  if order==2:t=t.replace('int i;short *entry;','short *entry;'+ctr+' i;').replace('int i=0;short *entry;','short *entry;'+ctr+' i=0;')
  if order==3:t=t.replace('int i;short *entry;',ctr+' i;short *entry;').replace('int i=0;short *entry;',ctr+' i=0;short *entry;').replace('entry+=4;i++;','i++;entry+=4;')
  if typ=='struct Gfx *':t='struct Gfx{unsigned char pad[24];unsigned char *icons;};\n'+t
  extra.append(Candidate(ca.module,ca.name,ca.mode,ca.address,ca.size,ca.variant,t,ca.original))
items+=extra
runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/remaining38b',['-O4,p','-O4,s','-O2','-O1','-O3'])
out={'exact':[],'attempts':[]};done=set()
for ca in items:
 if ca.address in done:continue
 _,rr=runner.run(ca)
 for v in rr:
  out['attempts'].append(dict(address=hex(ca.address),outcome=v['outcome'],diff=v.get('differing_bytes'),source=v.get('source'),key=v.get('key'),optimization=v.get('optimization')))
  if v['outcome']=='exact':
   done.add(ca.address);out['exact'].append(dict(module=ca.module,name=ca.name,mode=ca.mode,address=hex(ca.address),size=ca.size,variant=ca.variant,source=v['source'],optimization=v['optimization']));print('EXACT',hex(ca.address),ca.size,flush=True)
atomic_json(ROOT/'build/remaining38b.json',out)
for a in sorted(set(c.address for c in items)):
 rr=[x for x in out['attempts'] if int(x['address'],16)==a and x['diff'] is not None];print(hex(a),min((x['diff'] for x in rr),default=None),flush=True)
