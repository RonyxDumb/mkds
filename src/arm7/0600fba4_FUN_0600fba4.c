/* Decompiled C draft; module arm7; ROM address 0600fba4. No matching claim. */
#include "types.h"
#include "deps/0600fba4_FUN_0600fba4.h"

void FUN_0600fba4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(DAT_0600fe18 & 0xfffffffc) >> (DAT_0600fe18 & 3) * 8 |
          *(uint *)(DAT_0600fe18 & 0xfffffffc) << (DAT_0600fe18 & 3) * -8 + 0x20;
  uVar1 = *(ushort *)(uVar2 + 0x404) - 0x80;
                    /* WARNING: Could not recover jumptable at 0x0600fbd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (uVar1 < 5) {
    (*(code *)(uVar1 * 4 + 0x600fbd8))();
    return;
  }
  if (*(short *)(uVar2 + DAT_0600fe1c) != 0) {
    FUN_06008a8c(2,5);
  }
  return;
}

