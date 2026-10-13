/* Decompiled C draft; module arm9; ROM address 02009494. No matching claim. */
#include "types.h"
#include "deps/02009494_func_02009494.h"

void func_02009494(void)

{
  int iVar1;
  
  iVar1 = iRam020094ac;
  *(undefined2 *)(*(int *)(iRam020094ac + 4) + iRam020094b0) = 1;
  *(undefined1 *)(iVar1 + 0xe) = *(undefined1 *)(*(int *)(iVar1 + 4) + iRam020094b4);
  *(undefined1 *)(iVar1 + 0xc) = 5;
  return;
}

