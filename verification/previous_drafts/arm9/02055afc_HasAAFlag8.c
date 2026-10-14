/* Decompiled C draft; module arm9; ROM address 02055afc. No matching claim. */
#include "types.h"
#include "deps/02055afc_HasAAFlag8.h"

bool HasAAFlag8(void)

{
  return (*(ushort *)
           ((*(uint *)(uRam02055b18 & 0xfffffffc) >> (uRam02055b18 & 3) * 8 |
            *(uint *)(uRam02055b18 & 0xfffffffc) << (uRam02055b18 & 3) * -8 + 0x20) + 8) & 8) != 0;
}

