/* Decompiled C draft; module arm9; ROM address 020a018c. No matching claim. */
#include "types.h"
#include "deps/020a018c_func_020a018c.h"

void func_020a018c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_40;
  undefined1 auStack_3c [36];
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  local_40 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_40),1);
  uVar2 = param_2 + 0xa0U & 3;
  uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar3 = param_2 + 0xacU & 3;
  uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  local_14 = (int)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
                  (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20)) >> 4;
  local_18 = 0;
  local_10 = 0;
  func_01ff9048(0x1c,(undefined4)(uintptr_t)(&local_18),3);
  uVar2 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
  func_01ff9048(0x19,param_2 + 0x28,0xc);
  if (*(ushort *)(param_2 + 0x7e) != 0) {
    iVar1 = (int)(uint)*(ushort *)(param_2 + 0x7e) >> 4;
    MTX_RotY33__from_thumb
              ((undefined4 *)(void *)(auStack_3c),(int)*(short *)(iRam020a028c + iVar1 * 4),
               (int)*(short *)(iRam020a028c + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_3c),9);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  DrawObject2D3D(param_1,*(uint *)(uRam020a0290 & 0xfffffffc) >> (uRam020a0290 & 3) * 8 |
                         *(uint *)(uRam020a0290 & 0xfffffffc) << (uRam020a0290 & 3) * -8 + 0x20,
                 param_2);
  return;
}

