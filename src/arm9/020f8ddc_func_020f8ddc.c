/* Decompiled C draft; module arm9; ROM address 020f8ddc. No matching claim. */
#include "types.h"
#include "deps/020f8ddc_func_020f8ddc.h"

void func_020f8ddc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return;
  }
  uVar1 = (*(uint *)(uRam020f8e34 & 0xfffffffc) >> (uRam020f8e34 & 3) * 8 |
          *(uint *)(uRam020f8e34 & 0xfffffffc) << (uRam020f8e34 & 3) * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 4) {
    uVar1 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 2) {
      func_0208b7bc(uRam020f8e38,param_1 + 0x50);
      func_0208b7bc(0x440,param_1 + 0x50);
      return;
    }
    return;
  }
  return;
}

