/* Decompiled C draft; module arm9; ROM address 0202d9fc. No matching claim. */
#include "types.h"
#include "deps/0202d9fc_func_0202d9fc.h"

uint func_0202d9fc(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = iRam0202da40;
  iVar2 = iRam0202da3c;
  piVar1 = piRam0202da38;
  uVar5 = 0;
  do {
    iVar4 = func_0206174c(*(int *)(*piVar1 + iVar2) + iVar3 * (uVar5 & 0xff));
    if (iVar4 == 0) {
      return uVar5;
    }
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 10);
  return 0xffffffff;
}

