/* Decompiled C draft; module arm9_ov001; ROM address 02190fc4. No matching claim. */
#include "types.h"
#include "deps/02190fc4_FUN_02190fc4.h"

void FUN_02190fc4(int param_1)

{
  FUN_02187218(param_1,7,DAT_02191018);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0219101c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02191020),DAT_02191024);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  *(undefined4 *)(param_1 + DAT_02191028) = 1;
  FUN_0219226c(param_1);
  FUN_02188200(param_1,DAT_0219102c);
  func_0x020d2774(param_1,DAT_02191030);
  return;
}

