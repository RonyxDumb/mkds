/* Decompiled C draft; module arm9_ov003; ROM address 021c04ec. No matching claim. */
#include "types.h"
#include "deps/021c04ec_FUN_021c04ec.h"

void FUN_021c04ec(int param_1)

{
  if (param_1 != *(char *)(*DAT_021c0520 + DAT_021c0524)) {
    FUN_021c0050(param_1,1);
    FUN_021c0050((int)*(char *)(*DAT_021c0520 + DAT_021c0524),0);
    *(char *)(*DAT_021c0520 + DAT_021c0524) = (char)param_1;
  }
  return;
}

