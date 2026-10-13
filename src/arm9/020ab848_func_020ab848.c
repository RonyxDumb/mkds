/* Decompiled C draft; module arm9; ROM address 020ab848. No matching claim. */
#include "types.h"
#include "deps/020ab848_func_020ab848.h"

void func_020ab848(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  func_020ab11c();
  piVar1 = piRam020ab8bc;
  *param_1 = *param_1 - *(int *)(*piRam020ab8bc + 0x50);
  *param_2 = *param_2 - *(int *)(*piVar1 + 0x54);
  *param_3 = *param_3 - *(int *)(*piVar1 + 0x50);
  *param_4 = *param_4 - *(int *)(*piVar1 + 0x54);
  iVar2 = *param_1;
  if (iVar2 < 0) {
    iVar2 = iVar2 + iRam020ab8c0;
  }
  *param_1 = iVar2;
  iVar2 = *param_2;
  if (iVar2 < 0) {
    iVar2 = iVar2 + iRam020ab8c0;
  }
  *param_2 = iVar2;
  iVar2 = *param_3;
  if (iVar2 < 0) {
    iVar2 = iVar2 + iRam020ab8c0;
  }
  *param_3 = iVar2;
  iVar2 = *param_4;
  if (iVar2 < 0) {
    iVar2 = iVar2 + iRam020ab8c0;
  }
  *param_4 = iVar2;
  return;
}

