/* Decompiled C draft; module arm7; ROM address 0380325c. No matching claim. */
#include "types.h"
#include "deps/0380325c_FUN_0380325c.h"

void FUN_0380325c(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = DAT_0380351c;
  if ((param_1 & 0x2000000) != 0) {
    iVar4 = 0;
    do {
      puVar2[iVar4] = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
  }
  puVar2 = DAT_0380351c;
  DAT_0380351c[(param_1 & 0xf0000) >> 0x10] = (ushort)param_1;
  if ((param_1 & 0x1000000) != 0) {
    uVar1 = ((*puVar2 & 0xff00) << 8) >> 0x10;
    uVar3 = uVar1 - 0x40;
                    /* WARNING: Could not recover jumptable at 0x038032bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar3 < 4) {
      (*(code *)(uVar3 * 4 + 0x38032c4))();
      return;
    }
    FUN_0380146c(uVar1,1);
  }
  return;
}

