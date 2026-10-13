/* Decompiled C draft; module arm9; ROM address 02058b10. No matching claim. */
#include "types.h"
#include "deps/02058b10_func_02058b10.h"

void func_02058b10(void)

{
  int iVar1;
  
  func_020562e8();
  iVar1 = *piRam02058b30 + iRam02058b34;
  *(undefined2 *)(iVar1 + 0x10) = 0xf;
  *(undefined2 *)(iVar1 + 0x12) = 1;
  return;
}

