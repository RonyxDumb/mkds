/* Decompiled C draft; module arm9_ov003; ROM address 021d18f0. No matching claim. */
#include "types.h"
#include "deps/021d18f0_FUN_021d18f0.h"

void FUN_021d18f0(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  uVar1 = DAT_021d196c;
  puVar3 = *(uint **)(param_1 + 8);
  if (param_2 < 0) {
    iVar2 = 0;
    if (*(char *)(param_1 + 0xc) != '\0') {
      do {
        if ((param_3 == DAT_021d1964) || (param_3 == DAT_021d1968)) {
          *puVar3 = param_4 * 0x2000000 | *puVar3 & uVar1 | param_3;
        }
        else {
          *puVar3 = *puVar3 & uVar1 | param_3;
        }
        puVar3 = puVar3 + 2;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0xc));
    }
    return;
  }
  if ((param_3 != DAT_021d1964) && (param_3 != DAT_021d1968)) {
    puVar3[param_2 * 2] = puVar3[param_2 * 2] & DAT_021d196c | param_3;
    return;
  }
  puVar3[param_2 * 2] = param_4 << 0x19 | puVar3[param_2 * 2] & DAT_021d196c | param_3;
  return;
}

