"""Reconstruct only character-selection functions, with fixed subsystem scope."""
from pathlib import Path
from batch_matching import Candidate, MatchingContext, Search, atomic_json, candidates

ROOT=Path(__file__).resolve().parents[1]
ctx=MatchingContext(ROOT,ROOT/'baseline')
runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/character-select',
              ['-O4,p','-O4,s','-O2','-O1','-O3'])
def word(a):return int.from_bytes(ctx.original('arm9',a,4),'little')
state_slot=word(0x2027614)
PRE='''typedef struct CharacterSelectState {
 unsigned char reserved00[0x60];
 int cursor, previous_cursor, timer, phase, alpha;
 unsigned short render_value;
 unsigned char reserved76[6];
 int character_count, mode;
 short neighbors[4];
 unsigned char reserved8c[4];
 struct {int character;short cell,unused;} entries[12];
 int current_character,current_value;
} CharacterSelectState;
'''+f'#define state (*(CharacterSelectState **){state_slot:#x}u)\n'
items=[]
def add(a,body,pre=PRE):
    name,mode,size=ctx.inventory['arm9',a]
    items.append(Candidate('arm9',name,mode,a,size,'character-select-typed',pre+body,ctx.original('arm9',a,size)))

# Layout variants dispatched for 12, 11, 10, 9 and 8 visible characters.
# Each table row contains four halfwords. Keep individual loads/stores in order.
specs=[(0x2027448,0x2027618,12,{}),
       (0x2027648,0x2027820,11,{5:('state->previous_cursor!=2 && state->previous_cursor!=9',6,5)}),
       (0x2027850,0x2027a28,10,{1:('state->previous_cursor!=5',2,1),8:('state->previous_cursor!=5',10,9)}),
       (0x2027a58,0x2027bbc,9,{}),
       (0x2027be0,0x2027dc8,8,{1:('state->previous_cursor!=4',2,1),3:('state->previous_cursor!=1 && state->previous_cursor!=6',5,4),4:('state->previous_cursor!=2 && state->previous_cursor!=7',7,6),6:('state->previous_cursor!=4',10,9)})]
for a,table,count,special in specs:
    symbols={row:ctx.data_symbols['arm9'][word(table+row*4)] for row in range(max(count,12)) if row*4+table<a+ctx.inventory['arm9',a][2]}
    declarations=''.join('extern const unsigned short '+n+'[4];\n' for n in sorted(set(symbols.values())))
    rows=[];nextrow=0
    for i in range(count):
        if i in special:
            condition,yes,no=special[i];rows.append((i,condition,yes,no));nextrow=max(yes,no)+1
        else:rows.append((i,None,nextrow,nextrow));nextrow+=1
    for use_local,shared_case,invert_mask in [(True,None,k) for k in range(1<<len(special))]+[(False,None,0),(True,{0x2027648:5,0x2027850:1,0x2027be0:3}.get(a),0)]:
        def copy(row):
            ptr=symbols[row]
            target='s' if use_local else 'state'
            return ''.join(f'{target}->neighbors[{j}]={ptr}[{j}];' for j in range(4))
        body=f'void func_{a:08x}(void){{'+('CharacterSelectState *s=state;' if use_local else '')+'switch('+('s' if use_local else 'state')+'->cursor){'
        for i,cond,yes,no in rows:
            body+=f'case {i}:'
            if i in special and invert_mask&(1<<list(special).index(i)):
                cond=cond.replace('!=','==').replace(' && ',' || ')
                yes,no=no,yes
            if i==shared_case:
                body+='break;'
                continue
            if cond:body+='if('+cond.replace('state->','s->' if use_local else 'state->')+'){'+copy(yes)+'return;}'+copy(no)+'return;'
            else:body+=copy(yes)+'return;'
        body+='default:return;}'
        if shared_case is not None:
            _,cond,yes,no=next(row for row in rows if row[0]==shared_case)
            body+='if('+cond.replace('state->','s->' if use_local else 'state->')+'){'+copy(yes)+'return;}'+copy(no)+'return;'
        add(a,body+'}',PRE+declarations)

pre=''.join('extern void func_'+x+'(void);\n' for x in ['02027be0','02027a58','02027850','02027648','02027448','02027188','0202721c'])
pre+='extern void func_02025f54(void *,int);extern int func_02025e60(int);\n'
for local in [False,True]:
    body='void func_020270fc(int previous_cursor){state->previous_cursor=previous_cursor;switch(state->character_count){'
    for n,fn in [(8,'02027be0'),(9,'02027a58'),(10,'02027850'),(11,'02027648'),(12,'02027448')]:body+=f'case {n}:func_{fn}();break;'
    body+='}func_02027188();func_0202721c();func_02025f54((unsigned char *)state+0xf8,0);'
    if local:body+='CharacterSelectState *s=state;s->current_character=s->entries[s->cursor].character;'
    else:body+='state->current_character=state->entries[state->cursor].character;'
    body+='state->current_value=func_02025e60(state->current_character);}'
    add(0x20270fc,body,PRE+pre)
    for initial_slot in [True,False]:
        initial=('CharacterSelectState **slot=(CharacterSelectState **)'+hex(state_slot)+'u;(*slot)->previous_cursor=previous_cursor;switch((*slot)->character_count){' if initial_slot else 'state->previous_cursor=previous_cursor;switch(state->character_count){')
        tail='CharacterSelectState **slot2=(CharacterSelectState **)'+hex(state_slot)+'u;CharacterSelectState *s=*slot2;s->current_character=s->entries[s->cursor].character;'
        variant='void func_020270fc(int previous_cursor){'+initial
        for n,fn in [(8,'02027be0'),(9,'02027a58'),(10,'02027850'),(11,'02027648'),(12,'02027448')]:variant+=f'case {n}:func_{fn}();break;'
        variant+='}func_02027188();func_0202721c();func_02025f54((unsigned char *)state+0xf8,0);'+tail+'state->current_value=func_02025e60(state->current_character);}'
        add(0x20270fc,variant,PRE+pre)

pre='#define system_mode (*(unsigned short *)'+hex(word(0x2026118))+'u)\nextern void *GetGlobalCA_from_thumb(void);extern void func_0211f498(void);extern void Mem_DestroyHeap(int);\n'
add(0x20260e4,'void func_020260e4(void){if('+'system_mode'+'==2){if(*(int *)((unsigned char *)GetGlobalCA_from_thumb()+200)==2)func_0211f498();}Mem_DestroyHeap(*(int *)((unsigned char *)state+0x5c));state=0;}',PRE+pre)
pre='extern void func_0202b7c0(int);\n'
add(0x2027424,'void func_02027424(int value){if(*(int *)((unsigned char *)state+'+str(word(0x2027444))+'))func_0202b7c0(value);}',PRE+pre)
pre='#define system_mode (*(unsigned short *)'+hex(word(0x20272e0))+'u)\n'
add(0x20272c0,'void func_020272c0(unsigned short a,unsigned short b){if('+'system_mode'+'!=2){CharacterSelectState *s=state;if(*(int *)((unsigned char *)s+'+str(word(0x20272e8))+')==0){unsigned char *p=*(unsigned char **)((unsigned char *)s+0x18);*(unsigned short *)(p+6)=a;*(unsigned short *)(p+0xc6)=b;}}}',PRE+pre)
add(0x20272c0,'void func_020272c0(unsigned short a,unsigned short b){if(system_mode!=2){CharacterSelectState *s=state;if(*(int *)((unsigned char *)s+'+str(word(0x20272e8))+')==0){*(unsigned short *)(*(unsigned char **)((unsigned char *)s+0x18)+6)=a;*(unsigned short *)(*(unsigned char **)((unsigned char *)s+0x18)+0xc6)=b;}}}',PRE+pre)

def data_array(slot,typ):
    name=ctx.data_symbols['arm9'][word(slot)]
    return name,'extern '+typ+' '+name+'[];\n'

table,decl=data_array(0x20271dc,'short')
for direct in [True,False]:
    prefix='CharacterSelectState *s=state;short *entry='+table+'+s->cursor*4;'
    sprite='(*(unsigned char **)((unsigned char *)s+0x34))'
    body='void func_0202719c(void){'+prefix
    body+='*(int *)('+sprite+'+'+str(word(0x20271e0))+')=1;*(int *)('+sprite+'+'+str(word(0x20271e4))+')=0;'
    if direct:body+='*(unsigned short *)('+sprite+'+entry[1]*64+4)=1;*(unsigned short *)('+sprite+'+entry[1]*64+6)=1;'
    else:body+='unsigned char *icon='+sprite+'+entry[1]*64;*(unsigned short *)(icon+4)=1;*(unsigned short *)(icon+6)=1;'
    add(0x202719c,body+'}',PRE+decl)
table,decl=data_array(0x2027218,'short')
pre=decl+'extern void func_02025c6c(int,int,void *);\n'
add(0x20271e8,'void func_020271e8(void){CharacterSelectState *s=state;int off=s->cursor*4;func_02025c6c(24,'+table+'[off],*(void **)((unsigned char *)s+0x28));func_02025c6c(25,'+table+'[off],*(void **)((unsigned char *)s+0x28));}',PRE+pre)
table,decl=data_array(0x2027348,'short')
pre='#define system_mode (*(unsigned short *)'+hex(word(0x2027338))+'u)\n'+decl
add(0x20272ec,'void func_020272ec(void){if(system_mode!=2){CharacterSelectState *s=state;int i;short *entry='+table+';*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+'+str(word(0x2027340))+')=0;*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+'+str(word(0x2027344))+')=1;for(i=0;i<12;i++){*(unsigned short *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[1]*64+4)=0;*(unsigned short *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[1]*64+6)=0;entry+=4;}}}',PRE+pre)
table,decl=data_array(0x20273b8,'short')
pre='#define system_mode (*(unsigned short *)'+hex(word(0x20273b4))+'u)\n'+decl
add(0x202734c,'void func_0202734c(int visible){CharacterSelectState *s=state;if(system_mode!=2){int i;short *entry='+table+';for(i=0;i<s->character_count;i++){*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[2]*64)=visible;*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[1]*64)=*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[2]*64);*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[0]*64)=*(int *)(*(unsigned char **)((unsigned char *)s+0x34)+entry[1]*64);entry+=4;}}}',PRE+pre)

for ca in list(items):
    if True:
        named=ca.source.replace('#define state (*(CharacterSelectState **)0x2174e14u)', 'extern CharacterSelectState *data_02174e14;\n#define state data_02174e14')
        items.append(Candidate(ca.module,ca.name,ca.mode,ca.address,ca.size,ca.variant,named,ca.original))
items.extend(c for c in candidates(ctx,modules=['arm9']) if 0x02025f90<=c.address<0x02027df8)
out={'exact':[],'attempts':[]};done=set()
for ca in items:
    if ca.address in done:continue
    _,results=runner.run(ca)
    for v in results:
        out['attempts'].append(dict(address=hex(ca.address),outcome=v['outcome'],optimization=v.get('optimization'),differences=v.get('differing_bytes'),diagnostic=v.get('diagnostic')))
        if v['outcome']=='exact':
            out['exact'].append(dict(module=ca.module,name=ca.name,mode=ca.mode,address=hex(ca.address),size=ca.size,variant=ca.variant,source=v['source'],optimization=v['optimization']))
            done.add(ca.address);print('EXACT',hex(ca.address),ca.size,flush=True)
atomic_json(ROOT/'build/character-select.json',out)
print('Attempts',len(out['attempts']),flush=True)
