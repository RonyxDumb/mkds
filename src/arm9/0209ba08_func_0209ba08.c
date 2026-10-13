/* Decompiled C draft; module arm9; ROM address 0209ba08. No matching claim. */
#include "types.h"
#include "deps/0209ba08_func_0209ba08.h"

void func_0209ba08(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar2 = uVar3 + 0x14 & 3;
    uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
    *(uint *)(uVar3 + 0x14) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xfffffff0;
    uVar2 = uVar3 + 0x14 & 3;
    uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
    *(uint *)(uVar3 + 0x14) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | param_2;
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    StructML_SomeFn_8();
    return;
  }
  return;
}

