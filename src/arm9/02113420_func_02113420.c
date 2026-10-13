/* Decompiled C draft; module arm9; ROM address 02113420. No matching claim. */
#include "types.h"
#include "deps/02113420_func_02113420.h"

void func_02113420(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02113454;
  *(undefined4 *)(*piRam02113454 + 0x50) = 6;
  *(undefined4 *)(*piVar1 + 0x54) = 0;
  iVar2 = *(int *)(*piVar1 + 0x6c);
  if (iVar2 == 0) {
    func_021139a0();
  }
  else if (iVar2 == 1) {
    func_0211398c();
  }
  func_021139b4();
  return;
}

