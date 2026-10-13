/* Decompiled C draft; module arm9; ROM address 020f8258. No matching claim. */
#include "types.h"
#include "deps/020f8258_func_020f8258.h"

void func_020f8258(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)((uint)piRam020f8298 & 0xfffffffc) >> ((uint)piRam020f8298 & 3) * 8 |
          *(uint *)((uint)piRam020f8298 & 0xfffffffc) << ((uint)piRam020f8298 & 3) * -8 + 0x20;
  if (0 < (int)uVar1) {
    *piRam020f8298 = uVar1 - 1;
  }
  uVar1 = *(uint *)((uint)piRam020f829c & 0xfffffffc) >> ((uint)piRam020f829c & 3) * 8 |
          *(uint *)((uint)piRam020f829c & 0xfffffffc) << ((uint)piRam020f829c & 3) * -8 + 0x20;
  if (0 < (int)uVar1) {
    *piRam020f829c = uVar1 - 1;
  }
  uVar1 = *(uint *)((uint)piRam020f82a0 & 0xfffffffc) >> ((uint)piRam020f82a0 & 3) * 8 |
          *(uint *)((uint)piRam020f82a0 & 0xfffffffc) << ((uint)piRam020f82a0 & 3) * -8 + 0x20;
  if (0 < (int)uVar1) {
    *piRam020f82a0 = uVar1 - 1;
  }
  return;
}

