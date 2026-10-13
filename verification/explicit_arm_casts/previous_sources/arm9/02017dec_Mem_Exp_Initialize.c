/* Decompiled C draft; module arm9; ROM address 02017dec. No matching claim. */
#include "types.h"
#include "deps/02017dec_Mem_Exp_Initialize.h"

int Mem_Exp_Initialize(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_14;
  uint local_10;
  
  Mem_InitializeHeapHead(param_1,uRam02017e68,param_1 + 0x38,param_2,param_3);
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x36) = 0;
  uVar2 = uRam02017e6c;
  *(ushort *)(param_1 + 0x36) = *(ushort *)(param_1 + 0x36) & 0xfffe;
  uVar1 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  local_14 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  local_10 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar2 = Mem_Exp_InitializeMemoryBlock(&local_14,uVar2);
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return param_1;
}

