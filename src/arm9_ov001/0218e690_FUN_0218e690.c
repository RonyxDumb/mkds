/* Decompiled C draft; module arm9_ov001; ROM address 0218e690. No matching claim. */
#include "types.h"
#include "deps/0218e690_FUN_0218e690.h"

void FUN_0218e690(int param_1)

{
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x70),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x74));
  func_0x0208b7bc(DAT_0218e6f4,param_1 + 4);
  func_0x0208b7bc(DAT_0218e6f8,param_1 + 4);
  if (*DAT_0218e6fc != 7) {
    *DAT_0218e700 = *DAT_0218e6fc;
  }
  *DAT_0218e6fc = 7;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218e704;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218e708;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218e70c;
  return;
}

