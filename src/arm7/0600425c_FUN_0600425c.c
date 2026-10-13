/* Decompiled C draft; module arm7; ROM address 0600425c. No matching claim. */
#include "types.h"
#include "deps/0600425c_FUN_0600425c.h"

void FUN_0600425c(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  *puVar1 = 0xb;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  thunk_FUN_038074cc();
  return;
}

