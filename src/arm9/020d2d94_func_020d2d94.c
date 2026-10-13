/* Decompiled C draft; module arm9; ROM address 020d2d94. No matching claim. */
#include "types.h"
#include "deps/020d2d94_func_020d2d94.h"

void func_020d2d94(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(*piRam020d2de4 + 8);
  piVar1 = (int *)(*piRam020d2de4 + iRam020d2de8);
  iVar4 = 0;
  do {
    if (*piVar3 != 0) {
      puVar2 = *(undefined4 **)(*piVar3 + 0x28);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = 0;
      }
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x18);
  iVar4 = 0;
  do {
    if (*piVar1 != 0) {
      puVar2 = *(undefined4 **)(*piVar1 + 0x24);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = 0;
      }
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  return;
}

