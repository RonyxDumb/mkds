/* Decompiled C draft; module arm9; ROM address 0211784c. No matching claim. */
#include "types.h"
#include "deps/0211784c_func_0211784c.h"

void func_0211784c(void)

{
  int *piVar1;
  int iVar2;
  
  func_021184d4();
  func_02118414();
  if (*(int *)(*piRam021178ac + 0x38) == 5) {
    *(undefined4 *)(*piRam021178ac + 0x68) = 1;
  }
  piVar1 = piRam021178ac;
  *(int *)(*piRam021178ac + 0x38) = *(int *)(*piRam021178ac + 0x38) + 1;
  if ((9 < *(int *)(*piVar1 + 0x38)) && (iVar2 = func_021185d4(), iVar2 == 0)) {
    if (*(int *)(*piRam021178ac + 0x3c) == 0) {
      func_02118148();
      return;
    }
    func_021185ec();
    *(undefined4 *)(*piRam021178ac + 0x88) = 1;
    func_02118024();
  }
  return;
}

