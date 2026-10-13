/* Decompiled C draft; module arm7; ROM address 06003854. No matching claim. */
#include "types.h"
#include "deps/06003854_FUN_06003854.h"

void FUN_06003854(undefined2 param_1,undefined2 param_2,int param_3)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  if (param_3 == 0) {
    *puVar1 = 10;
  }
  else {
    *puVar1 = 0x26;
  }
  puVar1[1] = 1;
  puVar1[4] = 4;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  thunk_FUN_038074cc();
  return;
}

