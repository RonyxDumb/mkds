/* Decompiled C draft; module arm9_ov000; ROM address 02196a84. No matching claim. */
#include "types.h"
#include "deps/02196a84_FUN_02196a84.h"

int FUN_02196a84(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_02196df0();
  iVar2 = param_2;
  while ((0 < iVar2 && (iVar1 != 0))) {
    *DAT_02196adc = DAT_02196ad8;
    iVar3 = iVar1 - param_1;
    FUN_021971ec(param_1,iVar3);
    FUN_02196ae0(param_1,iVar3);
    iVar2 = iVar2 - (iVar3 + 7);
    param_1 = iVar1 + 7;
    if (0 < iVar2) {
      iVar1 = FUN_02196df0(param_1,iVar2);
    }
  }
  return param_2 - iVar2;
}

