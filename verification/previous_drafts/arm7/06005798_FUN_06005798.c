/* Decompiled C draft; module arm7; ROM address 06005798. No matching claim. */
#include "types.h"
#include "deps/06005798_FUN_06005798.h"

void FUN_06005798(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)thunk_FUN_03807424();
  *puVar1 = 0x13;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  thunk_FUN_038074cc();
  return;
}

