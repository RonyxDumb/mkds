/* Decompiled C draft; module arm9; ROM address 0208c1ac. No matching claim. */
#include "types.h"
#include "deps/0208c1ac_func_0208c1ac.h"

void func_0208c1ac(void)

{
  (*(code *)(*(uint *)(uRam0208c1cc & 0xfffffffc) >> (uRam0208c1cc & 3) * 8 |
            *(uint *)(uRam0208c1cc & 0xfffffffc) << (uRam0208c1cc & 3) * -8 + 0x20))();
  return;
}

