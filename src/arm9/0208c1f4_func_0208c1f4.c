/* Decompiled C draft; module arm9; ROM address 0208c1f4. No matching claim. */
#include "types.h"
#include "deps/0208c1f4_func_0208c1f4.h"

void func_0208c1f4(void)

{
  (*(code *)(*(uint *)(uRam0208c214 & 0xfffffffc) >> (uRam0208c214 & 3) * 8 |
            *(uint *)(uRam0208c214 & 0xfffffffc) << (uRam0208c214 & 3) * -8 + 0x20))();
  return;
}

