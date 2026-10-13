/* Decompiled C draft; module arm9_ov000; ROM address 021a911c. No matching claim. */
#include "types.h"
#include "deps/021a911c_FUN_021a911c.h"

void FUN_021a911c(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 4);
  FUN_021a7748(param_1,(int)(uint)*(ushort *)(param_2 + 2) >> 8 |
                       (uint)*(ushort *)(param_2 + 2) << 8 & DAT_021a9160 & 0xffff,
               uVar1 << 0x18 & DAT_021a9164 |
               uVar1 << 8 & DAT_021a9168 | uVar1 >> 0x18 | uVar1 >> 8 & DAT_021a9160);
  return;
}

