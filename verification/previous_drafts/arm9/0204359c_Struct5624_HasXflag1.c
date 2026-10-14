/* Decompiled C draft; module arm9; ROM address 0204359c. No matching claim. */
#include "types.h"
#include "deps/0204359c_Struct5624_HasXflag1.h"

bool Struct5624_HasXflag1(void)

{
  return (*(ushort *)
           ((*(uint *)(uRam020435b8 & 0xfffffffc) >> (uRam020435b8 & 3) * 8 |
            *(uint *)(uRam020435b8 & 0xfffffffc) << (uRam020435b8 & 3) * -8 + 0x20) + 4) & 1) != 0;
}

