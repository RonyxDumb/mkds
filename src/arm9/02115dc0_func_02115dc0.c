/* Decompiled C draft; module arm9; ROM address 02115dc0. No matching claim. */
#include "types.h"
#include "deps/02115dc0_func_02115dc0.h"

void func_02115dc0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02115df4;
  *(undefined4 *)(*piRam02115df4 + 0x58) = 6;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  iVar2 = *(int *)(*piVar1 + 0x78);
  if (iVar2 == 0) {
    func_02116230();
  }
  else if (iVar2 == 1) {
    func_0211621c();
  }
  func_02116244();
  return;
}

