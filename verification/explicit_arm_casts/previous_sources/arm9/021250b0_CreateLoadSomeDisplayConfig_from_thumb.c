/* Decompiled C draft; module arm9; ROM address 021250b0. No matching claim. */
#include "types.h"
#include "deps/021250b0_CreateLoadSomeDisplayConfig_from_thumb.h"

int CreateLoadSomeDisplayConfig_from_thumb(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 local_30 [20];
  
  puVar4 = local_30;
  iVar3 = 0x14;
  puVar5 = puRam0212512c;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = CreateDisplayConfig(param_1,local_30);
  DisplayEngineConfig_SetBg1Config(iVar3 + 0x28,0,0,0,0,0x12,2,0);
  DisplayEngineConfig_SetBg3Config(iVar3 + 0x70,1,0,0,0,0x10,4);
  SetGlobalDisplayConfig(iVar3);
  uVar2 = uRam02125134;
  *puRam02125130 = *puRam02125130 & uRam02125134 | 0x10;
  *puRam02125138 = *puRam02125138 & uVar2 | 0x10;
  return iVar3;
}

