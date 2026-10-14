/* Decompiled C draft; module arm9; ROM address 021501c0. No matching claim. */
#include "types.h"
#include "deps/021501c0_func_021501c0.h"

void func_021501c0(void)

{
  do {
  } while (*(uint *)(uRam021501d4 & 0xfffffffc) >> (uRam021501d4 & 3) * 8 != 0 ||
           *(uint *)(uRam021501d4 & 0xfffffffc) << (uRam021501d4 & 3) * -8 + 0x20 != 0);
  return;
}

