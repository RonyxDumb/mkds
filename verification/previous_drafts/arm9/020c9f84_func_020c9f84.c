/* Decompiled C draft; module arm9; ROM address 020c9f84. No matching claim. */
#include "types.h"
#include "deps/020c9f84_func_020c9f84.h"

void func_020c9f84(void)

{
  func_020c0b84((undefined4 *)(uintptr_t)((*(uint *)((uint)puRam020c9fb4 & 0xfffffffc) >> ((uint)puRam020c9fb4 & 3) * 8 |
                *(uint *)((uint)puRam020c9fb4 & 0xfffffffc) << ((uint)puRam020c9fb4 & 3) * -8 + 0x20
                ) + 400));
  *puRam020c9fb4 = 0;
  return;
}

