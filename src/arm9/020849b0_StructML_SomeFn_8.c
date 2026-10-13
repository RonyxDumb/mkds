/* Decompiled C draft; module arm9; ROM address 020849b0. No matching claim. */
#include "types.h"
#include "deps/020849b0_StructML_SomeFn_8.h"

void StructML_SomeFn_8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020849b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020849bc)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

