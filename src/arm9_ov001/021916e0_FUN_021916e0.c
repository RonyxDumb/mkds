/* Decompiled C draft; module arm9_ov001; ROM address 021916e0. No matching claim. */
#include "types.h"
#include "deps/021916e0_FUN_021916e0.h"

void FUN_021916e0(int param_1)

{
  func_0x0207a974((short)*(char *)(*DAT_02191790 + 0x62));
  if ((*(ushort *)(param_1 + 2) & DAT_02191794) == 0) {
    *(int *)(param_1 + DAT_021917a0) = *(int *)(param_1 + DAT_02191798) + DAT_0219179c;
  }
  else {
    *(int *)(param_1 + DAT_021917a0) = *(int *)(param_1 + DAT_02191798) - DAT_0219179c;
  }
  FUN_02187218(param_1,3,DAT_021917a4);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021917a8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021917ac));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021917b0),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021917b4));
  FUN_021889c8(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021917b8),DAT_021917bc);
  FUN_02188200(param_1,DAT_021917c0);
  FUN_021875c0(param_1,DAT_021917c8,0,DAT_021917cc,DAT_021917c4,0);
  return;
}

