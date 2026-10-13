/* Decompiled C draft; module arm9; ROM address 0202f1a8. No matching claim. */
#include "types.h"
#include "deps/0202f1a8_IsDwc_2.h"

bool IsDwc_2(void)

{
  short *psVar1;
  
  psVar1 = (short *)GetBiosBootIndicatorRef();
  return *psVar1 == 2;
}

