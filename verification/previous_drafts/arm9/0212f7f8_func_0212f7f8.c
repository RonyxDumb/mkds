/* Decompiled C draft; module arm9; ROM address 0212f7f8. No matching claim. */
#include "types.h"
#include "deps/0212f7f8_func_0212f7f8.h"

uint func_0212f7f8(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar5 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar1 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    iVar2 = _s32_div_f(uVar5 * ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - uVar4));
    return uVar4 + iVar2;
  }
  uVar1 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  return uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
}

