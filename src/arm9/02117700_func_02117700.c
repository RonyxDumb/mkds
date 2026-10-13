/* Decompiled C draft; module arm9; ROM address 02117700. No matching claim. */
#include "types.h"
#include "deps/02117700_func_02117700.h"

void func_02117700(void)

{
  int iVar1;
  
  func_02118414();
  iVar1 = func_021277ac();
  if (iVar1 != 0) {
    iVar1 = func_02127794();
    if ((iVar1 == -1) || (iVar1 == 0)) {
      func_021181b8();
      return;
    }
    if (iVar1 != 1) {
      return;
    }
    *(undefined4 *)(*piRam02117754 + 0x88) = 3;
    func_02118024();
    if (*psRam02117758 == 2) {
      func_0211f378();
    }
  }
  return;
}

