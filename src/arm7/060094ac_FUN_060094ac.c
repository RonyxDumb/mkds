/* Decompiled C draft; module arm7; ROM address 060094ac. No matching claim. */
#include "types.h"
#include "deps/060094ac_FUN_060094ac.h"

void FUN_060094ac(short *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*param_1 != 0) {
    FUN_060094f8();
    uVar3 = (uint)(param_1 + 4) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar1 = (uint)(param_1 + 6) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    FUN_06015220(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,
                 (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - 0x10);
    uVar3 = *(uint *)(DAT_060094f4 & 0xfffffffc) >> (DAT_060094f4 & 3) * 8 |
            *(uint *)(DAT_060094f4 & 0xfffffffc) << (DAT_060094f4 & 3) * -8 + 0x20;
    *(short *)(uVar3 + 0x3fc) = *(short *)(uVar3 + 0x3fc) + 1;
  }
  return;
}

