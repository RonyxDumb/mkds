/* Decompiled C draft; module arm9; ROM address 02022d44. No matching claim. */
#include "types.h"
#include "deps/02022d44_NFTR_LoadV2.h"

void NFTR_LoadV2(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  short sVar2;
  undefined2 uVar3;
  
  sVar2 = NFTR_Process(param_2,param_1);
  *(short *)(param_1 + 8) = sVar2 + -1;
  uVar1 = uRam02022d84;
  if (*(short *)(param_1 + 8) == 0) {
    uVar3 = 3;
  }
  else {
    uVar3 = 2;
  }
  *(undefined2 *)(param_1 + 10) = uVar3;
  *(undefined4 *)(param_1 + 4) = uVar1;
  return;
}

