/* Decompiled C draft; module arm9; ROM address 020849c0. No matching claim. */
#include "types.h"
#include "deps/020849c0_Model_Render.h"

void Model_Render(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020849c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020849cc)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

