/* Decompiled C draft; module arm9; ROM address 020467d0. No matching claim. */
#include "types.h"
#include "deps/020467d0_GetCupForCourse.h"

int GetCupForCourse(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 9;
  iVar3 = 0;
  do {
    iVar5 = 0;
    do {
      uVar2 = iRam02046824 + iVar3 * 0x10 + iVar5 * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      iVar5 = iVar5 + 1;
      if (param_1 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
        iVar4 = iVar3;
      }
    } while (iVar5 < 4);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return iVar4;
}

