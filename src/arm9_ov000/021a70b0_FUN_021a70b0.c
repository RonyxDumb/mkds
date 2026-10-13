/* Decompiled C draft; module arm9_ov000; ROM address 021a70b0. No matching claim. */
#include "types.h"
#include "deps/021a70b0_FUN_021a70b0.h"

undefined4 FUN_021a70b0(void)

{
  if (*(int *)(DAT_021a70e0 + 0x1c) < *(int *)(DAT_021a70e0 + 0x14)) {
    return 0xffffffff;
  }
  (**(code **)(*DAT_021a70e8 + 0x1c))(*DAT_021a70e4);
  *DAT_021a70e4 = 0;
  return 0;
}

