/* Decompiled C draft; module arm9; ROM address 020591cc. No matching claim. */
#include "types.h"
#include "deps/020591cc_func_020591cc.h"

bool func_020591cc(void)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  
  bVar3 = false;
  piVar2 = (int *)*piRam0205927c;
  if (piVar2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *piVar2;
  }
  if ((iVar1 != 0) && (piVar2[1] != 0xd)) {
    bVar3 = true;
  }
  if (!bVar3) {
    return true;
  }
  StateDualHandler_Execute((int)piVar2 + iRam02059280);
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  piVar2 = (int *)*piRam0205927c;
  if (piVar2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *piVar2;
  }
  if ((iVar1 != 0) && (piVar2[1] != 0xd)) {
    bVar3 = true;
  }
  if ((bVar3) && ((*(ushort *)((int)piVar2 + iRam02059284) & 0x80) == 0)) {
    bVar4 = true;
  }
  if ((bVar4) && (piVar2[2] != 9)) {
    bVar5 = true;
  }
  if (!bVar5) {
    if (piVar2 == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *piVar2;
    }
    if ((iVar1 == 1) && ((char)piVar2[0x21] == '\0')) {
      func_02050e60(7);
    }
  }
  return *(short *)(*piRam0205927c + iRam02059288) == 0xf;
}

