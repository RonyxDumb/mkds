/* Decompiled C draft; module arm9; ROM address 02056574. No matching claim. */
#include "types.h"
#include "deps/02056574_func_02056574.h"

undefined4 func_02056574(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 0) {
    uVar1 = StructNKPG_CopyToTime_from_thumb(*(undefined4 *)(*piRam020565a8 + 0x14));
  }
  else if (param_1 == 1) {
    uVar1 = StructNKPG_CopyToTime_from_thumb(*(undefined4 *)(*piRam020565a8 + 0x18));
  }
  return uVar1;
}

