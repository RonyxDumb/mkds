/* Decompiled C draft; module arm9_ov000; ROM address 021a1a38. No matching claim. */
#include "types.h"
#include "deps/021a1a38_FUN_021a1a38.h"

void FUN_021a1a38(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((*DAT_021a1aac != 0) && (param_1 != 0)) {
    FUN_0219f0f4();
    FUN_0219c384(param_1,param_2);
    FUN_0219d558(0,DAT_021a1ab0,0);
    iVar4 = *DAT_021a1aac;
    cVar1 = *(char *)(iVar4 + 0x15);
    iVar2 = *(int *)(iVar4 + DAT_021a1ab4);
    uVar3 = FUN_0219d5e4();
    (**(code **)(*DAT_021a1aac + DAT_021a1abc))
              (param_1,0,iVar2 == 0,cVar1 == '\x02',uVar3,*(undefined4 *)(iVar4 + DAT_021a1ab8));
    FUN_021a104c();
  }
  return;
}

