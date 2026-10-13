/* Decompiled C draft; module arm9; ROM address 0210f868. No matching claim. */
#include "types.h"
#include "deps/0210f868_func_0210f868.h"

void func_0210f868(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = iRam0210f8a8;
  iVar4 = 0;
  *(undefined4 *)(iRam0210f8a8 + param_1 * 4) = param_2;
  do {
    uVar3 = iVar2 + iVar4 * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) {
      *puRam0210f8ac = 1;
      return;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  *puRam0210f8ac = 0;
  return;
}

