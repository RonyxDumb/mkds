/* Decompiled C draft; module arm9; ROM address 020a228c. No matching claim. */
#include "types.h"
#include "deps/020a228c_func_020a228c.h"

void func_020a228c(int param_1)

{
  *(undefined4 *)
   (param_1 * 0x70 +
    (*(uint *)(uRam020a22a8 & 0xfffffffc) >> (uRam020a22a8 & 3) * 8 |
    *(uint *)(uRam020a22a8 & 0xfffffffc) << (uRam020a22a8 & 3) * -8 + 0x20) + 100) = 0xffffffff;
  return;
}

