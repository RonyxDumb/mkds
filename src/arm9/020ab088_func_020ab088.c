/* Decompiled C draft; module arm9; ROM address 020ab088. No matching claim. */
#include "types.h"
#include "deps/020ab088_func_020ab088.h"

void func_020ab088(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  Mem_CpuFill8((uint *)(uintptr_t)(uRam020ab0fc),0,0x54);
  puVar1 = puRam020ab100;
  *puRam020ab100 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_2;
  puVar1[3] = param_3;
  puVar1[4] = param_4;
  puVar1[5] = param_5;
  puVar1[7] = param_6;
  func_020ab714();
  func_020ab5e4((undefined2 *)(uintptr_t)(uRam020ab104),0x28,5);
  func_020ab580(puRam020ab108[2] | *puRam020ab108 | 0xf0 | puRam020ab108[1]);
  puVar2 = puRam020ab110;
  puVar1 = puRam020ab10c;
  uVar5 = *puRam020ab10c;
  *puRam020ab110 = uVar5;
  puVar3 = puRam020ab114;
  *puRam020ab114 = uVar5;
  puVar4 = puRam020ab118;
  *puRam020ab118 = uVar5;
  puVar4[1] = puVar1[1];
  puVar3[1] = puVar1[2];
  puVar2[1] = puVar1[3];
  return;
}

