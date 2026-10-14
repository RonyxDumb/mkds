/* Decompiled C draft; module arm9; ROM address 020e6d34. No matching claim. */
#include "types.h"
#include "deps/020e6d34_func_020e6d34.h"

void func_020e6d34(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  *(undefined4 *)(param_2 + 0xc) = *param_1;
  *(undefined4 *)(param_2 + 0x10) = uVar2;
  *(undefined4 *)(param_2 + 0x14) = uVar3;
  uVar1 = *(uint *)(uRam020e6d84 & 0xfffffffc) >> (uRam020e6d84 & 3) * 8 |
          *(uint *)(uRam020e6d84 & 0xfffffffc) << (uRam020e6d84 & 3) * -8 + 0x20;
  uVar2 = *(undefined4 *)(uVar1 + 0x1c);
  uVar3 = *(undefined4 *)(uVar1 + 0x20);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(uVar1 + 0x18);
  *(undefined4 *)(param_2 + 0x1c) = uVar2;
  *(undefined4 *)(param_2 + 0x20) = uVar3;
  Vector3_Cross((uint)(uintptr_t)((undefined4 *)(param_2 + 0xc)),(uint)(uintptr_t)((undefined4 *)(param_2 + 0x18)),(uint *)(uintptr_t)(param_2));
  Vector3_MaybeNormalize(param_2,(int *)(uintptr_t)(param_2));
  return;
}

