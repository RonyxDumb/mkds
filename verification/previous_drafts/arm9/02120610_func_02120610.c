/* Decompiled C draft; module arm9; ROM address 02120610. No matching claim. */
#include "types.h"
#include "deps/02120610_func_02120610.h"

void func_02120610(void)

{
  uint uVar1;
  
  uVar1 = uRam02120640;
  *(undefined4 *)
   ((*(uint *)(uRam02120640 & 0xfffffffc) >> (uRam02120640 & 3) * 8 |
    *(uint *)(uRam02120640 & 0xfffffffc) << (uRam02120640 & 3) * -8 + 0x20) + 0x1f44) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8000) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x1f48) = 0;
  return;
}

