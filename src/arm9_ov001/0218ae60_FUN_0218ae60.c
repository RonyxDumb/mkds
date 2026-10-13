/* Decompiled C draft; module arm9_ov001; ROM address 0218ae60. No matching claim. */
#include "types.h"
#include "deps/0218ae60_FUN_0218ae60.h"

void FUN_0218ae60(int param_1)

{
  FUN_02187218(param_1,3,0);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218aedc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218aee0),0);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02187518(param_1,0,0,0,DAT_0218aee4,0);
  FUN_02187518(param_1,0,0,0,DAT_0218aee8,0);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_0218aeec,DAT_0218aef0);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xffdf;
  FUN_02188200(param_1,0);
  return;
}

