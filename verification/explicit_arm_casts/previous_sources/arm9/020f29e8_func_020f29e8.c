/* Decompiled C draft; module arm9; ROM address 020f29e8. No matching claim. */
#include "types.h"
#include "deps/020f29e8_func_020f29e8.h"

void func_020f29e8(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  uint uVar6;
  
  uVar6 = param_1 + 0x60U & 3;
  uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x5cU & 3;
  uVar3 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 100U & 3;
  uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  uVar2 = 0;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar2 = Vector3_MaybeNormalize(param_1 + 0x5c,param_1 + 0x130);
  }
  *(undefined4 *)(param_1 + 300) = uVar2;
  func_020f2a6c(param_1 + 0x130,param_1 + 0xf0,param_1 + 0x13c);
  Vector3_Cross(param_1 + 0x13c,param_1 + 0xf0,param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x124) = uRam020f2a68;
  return;
}

