/* Decompiled C draft; module arm9; ROM address 02028fac. No matching claim. */
#include "types.h"
#include "deps/02028fac_func_02028fac.h"

void func_02028fac(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar3 = func_020280dc();
  if (iVar3 == 0) {
    iVar6 = *piRam02028ff4;
    iVar3 = func_02029000(*(undefined4 *)(iVar6 + 0x70));
    iVar4 = func_02028ff8(*(undefined4 *)(iVar6 + 0x78));
    piVar1 = piRam02028ff4;
    for (iVar5 = 0; iVar5 < iVar3 + iVar4; iVar5 = iVar5 + 1) {
      uVar2 = func_02025ebc(*piVar1 + 0xec);
      *(undefined2 *)(*(int *)(iVar6 + 0x7c) + iVar5 * 0x40 + 6) = uVar2;
    }
  }
  return;
}

