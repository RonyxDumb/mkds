/* Decompiled C draft; module arm9; ROM address 0204ef88. No matching claim. */
#include "types.h"
#include "deps/0204ef88_func_0204ef88.h"

void func_0204ef88(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*puRam0204efc0;
  if (piVar2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *piVar2;
  }
  if (iVar1 == 2) {
    if (*(ushort *)((int)piVar2 + iRam0204efc4) == uRam0204efc8) {
      func_02050e60(8);
      return;
    }
    func_02007008();
  }
  return;
}

