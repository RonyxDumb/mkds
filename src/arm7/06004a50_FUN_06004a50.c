/* Decompiled C draft; module arm7; ROM address 06004a50. No matching claim. */
#include "types.h"
#include "deps/06004a50_FUN_06004a50.h"

void FUN_06004a50(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  *puVar1 = 0xd;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  puVar1[5] = param_4;
  thunk_FUN_038074cc();
  return;
}

