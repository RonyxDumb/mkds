/* Decompiled C draft; module arm9; ROM address 02104d78. No matching claim. */
#include "types.h"
#include "deps/02104d78_func_02104d78.h"

void func_02104d78(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_18;
  uint local_14;
  uint local_10;
  uint uVar5;
  
  uVar3 = param_2 + 0x138U & 3;
  uVar2 = *(uint *)(param_2 + 0x138U & 0xfffffffc);
  uVar5 = param_2 + 0x134U & 3;
  uVar4 = *(uint *)(param_2 + 0x134U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    *(undefined4 *)(param_2 + 0x13c) = *(undefined4 *)(param_2 + 0x50);
    *(undefined4 *)(param_2 + 0x140) = *(undefined4 *)(param_2 + 0x54);
    *(undefined4 *)(param_2 + 0x144) = *(undefined4 *)(param_2 + 0x58);
    func_02105338(uVar5,(int)*(short *)(param_2 + 0xd8),param_2 + 0x68);
  }
  else {
    uVar3 = param_1 + 0x8cU & 3;
    uVar2 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    VecFx32_AddScale1((uint)((ulonglong)uRam02104e54 * (ulonglong)uVar3) >> 0xc |
                      (((int)uVar3 >> 0x1f) * uRam02104e54 +
                      ((int)((ulonglong)uRam02104e54 * (ulonglong)uVar3 >> 0x20) - uVar3)) *
                      0x100000,param_1 + 0x38,param_2 + 0x50,(int *)(uintptr_t)(param_2 + 0x13c));
    uVar3 = param_2 + 0x148U & 3;
    uVar2 = *(uint *)(param_2 + 0x148U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = param_2 + 0x68U & 3;
    uVar2 = *(uint *)(param_2 + 0x68U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)(int)uVar4;
    local_18 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar3 = param_2 + 0x6cU & 3;
    uVar2 = *(uint *)(param_2 + 0x6cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)(int)uVar4;
    local_14 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar3 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * (longlong)(int)uVar4;
    local_10 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    func_02105338(uVar5,(int)*(short *)(param_2 + 0xd8),(uint)(uintptr_t)(&local_18));
  }
  func_021052fc(uVar5);
  return;
}

