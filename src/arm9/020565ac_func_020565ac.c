/* Decompiled C draft; module arm9; ROM address 020565ac. No matching claim. */
#include "types.h"
#include "deps/020565ac_func_020565ac.h"

undefined4 func_020565ac(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 == 0) {
    uVar1 = StructNKPG_AnotherCopyToTime_from_thumb(*(undefined4 *)(*piRam020565e0 + 0x14));
  }
  else if (param_1 == 1) {
    uVar1 = StructNKPG_AnotherCopyToTime_from_thumb(*(undefined4 *)(*piRam020565e0 + 0x18));
  }
  return uVar1;
}

