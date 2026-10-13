/* Decompiled C draft; module arm7; ROM address 03801b14. No matching claim. */
#include "types.h"
#include "deps/03801b14_FUN_03801b14.h"

void FUN_03801b14(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = DAT_03801ccc;
  if ((param_1 & 0x2000000) != 0) {
    iVar3 = 0;
    do {
      puVar2[iVar3] = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
  }
  puVar2 = DAT_03801ccc;
  DAT_03801ccc[(param_1 & 0xf0000) >> 0x10] = (ushort)param_1;
  if ((param_1 & 0x1000000) != 0) {
    uVar1 = ((*puVar2 & 0xff00) << 8) >> 0x10;
                    /* WARNING: Could not recover jumptable at 0x03801b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar1 < 4) {
      (*(code *)(uVar1 * 4 + 0x3801b7c))();
      return;
    }
    FUN_0380146c(uVar1,1);
  }
  return;
}

