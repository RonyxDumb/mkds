/* Decompiled C draft; module arm9; ROM address 020299f0. No matching claim. */
#include "types.h"
#include "deps/020299f0_IsDwc.h"

bool IsDwc(void)

{
  short *psVar1;
  
  psVar1 = (short *)GetBootIndicatorPointer();
  return *psVar1 == 2;
}

