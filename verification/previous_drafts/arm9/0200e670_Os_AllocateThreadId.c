/* Decompiled C draft; module arm9; ROM address 0200e670. No matching claim. */
#include "types.h"
#include "deps/0200e670_Os_AllocateThreadId.h"

void Os_AllocateThreadId(void)

{
  *piRam0200e684 =
       (*(uint *)((uint)piRam0200e684 & 0xfffffffc) >> ((uint)piRam0200e684 & 3) * 8 |
       *(uint *)((uint)piRam0200e684 & 0xfffffffc) << ((uint)piRam0200e684 & 3) * -8 + 0x20) + 1;
  return;
}

