/* Decompiled C draft; module arm7; ROM address 060001dc. No matching claim. */
#include "types.h"
#include "deps/060001dc_FUN_060001dc.h"

void FUN_060001dc(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    uVar1 = uVar1 + *(byte *)(DAT_06000210 + iVar2 + 0x1550);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
                    /* WARNING: Could not recover jumptable at 0x0600020c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_06000214)(uVar1 >> 4);
  return;
}

