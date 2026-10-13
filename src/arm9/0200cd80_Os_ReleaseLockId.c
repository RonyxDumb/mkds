/* Decompiled C draft; module arm9; ROM address 0200cd80. No matching claim. */
#include "types.h"
#include "deps/0200cd80_Os_ReleaseLockId.h"

void Os_ReleaseLockId(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 + -0x60 < 0) {
    uVar2 = param_1 - 0x40;
    puVar1 = puRam0200cdac;
  }
  else {
    uVar2 = param_1 - 0x60;
    puVar1 = puRam0200cdac + 1;
  }
  *puVar1 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20 |
            0x80000000U >> (uVar2 & 0xff);
  return;
}

