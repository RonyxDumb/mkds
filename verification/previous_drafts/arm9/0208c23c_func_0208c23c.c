/* Decompiled C draft; module arm9; ROM address 0208c23c. No matching claim. */
#include "types.h"
#include "deps/0208c23c_func_0208c23c.h"

void func_0208c23c(void)

{
  (*(code *)(*(uint *)(uRam0208c25c & 0xfffffffc) >> (uRam0208c25c & 3) * 8 |
            *(uint *)(uRam0208c25c & 0xfffffffc) << (uRam0208c25c & 3) * -8 + 0x20))();
  return;
}

