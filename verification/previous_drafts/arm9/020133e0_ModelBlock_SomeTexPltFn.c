/* Decompiled C draft; module arm9; ROM address 020133e0. No matching claim. */
#include "types.h"
#include "deps/020133e0_ModelBlock_SomeTexPltFn.h"

void ModelBlock_SomeTexPltFn(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  param_1 = param_1 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar1 = (uint)*(ushort *)(param_1 + 4 + (uint)*(ushort *)(param_1 + 10)) * param_2 +
          param_1 + 4 + (uint)*(ushort *)(param_1 + 10) + 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  param_1 = param_1 + (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  if (param_3 == 0) {
    uVar1 = param_1 + 0xcU & 3;
    uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffff7ff;
  }
  else {
    uVar1 = param_1 + 0xcU & 3;
    uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x800;
  }
  return;
}

