/* Decompiled C draft; module arm9; ROM address 0208c050. No matching claim. */
#include "types.h"
#include "deps/0208c050_func_0208c050.h"

void func_0208c050(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = param_1 + 0x1c & 3;
  uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) &&
     (uVar1 = param_1 + 0x20 & 3, uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc),
     uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0)) {
    return;
  }
  uVar3 = func_02041588((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80);
  *(undefined4 *)(param_1 + 0x1c) = uVar3;
  uVar1 = param_1 + 0x1c & 3;
  uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return;
}

