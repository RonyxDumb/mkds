/* Decompiled C draft; module arm9; ROM address 0210f808. No matching claim. */
#include "types.h"
#include "deps/0210f808_func_0210f808.h"

void func_0210f808(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = iRam0210f854;
  uVar3 = 0;
  do {
    *(undefined2 *)(iVar1 + uVar3 * 0xc) = 0xffff;
    iVar2 = iVar1 + uVar3 * 0xc;
    *(undefined2 *)(iVar2 + 2) = 0xffff;
    *(undefined4 *)(iVar2 + 4) = 0xffffffff;
    *(char *)(iVar2 + 8) = (char)uVar3;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 2);
  return;
}

