/* Decompiled C draft; module arm9; ROM address 0207a974. No matching claim. */
#include "types.h"
#include "deps/0207a974_GetDriverEntry.h"

int GetDriverEntry(int param_1)

{
  return iRam0207a98c * param_1 +
         (*(uint *)(uRam0207a988 & 0xfffffffc) >> (uRam0207a988 & 3) * 8 |
         *(uint *)(uRam0207a988 & 0xfffffffc) << (uRam0207a988 & 3) * -8 + 0x20);
}

