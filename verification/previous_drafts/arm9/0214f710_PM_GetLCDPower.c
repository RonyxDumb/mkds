/* Decompiled C draft; module arm9; ROM address 0214f710. No matching claim. */
#include "types.h"
#include "deps/0214f710_PM_GetLCDPower.h"

bool PM_GetLCDPower(void)

{
  return (*puRam0214f728 & 1) != 0;
}

