/* Decompiled C draft; module arm9_ov001; ROM address 02191adc. No matching claim. */
#include "types.h"
#include "deps/02191adc_FUN_02191adc.h"

void FUN_02191adc(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191b34),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191b38));
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188950(param_1,&local_18);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191b3c),0);
  return;
}

