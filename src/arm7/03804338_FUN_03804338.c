/* Decompiled C draft; module arm7; ROM address 03804338. No matching claim. */
#include "types.h"
#include "deps/03804338_FUN_03804338.h"

void FUN_03804338(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = DAT_038044d8;
  if ((param_1 & 0x2000000) != 0) {
    iVar3 = 0;
    do {
      puVar2[iVar3] = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
  }
  puVar2 = DAT_038044d8;
  DAT_038044d8[(param_1 & 0xf0000) >> 0x10] = (ushort)param_1;
  if ((param_1 & 0x1000000) != 0) {
    uVar1 = ((*puVar2 & 0xff00) << 8) >> 0x10;
                    /* WARNING: Could not recover jumptable at 0x0380439c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar1 - 0x22 < 0xb) {
      (*(code *)(&UNK_038043a4 + (uVar1 - 0x22) * 4))();
      return;
    }
    iVar3 = FUN_03801320(1,uVar1,3,param_4,param_3);
    if (iVar3 == 0) {
      FUN_0380146c(uVar1,4);
    }
  }
  return;
}

