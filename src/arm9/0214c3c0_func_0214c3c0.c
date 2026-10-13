/* Decompiled C draft; module arm9; ROM address 0214c3c0. No matching claim. */
#include "types.h"
#include "deps/0214c3c0_func_0214c3c0.h"

void func_0214c3c0(void)

{
  undefined4 *puVar1;
  
  if ((*(uint *)(uRam0214c40c & 0xfffffffc) >> (uRam0214c40c & 3) * 8 |
      *(uint *)(uRam0214c40c & 0xfffffffc) << (uRam0214c40c & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  func_021494f0(*(uint *)((uint)puRam0214c410 & 0xfffffffc) >> ((uint)puRam0214c410 & 3) * 8 |
                *(uint *)((uint)puRam0214c410 & 0xfffffffc) << ((uint)puRam0214c410 & 3) * -8 + 0x20
               );
  puVar1 = puRam0214c414;
  *puRam0214c410 = 0;
  *puVar1 = 0;
  return;
}

