/* Decompiled C draft; module arm9_ov001; ROM address 0218bd80. No matching claim. */
#include "types.h"
#include "deps/0218bd80_FUN_0218bd80.h"

void FUN_0218bd80(int param_1)

{
  FUN_02187218(param_1,7,0);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bdd8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bddc),0);
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218bde0),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bde4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bddc),0);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xffdf;
  return;
}

