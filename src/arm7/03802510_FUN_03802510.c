/* Decompiled C draft; module arm7; ROM address 03802510. No matching claim. */
#include "types.h"
#include "deps/03802510_FUN_03802510.h"

void FUN_03802510(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = DAT_038026dc;
  if ((param_1 & 0x2000000) != 0) {
    iVar4 = 0;
    do {
      puVar2[iVar4] = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
  }
  puVar2 = DAT_038026dc;
  DAT_038026dc[(param_1 & 0xf0000) >> 0x10] = (ushort)param_1;
  if ((param_1 & 0x1000000) != 0) {
    uVar1 = ((*puVar2 & 0xff00) << 8) >> 0x10;
    uVar3 = uVar1 - 0x60;
                    /* WARNING: Could not recover jumptable at 0x03802574. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar3 < 8) {
      (*(code *)(uVar3 * 4 + 0x380257c))();
      return;
    }
    FUN_0380146c(uVar1,1);
  }
  return;
}

