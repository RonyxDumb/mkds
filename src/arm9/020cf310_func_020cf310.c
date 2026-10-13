/* Decompiled C draft; module arm9; ROM address 020cf310. No matching claim. */
#include "types.h"
#include "deps/020cf310_func_020cf310.h"

void func_020cf310(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(uRam020cf334 & 0xfffffffc) >> (uRam020cf334 & 3) * 8 |
          *(uint *)(uRam020cf334 & 0xfffffffc) << (uRam020cf334 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x354;
  uVar2 = uVar1 & 3;
  uVar4 = *(uint *)(uVar1 & 0xfffffffc);
  uVar3 = uVar3 + 0x5f4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020cf330. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cf338)(uRam020cf33c,
                   (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
                   (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20));
  return;
}

