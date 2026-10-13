/* Decompiled C draft; module arm9_ov003; ROM address 021d11a0. No matching claim. */
#include "types.h"
#include "deps/021d11a0_FUN_021d11a0.h"

undefined4 FUN_021d11a0(void)

{
  if (*(char *)(*DAT_021d11cc + DAT_021d11d0) == '\x05') {
    *(char *)(*DAT_021d11cc + DAT_021d11d0) = '\x06';
    FUN_021cf69c();
    return 1;
  }
  return 0;
}

