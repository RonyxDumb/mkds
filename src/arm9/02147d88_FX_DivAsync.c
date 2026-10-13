/* Decompiled C draft; module arm9; ROM address 02147d88. No matching claim. */
#include "types.h"
#include "deps/02147d88_FX_DivAsync.h"

void FX_DivAsync(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = puRam02147db8;
  *puRam02147db4 = 1;
  *puVar1 = 0;
  puVar2 = puRam02147dbc;
  puVar1[1] = param_1;
  *puVar2 = param_2;
  puVar2[1] = 0;
  return;
}

