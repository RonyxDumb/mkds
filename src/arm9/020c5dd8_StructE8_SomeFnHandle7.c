/* Decompiled C draft; module arm9; ROM address 020c5dd8. No matching claim. */
#include "types.h"
#include "deps/020c5dd8_StructE8_SomeFnHandle7.h"

void StructE8_SomeFnHandle7(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam020c5dec & 0xfffffffc) >> (uRam020c5dec & 3) * 8 |
    *(uint *)(uRam020c5dec & 0xfffffffc) << (uRam020c5dec & 3) * -8 + 0x20) + 0xdc) = 0;
  return;
}

