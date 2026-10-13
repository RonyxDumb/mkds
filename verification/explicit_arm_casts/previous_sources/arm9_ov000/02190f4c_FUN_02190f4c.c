/* Decompiled C draft; module arm9_ov000; ROM address 02190f4c. No matching claim. */
#include "types.h"
#include "deps/02190f4c_FUN_02190f4c.h"

void FUN_02190f4c(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (iVar4 == 0) {
    func_0x0213442c(DAT_02190fd8,DAT_02190fdc,0,0x23);
  }
  if (param_2 == 0) {
    func_0x0213442c(DAT_02190fe0,DAT_02190fdc,0,0x24);
  }
  if ((param_3 != 1) && (param_3 != 0)) {
    func_0x0213442c(DAT_02190fe4,DAT_02190fdc,0,0x25);
  }
  if (param_3 == 1) {
    *(undefined4 *)(iVar4 + DAT_02190fe8) = 1;
  }
  iVar3 = *(int *)(iVar4 + DAT_02190fec);
  uVar1 = *(undefined4 *)(iVar4 + DAT_02190ff0);
  if (iVar3 != 0) {
    piVar2 = (int *)FUN_021a3690(0x10);
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_2;
      piVar2[3] = param_3;
      piVar2[1] = *(int *)(iVar4 + DAT_02190ff4);
      piVar2[2] = iVar4;
    }
    FUN_02190ed4(param_1,iVar3,uVar1,piVar2,0,1);
  }
  return;
}

