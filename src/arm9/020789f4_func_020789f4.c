/* Decompiled C draft; module arm9; ROM address 020789f4. No matching claim. */
#include "types.h"
#include "deps/020789f4_func_020789f4.h"

void func_020789f4(void)

{
  int iVar1;
  
  iVar1 = *piRam02078a30;
  if (*(int *)(iVar1 + 0x54) == 0) {
    *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + 0x15;
    if (-0x2e < *(int *)(iVar1 + 0x50)) {
      *(undefined4 *)(iVar1 + 0x50) = 0xffffffd2;
      return;
    }
  }
  else {
    if (*(int *)(iVar1 + 0x54) != 1) {
      return;
    }
    *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + -0x15;
    if (*(int *)(iVar1 + 0x50) < -0xfa) {
      *(undefined4 *)(iVar1 + 0x50) = 0xffffff06;
    }
  }
  return;
}

