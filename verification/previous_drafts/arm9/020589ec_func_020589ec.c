/* Decompiled C draft; module arm9; ROM address 020589ec. No matching claim. */
#include "types.h"
#include "deps/020589ec_func_020589ec.h"

void func_020589ec(void)

{
  int iVar1;
  
  iVar1 = func_0205955c();
  if (iVar1 == 1) {
    iVar1 = *piRam02058a10 + iRam02058a14;
    *(undefined2 *)(iVar1 + 0x10) = 4;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

