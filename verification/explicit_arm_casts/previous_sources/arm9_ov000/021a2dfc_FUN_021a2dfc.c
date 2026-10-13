/* Decompiled C draft; module arm9_ov000; ROM address 021a2dfc. No matching claim. */
#include "types.h"
#include "deps/021a2dfc_FUN_021a2dfc.h"

void FUN_021a2dfc(int param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20 [3];
  
  iVar3 = *DAT_021a2e78 + param_1 * 0x30;
  uVar1 = FUN_021a2fb4();
  *(undefined1 *)(iVar3 + 0x1e) = uVar1;
  uVar2 = FUN_021a31e8(param_2);
  switch(uVar2) {
  case 1:
    if (param_3 != 8) {
      return;
    }
    func_0x0214d1fc(param_2,local_20,8);
    *(undefined4 *)(iVar3 + 0x18) = local_20[0];
    *(undefined4 *)(iVar3 + 0x10) = 0;
    if ((*(int *)(iVar3 + 4) == 0) || (*(int *)(iVar3 + 8) < *(int *)(iVar3 + 0x18))) {
      *(undefined1 *)(iVar3 + 0x1d) = 4;
    }
    else {
      *(undefined1 *)(iVar3 + 0x1d) = 2;
    }
    break;
  case 2:
  case 3:
  case 4:
    *(undefined1 *)(iVar3 + 0x1d) = 3;
  }
  *(short *)(iVar3 + 0x22) = (short)uVar2;
  return;
}

