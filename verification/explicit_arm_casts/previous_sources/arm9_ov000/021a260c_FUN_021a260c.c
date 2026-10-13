/* Decompiled C draft; module arm9_ov000; ROM address 021a260c. No matching claim. */
#include "types.h"
#include "deps/021a260c_FUN_021a260c.h"

void FUN_021a260c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_118 [260];
  
  if (*DAT_021a2734 != 0) {
    FUN_021a3704(4,*DAT_021a2734,0);
    *DAT_021a2734 = 0;
  }
  if (param_2 != 0) {
    iVar2 = FUN_021a0ed8(auStack_118,0xffffffff,0x20,3);
    iVar3 = func_0x0213a434(DAT_021a2738);
    iVar3 = (DAT_021a273c - iVar2) - iVar3;
    iVar2 = FUN_021a372c(4,iVar3);
    *DAT_021a2734 = iVar2;
    if (iVar2 == 0) {
      FUN_021a1a38(0xb,DAT_021a2740);
      return;
    }
    func_0x0214d1fc(param_2,iVar2,iVar3);
    *(undefined1 *)(*DAT_021a2734 + iVar3 + -1) = 0;
  }
  FUN_021a10b0(0,param_1,param_3,param_4);
  piVar1 = DAT_021a2744;
  *(undefined4 *)(*DAT_021a2744 + DAT_021a2748) = param_5;
  *(undefined4 *)(*piVar1 + DAT_021a274c) = param_6;
  *(undefined4 *)(*piVar1 + DAT_021a2750) = 2;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0xe4) == 0) {
    uVar4 = FUN_0218b668(*(undefined4 *)(iVar2 + DAT_021a2754),*(undefined4 *)(iVar2 + DAT_021a2754)
                         ,*(undefined4 *)(iVar2 + DAT_021a275c),0,0x14,1,0,DAT_021a2758,0);
    *(undefined4 *)(*DAT_021a2744 + 0xe4) = uVar4;
  }
  if ((*(int *)(*DAT_021a2744 + 0xe4) != 0) || (iVar2 = FUN_0219e594(5), iVar2 == 0)) {
    FUN_0219d558(3,DAT_021a2760,0);
    FUN_021a0f20(*(undefined4 *)(*DAT_021a2744 + DAT_021a2764));
    iVar2 = FUN_0219e594();
    if (iVar2 == 0) {
      if (*(int *)(*DAT_021a2744 + 0x10) == 0) {
        FUN_021a2768(*(undefined4 *)(*DAT_021a2744 + DAT_021a2764));
      }
      FUN_0219e8b8(0);
    }
  }
  return;
}

