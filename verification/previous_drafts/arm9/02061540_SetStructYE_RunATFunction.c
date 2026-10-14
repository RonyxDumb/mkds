/* Decompiled C draft; module arm9; ROM address 02061540. No matching claim. */
#include "types.h"
#include "deps/02061540_SetStructYE_RunATFunction.h"

void SetStructYE_RunATFunction(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam0206157c & 0xfffffffc) >> (uRam0206157c & 3) * 8 |
    *(uint *)(uRam0206157c & 0xfffffffc) << (uRam0206157c & 3) * -8 + 0x20) + 0x40) = param_1;
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uRam02061580);
  *(undefined4 *)
   ((*(uint *)(uRam02061584 & 0xfffffffc) >> (uRam02061584 & 3) * 8 |
    *(uint *)(uRam02061584 & 0xfffffffc) << (uRam02061584 & 3) * -8 + 0x20) + 0xf8) = 1;
  return;
}

