/* Decompiled C draft; module arm9; ROM address 02017274. No matching claim. */
#include "types.h"
#include "deps/02017274_func_02017274.h"

void func_02017274(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = iRam020172bc;
  *(undefined4 *)(iRam020172bc + 8) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = param_3;
  func_020170e4();
  puVar3 = puRam020172cc;
  uVar2 = uRam020172c8;
  if (param_4 != 0) {
    *puRam020172c4 = uRam020172c0;
    *puVar3 = uVar2;
    return;
  }
  return;
}

