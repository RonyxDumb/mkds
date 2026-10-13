/* Decompiled C draft; module arm9; ROM address 020f8e78. No matching claim. */
#include "types.h"
#include "deps/020f8e78_func_020f8e78.h"

/* WARNING: Removing unreachable block (ram,0x020f901c) */

void func_020f8e78(int param_1)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  
  *(undefined4 *)(param_1 + 0x70) = uRam020f9048;
  uVar9 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar6 = param_1 + 0x44U & 3;
  uVar12 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20 | 0x40;
  uVar4 = uRam020f904c;
  uVar9 = param_1 + 0x70U & 3;
  uVar5 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  *(uint *)(param_1 + 0x6c) = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  uVar9 = param_1 + 0x6cU & 3;
  uVar5 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  *(uint *)(param_1 + 0x68) = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  uVar9 = uVar4 & 3;
  uVar5 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = param_1 + 0x6cU & 3;
  uVar7 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  iVar10 = (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * 0xa8 +
           (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
  uVar9 = iVar10 + 100;
  uVar6 = uVar9 & 3;
  uVar12 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = iVar10 + 0x6c;
  uVar5 = uVar9 & 3;
  uVar13 = *(uint *)(uVar9 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) *
          (longlong)(int)(uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
  *(uint *)(param_1 + 0xdc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = param_1 + 0x6cU & 3;
  uVar6 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xe0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = param_1 + 0xe0U & 3;
  uVar6 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  func_020d5148((int)*(short *)(param_1 + 0xda),
                (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) + 0xa000);
  LightInfo_SomeFn((ushort *)(uintptr_t)(param_1 + 0x7c),1);
  puVar2 = puRam020f9050;
  *(undefined4 *)(param_1 + 0x90) = 0;
  uVar8 = puVar2[1];
  uVar11 = puVar2[2];
  *(undefined4 *)(param_1 + 0xf0) = *puVar2;
  *(undefined4 *)(param_1 + 0xf4) = uVar8;
  *(undefined4 *)(param_1 + 0xf8) = uVar11;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  uVar9 = param_1 + 0x104U & 3;
  uVar6 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  *(undefined4 *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined2 *)(param_1 + 0x114) = 5;
  *(undefined2 *)(param_1 + 0x116) = 0;
  *(undefined2 *)(param_1 + 0x118) = 0;
  *(undefined2 *)(param_1 + 0x11a) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 1;
  uVar9 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) & 0x400000) == 0) {
    uVar9 = param_1 + 0x44U & 3;
    uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar9 = (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) * 0xa8 +
            (*(uint *)(uRam020f904c & 0xfffffffc) >> (uRam020f904c & 3) * 8 |
            *(uint *)(uRam020f904c & 0xfffffffc) << (uRam020f904c & 3) * -8 + 0x20) + 0xa0;
    uVar6 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    func_02109038(param_1,uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20,param_1 + 0x50);
    func_0210cf9c(param_1,1);
    uVar9 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20 | 0x400000;
  }
  uVar9 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar6 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar9 = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f904c & 0xfffffffc) >> (uRam020f904c & 3) * 8 |
          *(uint *)(uRam020f904c & 0xfffffffc) << (uRam020f904c & 3) * -8 + 0x20) + 0x28;
  uVar4 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x180000) == 0) {
    *(uint *)(param_1 + 0x120) = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
  }
  if ((*(ushort *)(param_1 + 0x78) & 0xf00) != 0) {
    return;
  }
  uVar9 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar9 = (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f904c & 0xfffffffc) >> (uRam020f904c & 3) * 8 |
          *(uint *)(uRam020f904c & 0xfffffffc) << (uRam020f904c & 3) * -8 + 0x20) + 0x54;
  uVar6 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (uVar9 >> uVar6 * 8 != 0 || uVar9 << uVar6 * -8 + 0x20 != 0) {
    return;
  }
  if (*(short *)(param_1 + 0xda) == -1) {
    uVar9 = param_1 + 0xe0U & 3;
    uVar6 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    uVar3 = FindComputeSomeCollisionEntryId
                      (param_1 + 0x50,(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) + 0xa000,
                       0x4000,param_1);
    *(undefined2 *)(param_1 + 0xda) = uVar3;
    return;
  }
  return;
}

