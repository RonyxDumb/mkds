"""Reconstruct Thumb command/list candidates; acceptance requires a separate audit."""
import sys,os,json
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent))
from batch_matching import MatchingContext,Candidate,Search,atomic_json
r=Path(__file__).resolve().parents[1];c=MatchingContext(r,r/'baseline');runner=Search(c,r/'tools/mwccarm/1.2/sp2p3/mwccarm.exe',r/'tools/wibo',r/'build/family32',['-O4,p','-O4,s','-O2','-O1','-O3','-O0'])
items=[]
def add(a,pre,body):
 n,mode,s=c.inventory['arm9',a];items.append(Candidate('arm9',n,mode,a,s,'typed-thumb-family',pre+'\n'+body,c.original('arm9',a,s)))
add(0x2006914,'extern void func_02006b50(void *,int);','void func_02006914(void *p,int n){if(n>0 && p)func_02006b50(p,n);}')
add(0x2006954,'extern unsigned short func_02006c2c(void *,int);','unsigned short func_02006954(void *p,int n){unsigned short v=0;if(n>0 && p)v=func_02006c2c(p,n);return v;}')
add(0x20068f4,'extern void func_02006bec(void *,int);','void func_020068f4(void *p,int n){if(p && n && n!=-1)func_02006bec(p,n);}')
for typ in ['unsigned int','unsigned short']:
 add(0x20088dc,'',f'{typ} func_020088dc(unsigned short *p,int n){{unsigned int s=0;for(n=n>>1;n>0;n--)s+=*p++;s=(s>>16)+(s&65535);return (s+(s>>16))^65535;}}')
for loop in ['while(p){if(p->id==id)return p;p=p->next;}return 0;','for(;p;p=p->next)if(p->id==id)break;return p;']:
 add(0x2007014,'typedef struct Node{int id; char pad[36];struct Node *next;} Node;extern Node *GetGlobalGO_from_thumb(void);','Node *FindGlobalGOBy_from_thumb(int id){Node *p=GetGlobalGO_from_thumb();'+loop+'}')
for expr in ['if((p[0x4b]&2) && *(unsigned short *)(p+0x40)==1)return 1;return 0;','return (p[0x4b]&2)!=0 && *(unsigned short *)(p+0x40)==1;']:
 add(0x20091fc,'','int func_020091fc(unsigned char *p){'+expr+'}')
add(0x2006954,'extern unsigned int func_02006c2c(void *,int);','unsigned short func_02006954(void *p,int n){unsigned short v=0;if(n>0 && p)v=(unsigned short)func_02006c2c(p,n);return v;}')
add(0x20068f4,'extern void func_02006bec(void *,unsigned int);','void func_020068f4(void *p,unsigned int n){if(p && n && n!=65535)func_02006bec(p,n);}')
for expr in ['if(!(p[0x4b]&2))return 0;switch(*(unsigned short *)(p+0x40)){case 1:return 1;default:return 0;}', 'if(!(p[0x4b]&2))return 0;if(*(unsigned short *)(p+0x40)!=1)return 0;return 1;']:
 add(0x20091fc,'','int func_020091fc(unsigned char *p){'+expr+'}')
for ntyp in ['short','int']:
 for loop in ['while(n>0){s+=*p++;n--;}','for(;n>0;n--){s+=*p;p++;}']:
  add(0x20088dc,'','unsigned short func_020088dc(unsigned short *p,'+ntyp+' len){int n=len>>1;unsigned int s=0;'+loop+'s=(s>>16)+(s&65535);return (s+(s>>16))^65535;}')
pre='typedef struct Cmd{unsigned int op,pad;unsigned short id,pad2;unsigned int pad3,arg,x,y;unsigned char payload[132];} Cmd; extern void func_0200704c(Cmd *); extern void Mem_CpuCopy32(const void *,void *,unsigned int);extern void Mem_CpuCopy8(const void *,void *,unsigned int);'
for size in [156,160]:
 add(0x2006ddc,'extern void func_0200704c(void *);','void func_02006ddc(unsigned short id,unsigned int arg){unsigned char cmd['+str(size)+'];*(unsigned int *)cmd=2;*(unsigned short *)(cmd+8)=id;*(unsigned int *)(cmd+16)=arg;func_0200704c(cmd);}')
add(0x2006db0,pre,'void func_02006db0(unsigned short id,unsigned int x,const void *payload,unsigned int arg){Cmd c;c.op=6;c.id=id;c.arg=arg;c.x=x;c.y=40;Mem_CpuCopy32(payload,c.payload,64);func_0200704c(&c);}')
add(0x2006d78,pre,'void func_02006d78(unsigned short id,unsigned int x,const void *p,unsigned int y,const void *q,unsigned int arg){Cmd c;c.op=4;c.id=id;c.arg=arg;c.x=x;c.y=y;Mem_CpuCopy32(p,c.payload,64);Mem_CpuCopy32(q,c.payload+64,64);func_0200704c(&c);}')
node='typedef struct Node{int id;char pad[36];struct Node *next;} Node;extern Node *GetGlobalGO_from_thumb(void);extern void SetGlobalGO_from_thumb(Node *);extern unsigned int Os_DisableIrq(void);extern void Os_RestoreIrq(unsigned int);'
add(0x2006df8,node,'Node *func_02006df8(int id){unsigned int irq=Os_DisableIrq();Node *p=GetGlobalGO_from_thumb(),*q;if(!p){Os_RestoreIrq(irq);return 0;}if(p->id==id){SetGlobalGO_from_thumb(p->next);Os_RestoreIrq(irq);return p;}q=p->next;while(q){if(q->id==id){p->next=q->next;Os_RestoreIrq(irq);return q;}p=q;q=q->next;}Os_RestoreIrq(irq);return 0;}')
add(0x2006ef8,node,'int func_02006ef8(void){int n=0;Node *p=GetGlobalGO_from_thumb();while(p){n++;p=p->next;}return n;}')
add(0x2006c0c,'extern void *func_020070b8(void);extern int func_02005dac(void *,void *,int,int);','int func_02006c0c(void *p,int a,int n){if(n>0)return func_02005dac(func_020070b8(),p,a,n);return (int)p;}')
add(0x2006f14,'extern int *func_020070b8(void);extern void func_020070c0(int);extern void func_020070cc(int);','int func_02006f14(int x,int y){int *p=func_020070b8();if(*p==4 || *p==6)return 0;func_020070c0(x-14);func_020070cc(y-14);return 1;}')
for ret in ['void','int']:
 body=('return;' if ret=='void' else 'return 0;')
 final=('func_0200704c(cmd);' if ret=='void' else 'return func_0200704c(cmd);')
 add(0x2006d3c,'extern '+ret+' func_0200704c(void *);extern void Mem_CpuCopy8(const void *,void *,unsigned int);',ret+' func_02006d3c(unsigned short id,const void *p,int n,unsigned int arg){unsigned char cmd[156];if(n<0 || n>9){'+body+'}*(unsigned int *)cmd=10;*(unsigned short *)(cmd+8)=id;*(unsigned int *)(cmd+16)=arg;Mem_CpuCopy8(p,cmd+20,n);cmd[29]=n;'+final+'}')
glob=int.from_bytes(c.original('arm9',0x2006d34,4),'little'); fallback=int.from_bytes(c.original('arm9',0x2006d38,4),'little')
gsym=c.data_symbols['arm9'].get(glob)
print('slot',hex(glob),gsym)
if gsym:
 pre='extern int '+gsym+';extern void *func_020070b8(void);'
 for fn in ['02005cc8','02005d4c','02005b80','02005d08','02005bec','02005b18']:
  pre+='extern unsigned int func_'+fn+'(void *,int,void *,int);'
 for fn in ['02005a30','0200589c']:
  pre+='extern unsigned int func_'+fn+'(void *,void *,int);'
 pre+='extern unsigned int func_020068b4(void *,unsigned int,int);'
 body='unsigned int func_02006c2c(void *p,int n){void *ctx=func_020070b8();int slot='+gsym+';unsigned int v;for(;;){slot++;if(slot>15)slot=1;'
 for fn in ['02005cc8','02005d4c','02005b80','02005d08']:
  body+='v=func_'+fn+'(ctx,slot,p,n);if(v){'+gsym+'=slot;return v;}'
 body+='if(slot=='+gsym+')break;}v=func_02005a30(ctx,p,n);if(v)return v;v=func_0200589c(ctx,p,n);if(v)return v;slot='+gsym+';do{slot++;if(slot>15)slot=1;v=func_02005bec(ctx,slot,p,n);if(v){'+gsym+'=slot;return v;}}while(slot!='+gsym+');for(slot=1;slot<16;slot++){v=func_02005b18(ctx,slot,p,n);if(v)return v;}return func_020068b4(p,'+str(fallback)+'u,0);}'
 add(0x2006c2c,pre,body)
out={'exact':[],'attempts':[]};done=set()
for ca in items:
 if ca.address in done:continue
 _,results=runner.run(ca)
 for v in results:
  out['attempts'].append({'address':hex(ca.address),'outcome':v['outcome'],'optimization':v.get('optimization'),'differences':v.get('differing_bytes'),'diagnostic':v.get('diagnostic')})
  if v['outcome']=='exact':
   out['exact'].append(dict(module=ca.module,name=ca.name,mode=ca.mode,address=hex(ca.address),size=ca.size,variant=ca.variant,source=v['source'],optimization=v['optimization']));done.add(ca.address);print('EXACT',hex(ca.address),ca.size,flush=True)
atomic_json(r/'build/family32.json',out)
print('attempts',len(out['attempts']))
