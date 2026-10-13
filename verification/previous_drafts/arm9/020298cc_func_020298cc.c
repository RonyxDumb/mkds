/* Decompiled C draft; module arm9; ROM address 020298cc. No matching claim. */
#include "types.h"
#include "deps/020298cc_func_020298cc.h"

void func_020298cc(undefined1 param_1)

{
  *(undefined1 *)
   ((*(uint *)(uRam020298dc & 0xfffffffc) >> (uRam020298dc & 3) * 8 |
    *(uint *)(uRam020298dc & 0xfffffffc) << (uRam020298dc & 3) * -8 + 0x20) + 0x23f) = param_1;
  return;
}

