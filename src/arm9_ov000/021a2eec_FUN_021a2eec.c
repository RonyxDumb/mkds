/* Decompiled C draft; module arm9_ov000; ROM address 021a2eec. No matching claim. */
#include "types.h"
#include "deps/021a2eec_FUN_021a2eec.h"

void FUN_021a2eec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = FUN_0219b9c4();
  uVar3 = FUN_021a2fb4();
  piVar1 = DAT_021a2f94;
  switch(uVar3) {
  case 0:
    uVar4 = FUN_021a31e8(param_2);
    if ((1 < uVar4) && (uVar4 < 5)) {
      FUN_021a2dfc(iVar2,param_2,param_3);
      return;
    }
    break;
  case 1:
    FUN_021a2dfc(iVar2,param_2,param_3);
    return;
  case 2:
    FUN_021a2d68(iVar2,param_2,param_3);
    return;
  case 3:
    FUN_021a2d38(iVar2,param_2,param_3);
    return;
  case 4:
    iVar2 = iVar2 * 0x30;
    *(undefined1 *)(*DAT_021a2f94 + iVar2 + 0x1d) = 1;
    *(undefined4 *)(*piVar1 + iVar2 + 0x10) = 0;
    *(undefined4 *)(*piVar1 + iVar2 + 0x18) = 0;
    return;
  default:
    func_0x0200fd1c();
  }
  return;
}

