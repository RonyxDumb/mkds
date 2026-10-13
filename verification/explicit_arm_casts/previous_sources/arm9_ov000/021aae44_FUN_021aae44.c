/* Decompiled C draft; module arm9_ov000; ROM address 021aae44. No matching claim. */
#include "types.h"
#include "deps/021aae44_FUN_021aae44.h"

uint FUN_021aae44(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = DAT_021aaf10;
  if (*(char *)(param_1 + DAT_021aaf0c) != '\0') {
    uVar2 = 0;
  }
  if (*(int *)(param_1 + DAT_021aaf14) == -1) {
    return uVar2 | 4;
  }
  if (*(int *)(param_1 + DAT_021aaf18) == 3) {
    iVar3 = param_1 + DAT_021aaf1c;
    FUN_021ab7b4(iVar3);
    FUN_021ab728(iVar3,*(int *)(param_1 + DAT_021aaf20),
                 *(int *)(param_1 + DAT_021aaf24) - *(int *)(param_1 + DAT_021aaf20));
    FUN_021ab6d4(iVar3,param_1 + DAT_021aaf28);
    *(undefined4 *)(param_1 + DAT_021aaf2c) = 0x10;
  }
  else {
    if (*(int *)(param_1 + DAT_021aaf18) != 4) {
      return uVar2 | 3;
    }
    iVar3 = param_1 + DAT_021aaf30;
    FUN_021abd2c(iVar3);
    FUN_021abca0(iVar3,*(int *)(param_1 + DAT_021aaf20),
                 *(int *)(param_1 + DAT_021aaf24) - *(int *)(param_1 + DAT_021aaf20));
    FUN_021abc4c(iVar3,param_1 + DAT_021aaf28);
    *(undefined4 *)(param_1 + DAT_021aaf2c) = 0x14;
  }
  iVar3 = FUN_021ab548(param_1,param_1 + DAT_021aaf34);
  if (iVar3 != 0) {
    uVar1 = FUN_021aaf38(param_1);
    return uVar2 | uVar1;
  }
  return uVar2 | 1;
}

