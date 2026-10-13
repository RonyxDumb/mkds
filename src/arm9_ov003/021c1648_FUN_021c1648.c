/* Decompiled C draft; module arm9_ov003; ROM address 021c1648. No matching claim. */
#include "types.h"
#include "deps/021c1648_FUN_021c1648.h"

void FUN_021c1648(int param_1)

{
  if (param_1 != *(char *)(*DAT_021c167c + 0x62)) {
    FUN_021c12cc(param_1,1);
    FUN_021c12cc((int)*(char *)(*DAT_021c167c + 0x62),0);
    *(char *)(*DAT_021c167c + 0x62) = (char)param_1;
  }
  return;
}

