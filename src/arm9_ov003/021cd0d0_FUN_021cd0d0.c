/* Decompiled C draft; module arm9_ov003; ROM address 021cd0d0. No matching claim. */
#include "types.h"
#include "deps/021cd0d0_FUN_021cd0d0.h"

int FUN_021cd0d0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  *param_1 = *DAT_021cd10c + DAT_021cd110;
  uVar1 = DAT_021cd114;
  iVar5 = 0;
  iVar3 = *param_1;
  do {
    iVar2 = func_0x02134d30(iVar3 + 0x20,uVar1,6);
    if (iVar2 != 0) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 0x2a;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x14);
  return iVar4;
}

