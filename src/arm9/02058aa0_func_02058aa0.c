/* Decompiled C draft; module arm9; ROM address 02058aa0. No matching claim. */
#include "types.h"
#include "deps/02058aa0_func_02058aa0.h"

void func_02058aa0(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)*piRam02058b00;
  if (piVar4 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar4;
  }
  if (iVar3 == 1) {
    uVar1 = *(undefined1 *)((int)piVar4 + iRam02058b04);
    iVar3 = func_02059784();
    if (iVar3 == 0) {
      uVar2 = *(ushort *)(*piRam02058b00 + iRam02058b08);
      if (uRam02058b0c < uVar2) {
        func_02050e60(7);
        return;
      }
      *(ushort *)(*piRam02058b00 + iRam02058b08) = uVar2 + 1;
    }
    else {
      iVar3 = func_02050320(1,uVar1,uVar1);
      if (iVar3 != 0) {
        func_02050034(uVar1);
        return;
      }
    }
  }
  return;
}

