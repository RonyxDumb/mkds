/* Decompiled C draft; module arm9; ROM address 020a233c. No matching claim. */
#include "types.h"
#include "deps/020a233c_func_020a233c.h"

void func_020a233c(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020a234c & 0xfffffffc) >> (uRam020a234c & 3) * 8 |
    *(uint *)(uRam020a234c & 0xfffffffc) << (uRam020a234c & 3) * -8 + 0x20) + 0x388) = param_1;
  return;
}

