/* Decompiled C draft; module arm9; ROM address 0204f148. No matching claim. */
#include "types.h"
#include "deps/0204f148_func_0204f148.h"

void func_0204f148(void)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)*piRam0204f190;
  iVar4 = piVar3[3];
  if (piVar3 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar3;
  }
  if (iVar2 == 1) {
    uVar1 = *(undefined1 *)((int)piVar3 + 0x87);
  }
  else {
    uVar1 = 1;
  }
  piVar3[3] = 0x2a;
  *(undefined4 *)(*piRam0204f190 + 0x10) = 1;
  iVar2 = func_02006ddc(uVar1,uRam0204f194);
  piVar3 = piRam0204f190;
  if (iVar2 == 0) {
    *(undefined4 *)(*piRam0204f190 + 0x10) = 0;
    *(int *)(*piVar3 + 0xc) = iVar4;
  }
  return;
}

