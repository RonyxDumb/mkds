/* Decompiled C draft; module arm9_ov003; ROM address 021d07b0. No matching claim. */
#include "types.h"
#include "deps/021d07b0_FUN_021d07b0.h"

void FUN_021d07b0(undefined4 param_1)

{
  int *piVar1;
  
  if ((code *)*DAT_021d07f8 != (code *)0x0) {
    (*(code *)*DAT_021d07f8)
              (DAT_021d07fc,DAT_021d0800,
               *(undefined4 *)(DAT_021d0808 + *(int *)(*DAT_021d0804 + 0x40) * 4));
  }
  piVar1 = DAT_021d0804;
  *(undefined4 *)(*DAT_021d0804 + 0x40) = param_1;
  if ((code *)*DAT_021d07f8 != (code *)0x0) {
    (*(code *)*DAT_021d07f8)
              (DAT_021d07fc,DAT_021d080c,
               *(undefined4 *)(DAT_021d0808 + *(int *)(*piVar1 + 0x40) * 4));
  }
  return;
}

