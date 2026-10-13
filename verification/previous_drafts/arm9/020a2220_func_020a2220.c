/* Decompiled C draft; module arm9; ROM address 020a2220. No matching claim. */
#include "types.h"
#include "deps/020a2220_func_020a2220.h"

void func_020a2220(int param_1,undefined4 param_2)

{
  *(undefined4 *)
   (param_1 * 0x70 +
    (*(uint *)(uRam020a2238 & 0xfffffffc) >> (uRam020a2238 & 3) * 8 |
    *(uint *)(uRam020a2238 & 0xfffffffc) << (uRam020a2238 & 3) * -8 + 0x20) + 0x6c) = param_2;
  return;
}

