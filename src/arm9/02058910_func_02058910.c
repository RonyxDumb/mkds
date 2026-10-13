/* Decompiled C draft; module arm9; ROM address 02058910. No matching claim. */
#include "types.h"
#include "deps/02058910_func_02058910.h"

void func_02058910(void)

{
  int iVar1;
  
  iVar1 = func_02059ce8();
  if (iVar1 != 0) {
    if (*psRam02058944 == 2) {
      func_0205a108();
      func_020474e4();
    }
    iVar1 = *piRam02058948 + iRam0205894c;
    *(undefined2 *)(iVar1 + 0x10) = 3;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

