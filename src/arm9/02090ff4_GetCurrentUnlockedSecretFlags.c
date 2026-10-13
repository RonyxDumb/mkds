/* Decompiled C draft; module arm9; ROM address 02090ff4. No matching claim. */
#include "types.h"
#include "deps/02090ff4_GetCurrentUnlockedSecretFlags.h"

uint GetCurrentUnlockedSecretFlags(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = GetCurrentCupUnlockSecretFlags();
  uVar4 = GetCurrentCharacterUnlockSecretFlags();
  uVar7 = 0;
  bVar1 = false;
  uVar5 = CheckExtraKartUnlockFlags_from_thumb();
  if (uVar5 < 2) {
    iVar6 = CupHasRecord(3,1);
    if ((iVar6 == 0) || (iVar6 = CupGetResult(3,1), iVar6 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      SetMKDSSVExtraKartUnlockFlagsByState_from_thumb(2);
      bVar1 = true;
    }
  }
  if (bVar1) {
    uVar7 = 0x200;
  }
  bVar1 = false;
  uVar5 = CheckExtraKartUnlockFlags_from_thumb();
  if (uVar5 < 3) {
    iVar6 = CupHasRecord(3,2);
    if ((iVar6 == 0) || (iVar6 = CupGetResult(3,2), iVar6 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      iVar6 = CupHasRecord(7,2);
      if ((iVar6 == 0) || (iVar6 = CupGetResult(7,2), iVar6 != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) goto LAB_020910f4;
    }
    SetMKDSSVExtraKartUnlockFlagsByState_from_thumb(3);
    bVar1 = true;
  }
LAB_020910f4:
  if (bVar1) {
    uVar7 = 0x400;
  }
  bVar1 = false;
  uVar5 = CheckExtraKartUnlockFlags_from_thumb();
  if (uVar5 < 4) {
    iVar6 = CupHasRecord(3,3);
    if ((iVar6 == 0) || (iVar6 = CupGetResult(3,3), iVar6 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      iVar6 = CupHasRecord(7,3);
      if ((iVar6 == 0) || (iVar6 = CupGetResult(7,3), iVar6 != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (bVar2) {
        SetMKDSSVExtraKartUnlockFlagsByState_from_thumb(4);
        bVar1 = true;
      }
    }
  }
  if (bVar1) {
    uVar7 = 0x800;
  }
  return uVar3 | uVar4 | uVar7;
}

