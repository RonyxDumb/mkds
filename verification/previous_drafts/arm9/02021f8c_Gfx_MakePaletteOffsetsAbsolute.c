/* Decompiled C draft; module arm9; ROM address 02021f8c. No matching claim. */
#include "types.h"
#include "deps/02021f8c_Gfx_MakePaletteOffsetsAbsolute.h"

void Gfx_MakePaletteOffsetsAbsolute(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_1;
  return;
}

