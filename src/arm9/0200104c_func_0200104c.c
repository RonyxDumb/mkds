/* Decompiled C draft; module arm9; ROM address 0200104c. No matching claim. */
#include "types.h"
#include "deps/0200104c_func_0200104c.h"

void func_0200104c(void)

{
  uint uVar1;
  
  uVar1 = uRam0200107c;
  *(undefined4 *)
   ((*(uint *)(uRam0200107c & 0xfffffffc) >> (uRam0200107c & 3) * 8 |
    *(uint *)(uRam0200107c & 0xfffffffc) << (uRam0200107c & 3) * -8 + 0x20) + 4) = 2;
  *(undefined2 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x82) = 0;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(byte *)(uVar1 + 0x8b) = *(byte *)(uVar1 + 0x8b) & 0xf7;
  return;
}

