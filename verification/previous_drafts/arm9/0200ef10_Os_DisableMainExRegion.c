/* Decompiled C draft; module arm9; ROM address 0200ef10. No matching claim. */
#include "types.h"
#include "deps/0200ef10_Os_DisableMainExRegion.h"

void Os_DisableMainExRegion(void)

{
  *puRam0200ef20 = 0;
  return;
}

