/* Decompiled C draft; module arm9; ROM address 02058820. No matching claim. */
#include "types.h"
#include "deps/02058820_func_02058820.h"

void func_02058820(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  func_0214358c(0xe,uRam02058898,0);
  if ((int *)*piRam0205889c == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)*piRam0205889c;
  }
  if (iVar2 == 1) {
    func_020518c8(0);
  }
  iVar2 = iRam020588a0;
  piVar1 = piRam0205889c;
  iVar8 = 0;
  iVar3 = 0;
  do {
    piVar4 = (int *)*piVar1;
    if (piVar4 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *piVar4;
    }
    if (iVar5 == 1) {
      uVar7 = 0x12;
    }
    else {
      uVar7 = 2;
    }
    uVar6 = 0;
    if (uVar7 != 0) {
      do {
        *(undefined1 *)(*(int *)(iVar3 + *piVar1 + iVar2) + uVar6) = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
    }
    iVar3 = iVar3 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 8);
  *(undefined1 *)(*piRam0205889c + iRam020588a4) = 0;
  return;
}

