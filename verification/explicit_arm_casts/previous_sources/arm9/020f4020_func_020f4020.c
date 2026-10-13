/* Decompiled C draft; module arm9; ROM address 020f4020. No matching claim. */
#include "types.h"
#include "deps/020f4020_func_020f4020.h"

void func_020f4020(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 + 0x74;
  iVar4 = 0;
  iVar5 = param_1;
  do {
    *(int *)(param_1 + iVar4 * 4 + 100) = iVar3;
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar5 + 0x74) = *param_2;
    *(undefined4 *)(iVar5 + 0x78) = uVar1;
    *(undefined4 *)(iVar5 + 0x7c) = uVar2;
    iVar3 = iVar3 + 0xc;
    param_2 = param_2 + 3;
    iVar5 = iVar5 + 0xc;
  } while (iVar4 < 4);
  *(undefined4 *)(param_1 + 0x60) = 0;
  func_020d7d18(param_1,1,param_1 + 100,param_3);
  return;
}

