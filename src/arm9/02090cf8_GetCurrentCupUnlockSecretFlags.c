/* Decompiled C draft; module arm9; ROM address 02090cf8. No matching claim. */
#include "types.h"
#include "deps/02090cf8_GetCurrentCupUnlockSecretFlags.h"

uint GetCurrentCupUnlockSecretFlags(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_5c;
  uint local_48;
  uint local_40;
  uint local_34;
  uint local_2c;
  
  uVar3 = 0;
  iVar4 = 0;
  local_48 = 0;
  local_40 = 0;
  local_34 = 0;
  local_5c = 0;
  local_2c = 8;
  do {
    iVar2 = CheckSavedSecretFlag_from_thumb(iVar4);
    uVar5 = local_5c;
    if (iVar2 == 0) {
      iVar2 = CupHasRecord(0,iVar4);
      bVar1 = false;
      if ((iVar2 != 0) && (iVar2 = CupGetResult(0,iVar4), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        iVar2 = CupHasRecord(1,iVar4);
        bVar1 = false;
        if ((iVar2 != 0) && (iVar2 = CupGetResult(1,iVar4), iVar2 == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          SetSavedSecretFlag_from_thumb(iVar4);
          uVar5 = 1;
        }
      }
    }
    iVar2 = CheckSavedSecretFlag_from_thumb();
    uVar6 = local_48;
    if (iVar2 == 0) {
      iVar2 = CupHasRecord(2,iVar4);
      bVar1 = false;
      if ((iVar2 != 0) && (iVar2 = CupGetResult(2,iVar4), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        SetSavedSecretFlag_from_thumb(iVar4 + 4);
        uVar6 = 2;
      }
    }
    iVar2 = CheckSavedSecretFlag_from_thumb();
    uVar7 = local_40;
    if (iVar2 == 0) {
      iVar2 = CupHasRecord(4,iVar4);
      bVar1 = false;
      if ((iVar2 != 0) && (iVar2 = CupGetResult(4,iVar4), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        iVar2 = CupHasRecord(5,iVar4);
        bVar1 = false;
        if ((iVar2 != 0) && (iVar2 = CupGetResult(5,iVar4), iVar2 == 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          SetSavedSecretFlag_from_thumb(iVar4 + 8);
          uVar7 = 4;
        }
      }
    }
    iVar2 = CheckSavedSecretFlag_from_thumb();
    uVar8 = local_34;
    if (iVar2 == 0) {
      iVar2 = CupHasRecord(6,iVar4);
      bVar1 = false;
      if ((iVar2 != 0) && (iVar2 = CupGetResult(6,iVar4), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        SetSavedSecretFlag_from_thumb(iVar4 + 0xc);
        uVar8 = local_2c;
      }
    }
    uVar3 = uVar3 | uVar5 | uVar6 | uVar7 | uVar8;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  uVar5 = 0;
  iVar4 = CheckSavedSecretFlag_from_thumb(0x10);
  if (iVar4 == 0) {
    iVar4 = CupHasRecord(3,2);
    if ((iVar4 == 0) || (iVar4 = CupGetResult(3,2), iVar4 != 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      iVar4 = CupHasRecord(7,2);
      if ((iVar4 == 0) || (iVar4 = CupGetResult(7,2), iVar4 != 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        SetSavedSecretFlag_from_thumb(0x10);
        uVar5 = 0x10;
      }
    }
  }
  return uVar3 | uVar5;
}

