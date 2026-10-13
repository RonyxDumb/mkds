/* Decompiled C draft; module arm9; ROM address 020d3c2c. No matching claim. */
#include "types.h"
#include "deps/020d3c2c_GetIncrementSomeItemCounter.h"

void GetIncrementSomeItemCounter(void)

{
  *psRam020d3c40 = *psRam020d3c40 + 1;
  return;
}

