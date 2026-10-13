/* Decompiled C draft; module arm9; ROM address 02148a58. No matching claim. */
#include "types.h"
#include "deps/02148a58_GX_VBlankIntr.h"

ushort GX_VBlankIntr(int param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = *puRam02148a84;
  if (param_1 != 0) {
    param_2 = *puRam02148a84;
  }
  if (param_1 != 0) {
    *puRam02148a84 = param_2 | 8;
  }
  else {
    *puRam02148a84 = *puRam02148a84 & 0xfff7;
  }
  return uVar1 & 8;
}

