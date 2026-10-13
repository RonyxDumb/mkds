/* Decompiled C draft; module arm9_ov001; ROM address 02191550. No matching claim. */
#include "types.h"
#include "deps/02191550_FUN_02191550.h"

void FUN_02191550(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021915ec),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021915f0));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021915f4),DAT_021915f8);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188950(param_1,&local_18);
  FUN_02188200(param_1,DAT_021915fc);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_02191600,DAT_02191604);
  FUN_02187518(param_1,DAT_02191604,0,DAT_0219160c,DAT_02191608,0);
  FUN_02187518(param_1,DAT_02191604,0,DAT_0219160c,DAT_02191610,0);
  func_0x020d2774(param_1,DAT_02191614);
  return;
}

