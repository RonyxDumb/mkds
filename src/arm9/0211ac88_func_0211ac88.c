/* Decompiled C draft; module arm9; ROM address 0211ac88. No matching claim. */
#include "types.h"
#include "deps/0211ac88_func_0211ac88.h"

void func_0211ac88(void)

{
  int *piVar1;
  int iVar2;
  
  func_0211c818();
  func_0211c14c();
  piVar1 = piRam0211ace8;
  *(int *)(*piRam0211ace8 + 0x38) = *(int *)(*piRam0211ace8 + 0x38) + 1;
  if (*(int *)(*piVar1 + 0x38) == 5) {
    *(undefined4 *)(*piVar1 + 0x84) = 1;
  }
  iVar2 = *piRam0211ace8;
  if (9 < *(int *)(iVar2 + 0x38)) {
    if ((*(int *)(iVar2 + 0x2c) == 3) || (*(int *)(iVar2 + 0x70) == 1)) {
      func_0211ba1c();
      return;
    }
    func_0211b9d8();
    *(undefined4 *)(*piRam0211ace8 + 0xb8) = 1;
    func_0202b7c0(3);
  }
  return;
}

