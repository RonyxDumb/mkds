/* Decompiled C draft; module arm9; ROM address 01ffc090. No matching claim. */
#include "types.h"
#include "deps/01ffc090_func_01ffc090.h"

void func_01ffc090(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_2 == 0) {
    uVar4 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 8) != 0) {
      uVar4 = param_1 + 0x2ccU & 3;
      uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar2 = param_1 + 0x2c4U & 3;
      uVar5 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
      *(uint *)(param_1 + 0x3ec) =
           -(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) *
           ((int)*(short *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x32) +
            (int)*(short *)(param_1 + 0x38a) >> 1);
    }
    func_01ffc500(param_1 + 0x2d4);
  }
  uVar4 = param_1 + 0x3ecU & 3;
  uVar2 = *(uint *)(param_1 + 0x3ecU & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if (uVar4 == 0) {
    uVar2 = param_1 + 0x3f0U & 3;
    uVar3 = *(uint *)(param_1 + 0x3f0U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      uVar2 = -uVar2;
    }
    if ((int)uVar2 < 5) {
      *(undefined4 *)(param_1 + 0x3f0) = 0;
      goto LAB_01ffc134;
    }
  }
  uVar2 = param_1 + 0x3f0U & 3;
  uVar3 = *(uint *)(param_1 + 0x3f0U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  lVar1 = (longlong)(int)(uVar4 - uVar2) *
          (longlong)
          (int)(*(uint *)(uRam01ffc154 & 0xfffffffc) >> (uRam01ffc154 & 3) * 8 |
               *(uint *)(uRam01ffc154 & 0xfffffffc) << (uRam01ffc154 & 3) * -8 + 0x20) + 0x800;
  *(uint *)(param_1 + 0x3f0) =
       uVar2 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
LAB_01ffc134:
  uVar4 = param_1 + 0x3f0U & 3;
  uVar2 = *(uint *)(param_1 + 0x3f0U & 0xfffffffc);
  *(ushort *)(param_1 + 0x236) =
       *(short *)(param_1 + 0x236) +
       ((ushort)(uVar2 >> uVar4 * 8) | (ushort)(uVar2 << uVar4 * -8 + 0x20));
  return;
}

