/* Decompiled C draft; module arm9; ROM address 0212bb7c. No matching claim. */
#include "types.h"
#include "deps/0212bb7c_func_0212bb7c.h"

void func_0212bb7c(uint param_1)

{
  *puRam0212bb98 =
       (*(uint *)((uint)puRam0212bb98 & 0xfffffffc) >> ((uint)puRam0212bb98 & 3) * 8 |
       *(uint *)((uint)puRam0212bb98 & 0xfffffffc) << ((uint)puRam0212bb98 & 3) * -8 + 0x20) &
       ~(1 << (param_1 & 0xff));
  return;
}

