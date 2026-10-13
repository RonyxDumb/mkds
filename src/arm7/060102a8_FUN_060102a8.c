/* Decompiled C draft; module arm7; ROM address 060102a8. No matching claim. */
#include "types.h"
#include "deps/060102a8_FUN_060102a8.h"

/* WARNING: Removing unreachable block (ram,0x06010484) */

void FUN_060102a8(void)

{
  uint uVar1;
  
  uVar1 = *(ushort *)
           ((*(uint *)(DAT_06010498 & 0xfffffffc) >> (DAT_06010498 & 3) * 8 |
            *(uint *)(DAT_06010498 & 0xfffffffc) << (DAT_06010498 & 3) * -8 + 0x20) + 0x404) - 0x10;
                    /* WARNING: Could not recover jumptable at 0x060102d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (5 < uVar1) {
    return;
  }
  (*(code *)(uVar1 * 4 + 0x60102dc))();
  return;
}

