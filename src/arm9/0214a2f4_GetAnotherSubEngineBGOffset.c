/* Decompiled C draft; module arm9; ROM address 0214a2f4. No matching claim. */
#include "types.h"
#include "deps/0214a2f4_GetAnotherSubEngineBGOffset.h"

int GetAnotherSubEngineBGOffset(void)

{
  return ((int)(*puRam0214a310 & 0x1f00) >> 8) * 0x800 + 0x6200000;
}

