/* Decompiled C draft; module arm9; ROM address 020acaa4. No matching claim. */
#include "types.h"
#include "deps/020acaa4_func_020acaa4.h"

void func_020acaa4(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020acab4 & 0xfffffffc) >> (uRam020acab4 & 3) * 8 |
    *(uint *)(uRam020acab4 & 0xfffffffc) << (uRam020acab4 & 3) * -8 + 0x20) + 0x74) = param_1;
  return;
}

