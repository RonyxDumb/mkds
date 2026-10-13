/* Decompiled C draft; module arm9_ov000; ROM address 021a104c. No matching claim. */
#include "types.h"
#include "deps/021a104c_FUN_021a104c.h"

void FUN_021a104c(void)

{
  if (*DAT_021a10a4 != 0) {
    if (*(int *)(*DAT_021a10a4 + 0xe4) != 0) {
      FUN_0218b64c();
      *(undefined4 *)(*DAT_021a10a4 + 0xe4) = 0;
    }
    FUN_0219b110();
    *(undefined4 *)(*DAT_021a10a4 + DAT_021a10a8) = 0;
    if (*DAT_021a10ac != 0) {
      FUN_021a3704(4);
      *DAT_021a10ac = 0;
    }
    FUN_0219ea88();
    *(undefined1 *)(*DAT_021a10a4 + 0x18) = 1;
  }
  return;
}

