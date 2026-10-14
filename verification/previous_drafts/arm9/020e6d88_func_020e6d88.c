/* Decompiled C draft; module arm9; ROM address 020e6d88. No matching claim. */
#include "types.h"
#include "deps/020e6d88_func_020e6d88.h"

void func_020e6d88(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar2;
  
  uVar1 = uRam020e6dec;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  uVar5 = *(uint *)(uRam020e6de8 & 0xfffffffc) >> (uRam020e6de8 & 3) * 8 |
          *(uint *)(uRam020e6de8 & 0xfffffffc) << (uRam020e6de8 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar5 + 0xc) = *param_1;
  *(undefined4 *)(uVar5 + 0x10) = uVar3;
  *(undefined4 *)(uVar5 + 0x14) = uVar4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar3 = *(undefined4 *)(uVar2 + 0x1c);
  uVar4 = *(undefined4 *)(uVar2 + 0x20);
  *(undefined4 *)(uVar5 + 0x18) = *(undefined4 *)(uVar2 + 0x18);
  *(undefined4 *)(uVar5 + 0x1c) = uVar3;
  *(undefined4 *)(uVar5 + 0x20) = uVar4;
  Vector3_Cross((uint)(uintptr_t)((undefined4 *)(uVar5 + 0xc)),(uint)(uintptr_t)((undefined4 *)(uVar5 + 0x18)),(uint *)(uintptr_t)(uVar5));
  uVar2 = *(uint *)(uRam020e6de8 & 0xfffffffc) >> (uRam020e6de8 & 3) * 8 |
          *(uint *)(uRam020e6de8 & 0xfffffffc) << (uRam020e6de8 & 3) * -8 + 0x20;
  Vector3_MaybeNormalize(uVar2,(int *)(uintptr_t)(uVar2));
  return;
}

