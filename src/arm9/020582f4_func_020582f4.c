/* Decompiled C draft; module arm9; ROM address 020582f4. No matching claim. */
#include "types.h"
#include "deps/020582f4_func_020582f4.h"

void func_020582f4(void)

{
  int iVar1;
  
  iVar1 = *piRam02058330;
  if (*(int *)(iVar1 + 0x10) == 0) {
    if (*(int *)(iVar1 + 0xc) == 0xb) {
      func_02052da4();
      return;
    }
    if (*(int *)(iVar1 + 0xc) != 0x25) {
      return;
    }
    iVar1 = iVar1 + iRam02058334;
    *(undefined2 *)(iVar1 + 0x10) = 6;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

