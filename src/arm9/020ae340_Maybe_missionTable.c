/* Decompiled C draft; module arm9; ROM address 020ae340. No matching claim. */
#include "types.h"
#include "deps/020ae340_Maybe_missionTable.h"

void Maybe_missionTable(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_18;
  
  uVar1 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam020ae3a0);
  iVar2 = func_0203b6a4();
  iVar3 = func_0203b69c(uVar1);
  local_18 = 1;
  for (uVar6 = 1; uVar5 = local_18, (int)uVar6 <= iVar2; uVar6 = uVar6 + 1 & 0xff) {
    for (; (int)uVar5 <= iVar3; uVar5 = uVar5 + 1 & 0xff) {
      iVar4 = func_0203b680(uVar1,uVar6,uVar5);
      if (param_1 == iVar4) {
        *param_2 = (char)uVar6;
        *param_3 = (char)uVar5;
      }
    }
  }
  return;
}

