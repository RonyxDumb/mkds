/* MW build 82: entire local function bytes verified. Full ROM and caller ABI remain unverified. */
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
uint GetCurrentInternalCourseId_0(void);
void func_020b681c(undefined4 param_1,undefined4 param_2);
void func_020b6a98(undefined4 param_1,undefined4 param_2);
void func_020b6b18(int *param_1,int *param_2,int param_3,int param_4,short param_5,short param_6);
















/* Decompiled C draft; module arm9; ROM address 020b681c. No matching claim. */



void func_020b681c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = GetCurrentInternalCourseId_0();
  if (iVar1 == 0xe) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0xfffff434u,0xfffffff6,0x00000ba4u,0x00001766u);
    return;
  }
  if (iVar1 == 0x12) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0xfffff7c0,0xfffffc18,0xf30,0x00001388u);
    return;
  }
  if (iVar1 == 0x14) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0,0xfffff446u,0x00001770u,0x00000bb6u);
    return;
  }
  if (iVar1 == 0x1c) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0xffffff42,0xfffff132u,0x000018a6u,0x00000a96u);
    return;
  }
  if (iVar1 == 0x1e) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0xfffff7c2u,0xffffffec,0x00000f32u,0x0000175cu);
    return;
  }
  if (iVar1 == 0x21) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0xfffff443u,0xffffffe2,0x00000bb3u,0x00001752u);
    return;
  }
  if (iVar1 == 0x26) {
    func_020b6b18((int *)(uintptr_t)(param_1),(int *)(uintptr_t)(param_2),0xfffffff6,0xfffff434u,0x00001766u,0x00000ba4u);
    return;
  }
  func_020b6a98(param_1,param_2);
  return;
}

