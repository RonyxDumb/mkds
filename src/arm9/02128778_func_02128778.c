/* Decompiled C draft; module arm9; ROM address 02128778. No matching claim. */
#include "types.h"
#include "deps/02128778_func_02128778.h"

void func_02128778(void)

{
  ushort *puVar1;
  
  *puRam021287ac = *puRam021287ac & uRam021287b4 | ((*puRam021287ac & uRam021287b0) >> 8 | 4) << 8;
  puVar1 = puRam021287b8;
  *puRam021287b8 = *puRam021287b8 & 0xfffc;
  *puVar1 = *puVar1 & 0x43 | (ushort)uRam021287bc;
  return;
}

