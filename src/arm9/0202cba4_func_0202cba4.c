/* Decompiled C draft; module arm9; ROM address 0202cba4. No matching claim. */
#include "types.h"
#include "deps/0202cba4_func_0202cba4.h"

void func_0202cba4(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam0202cbf0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    piVar2 = (int *)(*piVar1 + 0x50 + iVar3);
    iVar5 = *(int *)(*piVar1 + 0x50 + iVar3);
    if (iVar5 < 10) {
      *piVar2 = iVar5 + 1;
    }
    else if (piVar2[1] != piVar2[3]) {
      *piVar2 = 0;
      piVar2[2] = piVar2[3];
      iVar5 = piVar2[3];
      if (iVar5 < piVar2[1]) {
        piVar2[3] = iVar5 + 1;
      }
      else {
        piVar2[3] = iVar5 + -1;
      }
    }
    iVar3 = iVar3 + 0x2c;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

