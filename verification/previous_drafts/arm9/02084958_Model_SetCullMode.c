/* Decompiled C draft; module arm9; ROM address 02084958. No matching claim. */
#include "types.h"
#include "deps/02084958_Model_SetCullMode.h"

void Model_SetCullMode(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02084960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02084964)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

