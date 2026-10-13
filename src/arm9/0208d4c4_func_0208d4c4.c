/* Decompiled C draft; module arm9; ROM address 0208d4c4. No matching claim. */
#include "types.h"
#include "deps/0208d4c4_func_0208d4c4.h"

void func_0208d4c4(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  uint uVar6;
  
  uVar9 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar2 >> uVar9 * 8 != 0 || uVar2 << uVar9 * -8 + 0x20 != 0) {
    iVar3 = func_020846a8(*(undefined2 *)(param_2 + 0x74));
    uVar2 = uRam0208d64c;
    uVar9 = 0;
    do {
      uVar6 = param_2 + 0x3b0U & 3;
      uVar5 = *(uint *)(param_2 + 0x3b0U & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      lVar1 = (ulonglong)uVar2 * (ulonglong)uVar6;
      uVar7 = (uint)lVar1 >> 0xc |
              (((int)uVar6 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar6 = param_2 + 0x3b4U & 3;
      uVar5 = *(uint *)(param_2 + 0x3b4U & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      lVar1 = (ulonglong)uVar2 * (ulonglong)uVar6;
      uVar8 = (uint)lVar1 >> 0xc |
              (((int)uVar6 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar6 = param_2 + 0x3b8U & 3;
      uVar5 = *(uint *)(param_2 + 0x3b8U & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      lVar1 = (ulonglong)uVar2 * (ulonglong)uVar6;
      uVar4 = (uint)lVar1 >> 0xc |
              (((int)uVar6 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar6 = param_1 + uVar9 * 4;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      *(uint *)(uVar6 + 0x40) = uVar7;
      *(uint *)(uVar6 + 0x44) = uVar8;
      *(uint *)(uVar6 + 0x48) = uVar4;
      iStack_3c = -uVar7;
      iStack_38 = -uVar8;
      iStack_34 = -uVar4;
      VecFx32_Add(uVar9 * 0xc + iVar3 + 0x34,(uint)(uintptr_t)(&iStack_3c),&iStack_30);
      uVar6 = param_1 + uVar9 * 4;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar4 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      uVar6 = uVar4 + 0x20 & 3;
      uVar5 = *(uint *)(uVar4 + 0x20 & 0xfffffffc);
      uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 4;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar4 + 0x28) = iStack_30 + (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      uVar6 = uVar4 + 0x20 & 3;
      uVar5 = *(uint *)(uVar4 + 0x20 & 0xfffffffc);
      uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 8;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar4 + 0x2c) = iStack_2c + (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      uVar6 = uVar4 + 0x20 & 3;
      uVar5 = *(uint *)(uVar4 + 0x20 & 0xfffffffc);
      uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar4 + 0x30) = iStack_28 + (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      uVar6 = param_2 + 0x44U & 3;
      uVar5 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10) == 0) {
        uVar6 = param_1 + uVar9 * 4;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar4 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
        uVar6 = uVar4 + 0x24;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        *(uint *)(uVar4 + 0x24) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20 | 2;
      }
      else {
        uVar6 = param_1 + uVar9 * 4;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar4 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
        uVar6 = uVar4 + 0x24;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        *(uint *)(uVar4 + 0x24) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xfffffffd;
      }
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < 2);
    return;
  }
  return;
}

