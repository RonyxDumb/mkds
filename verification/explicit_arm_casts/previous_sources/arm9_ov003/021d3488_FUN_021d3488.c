/* Decompiled C draft; module arm9_ov003; ROM address 021d3488. No matching claim. */
#include "types.h"
#include "deps/021d3488_FUN_021d3488.h"

void FUN_021d3488(int param_1,int param_2)

{
  if (*(char *)(param_2 + 0x11) != '\0') {
    FUN_021d2808(param_2 + 0xc);
  }
  FUN_021d2e90(param_2);
  FUN_021d1d0c(*(undefined4 *)(*DAT_021d34bc + param_1 * 0x3c),param_2);
  return;
}

