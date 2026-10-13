/* Decompiled C draft; module arm9; ROM address 02061358. No matching claim. */
#include "types.h"
#include "deps/02061358_RunReadGhostBinsFn.h"

void RunReadGhostBinsFn(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02061394 & 0xfffffffc) >> (uRam02061394 & 3) * 8 |
    *(uint *)(uRam02061394 & 0xfffffffc) << (uRam02061394 & 3) * -8 + 0x20) + 0x40) = param_1;
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uRam02061398);
  *(undefined4 *)
   ((*(uint *)(uRam0206139c & 0xfffffffc) >> (uRam0206139c & 3) * 8 |
    *(uint *)(uRam0206139c & 0xfffffffc) << (uRam0206139c & 3) * -8 + 0x20) + 0xf8) = 1;
  return;
}

