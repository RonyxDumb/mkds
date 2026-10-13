/* Decompiled C draft; module arm9_ov000; ROM address 02192cfc. No matching claim. */
#include "types.h"
#include "deps/02192cfc_FUN_02192cfc.h"

int FUN_02192cfc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = FUN_02190b80(param_1,iVar2 + DAT_02192d2c,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_02190b80(param_1,iVar2 + DAT_02192d2c,param_3), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

