/* Decompiled C draft; module arm9; ROM address 0205329c. No matching claim. */
#include "types.h"
#include "deps/0205329c_func_0205329c.h"

void func_0205329c(int param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020532d8 & 0xfffffffc) >> (uRam020532d8 & 3) * 8 |
    *(uint *)(uRam020532d8 & 0xfffffffc) << (uRam020532d8 & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    func_020533a0();
    return;
  }
  return;
}

