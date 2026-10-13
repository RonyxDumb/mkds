/* Decompiled C draft; module arm9; ROM address 020517d4. No matching claim. */
#include "types.h"
#include "deps/020517d4_func_020517d4.h"

void func_020517d4(int param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02051810 & 0xfffffffc) >> (uRam02051810 & 3) * 8 |
    *(uint *)(uRam02051810 & 0xfffffffc) << (uRam02051810 & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    func_020533a0();
    return;
  }
  return;
}

