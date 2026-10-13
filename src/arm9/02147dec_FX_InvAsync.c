/* Decompiled C draft; module arm9; ROM address 02147dec. No matching claim. */
#include "types.h"
#include "deps/02147dec_FX_InvAsync.h"

void FX_InvAsync(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = puRam02147e20;
  *puRam02147e1c = 1;
  *puVar1 = 0;
  puVar2 = puRam02147e24;
  puVar1[1] = 0x1000;
  *puVar2 = param_1;
  puVar2[1] = 0;
  return;
}

