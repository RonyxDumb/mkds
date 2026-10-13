/* Decompiled C draft; module arm9; ROM address 02038d88. No matching claim. */
#include "types.h"
#include "deps/02038d88_CreateDisplayConfig.h"

int CreateDisplayConfig(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0xdc);
  DisplayConfig_SomeFn(iVar1,param_2);
  if (*(short *)(iVar1 + 10) == 1) {
    puVar2 = (undefined2 *)Mem_AllocateHeap(param_1,8);
    *puVar2 = 0x5000;
    *(undefined1 *)(puVar2 + 1) = 1;
    *(undefined1 *)((int)puVar2 + 3) = 1;
    *(undefined2 **)(iVar1 + 0x6c) = puVar2;
  }
  return iVar1;
}

