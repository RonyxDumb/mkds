/* Decompiled C draft; module arm9; ROM address 02021f7c. No matching claim. */
#include "types.h"
#include "deps/02021f7c_Gfx_MakeCharGraphicsOffsetsAbsolute.h"

void Gfx_MakeCharGraphicsOffsetsAbsolute(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_1;
  return;
}

