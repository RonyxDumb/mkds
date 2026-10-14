/* Decompiled C draft; module arm9; ROM address 02110534. No matching claim. */
#include "types.h"
#include "deps/02110534_func_02110534.h"

void func_02110534(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = iRam02110578;
  iVar2 = iRam02110574;
  iVar6 = 0;
  do {
    uVar4 = iVar2 + iVar6 * 4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = FX_Div(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,param_1);
    *(undefined4 *)(iVar3 + iVar6 * 4) = uVar5;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  return;
}

