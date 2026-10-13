/* Decompiled C draft; module arm9; ROM address 020cca9c. No matching claim. */
#include "types.h"
#include "deps/020cca9c_SetNextCpuMode.h"

void SetNextCpuMode(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020ccaac & 0xfffffffc) >> (uRam020ccaac & 3) * 8 |
    *(uint *)(uRam020ccaac & 0xfffffffc) << (uRam020ccaac & 3) * -8 + 0x20) + 0x1fc) = param_1;
  return;
}

