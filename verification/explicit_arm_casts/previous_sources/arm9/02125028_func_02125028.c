/* Decompiled C draft; module arm9; ROM address 02125028. No matching claim. */
#include "types.h"
#include "deps/02125028_func_02125028.h"

int func_02125028(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 local_30 [20];
  
  puVar4 = local_30;
  iVar3 = 0x14;
  puVar5 = puRam021250a0;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = CreateDisplayConfig(param_1,local_30);
  DisplayEngineConfig_SetBg1Config(iVar3 + 0x28,0,0,0,0,0x12,2,0);
  DisplayEngineConfig_SetBg3Config(iVar3 + 0x70,1,0,0,0,0xf,0);
  SetGlobalDisplayConfig(iVar3);
  uVar2 = uRam021250a8;
  *puRam021250a4 = *puRam021250a4 & uRam021250a8 | 0x10;
  *puRam021250ac = *puRam021250ac & uVar2 | 0x10;
  return iVar3;
}

