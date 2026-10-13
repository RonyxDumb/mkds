/* Decompiled C draft; module arm9; ROM address 02074874. No matching claim. */
#include "types.h"
#include "deps/02074874_func_02074874.h"

void func_02074874(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02074884 & 0xfffffffc) >> (uRam02074884 & 3) * 8 |
    *(uint *)(uRam02074884 & 0xfffffffc) << (uRam02074884 & 3) * -8 + 0x20) + 100) = param_1;
  return;
}

