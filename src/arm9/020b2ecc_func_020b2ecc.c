/* Decompiled C draft; module arm9; ROM address 020b2ecc. No matching claim. */
#include "types.h"
#include "deps/020b2ecc_func_020b2ecc.h"

undefined4 func_020b2ecc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_10 [2];
  
  uVar1 = GetCurrentMissionLevel_0();
  uVar2 = GetCurrentMissionLevelStage_0();
  iVar3 = IsMissionStageBeaten(uVar1,uVar2,local_10);
  iVar4 = func_020b2d54();
  if ((((iVar4 == 0) && (*(int *)(*piRam020b2f14 + 0x20) != 0)) && (iVar3 != 0)) &&
     (local_10[0] - 5U < 3)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

