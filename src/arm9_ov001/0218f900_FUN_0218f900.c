/* Decompiled C draft; module arm9_ov001; ROM address 0218f900. No matching claim. */
#include "types.h"
#include "deps/0218f900_FUN_0218f900.h"

void FUN_0218f900(int param_1)

{
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f988),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f98c));
  FUN_02188d1c(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f990),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218f994));
  FUN_02188cec(param_1,0);
  FUN_02188c90(param_1);
  FUN_021875c0(param_1,0,0,0,DAT_0218f998,0);
  FUN_021875c0(param_1,0,0,0,DAT_0218f99c,0);
  FUN_021875c0(param_1,0,0,0,DAT_0218f9a0,0);
  func_0x020d2774(param_1,DAT_0218f9a4);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  return;
}

