/* Decompiled C draft; module arm9; ROM address 0214d964. No matching claim. */
#include "types.h"
#include "deps/0214d964_func_0214d964.h"

int func_0214d964(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar2 = 0;
  uVar1 = 0;
  do {
    if (9 < (param_1 >> (uVar1 & 0xff) & 0xf)) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    uVar1 = uVar1 + 4;
  } while (iVar2 < 8);
  iVar4 = 0;
  uVar1 = 0;
  iVar2 = 1;
  do {
    iVar3 = iVar2 * (param_1 >> (uVar1 & 0xff) & 0xf) + iVar3;
    iVar4 = iVar4 + 1;
    uVar1 = uVar1 + 4;
    iVar2 = iVar2 * 10;
  } while (iVar4 < 8);
  return iVar3;
}

