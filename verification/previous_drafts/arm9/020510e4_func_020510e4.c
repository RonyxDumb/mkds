/* Decompiled C draft; module arm9; ROM address 020510e4. No matching claim. */
#include "types.h"
#include "deps/020510e4_func_020510e4.h"

bool func_020510e4(void)

{
  return (*(ushort *)
           ((*(uint *)(uRam02051104 & 0xfffffffc) >> (uRam02051104 & 3) * 8 |
            *(uint *)(uRam02051104 & 0xfffffffc) << (uRam02051104 & 3) * -8 + 0x20) + 0x454) & 0x40)
         != 0;
}

