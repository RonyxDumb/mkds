/* Decompiled C draft; module arm9; ROM address 020be8e4. No matching claim. */
#include "types.h"
#include "deps/020be8e4_func_020be8e4.h"

void func_020be8e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = uRam020be92c;
  param_1 = param_1 * 0xc;
  *(undefined4 *)
   ((*(uint *)(uRam020be92c & 0xfffffffc) >> (uRam020be92c & 3) * 8 |
    *(uint *)(uRam020be92c & 0xfffffffc) << (uRam020be92c & 3) * -8 + 0x20) + param_1 + 0xfc) = 1;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + param_1 + 0x100) = param_2;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + param_1 + 0x104) = param_3;
  return;
}

