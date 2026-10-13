/* Decompiled C draft; module arm9_ov001; ROM address 0218c490. No matching claim. */
#include "types.h"
#include "deps/0218c490_FUN_0218c490.h"

void FUN_0218c490(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218c530 + 0x62));
  FUN_02187218(param_1,2,DAT_0218c534);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c538),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c53c));
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218c540),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c544),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c53c),0);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c548),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c54c));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c550),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c554));
  FUN_02188998(param_1,iVar1 + 0x80);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c558),0);
  FUN_0218c5fc(param_1);
  return;
}

