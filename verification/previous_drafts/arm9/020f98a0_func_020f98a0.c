/* Decompiled C draft; module arm9; ROM address 020f98a0. No matching claim. */
#include "types.h"
#include "deps/020f98a0_func_020f98a0.h"

void func_020f98a0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined2 *param_4,
                  int param_5)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  *(undefined4 *)(param_1 + 0xe4) = *param_2;
  *(undefined4 *)(param_1 + 0xe8) = uVar3;
  *(undefined4 *)(param_1 + 0xec) = uVar4;
  if (param_4 == (undefined2 *)0x0) {
    LightInfo_SomeFn((ushort *)(uintptr_t)(param_1 + 0x7c),1);
  }
  else {
    puVar7 = (undefined2 *)(param_1 + 0x7c);
    iVar5 = 4;
    do {
      puVar6 = param_4 + 1;
      uVar2 = *param_4;
      param_4 = param_4 + 2;
      uVar1 = *puVar6;
      iVar5 = iVar5 + -1;
      puVar6 = puVar7 + 1;
      *puVar7 = uVar2;
      puVar7 = puVar7 + 2;
      *puVar6 = uVar1;
    } while (iVar5 != 0);
    *puVar7 = *param_4;
  }
  uVar3 = param_3[1];
  uVar4 = param_3[2];
  *(undefined4 *)(param_1 + 0xf0) = *param_3;
  *(undefined4 *)(param_1 + 0xf4) = uVar3;
  *(undefined4 *)(param_1 + 0xf8) = uVar4;
  if (param_5 != 0) {
    uVar3 = 0;
  }
  uVar2 = (undefined2)uVar3;
  if (param_5 == 0) {
    uVar2 = 5;
  }
  *(undefined2 *)(param_1 + 0x116) = uVar2;
  return;
}

