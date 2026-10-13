/* Decompiled C draft; module arm9; ROM address 020f6e58. No matching claim. */
#include "types.h"
#include "deps/020f6e58_func_020f6e58.h"

void func_020f6e58(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_18 [16];
  
  uVar1 = func_020e6b14();
  Vector3_Cross(param_1 + 0xf0,uVar1,(uint *)(void *)(auStack_18));
  uVar3 = param_1 + 0x108U & 3;
  uVar2 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    uVar3 = param_1 + 0x10cU & 3;
    uVar2 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
    uVar3 = -(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  }
  else {
    uVar3 = param_1 + 0x10cU & 3;
    uVar2 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  }
  VecFx32_AddScale1(uVar3,(uint)(uintptr_t)(auStack_18),param_1 + 0xf0,(int *)(uintptr_t)(param_1 + 0xf0));
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x80;
  uVar3 = param_1 + 0x60U & 3;
  uVar2 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(uint *)(param_1 + 0x60) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x400;
  VecFx32_Add(param_1 + 0x50,param_1 + 0x5c,(int *)(uintptr_t)(param_1 + 0x50));
  *(short *)(param_1 + 0xd8) = *(short *)(param_1 + 0xd8) + -1;
  if (*(short *)(param_1 + 0xd8) < 1) {
    uVar3 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    func_020f0f70((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam020f6f0c & 0xfffffffc) >> (uRam020f6f0c & 3) * 8 |
                  *(uint *)(uRam020f6f0c & 0xfffffffc) << (uRam020f6f0c & 3) * -8 + 0x20),param_1);
    return;
  }
  return;
}

