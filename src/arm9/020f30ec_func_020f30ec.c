/* Decompiled C draft; module arm9; ROM address 020f30ec. No matching claim. */
#include "types.h"
#include "deps/020f30ec_func_020f30ec.h"

void func_020f30ec(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_3 != (undefined4 *)0x0) {
    uVar3 = param_3[1];
    uVar5 = param_3[2];
    *(undefined4 *)(param_1 + 0x5c) = *param_3;
    *(undefined4 *)(param_1 + 0x60) = uVar3;
    *(undefined4 *)(param_1 + 100) = uVar5;
  }
  iVar2 = iRam020f3148;
  uVar1 = param_1 + 0x70U & 3;
  uVar4 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  if ((int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < iRam020f3148) {
    *(int *)(param_1 + 0x68) = iRam020f3148;
    *(int *)(param_1 + 0x6c) = iVar2;
    *(int *)(param_1 + 0x70) = iVar2;
  }
  uVar3 = uRam020f314c;
  *(undefined4 *)(param_1 + 300) = param_2;
  *(undefined4 *)(param_1 + 0x124) = uVar3;
  uVar1 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xf8ffffff;
  return;
}

