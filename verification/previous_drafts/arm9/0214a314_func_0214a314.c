/* Decompiled C draft; module arm9; ROM address 0214a314. No matching claim. */
#include "types.h"
#include "deps/0214a314_func_0214a314.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int func_0214a314(void)

{
  return ((_DAT_04000000 & 0x38000000) >> 0x1b) * 0x10000 + 0x6000000 +
         ((int)(*puRam0214a344 & 0x1f00) >> 8) * 0x800;
}

