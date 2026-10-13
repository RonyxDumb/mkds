/* Decompiled C draft; module arm9; ROM address 020587d8. No matching claim. */
#include "types.h"
#include "deps/020587d8_func_020587d8.h"

void func_020587d8(void)

{
  int iVar1;
  
  iVar1 = *piRam02058818;
  if (*(int *)(iVar1 + 0x10) == 0) {
    if (*(int *)(iVar1 + 0xc) == 0xb) {
      iVar1 = iVar1 + iRam0205881c;
      *(undefined2 *)(iVar1 + 0x10) = 8;
      *(undefined2 *)(iVar1 + 0x12) = 1;
      return;
    }
    if (*(int *)(iVar1 + 0xc) == 0xc) {
      *(undefined4 *)(iVar1 + 0xc) = 0xb;
      return;
    }
    func_02050e60(2);
  }
  return;
}

