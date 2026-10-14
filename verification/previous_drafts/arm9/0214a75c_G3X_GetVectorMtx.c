/* Decompiled C draft; module arm9; ROM address 0214a75c. No matching claim. */
#include "types.h"
#include "deps/0214a75c_G3X_GetVectorMtx.h"

undefined4 G3X_GetVectorMtx(undefined4 param_1)

{
  if (((*(uint *)(uRam0214a79c & 0xfffffffc) >> (uRam0214a79c & 3) * 8 |
       *(uint *)(uRam0214a79c & 0xfffffffc) << (uRam0214a79c & 3) * -8 + 0x20) & 0x8000000) == 0) {
    asm_MI_Copy36B((undefined4 *)(uintptr_t)(uRam0214a7a0),(undefined4 *)(uintptr_t)(param_1));
    return 0;
  }
  return 0xffffffff;
}

