/* Decompiled C draft; module arm9; ROM address 02068a00. No matching claim. */
#include "types.h"
#include "deps/02068a00_StructMQRacerEntry_SomeFn_31.h"

void StructMQRacerEntry_SomeFn_31(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x3ccU & 3;
  uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02068a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02068a0c)(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

