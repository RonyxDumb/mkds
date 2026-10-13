/* Decompiled C draft; module arm9; ROM address 02009724. No matching claim. */
#include "types.h"
#include "deps/02009724_func_02009724.h"

int func_02009724(short *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = 0;
  sVar1 = *param_1;
  psVar2 = param_1 + 1;
  while (sVar1 != 0) {
    iVar3 = iVar3 + 1;
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  }
  return iVar3;
}

