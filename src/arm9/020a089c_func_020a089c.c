/* Decompiled C draft; module arm9; ROM address 020a089c. No matching claim. */
#include "types.h"
#include "deps/020a089c_func_020a089c.h"

void func_020a089c(int param_1,undefined4 param_2,undefined2 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(uRam020a08d8 & 0xfffffffc) >> (uRam020a08d8 & 3) * 8 |
          *(uint *)(uRam020a08d8 & 0xfffffffc) << (uRam020a08d8 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0x12) {
    uVar1 = uVar2;
    if (uVar2 == 0x1f) {
      param_3 = (undefined2)uRam020a08e0;
      uVar1 = uRam020a08e4;
    }
    if (uVar2 == 0x1f) {
      *(undefined2 *)(param_1 + 0xbc) = param_3;
      *(short *)(param_1 + 0xbe) = (short)uVar1;
    }
    else {
      *(short *)(param_1 + 0xbc) = (short)uRam020a08e8;
    }
    return;
  }
  *(short *)(param_1 + 0xbc) = (short)uRam020a08dc;
  return;
}

