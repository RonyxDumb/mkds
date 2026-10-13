/* Decompiled C draft; module arm9; ROM address 020d9e60. No matching claim. */
#include "types.h"
#include "deps/020d9e60_func_020d9e60.h"

void func_020d9e60(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((*(ushort *)
        ((*(uint *)(uRam020d9f88 & 0xfffffffc) >> (uRam020d9f88 & 3) * 8 |
         *(uint *)(uRam020d9f88 & 0xfffffffc) << (uRam020d9f88 & 3) * -8 + 0x20) + 2) & 0x12) != 0)
  {
    return;
  }
  uVar1 = param_1 + 0x54 & 3;
  uVar2 = *(uint *)(param_1 + 0x54 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0xc & 3;
    uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    *(int *)(param_1 + 0x164) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    uVar1 = param_1 + 0x10 & 3;
    uVar2 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
    *(int *)(param_1 + 0x168) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    uVar1 = param_1 + 0x14 & 3;
    uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    *(int *)(param_1 + 0x16c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    func_020849f8(param_1 + 0xd4,param_1 + 0x140,0);
    uVar1 = param_1 + 0x60 & 3;
    uVar2 = *(uint *)(param_1 + 0x60 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      *(int *)(param_1 + 0x164) =
           (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) >> 4;
      uVar1 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(int *)(param_1 + 0x168) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
      uVar1 = param_1 + 8 & 3;
      uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
      *(int *)(param_1 + 0x16c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
      func_020849f8(param_1 + 0x68,param_1 + 0x140,0);
      return;
    }
    return;
  }
  uVar1 = param_1 + 0x60 & 3;
  uVar2 = *(uint *)(param_1 + 0x60 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    *(int *)(param_1 + 0x164) =
         (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) >> 4;
    uVar1 = param_1 + 4 & 3;
    uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
    *(int *)(param_1 + 0x168) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    uVar1 = param_1 + 8 & 3;
    uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
    *(int *)(param_1 + 0x16c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
    func_020849f8(param_1 + 0x68,param_1 + 0x140,0);
  }
  uVar1 = param_1 + 0xc & 3;
  uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  *(int *)(param_1 + 0x164) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_1 + 0x10 & 3;
  uVar2 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  *(int *)(param_1 + 0x168) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_1 + 0x14 & 3;
  uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  *(int *)(param_1 + 0x16c) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  func_020849f8(param_1 + 0xd4,param_1 + 0x140,0);
  return;
}

