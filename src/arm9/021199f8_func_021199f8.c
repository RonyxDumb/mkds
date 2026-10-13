/* Decompiled C draft; module arm9; ROM address 021199f8. No matching claim. */
#include "types.h"
#include "deps/021199f8_func_021199f8.h"

void func_021199f8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02119a34;
  *(undefined4 *)(*piRam02119a34 + 0x38) = 8;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x40) == 0) {
    if ((*(int *)(iVar2 + 0x6c) == 1) && (iVar2 = func_0211e130(), iVar2 != 0)) {
      func_021282c8();
      return;
    }
  }
  else {
    func_021282c8();
  }
  return;
}

