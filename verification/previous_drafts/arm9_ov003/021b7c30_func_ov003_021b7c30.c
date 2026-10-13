/* Decompiled C draft; module arm9_ov003; ROM address 021b7c30. No matching claim. */
#include "types.h"
#include "deps/021b7c30_func_ov003_021b7c30.h"

int func_ov003_021b7c30(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  return iVar2;
}

