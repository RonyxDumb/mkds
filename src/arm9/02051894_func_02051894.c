/* Decompiled C draft; module arm9; ROM address 02051894. No matching claim. */
#include "types.h"
#include "deps/02051894_func_02051894.h"

void func_02051894(int param_1)

{
  uint uVar1;
  
  uVar1 = uRam020518c4;
  *(undefined4 *)
   ((*(uint *)(uRam020518c4 & 0xfffffffc) >> (uRam020518c4 & 3) * 8 |
    *(uint *)(uRam020518c4 & 0xfffffffc) << (uRam020518c4 & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8) = 2;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = 0;
  }
  return;
}

