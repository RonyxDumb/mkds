/* Decompiled C draft; module arm9; ROM address 02025df4. No matching claim. */
#include "types.h"
#include "deps/02025df4_func_02025df4.h"

int func_02025df4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    uVar1 = func_02025e28(iVar3);
    iVar2 = func_0205fd2c(param_1,param_2,uVar1);
    if (iVar2 != 0) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x24);
  return iVar4;
}

