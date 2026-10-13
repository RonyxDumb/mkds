/* Decompiled C draft; module arm9_ov001; ROM address 02191258. No matching claim. */
#include "types.h"
#include "deps/02191258_FUN_02191258.h"

void FUN_02191258(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021912f4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021912f8));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021912fc),0);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188950(param_1,&local_18);
  FUN_02188200(param_1,DAT_02191300);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_02191304,DAT_02191308);
  FUN_02187518(param_1,DAT_02191308,0,DAT_02191310,DAT_0219130c,0);
  FUN_02187518(param_1,DAT_02191308,0,DAT_02191310,DAT_02191314,0);
  func_0x020d2774(param_1,DAT_021912fc);
  return;
}

