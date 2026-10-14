/* Decompiled C draft; module arm9; ROM address 020581f4. No matching claim. */
#include "types.h"
#include "deps/020581f4_func_020581f4.h"

void func_020581f4(void)

{
  int iVar1;
  
  if ((int *)*piRam02058218 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)*piRam02058218;
  }
  if (iVar1 == 1) {
    func_020518c8(1);
  }
  return;
}

