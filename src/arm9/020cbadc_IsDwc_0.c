/* Decompiled C draft; module arm9; ROM address 020cbadc. No matching claim. */
#include "types.h"
#include "deps/020cbadc_IsDwc_0.h"

bool IsDwc_0(void)

{
  short *psVar1;
  
  psVar1 = (short *)GetBootIndicatorPointer_0();
  return *psVar1 == 2;
}

