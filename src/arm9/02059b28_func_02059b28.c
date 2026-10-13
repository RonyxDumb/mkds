/* Decompiled C draft; module arm9; ROM address 02059b28. No matching claim. */
#include "types.h"
#include "deps/02059b28_func_02059b28.h"

undefined4 func_02059b28(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  piVar2 = (int *)*puRam02059b70;
  if (piVar2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *piVar2;
  }
  if (iVar1 == 1) {
    uVar4 = 0x12;
  }
  else {
    uVar4 = 2;
  }
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      if (*(char *)(*(int *)((int)piVar2 + iRam02059b74 + param_1 * 4) + uVar3) == '\0') {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  return 1;
}

