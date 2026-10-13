/* Decompiled C draft; module arm7; ROM address 037fb218. No matching claim. */
#include "types.h"
#include "deps/037fb218_FUN_037fb218.h"

void FUN_037fb218(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 2) {
    *(undefined2 *)(param_2 + iVar1) = param_1;
  }
  return;
}

