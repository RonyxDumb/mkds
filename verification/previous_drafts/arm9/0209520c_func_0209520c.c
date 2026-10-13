/* Decompiled C draft; module arm9; ROM address 0209520c. No matching claim. */
#include "types.h"
#include "deps/0209520c_func_0209520c.h"

int func_0209520c(void)

{
  return (*(uint *)(uRam02095220 & 0xfffffffc) >> (uRam02095220 & 3) * 8 |
         *(uint *)(uRam02095220 & 0xfffffffc) << (uRam02095220 & 3) * -8 + 0x20) + iRam02095224;
}

