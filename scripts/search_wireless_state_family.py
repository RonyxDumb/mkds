"""Typed wireless state/list reconstructions; search results require fresh acceptance."""
from pathlib import Path
from batch_matching import MatchingContext, Candidate, Search, atomic_json

root = Path(__file__).resolve().parents[1]
ctx = MatchingContext(root, root / 'baseline')
runner = Search(ctx, root/'tools/mwccarm/1.2/sp2p3/mwccarm.exe', root/'tools/wibo',
                root/'build/wireless34', ['-O4,p','-O4,s','-O2','-O1','-O3','-O0'])
items = []
def literal(address):
    return int.from_bytes(ctx.original('arm9', address, 4), 'little')
def global_name(slot):
    return ctx.data_symbols['arm9'][literal(slot)]
def add(address, source):
    name, mode, size = ctx.inventory['arm9', address]
    items.append(Candidate('arm9', name, mode, address, size, 'typed-wireless-state', source,
                           ctx.original('arm9', address, size)))

g = global_name(0x20095f0)
for qualifier in ['', 'volatile ']:
    pre = 'typedef struct State{void *head;unsigned char *current,*payload;unsigned char state,pad,count,pad2,kind;} State;extern '+qualifier+'State '+g+';\n'
    add(0x20095c4, pre+'void func_020095c4(void){if('+g+'.state==2){unsigned char *p='+g+'.current;if(p['+str(literal(0x20095f4))+']==0){'+g+'.kind=9;'+g+'.payload=p;}else{'+g+'.kind=4;'+g+'.payload=p+'+str(literal(0x20095f8))+';}'+g+'.state=3;}}')
g = global_name(0x200971c)
offset = literal(0x2009720)
pre='typedef struct Node{unsigned char pad['+str(offset)+'];struct Node *next;} Node;extern Node *'+g+';\n'
for loop in ['Node *q=p->next;while(q){p=q;q=q->next;}', 'while(p->next)p=p->next;', 'Node *q;for(q=p->next;q;q=q->next)p=q;']:
    add(0x20096f4,pre+'void func_020096f4(Node *n){Node *p='+g+';if(!p)'+g+'=n;else{'+loop+'p->next=n;}n->next=0;}')
g=global_name(0x200bd30)
for qual in ['', 'volatile ']:
    pre='typedef struct State{unsigned char pad[26];unsigned short a,b,c,d;} State;extern '+qual+'State *'+g+';\n'
    for body in ['int result=0,ready=0;State *p='+g+';if(p->a==1 && p->d==0)ready=1;if(ready && p->b==0)result=1;return result;',
                 'int result=0;int ready=('+g+'->a==1 && '+g+'->d==0);if(ready && '+g+'->b==0)result=1;return result;']:
        add(0x200bd0c, pre+'int func_0200bd0c(void){'+body+'}')
g=global_name(0x20099bc)
pre='extern unsigned short *'+g+';\n'
for ret in ['unsigned char','unsigned int']:
    for expr in ['a|b|c|d','d|(c|(b|a))','(b|a)|c|d']:
        add(0x2009974,pre+ret+' func_02009974(void){unsigned short *p='+g+';unsigned int a=p[9]?2:0,b=p[7]?1:0,c=p[10]?4:0,d=p[11]?8:0;return (unsigned char)('+expr+');}')
g=global_name(0x2009640)
offset=literal(0x2009644)
pre='typedef struct Node{unsigned char pad['+str(offset)+'];struct Node *next;} Node;typedef struct State{Node *head,*current;void *payload;unsigned char state,pad,count;} State;extern State '+g+';extern void func_020096c0(void);\n'
for expr in ['if(p && p->next)n=p->next;', 'if(p){Node *q=p->next;if(q)n=q;}']:
    add(0x20095fc,pre+'int func_020095fc(void){Node *n='+g+'.head;if(!n)return 0;{Node *p='+g+'.current;'+expr+'}'+g+'.current=n;func_020096c0();'+g+'.count=((unsigned char *)'+g+'.current)['+str(literal(0x2009648))+'];'+g+'.state=2;return 1;}')
pre='extern void CopyMemory16(const void *,void *,unsigned int);\n'
for counter in ['unsigned char','signed char']:
    add(0x200973c,pre+'void func_0200973c(unsigned char *p,const void *data,unsigned int mask,unsigned short value){'+counter+' count=1;int i;CopyMemory16(data,p+'+str(literal(0x2009794))+','+str(literal(0x2009798))+');for(i=0;i<15;i++){if(mask & (2u<<i))count++;}p['+str(literal(0x200979c))+']=count;*(unsigned short *)(p+'+str(literal(0x20097a0))+')=mask|1;*(unsigned short *)(p+'+str(literal(0x20097a4))+')=value;p['+str(literal(0x20097a8))+']++;}')
pre='typedef struct File{unsigned int words[18];} File;extern void Fs_File_Initialize(File *);extern int Fs_File_Open(File *,const char *);extern int Fs_File_Close(File *);extern int Fs_File_Read(File *,void *,unsigned int);\n'
add(0x20097ac,pre+'int SomeFileRead_from_thumb(const char *path,unsigned char *data,int large){File f;unsigned int size=large?'+str(literal(0x2009824))+':32;if(large)data+=32;if(!path)return 0;Fs_File_Initialize(&f);if(!Fs_File_Open(&f,path))return 0;if(size!=f.words[10]-f.words[9]){Fs_File_Close(&f);return 0;}Fs_File_Read(&f,data,size);Fs_File_Close(&f);return 1;}')
g=global_name(0x2009950)
pre='typedef struct Context{unsigned char pad['+str(literal(0x2009954))+'];void (*callback)(int,void *);} Context;extern Context *'+g+';\n'
add(0x2009928,pre+'void func_02009928(unsigned short a,unsigned short b){unsigned short args[2];if(b!=2 && b!=0){args[0]=a;args[1]=b;'+g+'->callback(255,args);}}')
g=global_name(0x200b848)
pre='typedef struct Context{unsigned char pad['+str(literal(0x200b84c))+'];void (*callback)(int,void *);} Context;extern Context *'+g+';\n'
add(0x200b820,pre+'void func_0200b820(unsigned short a,unsigned short b){unsigned short args[2];if('+g+'->callback){args[0]=a;args[1]=b;'+g+'->callback(2,args);}}')
g=global_name(0x200bd08)
pre='typedef struct Context{void (*callback)(int,void *);} Context;extern Context *'+g+';\n'
for cond in ['p[2]!=7 && p[2]!=9 && p[2]==21','p[2]==21']:
    add(0x200bcd8,pre+'void func_0200bcd8(unsigned short *p){if(p[1]==0){if('+cond+'){if('+g+'->callback)'+g+'->callback(9,p);}}}')
add(0x200bd34,pre+'void func_0200bd34(unsigned short *p){if(p[1]){unsigned short a=p[0];if('+g+'->callback){unsigned short args[2];args[0]=a;args[1]=p[1];'+g+'->callback('+str(literal(0x200bd78))+',args);}}else{if('+g+'->callback)'+g+'->callback(15,0);}}')

out={'exact':[],'attempts':[]};done=set()
for ca in items:
    if ca.address in done:continue
    _,results=runner.run(ca)
    for v in results:
        out['attempts'].append(dict(address=hex(ca.address),outcome=v['outcome'],optimization=v.get('optimization'),differences=v.get('differing_bytes'),diagnostic=v.get('diagnostic')))
        if v['outcome']=='exact':
            out['exact'].append(dict(module=ca.module,name=ca.name,mode=ca.mode,address=hex(ca.address),size=ca.size,variant=ca.variant,source=v['source'],optimization=v['optimization']))
            done.add(ca.address);print('EXACT',hex(ca.address),ca.size,flush=True)
atomic_json(root/'build/wireless34.json',out)
print('Attempts',len(out['attempts']),flush=True)
