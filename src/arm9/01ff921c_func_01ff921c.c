/* Decompiled C draft; module arm9; ROM address 01ff921c. No matching claim. */
#include "types.h"
#include "deps/01ff921c_func_01ff921c.h"

void func_01ff921c(void)

{
  do {
  } while (*(uint *)(uRam01ff9230 & 0xfffffffc) >> (uRam01ff9230 & 3) * 8 != 0 ||
           *(uint *)(uRam01ff9230 & 0xfffffffc) << (uRam01ff9230 & 3) * -8 + 0x20 != 0);
  return;
}

