/* Decompiled C draft; module arm9_ov001; ROM address 0218e5c4. No matching claim. */
#include "types.h"
#include "deps/0218e5c4_FUN_0218e5c4.h"

void FUN_0218e5c4(int param_1)

{
  undefined4 *puVar1;
  
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 0xa0) + 0x80);
  puVar1 = (undefined4 *)(param_1 + DAT_0218e634);
  *puVar1 = DAT_0218e630;
  *(undefined4 *)(param_1 + DAT_0218e638) = *puVar1;
  *(undefined4 *)(param_1 + DAT_0218e63c) = 0;
  FUN_02187218(param_1,8,DAT_0218e640);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x70),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x74));
  FUN_02188e24(param_1,0x3c,DAT_0218e644);
  if (*DAT_0218e648 != 7) {
    *DAT_0218e64c = *DAT_0218e648;
  }
  *DAT_0218e648 = 7;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  return;
}

