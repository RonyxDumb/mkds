/* Decompiled C draft; module arm9; ROM address 02018674. No matching claim. */
#include "types.h"
#include "deps/02018674_func_02018674.h"

void func_02018674(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  *puRam02018738 = *puRam02018738 & 0xcfff | 8;
  *(undefined4 *)(param_1 + 0x44) = param_2;
  uVar3 = param_1 + 0x38U & 3;
  uVar1 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if (-1 < (int)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) << 7)) {
    uVar3 = param_1 + 4U & 3;
    uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    if (uVar3 != 0) {
      do {
        *(uint *)(param_1 + 0x40) = uVar3;
        uVar1 = uVar3 + 0x24 & 3;
        uVar2 = *(uint *)(uVar3 + 0x24 & 0xfffffffc);
        if (-1 < (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1c)) {
          func_02019090(param_1);
        }
        uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      } while (uVar3 != 0);
      return;
    }
    return;
  }
  uVar3 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    do {
      *(uint *)(param_1 + 0x40) = uVar3;
      uVar1 = uVar3 + 0x24 & 3;
      uVar2 = *(uint *)(uVar3 + 0x24 & 0xfffffffc);
      if (-1 < (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1c)) {
        func_02019090(param_1);
      }
      uVar1 = uVar3 + 4 & 3;
      uVar3 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    } while (uVar3 != 0);
    return;
  }
  return;
}

