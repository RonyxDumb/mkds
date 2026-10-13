/* Decompiled C draft; module arm9; ROM address 020b1cdc. No matching claim. */
#include "types.h"
#include "deps/020b1cdc_func_020b1cdc.h"

void func_020b1cdc(int param_1,undefined4 param_2)

{
  *(undefined4 *)
   ((*(uint *)(uRam020b1cf0 & 0xfffffffc) >> (uRam020b1cf0 & 3) * 8 |
    *(uint *)(uRam020b1cf0 & 0xfffffffc) << (uRam020b1cf0 & 3) * -8 + 0x20) + param_1 * 4 + 0x89c) =
       param_2;
  return;
}

