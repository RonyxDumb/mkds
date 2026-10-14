/* Decompiled C draft; module arm9; ROM address 0208c188. No matching claim. */
#include "types.h"
#include "deps/0208c188_func_0208c188.h"

void func_0208c188(void)

{
  (*(code *)(*(uint *)(uRam0208c1a8 & 0xfffffffc) >> (uRam0208c1a8 & 3) * 8 |
            *(uint *)(uRam0208c1a8 & 0xfffffffc) << (uRam0208c1a8 & 3) * -8 + 0x20))();
  return;
}

