/* Decompiled C draft; module arm9; ROM address 020298f4. No matching claim. */
#include "types.h"
#include "deps/020298f4_func_020298f4.h"

void func_020298f4(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02029904 & 0xfffffffc) >> (uRam02029904 & 3) * 8 |
    *(uint *)(uRam02029904 & 0xfffffffc) << (uRam02029904 & 3) * -8 + 0x20) + 0x1e8) = param_1;
  return;
}

