/* Decompiled C draft; module arm9_ov001; ROM address 02190df8. No matching claim. */
#include "types.h"
#include "deps/02190df8_FUN_02190df8.h"

void FUN_02190df8(int param_1)

{
  if (*(int *)(param_1 + 0xa8) == 1) {
    FUN_02187218(param_1,8,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x78),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x7c));
    FUN_02188c90(param_1);
    FUN_02188cec(param_1,0);
    return;
  }
  FUN_02187218(param_1,3,0);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02190e94),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02190e98),DAT_02190e9c);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02192358(param_1);
  FUN_021875c0(param_1,0,DAT_02190ea4,DAT_02190ea8,DAT_02190ea0,0);
  FUN_021875c0(param_1,0,DAT_02190ea4,DAT_02190ea8,DAT_02190eac,0);
  return;
}

