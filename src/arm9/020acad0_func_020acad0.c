/* Decompiled C draft; module arm9; ROM address 020acad0. No matching claim. */
#include "types.h"
#include "deps/020acad0_func_020acad0.h"

void func_020acad0(void)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = func_020adaf8();
  uVar1 = func_020ae488();
  *(undefined2 *)(*piRam020acafc + 0x60) = uVar1;
  if (9 < iVar2) {
    func_020adad0(3,5);
  }
  func_020acff4();
  return;
}

