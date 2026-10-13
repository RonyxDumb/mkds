/* Decompiled C draft; module arm9_ov000; ROM address 0219f23c. No matching claim. */
#include "types.h"
#include "deps/0219f23c_FUN_0219f23c.h"

void FUN_0219f23c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    FUN_0219f344();
    return;
  }
  FUN_021a1140();
  iVar3 = *DAT_0219f2d4;
  if ((*(char *)(iVar3 + 0x15) != '\x02') && (*(char *)(iVar3 + 0x15) != '\x03')) {
    if (*(char *)(iVar3 + 0x15) == '\0') {
      if (param_1 == 1) {
        FUN_021a0f20(0);
        FUN_0219e594();
        return;
      }
    }
    else if ((*(char *)(iVar3 + 0x15) == '\x01') && (param_1 == 1)) {
      FUN_0219fbec(0,0);
    }
    return;
  }
  iVar1 = *(int *)(iVar3 + DAT_0219f2d8);
  uVar2 = FUN_0219d5e4();
  (**(code **)(*DAT_0219f2d4 + DAT_0219f2e0))
            (0,1,iVar1 == 0,0,uVar2,*(undefined4 *)(iVar3 + DAT_0219f2dc));
  return;
}

