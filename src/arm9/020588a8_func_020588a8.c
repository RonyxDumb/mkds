/* Decompiled C draft; module arm9; ROM address 020588a8. No matching claim. */
#include "types.h"
#include "deps/020588a8_func_020588a8.h"

void func_020588a8(void)

{
  int iVar1;
  
  iVar1 = func_02058dc0(uRam020588cc);
  if (iVar1 == 1) {
    iVar1 = *piRam020588d0 + iRam020588d4;
    *(undefined2 *)(iVar1 + 0x10) = 0xc;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

