/* Decompiled C draft; module arm9; ROM address 020f1a38. No matching claim. */
#include "types.h"
#include "deps/020f1a38_func_020f1a38.h"

void func_020f1a38(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_48 [14];
  
  piVar1 = piRam020f1b00;
  iVar3 = 0;
  do {
    iVar6 = *piVar1 + iVar3 * 0xa8;
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 4) + -1;
    piVar2 = piRam020f1b00;
    local_48[iVar3] = 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xe);
  iVar6 = 0;
  iVar3 = *piRam020f1b04;
  do {
    iVar5 = iVar3 + iVar6 * 0x1c;
    if (*(int *)(iVar3 + iVar6 * 0x1c) != 0) {
      iVar4 = *(int *)(iVar5 + 8);
      iVar5 = *(int *)(iVar5 + 0xc);
      if (local_48[iVar4] < iVar5) {
        local_48[iVar4] = iVar5;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x12);
  iVar3 = 0;
  do {
    iVar6 = *piVar2 + iVar3 * 0xa8;
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + local_48[iVar3];
    iVar6 = *piVar2 + iVar3 * 0xa8;
    *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar6 + 0x10);
    piVar1 = piRam020f1b00;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xe);
  if (*(int *)(*piRam020f1b08 + 8) == 5) {
    iVar3 = 0;
    do {
      iVar6 = *piVar1 + iVar3 * 0xa8;
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 3;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xe);
    return;
  }
  *(int *)(*piRam020f1b00 + iRam020f1b0c) = *(int *)(*piRam020f1b00 + iRam020f1b0c) + 0x10;
  return;
}

