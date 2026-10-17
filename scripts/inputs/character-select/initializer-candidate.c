/* Unverified initializer candidate: 19 byte differences, excluded from matching totals. */
typedef struct MenuState {unsigned char pad[0x54];int p54,p58,heap,cursor,previous,timer,phase,alpha;unsigned short value;unsigned char pad76[6];int count,mode;} MenuState;
extern MenuState *data_02174e14;
typedef struct InitialState{char pad[0xf0];int character;} InitialState;
typedef struct EntryPair{unsigned int character,cell;} EntryPair;
typedef struct Render {unsigned char pad[24]; int icons;} Render;
typedef unsigned char uint8_t; typedef unsigned short uint16_t; typedef unsigned int uint32_t; typedef unsigned long long uint64_t;
typedef signed char int8_t; typedef short int16_t; typedef int int32_t; typedef long long int64_t; typedef unsigned int uintptr_t; typedef int intptr_t;
#define bool _Bool
#define true 1
#define false 0
#define UINT32_MAX 0xffffffffU
#define INT32_MAX 0x7fffffff
#define INT32_MIN (-2147483647-1)
#define __attribute__(x)
extern int __builtin_clz(unsigned int);



typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long longlong;
typedef unsigned long long ulonglong;
typedef unsigned char undefined;
typedef uint8_t undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
/* Unknown executable address: the return convention still needs validation. */
typedef void code();
static inline bool CARRY4(uint32_t a,uint32_t b){return (uint64_t)a+b>UINT32_MAX;}
static inline bool SBORROW4(uint32_t a,uint32_t b){int64_t r=(int64_t)(int32_t)a-(int64_t)(int32_t)b;return r<INT32_MIN||r>INT32_MAX;}
static inline bool SCARRY4(uint32_t a,uint32_t b){int64_t r=(int64_t)(int32_t)a+(int64_t)(int32_t)b;return r<INT32_MIN||r>INT32_MAX;}
static inline uint32_t LZCOUNT(uint32_t a){return a?(uint32_t)__builtin_clz(a):32u;}
#define CONCAT11(hi,lo) ((uint32_t)((((uint64_t)(hi)&0xffULL)<<8)|((uint64_t)(lo)&0xffULL)))
#define CONCAT12(hi,lo) ((uint32_t)((((uint64_t)(hi)&0xffULL)<<16)|((uint64_t)(lo)&0xffffULL)))
#define CONCAT13(hi,lo) ((uint32_t)((((uint64_t)(hi)&0xffULL)<<24)|((uint64_t)(lo)&0xffffffULL)))
#define CONCAT14(hi,lo) ((uint64_t)((((uint64_t)(hi)&0xffULL)<<32)|((uint64_t)(lo)&0xffffffffULL)))
#define CONCAT15(hi,lo) ((uint64_t)((((uint64_t)(hi)&0xffULL)<<40)|((uint64_t)(lo)&0xffffffffffULL)))
#define CONCAT22(hi,lo) ((uint32_t)((((uint64_t)(hi)&0xffffULL)<<16)|((uint64_t)(lo)&0xffffULL)))
#define CONCAT31(hi,lo) ((uint32_t)((((uint64_t)(hi)&0xffffffULL)<<8)|((uint64_t)(lo)&0xffULL)))
#define CONCAT44(hi,lo) ((uint64_t)((((uint64_t)(hi)&0xffffffffULL)<<32)|((uint64_t)(lo)&0xffffffffULL)))
#define SUB21(v,n) ((uint32_t)((uint64_t)(v)>>(8u*(n))))
#define SUB43(v,n) ((uint32_t)((uint64_t)(v)>>(8u*(n))))
#define SUB84(v,n) ((uint32_t)((uint64_t)(v)>>(8u*(n))))
#define ZEXT48(v) ((uint64_t)(uint32_t)(v))
typedef uint8_t mkds_alias_u8 __attribute__((may_alias,aligned(1)));
#define MKDS_SLICE_1(obj,n) (*(mkds_alias_u8 *)((uint8_t *)&(obj)+(n)))
typedef uint16_t mkds_alias_u16 __attribute__((may_alias,aligned(1)));
#define MKDS_SLICE_2(obj,n) (*(mkds_alias_u16 *)((uint8_t *)&(obj)+(n)))
typedef uint32_t mkds_alias_u32 __attribute__((may_alias,aligned(1)));
#define MKDS_SLICE_4(obj,n) (*(mkds_alias_u32 *)((uint8_t *)&(obj)+(n)))
typedef uint64_t mkds_alias_u64 __attribute__((may_alias,aligned(1)));
#define MKDS_SLICE_8(obj,n) (*(mkds_alias_u64 *)((uint8_t *)&(obj)+(n)))


typedef unsigned char   undefined;

typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef int    wchar_t;
typedef unsigned short    wchar16;
typedef ulong size_t;

typedef unsigned int    uint;
typedef long long    longlong;
typedef unsigned char    byte;

/* Function-specific inferred declarations. */
void BrightCtx_SomeFnTopBottom(short param_1);
undefined4 Bright_IsBothScreensFadedIn(void);
int CheckSavedSecretFlag_from_thumb(int);
undefined4 GetGlobalCA_from_thumb(void);
void LoadPlayerGfxData_from_thumb(undefined4 param_1,undefined4 *param_2);
void Maybe_mb_select_menu_etc_download_m_bg_00(undefined4 param_1,undefined4 param_2);
void Maybe_select_character_s(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
int Mem_CreateOrphanChildHeap(int);
void func_02025a50(int param_1,undefined4 param_2,int *param_3);
void func_02025b20(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,unsigned int param_8);
void func_02025bb4(undefined4 param_1,int param_2,int param_3,undefined4 param_4);
void func_02025c94(undefined4 param_1,int param_2,int param_3,undefined4 param_4);
undefined4 func_02025e60(int param_1);
void func_02025f80(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5);
void func_020271e8(void);
void func_0202721c(void);
void func_0202734c(undefined4 param_1);
void func_02027448(void);
void func_02027648(void);
void func_02027850(void);
void func_02027a58(void);
void func_02027be0(void);
undefined1 func_020295e4(void);
void func_02036820(undefined4 param_1);
void func_02077f48(undefined4 param_1);
void func_020789e4(void);
void func_021170f8(void);
void func_0211f394(void);
void func_0211f4b0(undefined4 param_1,undefined4 param_2);
void func_02121ee4(void);
void func_02124748(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,undefined4 param_7,int param_8);
void func_0212481c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,int param_7,undefined4 param_8,int param_9);
void func_021281c8(undefined4 param_1);
void func_02128374(void);
#define DAT_02026c8c ((undefined4)0x12cu)
#define DAT_02026c90 ((int *)&data_02174e14)
#define DAT_02026c94 ((int)0x108u)
#define DAT_02026c98 ((int)0x118u)
#define DAT_02026c9c ((unsigned short *)0x27ffc40u)
#define DAT_02026ca0 ((int *)0x217aa00u)
#define DAT_02026ca4 ((int)0x15f7u)
#define DAT_02026ca8 ((int)0x128u)
#define DAT_02026cac ((int)0x432u)
#define DAT_02026cb0 ((int)0x1e52u)
#define DAT_02026cb4 ((undefined4)0x2161ce8u)
#define DAT_02026cb8 ((undefined4)0x2047a29u)
#define DAT_02026cbc ((undefined4)0x2161c88u)
#define DAT_02026cc0 ((undefined4)0x2161ca8u)
#define DAT_02026cc4 ((undefined4)0x2161cc8u)
#define DAT_02026cc8 ((undefined4)0x2161d54u)
#define DAT_02026ccc ((undefined4)0x2161d04u)
#define DAT_02026cd0 ((undefined4)0x2161d2cu)
#define DAT_02026cd4 ((undefined4)0x2161dc0u)
#define DAT_02026cd8 ((undefined4)0x2161d78u)
#define DAT_02026cdc ((undefined4)0x2161d9cu)
#define DAT_02026ce0 ((int)0x240u)
#define DAT_02026ce4 ((int)0x200u)
#define DAT_02026ce8 ((int)0x1c0u)
#define DAT_02026cec ((int)0x180u)
#define DAT_02026cf0 ((int)0x140u)
#define DAT_02026cf4 ((int)0x100u)
#define DAT_02026cf8 ((undefined4)0x2161e34u)
#define DAT_02026cfc ((undefined4)0x2161e4cu)
#define DAT_02026d00 ((undefined4)0x2161de0u)
#define DAT_02026d04 ((undefined4)0x2161dfcu)
#define DAT_02026d08 ((undefined4)0x2161e18u)
#define DAT_02026d0c ((int)0x600u)
#define DAT_02026d10 ((short *)0x2153554u)
#define DAT_02026d14 ((int)0x650u)
#define DAT_02026d18 ((int)0x610u)
#define DAT_02026d1c ((int)0x674u)
#define DAT_02026d20 ((int)0x634u)
extern unsigned int data_021535b4[];
#define DAT_02026d24 data_021535b4
#define DAT_02027060 ((int *)0x2174e14u)
extern unsigned int data_021535b4[];
#define DAT_02027064 ((unsigned char *)data_021535b4)
#define DAT_02027068 ((unsigned short *)0x27ffc40u)
extern short data_02153554[];
#define DAT_0202706c data_02153554
#define DAT_02027070 ((short *)0x21534bcu)
#define DAT_02027074 ((short *)0x21534dcu)
#define DAT_02027078 ((short *)0x2153500u)
#define DAT_0202707c ((short *)0x2153528u)
#define DAT_02027080 ((undefined4)0x400u)
/* Decompiled C draft; module arm9; ROM address 02026910. No matching claim. */



void Maybe_select_character_s
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  undefined4 *puVar10;int iVar8;
  uint uVar9;

  int *piVar11;
  int iVar12;
  undefined4 unaff_r4;
  short *psVar13;
  volatile unsigned int clear;
  undefined4 local_4c[7];
  undefined4 player[7];
  int gfx1,gfx2,gfx3;
  
  uVar4 = Mem_CreateOrphanChildHeap(param_1);
  iVar5 = Mem_AllocateHeap(uVar4,DAT_02026c8c);
  *DAT_02026c90 = iVar5;
  clear=0;Mem_CpuFastMemorySet(clear,(undefined4 *)(uintptr_t)(iVar5),DAT_02026c8c);
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + 0x5c) = uVar4;
  *(undefined4 *)(*piVar11 + 0x80) = param_2;
  iVar5 = GetGlobalCA_from_thumb();
switch(*(int *)(iVar5+DAT_02026c94)){case 0:{
    func_02025f80(*DAT_02026c90 + 0xf8,0,10,-128,0);
    func_02025f80(*DAT_02026c90 + DAT_02026c98,0,10,0x60,0);
    if (*DAT_02026c9c != 2) {
      func_020789e4();
    }
  }break;case 2:{
    func_02025f80(*DAT_02026c90 + 0xf8,1,10,-128,0);
    func_02025f80(*DAT_02026c90 + DAT_02026c98,1,10,0x60,0);
switch(*(int *)(*DAT_02026c90+0x80)){case 1:{
      if (*(int *)(*DAT_02026ca0 + 4) == 8) {
        *(undefined1 *)(*DAT_02026ca0 + DAT_02026ca4) = 0xff;
      }
    }break;case 2:{
      func_02121ee4();
    }break;}
  }break;}
  func_02025f80(*DAT_02026c90 + DAT_02026c94,0,10,-64,0);
  
  *(undefined4 *)(*DAT_02026c90 + 0x54) = param_3;
  *(undefined4 *)(*DAT_02026c90 + 0x58) = param_4;
  if ((*(int *)(*DAT_02026c90+0x80)!=0 || (iVar5=GetGlobalCA_from_thumb(),*(int *)(iVar5+200)==3) || (iVar5=GetGlobalCA_from_thumb(),*(int *)(iVar5+200)==2))) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  iVar5 = DAT_02026ca8;
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + DAT_02026ca8) = uVar4;
  if (*(int *)(*piVar11 + iVar5) != 0) {
    iVar5 = *(int *)(*piVar11 + 0x80);
switch(iVar5){case 0:{
      unaff_r4 = 0;
    }break;case 1:{
      unaff_r4 = 1;
    }break;case 2:{
      unaff_r4 = 2;
    }break;}
    Maybe_mb_select_menu_etc_download_m_bg_00(unaff_r4,0);
  }
  iVar5 = *DAT_02026c90;
  iVar8 = *(int *)(iVar5 + 0x80);
switch(iVar8){case 0:{
    *(undefined4 *)(iVar5 + 0x78) = 0;
  }break;case 1:{
    piVar11 = (int *)*DAT_02026ca0;
    if (*piVar11 == 2) {
      uVar9 = (uint)*(ushort *)((int)piVar11 + DAT_02026cac);
    }
    else {
      uVar9 = 0;
    }
    *(uint *)(iVar5 + 0x78) =
         (uint)*(ushort *)((int)piVar11 + ((uVar9 << 0x10) >> 0xd) + DAT_02026cb0);
  }break;case 2:{
    uVar4 = func_020295e4();
    *(undefined4 *)(*DAT_02026c90 + 0x78) = uVar4;
  }break;}
  iVar5 = *DAT_02026c90;
  if (*(int *)(iVar5 + DAT_02026ca8) == 0) {
    func_02025b20(iVar5,DAT_02026cbc,DAT_02026cc0,DAT_02026cc4,DAT_02026cb4,0,0,DAT_02026cb8);
    func_02025a50(0,*(undefined4 *)(*DAT_02026c90 + 0x5c),(int *)(uintptr_t)(iVar5));
    func_02025b20((int)(uintptr_t)(local_4c),DAT_02026ccc,DAT_02026cd0,0,DAT_02026cc8,0,0,DAT_02026cb8);
    func_02124748(0,local_4c[2],local_4c[0],local_4c[3],0,0,*(undefined4 *)(iVar5 + 8),
                  *(undefined4 *)(iVar5 + 0xc));
    func_02025b20(*DAT_02026c90 + 0x38,DAT_02026cd8,DAT_02026cdc,0,DAT_02026cd4,0,0,DAT_02026cb8);
    iVar8 = DAT_02026ce0;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026ce0) = 0;
    iVar12 = DAT_02026ce4;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026ce4) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar8);
    iVar8 = DAT_02026ce8;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026ce8) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar12);
    iVar12 = DAT_02026cec;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026cec) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar8);
    iVar8 = DAT_02026cf0;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026cf0) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar12);
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026cf4) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar8);
  }
  if (*DAT_02026c9c != 2) {
    iVar8 = *DAT_02026c90;gfx1=iVar8+0x1c;
    func_02025b20(gfx1,DAT_02026d00,DAT_02026d04,DAT_02026d08,DAT_02026cf8,0,DAT_02026cfc,
                  DAT_02026cb8);
    func_02025a50(1,*(undefined4 *)(*DAT_02026c90 + 0x5c),(int *)(uintptr_t)(gfx1));
{int icon_count;short *icon_row;    icon_count = 0;
    *(undefined4 *)(((Render *)gfx1)->icons + DAT_02026d0c) = 0;
    icon_row = DAT_02026d10;
    do {
      *(undefined4 *)(((Render *)gfx1)->icons + icon_row[2] * 0x40 + 0x10) = 1;
      *(undefined4 *)(((Render *)gfx1)->icons + icon_row[1] * 0x40 + 0x10) =
           *(undefined4 *)(((Render *)gfx1)->icons + icon_row[2] * 0x40 + 0x10);
      *(undefined4 *)(((Render *)gfx1)->icons + *icon_row * 0x40 + 0x10) =
           *(undefined4 *)(((Render *)gfx1)->icons + icon_row[1] * 0x40 + 0x10);
      *(undefined4 *)(((Render *)gfx1)->icons + icon_row[2] * 0x40 + 0x34) = 0;
      *(undefined4 *)(((Render *)gfx1)->icons + icon_row[1] * 0x40 + 0x34) =
           *(undefined4 *)(((Render *)gfx1)->icons + icon_row[2] * 0x40 + 0x34);
      *(undefined4 *)(((Render *)gfx1)->icons + *icon_row * 0x40 + 0x34) =
           *(undefined4 *)(((Render *)gfx1)->icons + icon_row[1] * 0x40 + 0x34);
      iVar12 = DAT_02026d14;
      icon_row = icon_row + 4;
      icon_count = icon_count + 1;
    } while (icon_count < 0xc);
    *(undefined4 *)(((Render *)gfx1)->icons + DAT_02026d14) = 1;
    *(undefined4 *)(((Render *)gfx1)->icons + DAT_02026d18) =
         *(undefined4 *)(((Render *)gfx1)->icons + iVar12);
    icon_count = DAT_02026d1c;
    *(undefined4 *)(((Render *)gfx1)->icons + DAT_02026d1c) = 0;
    *(undefined4 *)(((Render *)gfx1)->icons + DAT_02026d20) =
         *(undefined4 *)(((Render *)gfx1)->icons + icon_count);}
  }
  else {
    iVar5 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar5 + 200) == 2) {
      func_0211f4b0(*(undefined4 *)(*DAT_02026c90 + 0x5c),*(undefined4 *)(*DAT_02026c90 + 0x58));
      func_0211f394();
    }
  }
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + 0x7c) = 8;
  iVar5=0;iVar8 = *piVar11;
  puVar10 = DAT_02026d24;
  do {

    {unsigned int low,high;low=((volatile unsigned int *)puVar10)[0];high=((volatile unsigned int *)puVar10)[1];*(unsigned int *)(iVar8+0x90)=low;*(unsigned int *)(iVar8+0x94)=high;}
    puVar10 = puVar10 + 2;
    iVar8 = iVar8 + 8;
    iVar5++;
  } while (iVar5 < 8);
  iVar8 = CheckSavedSecretFlag_from_thumb(0x15);
  if (iVar8 != 0) {
    iVar8 = *DAT_02026c90;
    int unlock_slot = iVar8 + iVar5 * 8;
    {unsigned int low,high;low=((volatile unsigned int *)DAT_02026d24)[16];high=((volatile unsigned int *)DAT_02026d24)[17];*(unsigned int *)(unlock_slot+0x90)=low;*(unsigned int *)(unlock_slot+0x94)=high;}
    iVar5++;
    *(int *)(iVar8 + 0x7c) = *(int *)(iVar8 + 0x7c) + 1;
  }
  iVar8 = CheckSavedSecretFlag_from_thumb(0x14);
  if (iVar8 != 0) {
    iVar12 = *DAT_02027060;
    iVar8 = iVar12 + iVar5 * 8;
    {unsigned int low,high;low=((volatile unsigned int *)data_021535b4)[18];high=((volatile unsigned int *)data_021535b4)[19];*(unsigned int *)(iVar8+0x90)=low;*(unsigned int *)(iVar8+0x94)=high;}
    iVar5 = iVar5 + 1;
    *(int *)(iVar12 + 0x7c) = *(int *)(iVar12 + 0x7c) + 1;
  }
  iVar8 = CheckSavedSecretFlag_from_thumb(0x16);
  if (iVar8 != 0) {
    iVar12 = *DAT_02027060;
    iVar8 = iVar12 + iVar5 * 8;
    {unsigned int low,high;low=((volatile unsigned int *)data_021535b4)[20];high=((volatile unsigned int *)data_021535b4)[21];*(unsigned int *)(iVar8+0x90)=low;*(unsigned int *)(iVar8+0x94)=high;}
    iVar5 = iVar5 + 1;
    *(int *)(iVar12 + 0x7c) = *(int *)(iVar12 + 0x7c) + 1;
  }
  iVar8 = CheckSavedSecretFlag_from_thumb(0x17);
  if (iVar8 != 0) {
    iVar12 = *DAT_02027060;
    iVar8 = iVar12 + iVar5 * 8;
    {unsigned int low,high;low=((volatile unsigned int *)data_021535b4)[22];high=((volatile unsigned int *)data_021535b4)[23];*(unsigned int *)(iVar8+0x90)=low;*(unsigned int *)(iVar8+0x94)=high;}
    iVar5 = iVar5 + 1;
    *(int *)(iVar12 + 0x7c) = *(int *)(iVar12 + 0x7c) + 1;
  }
  piVar11 = DAT_02027060;
  if (iVar5 < 0xc) {
    iVar8 = iVar5 << 3;
    do {
      *(undefined4 *)(*piVar11 + iVar8 + 0x90) = 0xffffffff;
      iVar8 = iVar8 + 8;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
  }
  piVar11 = DAT_02027060;
  iVar8 = 0;
  iVar5 = *DAT_02027060;
  if (0 < *(int *)(iVar5 + 0x7c)) {
    iVar12 = 0;
    do {
      iVar7 = GetGlobalCA_from_thumb();
      if (*(int *)(iVar5 + iVar12 + 0x90) == *(int *)(iVar7 + *(int *)(iVar5 + 0x78) * 0x18)) {
        *(int *)(iVar5 + 0x60) = iVar8;
      }
      iVar12 = iVar12 + 8;
      iVar8 = iVar8 + 1;
      iVar5 = *piVar11;
    } while (iVar8 < *(int *)(iVar5 + 0x7c));
  }
  piVar11 = DAT_02027060;
  {int q=*(volatile int *)DAT_02027060;*(unsigned int *)(q+100)=*(unsigned int *)(q+0x60);}
  iVar8 = *piVar11;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar8 + 0xf0) = *(undefined4 *)(iVar5 + *(int *)(iVar8 + 0x78) * 0x18);
  if (*(int *)(*DAT_02027060 + 0xf0) == -1) {
    ((InitialState *)*DAT_02027060)->character = 0;
  }
  uVar4 = func_02025e60(((InitialState *)*DAT_02027060)->character);
  *(undefined4 *)(*DAT_02027060 + 0xf4) = uVar4;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar5 + *(int *)(*DAT_02027060 + 0x78) * 0x18) = 0xffffffff;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar5 + *(int *)(*DAT_02027060 + 0x78) * 0x18 + 4) = 0xffffffff;
  iVar5 = GetGlobalCA_from_thumb();
  piVar11 = DAT_02027060;
  *(undefined4 *)(iVar5 + *(int *)(*DAT_02027060 + 0x78) * 0x18 + 0x14) = 0;
  if (*DAT_02027068 != 2) {
    iVar12 = *piVar11;gfx2=iVar12+0x1c;
    LoadPlayerGfxData_from_thumb(0,&player[0]);
    iVar8 = 0;
    iVar5 = *DAT_02027060;
    if (0 < *(int *)(iVar5 + 0x7c)) {
      psVar6 = DAT_0202706c;
      iVar7 = 0;
      do {
        func_0212481c(*(undefined4 *)(iVar5 + iVar7 + 0x90),player[2],player[0],player[1],player[3],1,
                      (int)psVar6[1],*(undefined4 *)(gfx2 + 8),*(undefined4 *)(gfx2 + 12));
        psVar6 = psVar6 + 4;
        iVar7 = iVar7 + 8;
        iVar8 = iVar8 + 1;
        iVar5 = *DAT_02027060;
      } while (iVar8 < *(int *)(iVar5 + 0x7c));
    }
  }
  psVar3 = DAT_0202707c;
  psVar2 = DAT_02027078;
  psVar1 = DAT_02027074;
  psVar6 = DAT_02027070;
  if (*DAT_02027068 != 2) {
    psVar13 = (short *)0x0;iVar5 = *DAT_02027060;gfx3=iVar5+0x1c;
    switch(*(undefined4 *)(iVar5 + 0x7c)) {
    case 8:
      psVar13 = psVar6;func_02027be0();
      break;
    case 9:
      psVar13 = psVar1;func_02027a58();
      break;
    case 10:
      psVar13 = psVar2;func_02027850();
      break;
    case 0xb:
      psVar13 = psVar3;func_02027648();
      break;
    case 0xc:
      func_02027448();
    }
    if (psVar13 != (short *)0x0) {
      iVar8 = 0;
      if (0 < *(int *)(*DAT_02027060 + 0x7c)) {
        psVar6 = DAT_0202706c;
        do {
          func_02025c94((int)*psVar6,(int)*psVar13,(int)psVar13[1],*(undefined4 *)(gfx3 + 0xc));
          func_02025c94((int)psVar6[1],(int)*psVar13,(int)psVar13[1],*(undefined4 *)(gfx3 + 0xc));
          func_02025bb4((int)psVar6[3],(int)*psVar13,(int)psVar13[1],*(undefined4 *)(gfx3 + 0x10));
          func_02025c94((int)psVar6[2],(*psVar13 + 3) * 0x10000 >> 0x10,
                        (psVar13[1] + 3) * 0x10000 >> 0x10,*(undefined4 *)(gfx3 + 0xc));
          psVar13 = psVar13 + 2;
          psVar6 = psVar6 + 4;
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(int *)(*DAT_02027060 + 0x7c));
      }
      if (iVar8 < 0xc) {
        psVar6 = DAT_0202706c + iVar8 * 4;
        do {
          *(undefined4 *)(((Render *)gfx3)->icons + *psVar6 * 0x40) = 0;
          *(undefined4 *)(((Render *)gfx3)->icons + psVar6[1] * 0x40) = 0;
          *(undefined4 *)(((Render *)gfx3)->icons + psVar6[2] * 0x40) = 0;
          func_02025bb4((int)psVar6[3],DAT_02027080,DAT_02027080,*(undefined4 *)(gfx3 + 0x10));
          psVar6 = psVar6 + 4;
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0xc);
      }
    }
    func_020271e8();
    func_0202721c();
  }
  if (*(int *)(*DAT_02027060 + 0x80) == 0) {
    func_021170f8();
    func_021281c8(0xe);
    func_02128374();
  }
  iVar5 = Bright_IsBothScreensFadedIn();
  if (iVar5 != 0) {
    *(undefined4 *)(*DAT_02027060 + 0x6c) = 1;
  }
  else {
    BrightCtx_SomeFnTopBottom(10);
    func_0202734c(0);
  }
  if (*DAT_02027068 != 2) {
    func_02077f48(0);
  }
  func_02036820(*(undefined4 *)(*DAT_02027060 + 0x5c));
  return;
}

