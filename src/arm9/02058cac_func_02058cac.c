/* Decompiled C draft; module arm9; ROM address 02058cac. No matching claim. */
#include "types.h"
#include "deps/02058cac_func_02058cac.h"

bool func_02058cac(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  bVar1 = false;
  piVar2 = (int *)*piRam02058da4;
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2;
  }
  if ((iVar3 != 0) && (piVar2[1] != 0xd)) {
    bVar1 = true;
  }
  if (!bVar1) {
    return true;
  }
  if (*piVar2 == 2) {
    uVar4 = (uint)*(ushort *)((int)piVar2 + iRam02058da8);
  }
  else {
    uVar4 = 0;
  }
  if (uVar4 == uRam02058dac) {
    if (piVar2 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar2;
    }
    if (iVar3 == 2) {
      if (*psRam02058db0 == 2) {
        func_02050e60(0);
        return (bool)3;
      }
      return (bool)2;
    }
  }
  StateDualHandler_Execute((int)piVar2 + iRam02058db4);
  bVar6 = false;
  bVar5 = false;
  bVar1 = false;
  piVar2 = (int *)*piRam02058da4;
  if (piVar2 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2;
  }
  if ((iVar3 != 0) && (piVar2[1] != 0xd)) {
    bVar1 = true;
  }
  if ((bVar1) && ((*(ushort *)((int)piVar2 + iRam02058db8) & 0x80) == 0)) {
    bVar5 = true;
  }
  if ((bVar5) && (piVar2[2] != 9)) {
    bVar6 = true;
  }
  if (!bVar6) {
    if (piVar2 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *piVar2;
    }
    if ((iVar3 == 1) && ((char)piVar2[0x21] == '\0')) {
      func_02050e60(7);
    }
  }
  return *(short *)(*piRam02058da4 + iRam02058dbc) == 0xf;
}

