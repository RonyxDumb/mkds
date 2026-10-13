/* Decompiled C draft; module arm7; ROM address 0600318c. No matching claim. */
#include "types.h"
#include "deps/0600318c_FUN_0600318c.h"

void FUN_0600318c(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  *puVar1 = 2;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  thunk_FUN_038074cc();
  return;
}

