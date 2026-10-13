/* Decompiled C draft; module arm9; ROM address 02085360. No matching claim. */
#include "types.h"
#include "deps/02085360_G3d_RenderDraw_1Mat1Poly.h"

void G3d_RenderDraw_1Mat1Poly(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02085374. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02085378)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0,0,1);
  return;
}

