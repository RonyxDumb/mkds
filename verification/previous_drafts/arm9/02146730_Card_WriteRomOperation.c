/* Decompiled C draft; module arm9; ROM address 02146730. No matching claim. */
#include "types.h"
#include "deps/02146730_Card_WriteRomOperation.h"

void Card_WriteRomOperation(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = puRam021467b0;
  do {
  } while (((*(uint *)(uRam021467a8 & 0xfffffffc) >> (uRam021467a8 & 3) * 8 |
            *(uint *)(uRam021467a8 & 0xfffffffc) << (uRam021467a8 & 3) * -8 + 0x20) & 0x80000000) !=
           0);
  *puRam021467ac = 0xc0;
  puVar2 = puRam021467b4;
  *puVar1 = (char)((uint)param_1 >> 0x18);
  puVar1 = puRam021467b8;
  *puVar2 = (char)((uint)param_1 >> 0x10);
  puVar2 = puRam021467bc;
  *puVar1 = (char)((uint)param_1 >> 8);
  puVar1 = puRam021467c0;
  *puVar2 = (char)param_1;
  puVar2 = puRam021467c4;
  *puVar1 = (char)((uint)param_2 >> 0x18);
  puVar1 = puRam021467c8;
  *puVar2 = (char)((uint)param_2 >> 0x10);
  puVar2 = puRam021467cc;
  *puVar1 = (char)((uint)param_2 >> 8);
  *puVar2 = (char)param_2;
  return;
}

