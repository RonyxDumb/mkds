/* Decompiled C draft; module arm9; ROM address 020d1164. No matching claim. */
#include "types.h"
#include "deps/020d1164_IsDwc_1.h"

bool IsDwc_1(void)

{
  short *psVar1;
  
  psVar1 = (short *)GetBootIndicatorPointer_1();
  return *psVar1 == 2;
}

