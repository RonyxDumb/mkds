/* Decompiled C draft; module arm9; ROM address 0203a8e0. No matching claim. */
#include "types.h"
#include "deps/0203a8e0_func_0203a8e0.h"

void func_0203a8e0(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam0203a8f0 & 0xfffffffc) >> (uRam0203a8f0 & 3) * 8 |
    *(uint *)(uRam0203a8f0 & 0xfffffffc) << (uRam0203a8f0 & 3) * -8 + 0x20) + 0x44) = param_1;
  return;
}

