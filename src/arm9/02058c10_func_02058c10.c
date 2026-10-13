/* Decompiled C draft; module arm9; ROM address 02058c10. No matching claim. */
#include "types.h"
#include "deps/02058c10_func_02058c10.h"

void func_02058c10(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = iRam02058c70;
  piVar3 = (int *)*puRam02058c6c;
  if (piVar3[4] == 0) {
    if (piVar3 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *piVar3;
    }
    if (iVar2 != 1) {
      *(undefined2 *)((int)piVar3 + iRam02058c70 + 0x10) = 0x16;
      *(undefined2 *)((int)piVar3 + iVar1 + 0x12) = 1;
      return;
    }
    iVar2 = piVar3[3];
    if (iVar2 == 0xb) {
LAB_02058c4c:
      func_02051814(0);
      return;
    }
    if (iVar2 == 0xd) {
      *(undefined2 *)((int)piVar3 + iRam02058c70 + 0x10) = 7;
      *(undefined2 *)((int)piVar3 + iVar1 + 0x12) = 1;
    }
    else if (iVar2 == 0xf) goto LAB_02058c4c;
  }
  return;
}

