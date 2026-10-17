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
undefined4 AllocateReserveTEQSub(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void Gfx_ReadCharGraphicsRelative(int *param_1,int param_2);
void Gfx_ReadPaletteRelative(int *param_1,int param_2);
void MaybeReadCharBlock_1(int *param_1,int param_2);
void MaybeReadScreenBlock(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
int find_buf_fn_from_thumb(undefined4 param_1);
void func_020b48b4(int *param_1,int param_2);
undefined4 func_020cccb4(void);
void func_0211efec(void);














/* Decompiled C draft; module arm9; ROM address 0211efec. No matching claim. */



void func_0211efec(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;

  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (*((unsigned short *)0x027ffc40u) != 2) {
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfb0u));
    MaybeReadCharBlock_1(&local_20,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfacu));
    Gfx_ReadPaletteRelative(&local_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216df98u));
    MaybeReadScreenBlock(&local_1c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfb0u));
    MaybeReadCharBlock_1(&local_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfacu));
    Gfx_ReadPaletteRelative(&local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216df98u));
    MaybeReadScreenBlock(&local_10,uVar1);
    uVar1 = Mem_AllocateHeap(*(undefined4 *)(*((int *)0x0217d378u) + 0x28),((undefined4)0x00000800u));
    *(undefined4 *)(*((int *)0x0217d378u) + 0x20) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216df94u));
    *(undefined4 *)(*((int *)0x0217d378u) + 4) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfa4u));
    *(undefined4 *)(*((int *)0x0217d378u) + 8) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216df9cu));
    Gfx_ReadCharGraphicsRelative(&local_30,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfa0u));
    func_020b48b4((int *)(uintptr_t)(*((int *)0x0217d378u)),uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfa8u));
    Gfx_ReadPaletteRelative(&local_2c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216df94u));
    *(undefined4 *)(*((int *)0x0217d378u) + 0x10) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfa4u));
    *(undefined4 *)(*((int *)0x0217d378u) + 0x14) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216df9cu));
    Gfx_ReadCharGraphicsRelative(&local_28,uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfa0u));
    func_020b48b4((int *)(uintptr_t)(*((int *)0x0217d378u) + 0xc),uVar1);
    uVar1 = find_buf_fn_from_thumb(*((undefined4 *)0x0216dfa8u));
    Gfx_ReadPaletteRelative(&local_24,uVar1);
    iVar3 = *(int *)(local_2c + 0xc);
    iVar2 = func_020cccb4();
    if ((iVar2 != 0x17) && (iVar2 = func_020cccb4(), iVar2 != 0xb)) {
      AllocateReserveTEQSub(4,0,*(undefined4 *)(local_20 + 0x14),*(undefined4 *)(local_20 + 0x10));
      AllocateReserveTEQSub(0xf,0,*(undefined4 *)(local_18 + 0xc),((undefined4)0x00000140u));
      AllocateReserveTEQSub(8,0,local_1c + 0xc,*(undefined4 *)(local_1c + 8));
      AllocateReserveTEQSub(8,((undefined4)0x00000800u),*(undefined4 *)(*((int *)0x0217d378u) + 0x20),((undefined4)0x00000800u));
    }
    iVar2 = func_020cccb4();
    if ((iVar2 != 0x19) && (iVar2 = func_020cccb4(), iVar2 != 0xd)) {
      AllocateReserveTEQSub
                (0x17,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
      AllocateReserveTEQSub(0x1f,0,*(undefined4 *)(local_c + 0xc),((undefined4)0x00000140u));
      AllocateReserveTEQSub(0x1b,0,local_10 + 0xc,*(undefined4 *)(local_10 + 8));
      AllocateReserveTEQSub(0x1b,((undefined4)0x00000800u),*(undefined4 *)(*((int *)0x0217d378u) + 0x20),((undefined4)0x00000800u));
    }
    AllocateReserveTEQSub(0x13,0,*(undefined4 *)(local_30 + 0x14),*(undefined4 *)(local_30 + 0x10));
    AllocateReserveTEQSub(0xe,0,*(undefined4 *)(local_2c + 0xc),((undefined4)0x000001a0u));
    AllocateReserveTEQSub(0xe,((int)0x000001c0u),iVar3 + ((int)0x000001c0u),0x40);
    AllocateReserveTEQSub(0x23,0,*(undefined4 *)(local_28 + 0x14),*(undefined4 *)(local_28 + 0x10));
    AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(local_24 + 0xc),*(undefined4 *)(local_24 + 8));
  }
  return;
}
