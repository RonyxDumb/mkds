/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
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

typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned int    uint;
typedef unsigned short    ushort;
typedef unsigned char    byte;

/* Function-specific inferred declarations. */
int FUN_037f83c0(void);
void FUN_037f9aec(int param_1,undefined4 param_2);
undefined4 FUN_037f9bdc(int param_1);
undefined4 FUN_037f9bf0(int param_1);
int FUN_037f9ca8(int param_1,int param_2);
int FUN_037f9e4c(int param_1,int param_2,uint param_3);
uint FUN_037f9ef4(int param_1,undefined4 *param_2,uint param_3,int param_4);
uint FUN_037f9f9c(int param_1,undefined4 param_2);
void FUN_037fb000(void);
void FUN_037fb2fc(uint *param_1,uint param_2,uint param_3);

/* Decompiled C draft; module arm7; ROM address 037f83c0. No matching claim. */



int FUN_037f83c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = FUN_037f9bf0(8);
  uVar2 = FUN_037f9bdc(8);
  iVar3 = FUN_037f9ef4(8,(undefined4 *)(uintptr_t)(uVar2),uVar1,1);
  iVar4 = FUN_037f9bf0(8);
  FUN_037fb2fc((uint *)(uintptr_t)(iVar3),0,iVar4 - iVar3);
  FUN_037f9aec(8,iVar3);
  uVar1 = FUN_037f9bf0(8);
  uVar2 = FUN_037f9bdc(8);
  iVar3 = FUN_037f9e4c(8,uVar2,uVar1);
  if (iVar3 < 0) {
    FUN_037fb000();
  }
  FUN_037f9f9c(8,iVar3);
  FUN_037f9ca8(8,iVar3);
  return iVar3;
}

