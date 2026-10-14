/* Decompiled C draft; module arm9; ROM address 020ae0ac. No matching claim. */
#include "types.h"
#include "deps/020ae0ac_GetRacerCpuIndex.h"

int GetRacerCpuIndex(int param_1)

{
  return (int)*(char *)(param_1 * 0x30 +
                        (*(uint *)(uRam020ae0c4 & 0xfffffffc) >> (uRam020ae0c4 & 3) * 8 |
                        *(uint *)(uRam020ae0c4 & 0xfffffffc) << (uRam020ae0c4 & 3) * -8 + 0x20) +
                       0x86);
}

