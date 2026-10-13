/* Decompiled C draft; module arm9; ROM address 020360e4. No matching claim. */
#include "types.h"
#include "deps/020360e4_func_020360e4.h"

bool func_020360e4(void)

{
  return (*(ushort *)
           ((*(uint *)(uRam02036104 & 0xfffffffc) >> (uRam02036104 & 3) * 8 |
            *(uint *)(uRam02036104 & 0xfffffffc) << (uRam02036104 & 3) * -8 + 0x20) + 0x454) & 0x40)
         != 0;
}

