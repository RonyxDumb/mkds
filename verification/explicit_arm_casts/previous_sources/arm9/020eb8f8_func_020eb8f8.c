/* Decompiled C draft; module arm9; ROM address 020eb8f8. No matching claim. */
#include "types.h"
#include "deps/020eb8f8_func_020eb8f8.h"

void func_020eb8f8(int param_1)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_18 [16];
  uint uVar6;
  
  func_020ebc2c();
  uVar6 = param_1 + 0xccU & 3;
  uVar5 = *(uint *)(param_1 + 0xccU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  *(uint *)(param_1 + 0xcc) =
       uVar6 - ((uint)((ulonglong)uVar6 * 0xa4) >> 0xc |
               (((int)uVar6 >> 0x1f) * 0xa4 + (int)((ulonglong)uVar6 * 0xa4 >> 0x20)) * 0x100000);
  uVar6 = param_1 + 0xd4U & 3;
  uVar5 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  *(uint *)(param_1 + 0xd4) =
       uVar6 - ((uint)((ulonglong)uVar6 * 0xa4) >> 0xc |
               (((int)uVar6 >> 0x1f) * 0xa4 + (int)((ulonglong)uVar6 * 0xa4 >> 0x20)) * 0x100000);
  VecFx32_Add(param_1 + 0xd8,param_1 + 0xe4,param_1 + 0xd8);
  uVar1 = *(ushort *)(param_1 + 0xf0);
  uVar6 = (uint)uVar1;
  if (uVar6 < 0x8000) {
    *(ushort *)(param_1 + 0xf0) = uVar1 - (short)(uVar6 * 0xf6 >> 0xc);
  }
  else {
    *(ushort *)(param_1 + 0xf0) = uVar1 + (short)((0x10000 - uVar6) * 0xf6 >> 0xc);
  }
  uVar6 = param_1 + 0x14U & 3;
  uVar5 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - iRam020ebaa8;
  VecFx32_Add(param_1 + 0xcc,param_1 + 0x10,param_1 + 0xcc);
  VecFx32_Add(param_1 + 0xb0,param_1 + 0xcc,param_1 + 4);
  VecFx32_Add(param_1 + 0xbc,param_1 + 0xd8,param_1 + 0xa0);
  uVar6 = param_1 + 0xa4U & 3;
  uVar5 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  uVar3 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0xa0U & 3;
  uVar5 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0xa8U & 3;
  uVar4 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar5 * (longlong)(int)uVar5 + (longlong)(int)uVar3 * (longlong)(int)uVar3;
  if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
    Vector3_MaybeNormalize(param_1 + 0xa0,param_1 + 0xa0);
  }
  *(short *)(param_1 + 0xac) = *(short *)(param_1 + 200) + *(short *)(param_1 + 0xf0);
  func_020d7a3c(param_1 + 0xa0,*(undefined2 *)(param_1 + 0xac),auStack_18);
  func_01ffccd0(param_1 + 0x28,auStack_18);
  uVar6 = param_1 + 0x84U & 3;
  uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if (0x59 < (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
    *puRam020ebaac = 0;
    *(undefined2 *)(param_1 + 0x90) = 0;
    *(undefined2 *)(param_1 + 0x92) = 1;
    return;
  }
  return;
}

