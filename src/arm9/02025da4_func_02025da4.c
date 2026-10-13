/* Decompiled C draft; module arm9; ROM address 02025da4. No matching claim. */
#include "types.h"
#include "deps/02025da4_func_02025da4.h"

int func_02025da4(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 1;
  func_02025e60(param_2);
  iVar1 = func_02025e34();
  iVar4 = iVar1;
  do {
    iVar2 = func_02025e28(iVar4);
    iVar3 = func_0205fd2c(param_1,param_2,iVar2);
    if (iVar3 != 0) {
      if (iVar2 == param_3) {
        return iVar5;
      }
      iVar5 = iVar5 + 1;
    }
    iVar4 = iVar4 + 1;
    if (0x23 < iVar4) {
      iVar4 = 0;
    }
  } while (iVar4 != iVar1);
  return iVar5;
}

