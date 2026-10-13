/* Decompiled C draft; module arm9_ov001; ROM address 0218355c. No matching claim. */
#include "types.h"
#include "deps/0218355c_FUN_0218355c.h"

void FUN_0218355c(ushort *param_1)

{
  FUN_02187218((int)(uintptr_t)(param_1),8,DAT_021835ac);
  if (*param_1 == DAT_021835b0) {
    FUN_02188d64((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x58),
                 *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x5c));
    FUN_02188e24((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x60),DAT_021835b4);
    return;
  }
  FUN_02188d30((int)(uintptr_t)(param_1),*(undefined4 *)(*(int *)(param_1 + 0x50) + 0x58),
               *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x5c),DAT_021835b4);
  return;
}

