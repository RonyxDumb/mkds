/* Decompiled C draft; module arm9; ROM address 020b1d90. No matching claim. */
#include "types.h"
#include "deps/020b1d90_func_020b1d90.h"

void func_020b1d90(void)

{
  uint uVar1;
  
  uVar1 = uRam020b1db8;
  *(undefined4 *)
   ((*(uint *)(uRam020b1db8 & 0xfffffffc) >> (uRam020b1db8 & 3) * 8 |
    *(uint *)(uRam020b1db8 & 0xfffffffc) << (uRam020b1db8 & 3) * -8 + 0x20) + 0x828) = 5;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x82c) = 1;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x830) = 1;
  return;
}

