/* Decompiled C draft; module arm7; ROM address 06004a04. No matching claim. */
#include "types.h"
#include "deps/06004a04_FUN_06004a04.h"

void FUN_06004a04(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  *puVar1 = 0x25;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  puVar1[5] = param_4;
  thunk_FUN_038074cc();
  return;
}

