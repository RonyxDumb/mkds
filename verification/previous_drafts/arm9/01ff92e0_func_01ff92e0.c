/* Decompiled C draft; module arm9; ROM address 01ff92e0. No matching claim. */
#include "types.h"
#include "deps/01ff92e0_func_01ff92e0.h"

void func_01ff92e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = puRam01ff92fc;
  if (*(uint *)((uint)puRam01ff92fc & 0xfffffffc) >> ((uint)puRam01ff92fc & 3) * 8 == 0 &&
      *(uint *)((uint)puRam01ff92fc & 0xfffffffc) << ((uint)puRam01ff92fc & 3) * -8 + 0x20 == 0) {
    *param_1 = 0;
    *puVar1 = param_1;
  }
  return;
}

