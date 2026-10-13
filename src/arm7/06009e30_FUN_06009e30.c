/* Decompiled C draft; module arm7; ROM address 06009e30. No matching claim. */
#include "types.h"
#include "deps/06009e30_FUN_06009e30.h"

void FUN_06009e30(undefined4 param_1)

{
  *DAT_06009e4c = (short)param_1;
  *DAT_06009e50 = (short)((uint)param_1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x06009e48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_06009e54)();
  return;
}

