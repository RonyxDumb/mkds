/* Decompiled C draft; module arm9; ROM address 020445f8. No matching claim. */
#include "types.h"
#include "deps/020445f8_func_020445f8.h"

void func_020445f8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam02044610 & 0xfffffffc) >> (uRam02044610 & 3) * 8 |
          *(uint *)(uRam02044610 & 0xfffffffc) << (uRam02044610 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0x1e8;
  uVar2 = uVar1 & 3;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc);
  uVar4 = uVar4 + 0x1f0;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x0204460c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02044614)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,
                   uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  return;
}

