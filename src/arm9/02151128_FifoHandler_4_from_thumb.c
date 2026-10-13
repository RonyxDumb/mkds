/* Decompiled C draft; module arm9; ROM address 02151128. No matching claim. */
#include "types.h"
#include "deps/02151128_FifoHandler_4_from_thumb.h"

ushort FifoHandler_4_from_thumb(undefined4 param_1,ushort param_2,int param_3)

{
  ushort *puVar1;
  
  puVar1 = puRam0215114c;
  *puRam0215114c = param_2 & 0xff;
  *puRam02151150 = 1;
  if (param_3 != 0) {
    *puVar1 = 0xff;
  }
  return *puRam0215114c;
}

