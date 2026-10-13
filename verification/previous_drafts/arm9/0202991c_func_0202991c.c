/* Decompiled C draft; module arm9; ROM address 0202991c. No matching claim. */
#include "types.h"
#include "deps/0202991c_func_0202991c.h"

void func_0202991c(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam0202992c & 0xfffffffc) >> (uRam0202992c & 3) * 8 |
    *(uint *)(uRam0202992c & 0xfffffffc) << (uRam0202992c & 3) * -8 + 0x20) + 0x1fc) = param_1;
  return;
}

