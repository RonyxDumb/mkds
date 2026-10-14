/* Decompiled C draft; module arm9; ROM address 0208c260. No matching claim. */
#include "types.h"
#include "deps/0208c260_func_0208c260.h"

void func_0208c260(void)

{
  (*(code *)(*(uint *)(uRam0208c280 & 0xfffffffc) >> (uRam0208c280 & 3) * 8 |
            *(uint *)(uRam0208c280 & 0xfffffffc) << (uRam0208c280 & 3) * -8 + 0x20))();
  return;
}

