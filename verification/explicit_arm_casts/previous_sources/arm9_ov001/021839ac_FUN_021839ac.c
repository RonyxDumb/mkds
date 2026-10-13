/* Decompiled C draft; module arm9_ov001; ROM address 021839ac. No matching claim. */
#include "types.h"
#include "deps/021839ac_FUN_021839ac.h"

void FUN_021839ac(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_021881a8(param_1,*(undefined4 *)(param_1 + 0x9c),
                       *(int *)(*(int *)(param_1 + 0xa0) + DAT_02183ab4) + 0x28,0);
  if (iVar1 == 0) {
    FUN_02187218(param_1,3,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ab8),
                 *(int *)(*(int *)(param_1 + 0xa0) + DAT_02183abc) << 2);
    FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ac0),DAT_02183ac4);
    FUN_02188998(param_1,*(undefined4 *)(param_1 + 0x9c));
    FUN_02188cd8(param_1,-*(int *)(*(int *)(param_1 + 0xa0) + DAT_02183ac8),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183acc));
    FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ad0),0);
    FUN_02188200(param_1,DAT_02183ad4);
  }
  else {
    FUN_02187218(param_1,3,0);
    FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ab8),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183abc));
    FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ac0),DAT_02183ac4);
    FUN_02188998(param_1,*(undefined4 *)(param_1 + 0x9c));
    FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ac8),
                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183acc));
    FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_02183ad0),0);
    FUN_02188200(param_1,DAT_02183ad4);
  }
  FUN_02184e6c(param_1);
  return;
}

