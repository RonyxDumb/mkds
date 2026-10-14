/* Decompiled C draft; module arm9; ROM address 0209c7a8. No matching claim. */
#include "types.h"
#include "deps/0209c7a8_func_0209c7a8.h"

void func_0209c7a8(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_20 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_20),1);
  uVar1 = param_2 + 4U & 3;
  uVar2 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar2 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  func_01ff9048(0x19,param_2 + 0x28,0xc);
  uVar1 = param_2 + 0x11cU & 3;
  uVar2 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
    uVar1 = param_2 + 0xbcU & 3;
    uVar2 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    local_1c = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = param_2 + 0xdcU & 3;
    uVar2 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    local_18 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    local_14 = local_1c;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_1c),3);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_SetNsbtpFrame
            (*(uint *)(uRam0209c874 & 0xfffffffc) >> (uRam0209c874 & 3) * 8 |
             *(uint *)(uRam0209c874 & 0xfffffffc) << (uRam0209c874 & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  DrawObject2D3D(param_1,*(uint *)(uRam0209c874 & 0xfffffffc) >> (uRam0209c874 & 3) * 8 |
                         *(uint *)(uRam0209c874 & 0xfffffffc) << (uRam0209c874 & 3) * -8 + 0x20,
                 param_2);
  return;
}

