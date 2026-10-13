/* Decompiled C draft; module arm9; ROM address 0209b088. No matching claim. */
#include "types.h"
#include "deps/0209b088_func_0209b088.h"

void func_0209b088(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_58;
  undefined1 auStack_54 [36];
  undefined1 auStack_30 [36];
  
  local_58 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_58),1);
  func_020e6d88((undefined4 *)(uintptr_t)(param_2 + 0x34));
  uVar3 = func_020e6bd0(param_2 + 4);
  func_01ff9048(0x19,uVar3,0xc);
  if (*(ushort *)(param_2 + 0xa2) != 0) {
    iVar1 = (int)(uint)*(ushort *)(param_2 + 0xa2) >> 4;
    MTX_RotZ33__from_thumb
              ((undefined4 *)(void *)(auStack_54),(int)*(short *)(iRam0209b1ec + iVar1 * 4),
               (int)*(short *)(iRam0209b1ec + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_54),9);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar2 = param_2 + 0xa8U & 3;
  uVar4 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  StructMapObject_SetNsbtpFrame
            (*(uint *)(uRam0209b1f0 & 0xfffffffc) >> (uRam0209b1f0 & 3) * 8 |
             *(uint *)(uRam0209b1f0 & 0xfffffffc) << (uRam0209b1f0 & 3) * -8 + 0x20,
             ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) << 4) >> 0x10);
  StructMapObject_SomeFn_9
            (param_1,*(uint *)(uRam0209b1f0 & 0xfffffffc) >> (uRam0209b1f0 & 3) * 8 |
                     *(uint *)(uRam0209b1f0 & 0xfffffffc) << (uRam0209b1f0 & 3) * -8 + 0x20);
  DrawObject2D3D(param_1,*(uint *)(uRam0209b1f0 & 0xfffffffc) >> (uRam0209b1f0 & 3) * 8 |
                         *(uint *)(uRam0209b1f0 & 0xfffffffc) << (uRam0209b1f0 & 3) * -8 + 0x20,
                 param_2);
  uVar2 = param_2 + 0xd4U & 3;
  uVar4 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  iVar1 = (int)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0xffff) >> 4;
  MTX_RotZ33__from_thumb
            ((undefined4 *)(void *)(auStack_30),(int)*(short *)(iRam0209b1ec + iVar1 * 4),
             (int)*(short *)(iRam0209b1ec + (iVar1 * 2 + 1) * 2));
  func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_30),9);
  uVar2 = param_2 + 0xacU & 3;
  uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  StructMapObject_SetNsbtpFrame
            (*(uint *)(uRam0209b1f4 & 0xfffffffc) >> (uRam0209b1f4 & 3) * 8 |
             *(uint *)(uRam0209b1f4 & 0xfffffffc) << (uRam0209b1f4 & 3) * -8 + 0x20,
             ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) << 4) >> 0x10);
  StructMapObject_SomeFn_9
            (param_1,*(uint *)(uRam0209b1f4 & 0xfffffffc) >> (uRam0209b1f4 & 3) * 8 |
                     *(uint *)(uRam0209b1f4 & 0xfffffffc) << (uRam0209b1f4 & 3) * -8 + 0x20);
  DrawObject2D3D(param_1,*(uint *)(uRam0209b1f4 & 0xfffffffc) >> (uRam0209b1f4 & 3) * 8 |
                         *(uint *)(uRam0209b1f4 & 0xfffffffc) << (uRam0209b1f4 & 3) * -8 + 0x20,
                 param_2);
  return;
}

