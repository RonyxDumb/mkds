/* Decompiled C draft; module arm9_ov003; ROM address 021bf2f0. No matching claim. */
#include "types.h"
#include "deps/021bf2f0_FUN_021bf2f0.h"

undefined4 FUN_021bf2f0(void)

{
  if (*DAT_021bf30c == 0) {
    return 1;
  }
  if (*(char *)(*DAT_021bf30c + 0x19) == '\0') {
    return 1;
  }
  return 0;
}

