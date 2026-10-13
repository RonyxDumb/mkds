/* Decompiled C draft; module arm7; ROM address 0380172c. No matching claim. */
#include "types.h"
#include "deps/0380172c_FUN_0380172c.h"

void FUN_0380172c(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_03801770;
  if (param_1 == 0) {
    FUN_0380146c(3,2);
  }
  else {
    *(int *)(DAT_03801770 + 0x24) = param_1;
    *(int *)(iVar1 + 0x28) = param_1;
    FUN_0380146c(3,0);
  }
  return;
}

