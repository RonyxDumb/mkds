/* Decompiled C draft; module arm9; ROM address 02037a94. No matching claim. */
#include "types.h"
#include "deps/02037a94_ResetDisplayConfig.h"

void ResetDisplayConfig(void)

{
  ResetSomeVram();
  *puRam02037ab8 = 0;
  return;
}

