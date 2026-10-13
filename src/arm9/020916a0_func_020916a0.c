/* Decompiled C draft; module arm9; ROM address 020916a0. No matching claim. */
#include "types.h"
#include "deps/020916a0_func_020916a0.h"

void func_020916a0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_40;
  undefined1 auStack_3c [36];
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  local_40 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_40),1);
  uVar3 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar3,0xc);
  uVar2 = param_2 + 0xb8U & 3;
  uVar4 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
  local_14 = (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) >> 4;
  local_18 = 0;
  local_10 = 0;
  func_01ff9048(0x1c,(undefined4)(uintptr_t)(&local_18),3);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar2 = param_2 + 0xa4U & 3;
  uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  iVar1 = (int)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0xffff) >> 4;
  MTX_RotZ33__from_thumb
            ((undefined4 *)(void *)(auStack_3c),(int)*(short *)(iRam0209177c + iVar1 * 4),
             (int)*(short *)(iRam0209177c + (iVar1 * 2 + 1) * 2));
  func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_3c),9);
  DrawObject2D3D(param_1,*(uint *)(uRam02091780 & 0xfffffffc) >> (uRam02091780 & 3) * 8 |
                         *(uint *)(uRam02091780 & 0xfffffffc) << (uRam02091780 & 3) * -8 + 0x20,
                 param_2);
  return;
}

