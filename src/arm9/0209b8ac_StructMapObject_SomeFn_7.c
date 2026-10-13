/* Decompiled C draft; module arm9; ROM address 0209b8ac. No matching claim. */
#include "types.h"
#include "deps/0209b8ac_StructMapObject_SomeFn_7.h"

void StructMapObject_SomeFn_7(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    if (param_2 == 0) {
      uVar2 = uVar3 + 0x14 & 3;
      uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
      *(uint *)(uVar3 + 0x14) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffff7fff;
    }
    else {
      uVar2 = uVar3 + 0x14 & 3;
      uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
      *(uint *)(uVar3 + 0x14) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x8000;
    }
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar3 = uVar3 + 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Maybe_helper_013044(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    return;
  }
  return;
}

