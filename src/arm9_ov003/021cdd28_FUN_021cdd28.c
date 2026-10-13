/* Decompiled C draft; module arm9_ov003; ROM address 021cdd28. No matching claim. */
#include "types.h"
#include "deps/021cdd28_FUN_021cdd28.h"

undefined4 FUN_021cdd28(void)

{
  if (*DAT_021cdd44 == 0) {
    return 1;
  }
  if (*(char *)(*DAT_021cdd44 + 0x18) == '\0') {
    return 1;
  }
  return 0;
}

