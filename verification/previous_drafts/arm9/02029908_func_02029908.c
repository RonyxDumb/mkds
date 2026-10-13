/* Decompiled C draft; module arm9; ROM address 02029908. No matching claim. */
#include "types.h"
#include "deps/02029908_func_02029908.h"

void func_02029908(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02029918 & 0xfffffffc) >> (uRam02029918 & 3) * 8 |
    *(uint *)(uRam02029918 & 0xfffffffc) << (uRam02029918 & 3) * -8 + 0x20) + 0x1f0) = param_1;
  return;
}

