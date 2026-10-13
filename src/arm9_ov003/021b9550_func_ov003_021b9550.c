/* Decompiled C draft; module arm9_ov003; ROM address 021b9550. No matching claim. */
#include "types.h"
#include "deps/021b9550_func_ov003_021b9550.h"

uint func_ov003_021b9550(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & param_2;
  uVar1 = uVar2 | (param_1 & ~param_2) + 1;
  if ((uVar2 | ~param_2) <= uVar1) {
    uVar1 = uVar2 | 1;
  }
  return uVar1;
}

