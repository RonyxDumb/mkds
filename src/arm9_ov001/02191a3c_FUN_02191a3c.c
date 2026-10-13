/* Decompiled C draft; module arm9_ov001; ROM address 02191a3c. No matching claim. */
#include "types.h"
#include "deps/02191a3c_FUN_02191a3c.h"

void FUN_02191a3c(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_10 = 0;
  local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191ab8);
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191abc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191ac0));
  FUN_02188950(param_1,&local_18);
  FUN_02188b78(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191ac4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191ac8));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191acc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191ad0));
  FUN_02188db8(param_1,DAT_02191ad4);
  *(undefined4 *)(param_1 + DAT_02191ad8) = 1;
  return;
}

