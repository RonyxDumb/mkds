/* Decompiled C draft; module arm9; ROM address 02012f24. No matching claim. */
#include "types.h"
#include "deps/02012f24_func_02012f24.h"

void func_02012f24(void)

{
  G3X_Initialize();
  func_02011074();
  *puRam02012f54 =
       (*(uint *)((uint)puRam02012f54 & 0xfffffffc) >> ((uint)puRam02012f54 & 3) * 8 |
       *(uint *)((uint)puRam02012f54 & 0xfffffffc) << ((uint)puRam02012f54 & 3) * -8 + 0x20) &
       0x3fffffff | 0x80000000;
  return;
}

