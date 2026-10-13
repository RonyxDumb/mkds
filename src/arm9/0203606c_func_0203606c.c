/* Decompiled C draft; module arm9; ROM address 0203606c. No matching claim. */
#include "types.h"
#include "deps/0203606c_func_0203606c.h"

void func_0203606c(void)

{
  if (*(char *)((*(uint *)(uRam0203609c & 0xfffffffc) >> (uRam0203609c & 3) * 8 |
                *(uint *)(uRam0203609c & 0xfffffffc) << (uRam0203609c & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    func_020360a0(0);
  }
  return;
}

