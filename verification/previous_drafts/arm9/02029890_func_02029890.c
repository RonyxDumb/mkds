/* Decompiled C draft; module arm9; ROM address 02029890. No matching claim. */
#include "types.h"
#include "deps/02029890_func_02029890.h"

void func_02029890(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020298a0 & 0xfffffffc) >> (uRam020298a0 & 3) * 8 |
    *(uint *)(uRam020298a0 & 0xfffffffc) << (uRam020298a0 & 3) * -8 + 0x20) + 0x208) = param_1;
  return;
}

