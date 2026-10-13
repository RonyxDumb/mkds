/* Decompiled C draft; module arm9; ROM address 0211e418. No matching claim. */
#include "types.h"
#include "deps/0211e418_func_0211e418.h"

void func_0211e418(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = piRam0211e46c;
  *(int *)(*piRam0211e46c + 0xc) = param_1;
  uVar4 = 0;
  *(undefined2 *)(*piVar1 + 0x10) = 0xffff;
  while( true ) {
    iVar3 = iRam0211e470 * (uVar4 & 0xff);
    iVar2 = func_0206174c(*(int *)(*piVar1 + 4) + iVar3);
    if ((iVar2 != 0) && (iVar2 = func_02061654(*(int *)(*piVar1 + 4) + iVar3), param_1 == iVar2))
    break;
    uVar4 = uVar4 + 1;
    if (9 < (int)uVar4) {
      return;
    }
  }
  *(short *)(*piRam0211e46c + 0x10) = (short)uVar4;
  return;
}

