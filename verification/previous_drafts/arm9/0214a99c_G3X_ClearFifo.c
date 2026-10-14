/* Decompiled C draft; module arm9; ROM address 0214a99c. No matching claim. */
#include "types.h"
#include "deps/0214a99c_G3X_ClearFifo.h"

void G3X_ClearFifo(void)

{
  GXi_NopClearFifo128_((undefined4 *)(uintptr_t)(uRam0214a9c8));
  do {
  } while (((*(uint *)(uRam0214a9cc & 0xfffffffc) >> (uRam0214a9cc & 3) * 8 |
            *(uint *)(uRam0214a9cc & 0xfffffffc) << (uRam0214a9cc & 3) * -8 + 0x20) & 0x8000000) !=
           0);
  return;
}

