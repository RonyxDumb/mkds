"""Reconstruct the render block shared by character-menu callbacks."""
from batch_matching import *
ns={'__file__':str(ROOT/'scripts/search_character_select_family.py')}
exec((ROOT/'scripts/search_character_select_family.py').read_text().split("out={'exact':[]")[0],ns)
ctx=ns['ctx'];word=ns['word'];PRE=ns['PRE'];items=[]
PRE=PRE.replace('unsigned char reserved00[0x60];','unsigned char reserved00[0x1c]; struct { unsigned char pad[12]; void *cellbank; void *a,*b; unsigned char *icons; unsigned char tail[40]; } render;')
PRE=PRE.replace('#define state (*(CharacterSelectState **)0x2174e14u)','extern CharacterSelectState *data_02174e14;\n#define state data_02174e14')
def add(a,body,pre=''):
 n,m,z=ctx.inventory['arm9',a];items.append(Candidate('arm9',n,m,a,z,'character-render-block',PRE+pre+body,ctx.original('arm9',a,z)))
for ca in ns['items']:
 if ca.address not in [0x202719c,0x20271e8,0x20272ec,0x202734c] or ca.variant!='character-select-typed':continue
 s=ca.source.replace('unsigned char reserved00[0x60];','unsigned char reserved00[0x1c]; struct { unsigned char pad[12]; void *cellbank; void *a,*b; unsigned char *icons; unsigned char tail[40]; } render;')
 s=s.replace('CharacterSelectState *s=state;','CharacterSelectState *s=state;void *gfx=(unsigned char *)s+0x1c;')
 s=s.replace('(*(unsigned char **)((unsigned char *)s+0x34))','(*(unsigned char **)((unsigned char *)gfx+0x18))').replace('*(unsigned char **)((unsigned char *)s+0x34','*(unsigned char **)((unsigned char *)gfx+0x18').replace('*(void **)((unsigned char *)s+0x28)','*(void **)((unsigned char *)gfx+0xc)')
 if ca.address==0x202734c:
  s=s.replace('i<s->character_count','i<state->character_count').replace('entry+=4;}}}', 'entry+=4;}*(int *)(*(unsigned char **)((unsigned char *)gfx+0x18)+'+str(word(0x20273bc))+')=visible;}}')
 for loop in [False,True]:
  t=s
  if loop:t=t.replace('for(i=0;i<12;i++){','i=0;do{').replace('entry+=4;}}}','entry+=4;i++;}while(i<12);}}')
  items.append(Candidate(ca.module,ca.name,ca.mode,ca.address,ca.size,'character-render-block',t,ca.original))
pre='extern void func_02128310(void);extern void func_02027424(int);extern void func_02025f14(void *,int);extern void func_020789d4(void);\n'
add(0x20273c0,'void func_020273c0(void){state->timer=0;*(int *)((unsigned char *)state+0x8c)=2;state->phase=8;func_02128310();func_02027424(3);func_02025f14((unsigned char *)state+0xf8,2);func_02025f14((unsigned char *)state+'+str(word(0x202741c))+',2);func_02025f14((unsigned char *)state+'+str(word(0x2027420))+',2);func_020789d4();}',pre)
pre='extern void func_02124b1c(void *,unsigned short,int);\n#define system_mode (*(unsigned short *)'+hex(word(0x20270cc))+'u)\n'
for loop in ['for(i=0;i<count;i++){','i=0;if(count){do{']:
 end='}' if loop.startswith('for') else 'i++;}while(i<count);}'
 add(0x2027084,'void func_02027084(void){CharacterSelectState *s=state;unsigned char *gfx=(unsigned char *)s+0x1c;if(system_mode!=2){int count=*(unsigned short *)(*(unsigned char **)(gfx+12)+6),i,off=0;'+loop+'func_02124b1c(*(unsigned char **)(gfx+24)+off,state->render_value,state->alpha);off+=64;'+end+'}}',pre)
pre='extern void func_02124748(int,void *,void *,void *,int,int,int,int);\n'
for islocal in [True,False]:
 sel='s' if islocal else 'state'
 call=lambda which:'func_02124748('+sel+'->entries['+sel+'->cursor].cell,*(void **)(gfx+36),*(void **)(gfx+28),*(void **)(gfx+40),0,'+str(which)+',*(int *)((unsigned char *)s+8),*(int *)((unsigned char *)s+12));'
 add(0x202721c,'void func_0202721c(void){CharacterSelectState *s=state;unsigned char *gfx=(unsigned char *)s+0x1c;if(*(int *)((unsigned char *)s+'+str(word(0x2027288))+')==0){'+call(2)+call(1)+'}}',pre)
pre='extern void *FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(const void *);extern void Gfx_ReadCharGraphics(void *,void *);extern void Gfx_ReadPalette(void *,void *);extern void LoadCellBankFrom(void *,void *);\n'
for layout in ['void *characters=0,*palette=0,*cells=0;','struct{void *characters,*palette,*cells;} r={0,0,0};']:
 body='void VerifySelectCharacterFiles_from_thumb(void){'+layout
 for i,fn in enumerate(['Gfx_ReadCharGraphics','LoadCellBankFrom','Gfx_ReadPalette','Gfx_ReadCharGraphics','LoadCellBankFrom','Gfx_ReadPalette','Gfx_ReadCharGraphics','LoadCellBankFrom','Gfx_ReadCharGraphics','LoadCellBankFrom']):
  var={'Gfx_ReadCharGraphics':'characters','LoadCellBankFrom':'cells','Gfx_ReadPalette':'palette'}[fn];var=('r.' if layout.startswith('struct') else '')+var
  address=word(0x2026030+i*4);name=ctx.data_symbols['arm9'].get(address)
  ptr='(const void *)'+hex(address)+'u'
  body+=fn+'(&'+var+',FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb('+ptr+'));'
 add(0x2025f90,body+'}',pre)
runner=Search(ctx,ROOT/'tools/mwccarm/1.2/base/mwccarm.exe',ROOT/'tools/wibo',ROOT/'build/render36',['-O4,p','-O4,s','-O2','-O1','-O3'])
out={'exact':[],'attempts':[]};done=set()
for ca in items:
 if ca.address in done:continue
 _,rr=runner.run(ca)
 for v in rr:
  out['attempts'].append(dict(address=hex(ca.address),outcome=v['outcome'],diff=v.get('differing_bytes'),optimization=v.get('optimization')))
  if v['outcome']=='exact':
   done.add(ca.address);out['exact'].append(dict(module=ca.module,name=ca.name,mode=ca.mode,address=hex(ca.address),size=ca.size,variant=ca.variant,source=v['source'],optimization=v['optimization']));print('EXACT',hex(ca.address),ca.size,flush=True)
atomic_json(ROOT/'build/render36.json',out)
print('attempts',len(out['attempts']))
