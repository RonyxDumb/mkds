/* Decompiled C draft; module arm9; ROM address 0200b698. No matching claim. */
#include "types.h"
#include "deps/0200b698_func_0200b698.h"

void func_0200b698(int param_1)

{
  int *piVar1;
  
  piVar1 = piRam0200b6dc;
  if (*(short *)(param_1 + 2) != 0) {
    func_0200b820(0xb);
    return;
  }
  *(undefined4 *)(*piRam0200b6dc + iRam0200b6e0) = 0;
  if (*(int *)(*piVar1 + iRam0200b6e4) != 0) {
    func_0200bab0();
    return;
  }
  func_0200b850(3,0,0);
  return;
}

