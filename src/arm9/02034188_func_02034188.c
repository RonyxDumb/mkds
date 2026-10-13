/* Decompiled C draft; module arm9; ROM address 02034188. No matching claim. */
#include "types.h"
#include "deps/02034188_func_02034188.h"

void func_02034188(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = 0;
  iVar3 = 0;
  uVar7 = 0;
  iVar2 = *piRam0203423c;
  iVar6 = *(int *)(iVar2 + 0xd8);
  if (0 < iVar6) {
    iVar5 = 0;
    do {
      if (*(int *)(*piRam02034240 + (uVar7 & 0xffff) * 0x30 + 0x74) == 0) {
        *(int *)(iVar2 + iVar5 + 0xec) = iVar4;
        iVar4 = iVar4 + 1;
      }
      iVar5 = iVar5 + 0xc;
      uVar7 = uVar7 + 1;
      iVar2 = *piRam0203423c;
      iVar6 = *(int *)(iVar2 + 0xd8);
    } while ((int)uVar7 < iVar6);
  }
  piVar1 = piRam02034240;
  uVar7 = 0;
  if (0 < iVar6) {
    do {
      if (*(int *)(*piRam02034240 + (uVar7 & 0xffff) * 0x30 + 0x74) == 1) {
        iVar3 = iVar3 + 1;
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < *(int *)(iVar2 + 0xd8));
  }
  if ((iVar4 < 4) && (iVar3 < 5)) {
    iVar4 = 4;
  }
  uVar7 = 0;
  if (0 < iVar6) {
    iVar3 = 0;
    do {
      if (*(int *)(*piVar1 + (uVar7 & 0xffff) * 0x30 + 0x74) == 1) {
        *(int *)(iVar2 + iVar3 + 0xec) = iVar4;
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 0xc;
      uVar7 = uVar7 + 1;
      iVar2 = *piRam0203423c;
    } while ((int)uVar7 < *(int *)(iVar2 + 0xd8));
  }
  return;
}

