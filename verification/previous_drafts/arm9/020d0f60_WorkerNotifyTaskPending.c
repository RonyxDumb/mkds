/* Decompiled C draft; module arm9; ROM address 020d0f60. No matching claim. */
#include "types.h"
#include "deps/020d0f60_WorkerNotifyTaskPending.h"

void WorkerNotifyTaskPending(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam020d0f74 & 0xfffffffc) >> (uRam020d0f74 & 3) * 8 |
    *(uint *)(uRam020d0f74 & 0xfffffffc) << (uRam020d0f74 & 3) * -8 + 0x20) + 0xf8) = 1;
  return;
}

