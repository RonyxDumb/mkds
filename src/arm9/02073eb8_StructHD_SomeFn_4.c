/* Decompiled C draft; module arm9; ROM address 02073eb8. No matching claim. */
#include "types.h"
#include "deps/02073eb8_StructHD_SomeFn_4.h"

void StructHD_SomeFn_4(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = param_1 + 0x144U & 3;
    uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    uVar2 = param_1 + 0x14cU & 3;
    uVar3 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
    *(uint *)(param_1 + 0x144) =
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (int)*(short *)(param_1 + 0x150) +
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
    uVar4 = param_1 + 0x144U & 3;
    uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 0x1001) {
      if ((int)uVar4 < -0x1000) {
        *(short *)(param_1 + 0x150) = -*(short *)(param_1 + 0x150);
        uVar4 = param_1 + 0x144U & 3;
        uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
        *(uint *)(param_1 + 0x144) = -0x2000 - (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
      }
    }
    else {
      *(short *)(param_1 + 0x150) = -*(short *)(param_1 + 0x150);
      uVar4 = param_1 + 0x144U & 3;
      uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
      *(uint *)(param_1 + 0x144) = 0x2000 - (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
    }
    uVar4 = param_1 + 0x148U & 3;
    uVar5 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    uVar2 = param_1 + 0x154U & 3;
    uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) *
            (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    *(uint *)(param_1 + 0x148) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar4 = param_1 + 0x148U & 3;
    uVar2 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    *(uint *)(param_1 + 0x148) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - 0x14;
    uVar4 = param_1 + 0x144U & 3;
    uVar5 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    uVar2 = param_1 + 0x148U & 3;
    uVar3 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) *
            (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    *(uint *)(param_1 + 0x158) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar4 = param_1 + 0x148U & 3;
    uVar2 = *(uint *)(param_1 + 0x148U & 0xfffffffc);
    if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < 1) {
      *(undefined4 *)(param_1 + 0x158) = 0;
      *(undefined4 *)(param_1 + 0x140) = 0;
    }
    return;
  }
  return;
}

