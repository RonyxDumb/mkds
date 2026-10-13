/* Decompiled C draft; module arm9; ROM address 02018270. No matching claim. */
#include "types.h"
#include "deps/02018270_Mem_Frame_Initialize.h"

int Mem_Frame_Initialize(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  Mem_InitializeHeapHead((undefined4 *)(uintptr_t)(param_1),uRam020182bc,param_1 + 0x30,param_2,param_3);
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return param_1;
}

