/* Decompiled C draft; module arm9_ov003; ROM address 021bf410. No matching claim. */
#include "types.h"
#include "deps/021bf410_FUN_021bf410.h"

undefined4 FUN_021bf410(void)

{
  if (*DAT_021bf438 == '\0') {
    return 0;
  }
  FUN_021d2168(1);
  *DAT_021bf438 = '\0';
  return 1;
}

