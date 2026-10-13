/* Decompiled C draft; module arm9_ov000; ROM address 021a8e78. No matching claim. */
#include "types.h"
#include "deps/021a8e78_FUN_021a8e78.h"

void FUN_021a8e78(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  uVar1 = *param_1;
  FUN_021a8878(uVar1 << 0x18 & DAT_021a8ec8 |
               uVar1 << 8 & DAT_021a8ecc | uVar1 >> 0x18 | uVar1 >> 8 & DAT_021a8ed0,
               uVar2 << 0x18 & DAT_021a8ec8 |
               uVar2 << 8 & DAT_021a8ecc | uVar2 >> 0x18 | uVar2 >> 8 & DAT_021a8ed0);
  return;
}

