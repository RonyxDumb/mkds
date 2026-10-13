/* Decompiled C draft; module arm9_ov001; ROM address 0218ef30. No matching claim. */
#include "types.h"
#include "deps/0218ef30_FUN_0218ef30.h"

void FUN_0218ef30(int param_1)

{
  func_0x0207a974((short)*(char *)(*DAT_0218efb0 + 0x62));
  FUN_02187218(param_1,3,DAT_0218efb4);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x90),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x94));
  FUN_02188cec(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa0));
  FUN_02188adc(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb0),DAT_0218efb8,
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xa8),DAT_0218efb8,0);
  if (*DAT_0218efbc != 0) {
    *DAT_0218efc0 = *DAT_0218efbc;
  }
  *DAT_0218efbc = 0;
  return;
}

