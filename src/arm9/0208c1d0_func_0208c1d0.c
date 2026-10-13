/* Decompiled C draft; module arm9; ROM address 0208c1d0. No matching claim. */
#include "types.h"
#include "deps/0208c1d0_func_0208c1d0.h"

void func_0208c1d0(void)

{
  (*(code *)(*(uint *)(uRam0208c1f0 & 0xfffffffc) >> (uRam0208c1f0 & 3) * 8 |
            *(uint *)(uRam0208c1f0 & 0xfffffffc) << (uRam0208c1f0 & 3) * -8 + 0x20))();
  return;
}

