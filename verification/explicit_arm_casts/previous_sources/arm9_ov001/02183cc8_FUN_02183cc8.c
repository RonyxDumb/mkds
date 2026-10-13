/* Decompiled C draft; module arm9_ov001; ROM address 02183cc8. No matching claim. */
#include "types.h"
#include "deps/02183cc8_FUN_02183cc8.h"

void FUN_02183cc8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02183d6c + 0x62));
  FUN_02187218(param_1,2,DAT_02183d70);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183d74),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183d78));
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183d7c);
  FUN_02188c48(param_1,uVar2,uVar2);
  FUN_02188998(param_1,iVar1 + 0x80);
  FUN_021889c8(param_1);
  FUN_02188cd8(param_1,0,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183d80));
  FUN_02188dcc(param_1,DAT_02183d84);
  FUN_02188200(param_1,DAT_02183d88);
  if (*(int *)(param_1 + DAT_02183d8c) < *(int *)(*(int *)(param_1 + 0xa0) + DAT_02183d80)) {
    FUN_02188200(param_1,DAT_02183d90);
  }
  FUN_02184e18(param_1);
  return;
}

