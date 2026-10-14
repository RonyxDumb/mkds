/* Decompiled C draft; module arm9; ROM address 02061428. No matching claim. */
#include "types.h"
#include "deps/02061428_RunSomeATFunction.h"

void RunSomeATFunction(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02061464 & 0xfffffffc) >> (uRam02061464 & 3) * 8 |
    *(uint *)(uRam02061464 & 0xfffffffc) << (uRam02061464 & 3) * -8 + 0x20) + 0x40) = param_1;
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uRam02061468);
  *(undefined4 *)
   ((*(uint *)(uRam0206146c & 0xfffffffc) >> (uRam0206146c & 3) * 8 |
    *(uint *)(uRam0206146c & 0xfffffffc) << (uRam0206146c & 3) * -8 + 0x20) + 0xf8) = 1;
  return;
}

