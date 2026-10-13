/* Decompiled C draft; module arm9; ROM address 02101178. No matching claim. */
#include "types.h"
#include "deps/02101178_func_02101178.h"

void func_02101178(int param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  code *unaff_r6;
  bool bVar9;
  
  puVar8 = (uint *)(param_1 + 0x16c);
  iVar2 = GetGlobalHD4();
  uVar6 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x8000000) == 0) {
    uVar4 = *(uint *)(uRam02101360 & 0xfffffffc) >> (uRam02101360 & 3) * 8 |
            *(uint *)(uRam02101360 & 0xfffffffc) << (uRam02101360 & 3) * -8 + 0x20;
    uVar6 = uVar4 + 8 & 3;
    uVar5 = *(uint *)(uVar4 + 8 & 0xfffffffc);
    bVar9 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 2;
    if (bVar9) {
      unaff_r6 = pcRam02101364;
    }
    if (!bVar9) {
      unaff_r6 = pcRam02101368;
    }
    if (*(char *)(uVar4 + 0x58) == '\0') {
      (*unaff_r6)(param_1,0xffffffff);
    }
    else {
      if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
        uVar6 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
      }
      else {
        uVar6 = 8;
      }
      uVar6 = uVar6 * 0x30 + uVar4 + 0x74;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      (*unaff_r6)(param_1,uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
      uVar6 = param_1 + 0x140U & 3;
      uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
      if ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) == 8) {
        (*unaff_r6)(param_1,0xffffffff);
      }
    }
  }
  uVar6 = param_1 + 0xd0U & 3;
  uVar4 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if ((undefined4 *)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) ==
      (undefined4 *)(param_1 + 0xc4)) {
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0xc4);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 200);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0xcc);
    *(undefined4 **)(param_1 + 0xd0) = (undefined4 *)(param_1 + 0x50);
  }
  uVar6 = param_1 + 0x140U & 3;
  uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  if ((int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) < 8) {
    uVar3 = GetDriverEntry();
    *(undefined4 *)(param_1 + 0x168) = uVar3;
    uVar6 = param_1 + 0x168U & 3;
    uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    uVar3 = *(undefined4 *)(uVar6 + 0x9c);
    uVar7 = *(undefined4 *)(uVar6 + 0xa0);
    *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(uVar6 + 0x98);
    *(undefined4 *)(param_1 + 0x188) = uVar3;
    *(undefined4 *)(param_1 + 0x18c) = uVar7;
    uVar6 = param_1 + 0x168U & 3;
    uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    uVar3 = *(undefined4 *)(uVar6 + 0xa8);
    uVar7 = *(undefined4 *)(uVar6 + 0xac);
    *(undefined4 *)(param_1 + 400) = *(undefined4 *)(uVar6 + 0xa4);
    *(undefined4 *)(param_1 + 0x194) = uVar3;
    *(undefined4 *)(param_1 + 0x198) = uVar7;
    *(undefined4 *)(param_1 + 0x144) = 0;
    uVar6 = param_1 + 0x168U & 3;
    uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    func_020f8e3c(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,0xf4);
    uVar6 = param_1 + 0x168U & 3;
    uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x48;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 1) != 0) {
      *(int *)(param_1 + 0xd0) = param_1 + 0xc4;
    }
  }
  uVar6 = iVar2 + 0xcU & 3;
  uVar4 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * 0xffff6000;
  *puVar8 = (uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar6) * 0x100000;
  uVar6 = iVar2 + 0x14U & 3;
  uVar4 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * 0xffff6000;
  *(uint *)(param_1 + 0x174) =
       (uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar6) * 0x100000;
  uVar6 = iVar2 + 0x15cU & 3;
  uVar4 = *(uint *)(iVar2 + 0x15cU & 0xfffffffc);
  uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  lVar1 = (ulonglong)uVar6 * 0xfffef000;
  *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
            *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) +
            ((uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar6) * 0x100000);
  uVar6 = iVar2 + 0x164U & 3;
  uVar4 = *(uint *)(iVar2 + 0x164U & 0xfffffffc);
  uVar4 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x174U & 3;
  uVar5 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  lVar1 = (ulonglong)uVar4 * 0xfffef000;
  *(uint *)(param_1 + 0x174) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar4) * 0x100000);
  uVar6 = param_1 + 0x17cU & 3;
  uVar4 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
  *(uint *)(param_1 + 0x17c) = -(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x270) = 0;
  return;
}

