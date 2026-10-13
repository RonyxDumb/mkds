/* Decompiled C draft; module arm9; ROM address 0210efac. No matching claim. */
#include "types.h"
#include "deps/0210efac_func_0210efac.h"

void func_0210efac(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

