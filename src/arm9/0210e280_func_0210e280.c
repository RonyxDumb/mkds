/* Decompiled C draft; module arm9; ROM address 0210e280. No matching claim. */
#include "types.h"
#include "deps/0210e280_func_0210e280.h"

void func_0210e280(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar3;
  
  uVar3 = param_1 + 0xc & 3;
  uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar4 = 0;
  if (0 < (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)) {
    do {
      iVar4 = iVar4 + 1;
      if (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 != 0 ||
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20 != 0) {
        uVar2 = uVar3 + 4 & 3;
        uVar1 = *(uint *)(uVar3 + 4 & 0xfffffffc);
        *(uint *)(uVar3 + 4) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1;
      }
      uVar2 = param_1 + 0x10 & 3;
      uVar1 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      uVar3 = uVar3 + (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    } while (iVar4 < (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20));
    return;
  }
  return;
}

