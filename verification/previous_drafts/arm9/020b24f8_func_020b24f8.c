/* Decompiled C draft; module arm9; ROM address 020b24f8. No matching claim. */
#include "types.h"
#include "deps/020b24f8_func_020b24f8.h"

undefined2 func_020b24f8(void)

{
  return *(undefined2 *)
          ((*(uint *)(uRam020b2508 & 0xfffffffc) >> (uRam020b2508 & 3) * 8 |
           *(uint *)(uRam020b2508 & 0xfffffffc) << (uRam020b2508 & 3) * -8 + 0x20) + 0x60);
}

