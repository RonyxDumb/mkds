/* Decompiled C draft; module arm9; ROM address 02038de4. No matching claim. */
#include "types.h"
#include "deps/02038de4_DisplayConfig_SomeFn.h"

void DisplayConfig_SomeFn(undefined2 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  iVar3 = 10;
  puVar4 = param_1;
  puVar5 = param_2;
  do {
    puVar6 = puVar5 + 1;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 2;
    uVar2 = *puVar6;
    iVar3 = iVar3 + -1;
    puVar6 = puVar4 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 2;
    *puVar6 = uVar2;
  } while (iVar3 != 0);
  DisplayEngineConfig_SomeClearFn(param_1 + 0x14,param_2[4]);
  DisplayEngineConfig_SomeClearFn(param_1 + 0x38,param_2[6]);
  *(undefined4 *)(param_1 + 0x36) = 0;
  *(undefined4 *)(param_1 + 0x5e) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x62) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x66) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6a) = 0;
  *(undefined4 *)(param_1 + 0x5a) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  return;
}

