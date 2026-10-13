/* Decompiled C draft; module arm9; ROM address 02117db0. No matching claim. */
#include "types.h"
#include "deps/02117db0_func_02117db0.h"

void func_02117db0(void)

{
  int iVar1;
  
  iVar1 = *piRam02117e10;
  if (((*(int *)(iVar1 + 0x3c) == 0) && (*(int *)(iVar1 + 0x88) == 1)) ||
     (*(int *)(iVar1 + 0x88) == 2)) {
    *puRam02117e14 = *puRam02117e14 & uRam02117e18 | uRam02117e1c;
  }
  if (*psRam02117e20 == 2) {
    func_0211f498();
  }
  else {
    func_0211de34();
    func_0211df38();
    func_0211f2ac();
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam02117e10 + 0x2c));
  *piRam02117e10 = 0;
  return;
}

