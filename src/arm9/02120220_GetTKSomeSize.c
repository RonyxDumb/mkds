/* Decompiled C draft; module arm9; ROM address 02120220. No matching claim. */
#include "types.h"
#include "deps/02120220_GetTKSomeSize.h"

int GetTKSomeSize(int param_1)

{
  return (int)*(short *)(param_1 * 0x244 +
                         (*(uint *)(uRam0212023c & 0xfffffffc) >> (uRam0212023c & 3) * 8 |
                         *(uint *)(uRam0212023c & 0xfffffffc) << (uRam0212023c & 3) * -8 + 0x20) +
                        0x43e);
}

