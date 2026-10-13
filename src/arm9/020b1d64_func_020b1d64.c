/* Decompiled C draft; module arm9; ROM address 020b1d64. No matching claim. */
#include "types.h"
#include "deps/020b1d64_func_020b1d64.h"

void func_020b1d64(void)

{
  uint uVar1;
  
  uVar1 = uRam020b1d8c;
  *(undefined4 *)
   ((*(uint *)(uRam020b1d8c & 0xfffffffc) >> (uRam020b1d8c & 3) * 8 |
    *(uint *)(uRam020b1d8c & 0xfffffffc) << (uRam020b1d8c & 3) * -8 + 0x20) + 0x828) = 6;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x82c) = 1;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x834) = 1;
  return;
}

