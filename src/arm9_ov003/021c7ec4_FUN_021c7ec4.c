/* Decompiled C draft; module arm9_ov003; ROM address 021c7ec4. No matching claim. */
#include "types.h"
#include "deps/021c7ec4_FUN_021c7ec4.h"

void FUN_021c7ec4(void)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(DAT_021c7ee0 + (*DAT_021c7edc - 0xb));
                    /* WARNING: Could not recover jumptable at 0x021c7ed8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_021c7ee8)(*(undefined4 *)(*DAT_021c7ee4 + 0x10),uVar1,uVar1);
  return;
}

