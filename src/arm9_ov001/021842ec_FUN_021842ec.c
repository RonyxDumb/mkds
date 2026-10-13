/* Decompiled C draft; module arm9_ov001; ROM address 021842ec. No matching claim. */
#include "types.h"
#include "deps/021842ec_FUN_021842ec.h"

void FUN_021842ec(int param_1)

{
  FUN_02187218(param_1,7,0);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184370),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02184374),0);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02187518(param_1,0,0,0,DAT_02184378,0);
  FUN_02187518(param_1,0,0,0,DAT_0218437c,0);
  func_0x020d2774(param_1,DAT_02184380);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_02184384,DAT_02184388);
  FUN_02188200(param_1,DAT_0218438c);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xffdf;
  return;
}

