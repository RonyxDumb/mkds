/* Decompiled C draft; module arm9; ROM address 0200ee3c. No matching claim. */
#include "types.h"
#include "deps/0200ee3c_DC_InvalidateRangeNoClean.h"

void DC_InvalidateRangeNoClean(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffffffe0;
  do {
    coproc_moveto_Invalidate_Entire_Data_by_MVA(uVar1);
    uVar1 = uVar1 + 0x20;
  } while ((int)uVar1 < (int)(param_2 + param_1));
  return;
}

