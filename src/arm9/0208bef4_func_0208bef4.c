/* Decompiled C draft; module arm9; ROM address 0208bef4. No matching claim. */
#include "types.h"
#include "deps/0208bef4_func_0208bef4.h"

void func_0208bef4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = param_1 + 0x3c & 3;
  uVar2 = *(uint *)(param_1 + 0x3c & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) &&
     (uVar1 = param_1 + 0x40 & 3, uVar2 = *(uint *)(param_1 + 0x40 & 0xfffffffc),
     uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0)) {
    return;
  }
  uVar3 = func_020413a4((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80);
  *(undefined4 *)(param_1 + 0x3c) = uVar3;
  uVar1 = param_1 + 0x3c & 3;
  uVar2 = *(uint *)(param_1 + 0x3c & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  return;
}

