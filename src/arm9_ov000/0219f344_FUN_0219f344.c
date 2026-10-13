/* Decompiled C draft; module arm9_ov000; ROM address 0219f344. No matching claim. */
#include "types.h"
#include "deps/0219f344_FUN_0219f344.h"

void FUN_0219f344(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_0219d558(1,DAT_0219f3b4,0);
  iVar1 = FUN_0219e608();
  if (iVar1 == 0) {
    FUN_021a104c();
    iVar3 = *DAT_0219f3b8;
    iVar1 = *(int *)(iVar3 + DAT_0219f3bc);
    if (iVar1 == 0) {
      if (*(char *)(iVar3 + 0x15) == '\x02') {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 1;
    }
    uVar2 = FUN_0219d5e4();
    (**(code **)(*DAT_0219f3b8 + DAT_0219f3c4))
              (0,1,iVar1 == 0,uVar4,uVar2,*(undefined4 *)(iVar3 + DAT_0219f3c0));
    *(undefined1 *)(*DAT_0219f3b8 + DAT_0219f3c8) = 0;
  }
  return;
}

