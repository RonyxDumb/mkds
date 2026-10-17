typedef struct TimerState{char pad[0x68];int timer;} TimerState;
extern int data_02174e14;
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
undefined4 Bright_IsBothScreensFadedIn(void);
undefined4 GetDirectInputUnitIndex(void);
undefined4 GetGlobalCA_from_thumb(void);
int _s32_div_f(int,int);
int func_0201ea84(int param_1,int param_2,int param_3);
undefined4 func_02025eb0(int param_1);
int func_02025ebc(int param_1);
void func_02025edc(int *param_1);
void func_02025f14(int *param_1,int param_2);
int func_02026120(void);
void func_02027084(void);
undefined4 func_020270d0(void);
void func_020270fc(undefined4 param_1);
void func_02027188(void);
void func_0202728c(int);
void func_020272c0(int,int);
void func_020272ec(void);
void func_0202734c(undefined4 param_1);
void func_020273c0(void);
void func_02027424(int);
uint func_0202b888(void);
void func_0202bb80(void);
void func_02077f48(undefined4 param_1);
void func_02077f5c(void);
void func_020780f4(void);
void func_02078420(int param_1);
void func_020789d4(void);
void func_02078a34(int param_1);
void func_02078a9c(int param_1);
ushort func_020ae408(undefined4 param_1,undefined4 param_2);
void func_020ae5d4(int param_1);
void func_02110698(void);
void func_021106a8(int param_1,int param_2);
void func_02116ec0(void);
void func_02116fb0(void);
void func_02117060(void);
void func_0211f378(void);
void func_0211f39c(void);
void func_021219cc(void);
undefined4 func_02121d0c(void);
void func_02121eb4(undefined4 param_1);
void func_02121f1c(undefined4 param_1);
void func_02124bf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5);
void func_02124c30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5);
undefined4 func_02128210(int param_1,int param_2);
#define DAT_02026480 (&data_02174e14)
#define DAT_02026484 ((undefined4)0x1000u)
#define DAT_02026488 ((unsigned short *)0x27ffc40u)
#define DAT_0202648c ((int *)0x217aa00u)
#define DAT_02026490 ((int)0x15f7u)
extern unsigned char data_02175674[];
#define DAT_02026494 data_02175674
extern unsigned char data_02175680[];
#define DAT_02026498 data_02175680
extern unsigned char data_0217567c[];
#define DAT_0202649c data_0217567c
extern unsigned char data_02175670[];
#define DAT_020264a0 data_02175670
extern unsigned char data_02175672[];
#define DAT_020264a4 data_02175672
#define DAT_020264a8 ((int)0x2153554u)
extern unsigned char data_02175628[];
#define DAT_020264ac data_02175628
#define DAT_02026840 (&data_02174e14)
#define DAT_02026844 ((int)0x108u)
#define DAT_02026848 ((int *)0x217aa00u)
#define DAT_0202684c ((int)0x15f7u)
#define DAT_02026850 ((unsigned short *)0x27ffc40u)
#define DAT_02026854 ((undefined4)0x1000u)
#define DAT_02026858 ((int)0x118u)
#define DAT_0202685c ((int)0x128u)
#define DAT_02026904 (&data_02174e14)
#define DAT_02026908 ((unsigned short *)0x27ffc40u)
#define DAT_0202690c ((int)0x108u)
/* Decompiled C draft; module arm9; ROM address 02026120. No matching claim. */



int func_02026120(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14; int gfx;
  
  iVar14 = 0;
  int input = GetDirectInputUnitIndex();
  piVar3 = DAT_02026480;
  iVar12 = *DAT_02026480;
  gfx=iVar12+0x1c;
  switch(*(undefined4 *)(iVar12 + 0x6c)) {
  case 0:
    iVar4 = Bright_IsBothScreensFadedIn();
    if (iVar4 != 0) {
      *(undefined4 *)(*DAT_02026480 + 0x6c) = 1;
    }
    break;
  case 1:
    if (*(int *)(iVar12 + 0x68) == 0) {
      func_0202734c(1);
    }
    piVar3 = DAT_02026480;
    *(int *)(*DAT_02026480 + 0x68) = *(int *)(*DAT_02026480 + 0x68) + 1;
    iVar4 = *piVar3;
    if (*(int *)(iVar4 + 0x68) < 10) {
      uVar7 = _s32_div_f(*(int *)(iVar4 + 0x68) << 0xc,10);
      *(undefined4 *)(iVar4 + 0x70) = uVar7;
    }
    else {
      *(undefined4 *)(iVar4 + 0x70) = DAT_02026484;
      *(undefined4 *)(*piVar3 + 0x68) = 0;
      if (*DAT_02026488 == 2) {
        uVar7 = 2;
      }
      else {
        uVar7 = 3;
      }
      *(undefined4 *)(*DAT_02026480 + 0x6c) = uVar7;
    }
    func_02027084();
    break;
  case 2:
    *(undefined4 *)(iVar12 + 0xf0) = 0xc;
    *(undefined4 *)(*piVar3 + 0xf4) = 0x24;
    *(undefined4 *)(*piVar3 + 0x68) = 0;
    *(undefined4 *)(*piVar3 + 0x8c) = 1;
    iVar4 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar4 + 200) == 3) {
      {unsigned char packed=(unsigned char)(*(undefined4 *)(*DAT_02026480 + 0xf0) | 0x40
        );if(*(int *)(*DAT_0202648c+4)==8)*(byte *)(*DAT_0202648c+DAT_02026490)=packed;}
      func_02027424(1);
      *(undefined4 *)(*DAT_02026480 + 0x6c) = 8;
    }
    else {
      iVar4 = GetGlobalCA_from_thumb();
      if (*(int *)(iVar4 + 200) == 2) {
        {unsigned char packed=(unsigned char)(*(undefined4 *)(*DAT_02026480 + 0xf0) | 0xc0);if(*(int *)(*DAT_0202648c+4)==8)*(byte *)(*DAT_0202648c+DAT_02026490)=packed;}
        *(undefined4 *)(*DAT_02026480 + 0x6c) = 6;
      }
    }
    break;
  case 3: {int previous;int offset;int touch,held;unsigned short x,y;
    previous = *(int *)(iVar12 + 0x60);
    touch = false;
    held = false;
    offset = input * 0x5c;
    if ((*(unsigned short *)((unsigned char *)DAT_02026494 + offset) == 0) && (*(ushort *)((unsigned char *)DAT_02026498 + offset) < 5)) {
      held = true;
    }
    if (((!held) && (*(unsigned short *)((unsigned char *)DAT_0202649c + offset) == 0)) &&
       (*(unsigned short *)((unsigned char *)DAT_02026494 + offset) != 0)) {
      touch = true;
    }
    if (touch) {
      x = *(undefined2 *)((unsigned char *)DAT_020264a0 + offset);
      y = *(undefined2 *)((unsigned char *)DAT_020264a4 + offset);
      {int scan;int hit;int current;      hit = func_0201ea84(*(undefined4 *)(gfx + 0x10),x,y);
      if (hit >= 0) {
        scan = 0;
        current = *DAT_02026480;
        
        if (0 < *(int *)(current + 0x7c)) {
          offset = DAT_020264a8;do {
            if (hit == *(short *)(offset + 6)) {
              *(int *)(current + 0x60) = scan;
              break;
            }
            offset = offset + 8;
            scan = scan + 1;
          } while (scan < *(int *)(current + 0x7c));
        }
        func_020270fc(previous);
        uVar7 = func_02025eb0(*(undefined4 *)(*DAT_02026480 + 0xf0));
        func_021106a8(uVar7,0);
        piVar3 = DAT_02026480;
        *(undefined4 *)(*DAT_02026480 + 0x68) = 0;
        *(undefined4 *)(*DAT_02026480 + 0x6c) = 5;
      }
      else {
        if ((*(int *)(*DAT_02026480 + 0x80) == 0) &&
           (hit = func_02128210(x,y), hit != 0)) {
          func_020273c0();
        }
      }
}    }
    else {
      iVar5 = func_020270d0();
      if (iVar5 != 0) {
        *(undefined4 *)(*DAT_02026480 + 0x68) = 0;
        *(undefined4 *)(*DAT_02026480 + 0x8c) = 3;
        *(undefined4 *)(*DAT_02026480 + 0x6c) = 6;
        uVar7 = func_02025eb0(*(undefined4 *)(*DAT_02026480 + 0xf0));
        func_021106a8(uVar7,0);
        func_02077f48(1);
        iVar4 = *DAT_02026480;
switch(*(int *)(iVar4+0x80)){case 2:{
          func_02121f1c(*(undefined4 *)(iVar4 + 0xf0));
          func_02121eb4(*(undefined4 *)(*DAT_02026480 + 0xf4));
        }break;case 1:{
          {unsigned char packed=(unsigned char)(*(undefined4 *)(iVar4 + 0xf0) | 0xc0);if(*(int *)(*DAT_0202648c+4)==8)*(byte *)(*DAT_0202648c+DAT_02026490)=packed;}
        }break;}
      }
      else {
        if ((ushort)(*(ushort *)((unsigned char *)DAT_020264ac + offset) & 1) != 0) {
          *(undefined4 *)(*DAT_02026480 + 0x68) = 0;
          *(undefined4 *)(*DAT_02026480 + 0x6c) = 5;
          func_02027188();
          uVar7 = func_02025eb0(*(undefined4 *)(*DAT_02026480 + 0xf0));
          func_021106a8(uVar7,0);
        }
        else {
          if ((*(int *)(*DAT_02026480 + 0x80) == 0) &&
             ((ushort)(*(ushort *)((unsigned char *)DAT_020264ac + offset) & 2) != 0)) {
            func_020273c0();
          }
          else {
if(func_020ae408(input,64)!=0){int next=(int)*(short *)(*DAT_02026480+0x84);if(next!=-1)*(int *)(*DAT_02026480+0x60)=next;}else if(func_020ae408(input,128)!=0){int next=(int)*(short *)(*DAT_02026480+0x86);if(next!=-1)*(int *)(*DAT_02026480+0x60)=next;}else if(func_020ae408(input,16)!=0){int next=(int)*(short *)(*DAT_02026480+0x88);if(next!=-1)*(int *)(*DAT_02026480+0x60)=next;}else if(func_020ae408(input,32)!=0){int next=(int)*(short *)(*DAT_02026480+0x8a);if(next!=-1)*(int *)(*DAT_02026480+0x60)=next;}            if (*(int *)(*DAT_02026480 + 0x60) != previous) {
              func_02110698();
              func_020270fc(previous);
              *(undefined4 *)(*DAT_02026480 + 0x6c) = 4;
            }
          }
        }
      }
    }
    break;}
  case 4:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    if (5 < *(int *)(*piVar3 + 0x68)) {
      func_020272ec();
      piVar3 = DAT_02026840;
      *(undefined4 *)(*DAT_02026840 + 0x68) = 0;
      *(undefined4 *)(*piVar3 + 0x6c) = 3;
    }
    break;
  case 5:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    if (5 < ((TimerState *)*piVar3)->timer) {
      ((TimerState *)*piVar3)->timer = 0;
      *(undefined4 *)(*piVar3 + 0x8c) = 1;
      func_020272ec();
      iVar6 = *DAT_02026840;
      iVar4 = *(int *)(iVar6 + 0x80);
switch(iVar4){case 0:{
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18) =
             *(undefined4 *)(iVar6 + 0xf0);
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18 + 4) =
             *(undefined4 *)(*DAT_02026840 + 0xf4);
        func_02116fb0();
        iVar4 = GetGlobalCA_from_thumb();
        if (*(int *)(iVar4 + 200) == 2) {
          iVar4 = GetGlobalCA_from_thumb();
          *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18 + 0x14) = 1;
          func_02077f48(1);
          *(undefined4 *)(*DAT_02026840 + 0x6c) = 7;
          func_02117060();
          func_02116ec0();
        }
        else {
          func_02027424(1);
          func_02077f5c();
          piVar3 = DAT_02026840;
          *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
          func_02025f14((int *)(uintptr_t)(*piVar3 + DAT_02026844),2);
        }
      }break;case 1:{
        iVar4 = GetGlobalCA_from_thumb();
        if (*(int *)(iVar4 + 200) == 3) {
          {unsigned char packed=(unsigned char)(*(undefined4 *)(*DAT_02026840 + 0xf0) | 0x40);if(*(int *)(*DAT_02026848+4)==8)*(byte *)(*DAT_02026848+DAT_0202684c)=packed;}
          func_02025f14((int *)(uintptr_t)(*DAT_02026840 + DAT_02026844),2);
          func_02027424(1);
          *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
          func_02077f5c();
        }
        else {
          iVar4 = GetGlobalCA_from_thumb();
          if (*(int *)(iVar4 + 200) == 2) {
            {unsigned char packed=(unsigned char)(*(undefined4 *)(*DAT_02026840 + 0xf0) | 0xc0);if(*(int *)(*DAT_02026848+4)==8)*(byte *)(*DAT_02026848+DAT_0202684c)=packed;}
            func_02077f48(1);
            *(undefined4 *)(*DAT_02026840 + 0x6c) = 6;
          }
        }
      }break;case 2:{
        func_02121f1c(*(undefined4 *)(iVar6 + 0xf0));
        func_02025f14((int *)(uintptr_t)(*DAT_02026840 + DAT_02026844),2);
        func_02027424(1);
        *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
        func_02077f5c();
      }break;}
    }
    break;
  case 6:
    if (((*(int *)(iVar12 + 0x80) == 1) && (iVar4 = func_0202b888(), iVar4 != 0)) ||
       ((*(int *)(*DAT_02026840 + 0x80) == 2 && (iVar4 = func_02121d0c(), iVar4 != 0)))) {
      if (*(int *)(*DAT_02026840 + 0x80) == 2) {
        func_021219cc();
      }
      iVar4 = GetGlobalCA_from_thumb();
      if ((*(int *)(iVar4 + 200) == 2) || (iVar4 = func_020270d0(), iVar4 != 0)) {
        *(undefined4 *)(*DAT_02026840 + 0x6c) = 7;
      }
      else {
        func_02027424(1);
        func_02025f14((int *)(uintptr_t)(*DAT_02026840 + DAT_02026844),2);
        *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
      }
    }
    break;
  case 7:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    if (0x3c < *(int *)(*piVar3 + 0x68)) {
      if (*(int *)(*piVar3 + 0x80) == 2) {
        func_02027424(3);
      }
      else {
        func_02027424(2);
      }
      func_02025f14((int *)(uintptr_t)(*DAT_02026840 + DAT_02026844),2);
      if (*DAT_02026850 != 2) {
        func_020789d4();
      }
      else {
        iVar4 = GetGlobalCA_from_thumb();
        if (*(int *)(iVar4 + 200) == 2) {
          func_0211f378();
        }
      }
      piVar3 = DAT_02026840;
      *(undefined4 *)(*DAT_02026840 + 0x68) = 0;
      *(undefined4 *)(*piVar3 + 0x6c) = 8;
    }
    break;
  case 8:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    iVar4 = *piVar3;
    if (*(int *)(iVar4 + 0x68) < 10) {
      uVar7 = _s32_div_f((10 - *(int *)(iVar4 + 0x68)) * 0x1000,10);
      *(undefined4 *)(iVar4 + 0x70) = uVar7;
    }
    else {
      iVar6 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar6 + *(int *)(*DAT_02026840 + 0x78) * 0x18) = *(undefined4 *)(iVar4 + 0xf0)
      ;
      iVar4 = GetGlobalCA_from_thumb();
      piVar3 = DAT_02026840;
      *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18 + 4) =
           *(undefined4 *)(*DAT_02026840 + 0xf4);
      *(undefined4 *)(*piVar3 + 0x6c) = 9;
    }
    *(unsigned short *)(*DAT_02026840 + 0x74) = *(unsigned short *)(*DAT_02026840 + 0x74) + (short)DAT_02026854;
    func_02027084();
    break;
  case 9:
    iVar14 = *(int *)(iVar12 + 0x8c);
  }
  func_02025edc((int *)(uintptr_t)(*DAT_02026840 + 0xf8));
  func_02025edc((int *)(uintptr_t)(*DAT_02026840 + DAT_02026844));
  func_02025edc((int *)(uintptr_t)(*DAT_02026840 + DAT_02026858));
  uVar7=func_02025ebc(*DAT_02026840 + 0xf8);func_0202728c(uVar7);
  uVar7 = func_02025ebc(*DAT_02026840 + DAT_02026844);
  uVar8 = func_02025ebc(*DAT_02026840 + DAT_02026858);
  func_020272c0(uVar7,uVar8);
  if (*DAT_02026850 != 2) {
    if (*(int *)(*DAT_02026840 + 0x8c) != 2) {
      func_02078a9c(*(undefined4 *)(*DAT_02026840 + 0xf0));
      func_02078a34(*(undefined4 *)(*DAT_02026840 + 0xf4));
    }
    iVar4 = GetGlobalCA_from_thumb();
    func_02078420(*(undefined4 *)(iVar4 + 0xd8));
  }
  if (*(int *)(*DAT_02026840 + DAT_0202685c) != 0) {
    func_0202bb80();
  }
  else {
    func_02124c30(*(undefined4 *)(iVar12 + 0xc),*(undefined4 *)(iVar12 + 8),0,
                  *(undefined4 *)(*DAT_02026840 + 0x54),*(undefined4 *)(iVar12 + 0x18));
  }
  if (*DAT_02026850 != 2) {
    func_02124bf0(*(undefined4 *)(gfx + 0xc),*(undefined4 *)(gfx + 0x8),0,
                  *(undefined4 *)(*DAT_02026904 + 0x58),*(undefined4 *)(gfx + 0x18));
    func_020ae5d4(*(undefined4 *)(*DAT_02026904 + 0x58));
  }
  else {
    iVar4 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar4 + 200) == 2) {
      func_0211f39c();
    }
  }
  if (*DAT_02026908 != 2) {
    func_020780f4();
  }
switch(iVar14){case 1:{
    iVar4 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar4 + 200) == 2) {
      iVar4 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar4 + DAT_0202690c) = 0;
    }
    else {
      iVar4 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar4 + DAT_0202690c) = 1;
    }
  }break;case 2:{
    if (*DAT_02026908 != 2) {
      func_02078a9c(0xffffffff);
      func_02078a34(0xffffffff);
    }
    iVar4 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar4 + DAT_0202690c) = 0;
  }break;}
  return iVar14;
}

