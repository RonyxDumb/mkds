/* Decompiled C draft; module arm7; ROM address 06003658. No matching claim. */
#include "types.h"
#include "deps/06003658_FUN_06003658.h"

void FUN_06003658(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  *puVar1 = 9;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  thunk_FUN_038074cc();
  return;
}

