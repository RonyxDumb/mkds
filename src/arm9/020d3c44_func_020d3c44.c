/* Decompiled C draft; module arm9; ROM address 020d3c44. No matching claim. */
#include "types.h"
#include "deps/020d3c44_func_020d3c44.h"

ushort func_020d3c44(void)

{
  ushort *puVar1;
  
  puVar1 = puRam020d3c74;
  *puRam020d3c74 = *puRam020d3c74 + 1;
  if (0x3e < *puVar1) {
    *puVar1 = *puRam020d3c78;
  }
  return *puRam020d3c74;
}

