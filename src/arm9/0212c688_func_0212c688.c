/* Decompiled C draft; module arm9; ROM address 0212c688. No matching claim. */
#include "types.h"
#include "deps/0212c688_func_0212c688.h"

void func_0212c688(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *param_1 = 0;
  }
  return;
}

