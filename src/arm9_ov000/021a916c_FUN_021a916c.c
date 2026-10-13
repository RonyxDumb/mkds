/* Decompiled C draft; module arm9_ov000; ROM address 021a916c. No matching claim. */
#include "types.h"
#include "deps/021a916c_FUN_021a916c.h"

void FUN_021a916c(undefined4 param_1,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x021a9182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_021a9188)(param_1,(int)(uint)*(ushort *)(param_2 + 2) >> 8 |
                          (uint)*(ushort *)(param_2 + 2) << 8 & DAT_021a9184 & 0xffff);
  return;
}

