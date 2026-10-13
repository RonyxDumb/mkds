/* Decompiled C draft; module arm7; ROM address 060096c4. No matching claim. */
#include "types.h"
#include "deps/060096c4_FUN_060096c4.h"

uint FUN_060096c4(ushort *param_1)

{
  uint uVar1;
  
  if (((uint)param_1 & 1) == 0) {
    uVar1 = *param_1 & 0xff;
  }
  else {
    uVar1 = (int)(uint)*(ushort *)((int)param_1 + -1) >> 8;
  }
  return uVar1;
}

