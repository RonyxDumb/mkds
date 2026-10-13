/* Decompiled C draft; module arm9; ROM address 02090b24. No matching claim. */
#include "types.h"
#include "deps/02090b24_GetCurrentCharacterUnlockSecretFlags.h"

uint GetCurrentCharacterUnlockSecretFlags(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  bVar1 = false;
  iVar3 = CheckSavedSecretFlag_from_thumb(0x14);
  if (iVar3 == 0) {
    iVar3 = CupHasRecord(3,0);
    if ((iVar3 == 0) || (iVar3 = CupGetResult(3,0), iVar3 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      SetSavedSecretFlag_from_thumb(0x14);
      bVar1 = true;
    }
  }
  if (bVar1) {
    uVar4 = 0x20;
  }
  bVar1 = false;
  iVar3 = CheckSavedSecretFlag_from_thumb(0x15);
  if (iVar3 == 0) {
    iVar3 = CupHasRecord(7,0);
    if ((iVar3 == 0) || (iVar3 = CupGetResult(7,0), iVar3 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      SetSavedSecretFlag_from_thumb(0x15);
      bVar1 = true;
    }
  }
  if (bVar1) {
    uVar4 = uVar4 | 0x40;
  }
  bVar1 = false;
  iVar3 = CheckSavedSecretFlag_from_thumb(0x16);
  if (iVar3 == 0) {
    iVar3 = CupHasRecord(7,1);
    if ((iVar3 == 0) || (iVar3 = CupGetResult(7,1), iVar3 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      SetSavedSecretFlag_from_thumb(0x16);
      bVar1 = true;
    }
  }
  if (bVar1) {
    uVar4 = uVar4 | 0x80;
  }
  bVar1 = false;
  iVar3 = CheckSavedSecretFlag_from_thumb(0x17);
  if (iVar3 == 0) {
    iVar3 = CupHasRecord(3,3);
    if ((iVar3 == 0) || (iVar3 = CupGetResult(3,3), iVar3 != 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (!bVar2) {
      iVar3 = CupHasRecord(7,3);
      if ((iVar3 == 0) || (iVar3 = CupGetResult(7,3), iVar3 != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) goto LAB_02090ce0;
    }
    SetSavedSecretFlag_from_thumb(0x17);
    bVar1 = true;
  }
LAB_02090ce0:
  if (bVar1) {
    uVar4 = uVar4 | 0x100;
  }
  return uVar4;
}

