/* Decompiled C draft; module arm9; ROM address 0203b230. No matching claim. */
#include "types.h"
#include "deps/0203b230_SomeMissionLevelStageChecking.h"

bool SomeMissionLevelStageChecking(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short sVar6;
  short unaff_r6;
  char cStack_18;
  byte bStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  uint uVar5;
  
  uVar2 = *(uint *)(uRam0203b31c & 0xfffffffc) >> (uRam0203b31c & 3) * 8 |
          *(uint *)(uRam0203b31c & 0xfffffffc) << (uRam0203b31c & 3) * -8 + 0x20;
  uVar5 = uVar2 + 8 & 3;
  uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uVar5 == 4) {
    sVar6 = (short)*(char *)(uVar2 + 0x54);
  }
  else {
    sVar6 = -1;
  }
  if (uVar5 == 4) {
    unaff_r6 = (short)*(char *)(uVar2 + 0x55);
  }
  if (uVar5 != 4) {
    unaff_r6 = -1;
  }
  iVar3 = IsRacerFinishedRace((short)*(char *)(uVar2 + 0x62));
  if (iVar3 == 0) {
    uVar5 = 6;
  }
  else {
    uVar5 = (*(uint *)(uRam0203b320 & 0xfffffffc) >> (uRam0203b320 & 3) * 8 |
            *(uint *)(uRam0203b320 & 0xfffffffc) << (uRam0203b320 & 3) * -8 + 0x20) + 0x4e0;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  }
  if (uVar5 == 0) {
    GetMissionLevelStageInfoByIds_from_thumb(sVar6,unaff_r6,&cStack_18);
    uStack_16 = 1;
    bStack_15 = ComputeMissionInternalScore();
    if (cStack_18 == '\0') {
      bVar1 = true;
    }
    else if (bStack_17 < bStack_15) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      SetMissionLevelStageInfoFromIds_from_thumb(sVar6,unaff_r6,&uStack_16);
      WriteSaveDataMissionRunSection_from_thumb();
    }
    return bVar1;
  }
  return false;
}

