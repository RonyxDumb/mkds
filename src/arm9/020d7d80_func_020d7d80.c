/* Decompiled C draft; module arm9; ROM address 020d7d80. No matching claim. */
#include "types.h"
#include "deps/020d7d80_func_020d7d80.h"

void func_020d7d80(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)*param_1;
  iVar3 = piVar5[1];
  iVar4 = 0;
  if (0 < iVar3) {
    iVar2 = 0;
    do {
      iVar1 = *piVar5 + iVar2;
      *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0x40);
      *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x44);
      iVar2 = iVar2 + 0x54;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  return;
}

