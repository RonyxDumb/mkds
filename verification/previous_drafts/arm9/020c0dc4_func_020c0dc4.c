/* Decompiled C draft; module arm9; ROM address 020c0dc4. No matching claim. */
#include "types.h"
#include "deps/020c0dc4_func_020c0dc4.h"

undefined2 func_020c0dc4(void)

{
  return *(undefined2 *)
          (*(uint *)(uRam020c0dd4 & 0xfffffffc) >> (uRam020c0dd4 & 3) * 8 |
          *(uint *)(uRam020c0dd4 & 0xfffffffc) << (uRam020c0dd4 & 3) * -8 + 0x20);
}

