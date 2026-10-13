/* Decompiled C draft; module arm9; ROM address 02021868. No matching claim. */
#include "types.h"
#include "deps/02021868_func_02021868.h"

int func_02021868(int param_1,int param_2)

{
  DC_InvalidateRangeNoClean
            ((*(uint *)(uRam020218b8 & 0xfffffffc) >> (uRam020218b8 & 3) * 8 |
             *(uint *)(uRam020218b8 & 0xfffffffc) << (uRam020218b8 & 3) * -8 + 0x20) + 0x20 +
             param_1 * 0x24 + param_2 * 2,2);
  return (int)*(short *)((*(uint *)(uRam020218b8 & 0xfffffffc) >> (uRam020218b8 & 3) * 8 |
                         *(uint *)(uRam020218b8 & 0xfffffffc) << (uRam020218b8 & 3) * -8 + 0x20) +
                         param_1 * 0x24 + param_2 * 2 + 0x20);
}

