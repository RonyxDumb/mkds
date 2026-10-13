/* Decompiled C draft; module arm9_ov001; ROM address 0218ead0. No matching claim. */
#include "types.h"
#include "deps/0218ead0_FUN_0218ead0.h"

void FUN_0218ead0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  FUN_02187218(param_1,5,DAT_0218eb6c);
  FUN_0218f850(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218eb70),DAT_0218eb74);
  FUN_02182a3c(0);
  FUN_02187e48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218eb78));
  iVar1 = *(int *)(param_1 + 0xa8);
  if (iVar1 == 1) {
    uVar4 = 2;
  }
  else if (iVar1 == 2) {
    uVar4 = 3;
  }
  else if (iVar1 == 3) {
    uVar4 = 3;
  }
  else {
    uVar4 = 1;
  }
  *(undefined4 *)(param_1 + 0xa8) = uVar4;
  if (*DAT_0218eb7c != 3) {
    *DAT_0218eb80 = *DAT_0218eb7c;
  }
  *DAT_0218eb7c = 3;
  puVar2 = (undefined4 *)(param_1 + DAT_0218eb84);
  *puVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc);
  puVar3 = (undefined4 *)(param_1 + DAT_0218eb88);
  *puVar3 = *puVar2;
  puVar2 = (undefined4 *)(param_1 + DAT_0218eb8c);
  *puVar2 = *puVar3;
  *(undefined4 *)(param_1 + DAT_0218eb90) = *puVar2;
  return;
}

