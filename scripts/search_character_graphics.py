"""Search typed reconstructions of graphics helpers called by character selection."""
from batch_matching import *
import itertools


def main():
    context = MatchingContext(ROOT, ROOT / 'baseline')
    candidates = []
    def add(address, source):
        name, mode, size = context.inventory['arm9', address]
        candidates.append(Candidate('arm9', name, mode, address, size,
                                    'character-graphics', source,
                                    context.original('arm9', address, size)))
    def word(address):
        return int.from_bytes(context.original('arm9', address, 4), 'little')
    for address, callee in [(0x2025bb4, 'func_0201eb54'), (0x2025c94, 'func_0201ea30')]:
        for argument, pointer in itertools.product(['int', 'unsigned int', 'short', 'unsigned short'], ['short', 'unsigned short']):
            add(address, f'''extern {pointer} *{callee}(void *,int);
void func_{address:08x}(int id,{argument} x,{argument} y,void *graphics){{
    {pointer} *entry={callee}(graphics,id);
    entry[0]=(entry[0]&0xfffff000U)|(x&0xfff);
    entry[1]=(entry[1]&0xfffff000U)|(y&0xfff);
}}
''')
    for layout in ['array', 'struct']:
        pre = 'typedef struct Portrait {void *characters,*palette,*cells,*layout;} Portrait;\n' if layout == 'struct' else ''
        fields = ['out->characters','out->cells','out->palette','out->layout'] if layout=='struct' else ['out[0]','out[2]','out[1]','out[3]']
        functions = ['GetPortraitNceNcgr_from_thumb','GetPortraitNceNcer_from_thumb','GetPortraitPalette_from_thumb','GetPortraitBNCL_from_thumb']
        pre += ''.join(f'extern void *{name}(int);\n' for name in functions)
        add(0x2025b84, pre + 'void LoadPlayerGfxData_from_thumb(int player,' + ('Portrait *' if layout=='struct' else 'void **') + 'out){' + ''.join(f'{field}={fn}(player);' for field,fn in zip(fields,functions)) + '}')
    for typ in ['int *','unsigned char *']:
        source='''extern void Gfx_ReadCharGraphicsRelative(void *,void *);
extern void func_020b48b4(void *,void *);
extern void Gfx_ReadPaletteRelative(void *,void *);
void func_02025b20(TYPE out,int characters,int cells,int palette,int layout,int animation,int extra,void *(*load)(int)){
if(characters)Gfx_ReadCharGraphicsRelative(out,load(characters));
if(cells)func_020b48b4((char *)out+8,load(cells));
if(palette)Gfx_ReadPaletteRelative((char *)out+4,load(palette));
if(layout)*(void **)((char *)out+12)=load(layout);
if(animation)*(void **)((char *)out+20)=load(animation);
if(extra)*(void **)((char *)out+16)=load(extra);
}'''.replace('TYPE',typ)
        add(0x2025b20,source)
    for signed in ['int','unsigned int']:
        add(0x2025e60,f'''extern int GetGlobalCA_from_thumb(void);
int func_02025e60(int character){{int result=-1;{signed} mode=*({signed} *)(GetGlobalCA_from_thumb()+200);
switch(mode){{case 0:case 1:case 3:case 5:result=((int *){word(0x2025ea8):#x}u)[character];break;
case 2:result=((int *){word(0x2025eac):#x}u)[character];break;}}return result;}}''')
    for coordinate in ['int','unsigned int','unsigned short']:
        add(0x2025f80,"""typedef struct Transition {int a,b,value;short x,y;} Transition;
extern void func_02025f14(Transition *,int);
void func_02025f80(Transition *transition,int mode,int value,COORD x,COORD y){
transition->value=value;transition->x=x;transition->y=y;func_02025f14(transition,mode);}
""".replace('COORD',coordinate))
    first,second=word(0x2025ea8),word(0x2025eac)
    for expression in ['table[character]','*(table+character)','*(int *)((char *)table+character*4)']:
        add(0x2025e60,f"""extern int GetGlobalCA_from_thumb(void);
extern int data_{first:08x}[],data_{second:08x}[];
int func_02025e60(int character){{int result=-1;int mode=*(int *)(GetGlobalCA_from_thumb()+200);
switch(mode){{case 0:case 1:case 3:case 5:{{int *table=data_{first:08x};result={expression};}}break;
case 2:{{int *table=data_{second:08x};result={expression};}}break;}}return result;}}
""")
    add(0x2025a50,f'''extern void func_02124ed0(int,int,int,int *);
extern void AllocateReserveTEQSub(int,int,int,int);
void func_02025a50(int sub,int heap,int *graphics){{int reserve;
func_02124ed0(heap,graphics[3],graphics[5],graphics+6);
if(sub==0){{reserve=19;AllocateReserveTEQSub(14,0,((int *)graphics[1])[3],{word(0x2025ab4)});
AllocateReserveTEQSub(14,{word(0x2025ab8)},((int *)graphics[1])[3]+{word(0x2025ab8)},64);}}
else{{reserve=35;AllocateReserveTEQSub(30,0,((int *)graphics[1])[3],((int *)graphics[1])[2]);}}
AllocateReserveTEQSub(reserve,0,((int *)graphics[0])[5],((int *)graphics[0])[4]);}}
''')
    # Companion resource loader and the transition routines reached by 02025f80.
    for candidate in list(candidates):
        if candidate.address==0x2025b20:
            add(0x2025abc,candidate.source.replace('func_02025b20','PlayerGfxData_Create_from_thumb').replace('Gfx_ReadCharGraphicsRelative','Gfx_ReadCharGraphics').replace('func_020b48b4','LoadCellBankFrom').replace('Gfx_ReadPaletteRelative','Gfx_ReadPalette'))
    for qualifier in ['', 'volatile ']:
        for dispatch in ['switch', 'if']:
            start='switch(s[0]){case 0:' if dispatch=='switch' else 'if(s[0]==0){'
            middle='break;case 2:' if dispatch=='switch' else '}else if(s[0]==2){'
            add(0x2025edc,'void func_02025edc('+qualifier+'int *s){'+start+
                's[1]++;if(s[1]>s[2]){s[1]=s[2];s[0]=1;return;}'+middle+
                's[1]--;if(s[1]<0){s[1]=0;s[0]=3;}}}')
    for dispatch in ['switch','if']:
        body="""if(mode==0){if(s[0]==2||s[0]==3){func_02025f54(s,mode);return;}}
else if(mode==2){if(s[0]==0||s[0]==1){func_02025f54(s,mode);return;}}
else{func_02025f54(s,mode);}""" if dispatch=='if' else """switch(mode){
case 0:if(s[0]==2||s[0]==3){func_02025f54(s,mode);return;}break;
case 2:if(s[0]==0||s[0]==1){func_02025f54(s,mode);return;}break;
default:func_02025f54(s,mode);break;}"""
        add(0x2025f14,'extern void func_02025f54(int *,int);\nvoid func_02025f14(int *s,int mode){'+body+'}')
    add(0x2025f14,"""extern void func_02025f54(int *,int);
void func_02025f14(int *s,int mode){switch(mode){
case 0:switch(s[0]){case 2:case 3:func_02025f54(s,mode);return;}break;
case 2:switch(s[0]){case 0:case 1:func_02025f54(s,mode);return;}break;
default:func_02025f54(s,mode);break;}}
""")
    runner=Search(context,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/character-graphics39',['-O4,p','-O4,s','-O2','-O1','-O3'])
    summary={'exact':[],'near_misses':[]};done=set()
    for candidate in candidates:
        if candidate.address in done:continue
        _,results=runner.run(candidate)
        for result in results:
            if result['outcome']=='exact':
                summary['exact'].append(dict(module=candidate.module,name=candidate.name,mode=candidate.mode,address=hex(candidate.address),size=candidate.size,variant=candidate.variant,source=result['source'],optimization=result['optimization']))
                done.add(candidate.address);print('EXACT',hex(candidate.address),candidate.size,flush=True);break
        else:
            valid=[r for r in results if r['outcome']=='mismatch']
            if valid:
                best=min(valid,key=lambda r:r['differing_bytes'])
                summary['near_misses'].append(dict(address=hex(candidate.address),differing_bytes=best['differing_bytes'],source=best['source'],optimization=best['optimization']))
    atomic_json(ROOT/'build/character-graphics39.json',summary)
    print('Exact helpers:',len(done))


if __name__=='__main__':main()
