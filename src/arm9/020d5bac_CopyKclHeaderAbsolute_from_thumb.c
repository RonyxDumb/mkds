/* Decompiled C draft; module arm9; ROM address 020d5bac. No matching claim. */
#include "types.h"
#include "deps/020d5bac_CopyKclHeaderAbsolute_from_thumb.h"

void CopyKclHeaderAbsolute_from_thumb(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar3 = 7;
  piVar4 = param_1;
  piVar5 = param_2;
  do {
    iVar1 = *piVar5;
    iVar2 = piVar5[1];
    piVar5 = piVar5 + 2;
    *piVar4 = iVar1;
    piVar4[1] = iVar2;
    piVar4 = piVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *piVar4 = *piVar5;
  *param_1 = (int)param_2 + *param_1;
  param_1[1] = (int)param_2 + param_1[1];
  param_1[2] = (int)param_2 + param_1[2];
  param_1[3] = (int)param_2 + param_1[3];
  *puRam020d5bec = 0;
  return;
}

