/* Decompiled C draft; module arm7; ROM address 037ff5fc. No matching claim. */
#include "types.h"
#include "deps/037ff5fc_FUN_037ff5fc.h"

void FUN_037ff5fc(uint param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_037faf70();
  iVar2 = 0;
  for (; (iVar2 < 8 && (param_3 != 0)); param_3 = param_3 >> 1) {
    if ((param_3 & 1) != 0) {
      FUN_037ff400(iVar2);
    }
    iVar2 = iVar2 + 1;
  }
  iVar2 = 0;
  for (; (iVar2 < 0x10 && (param_1 != 0)); param_1 = param_1 >> 1) {
    if ((param_1 & 1) != 0) {
      FUN_037fbd0c(iVar2,param_4);
    }
    iVar2 = iVar2 + 1;
  }
  if ((param_2 & 1) != 0) {
    *DAT_037ff6b8 = 0;
  }
  if ((param_2 & 2) != 0) {
    *DAT_037ff6bc = 0;
  }
  FUN_037faf84(uVar1);
  FUN_037ff2f4();
  return;
}

