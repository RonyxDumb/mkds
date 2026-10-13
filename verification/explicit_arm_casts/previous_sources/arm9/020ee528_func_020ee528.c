/* Decompiled C draft; module arm9; ROM address 020ee528. No matching claim. */
#include "types.h"
#include "deps/020ee528_func_020ee528.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_020ee528(int param_1)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar11;
  
  uVar12 = param_1 + 0x10U & 3;
  uVar10 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar11 = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
  uVar5 = *(undefined4 *)(uVar11 + 0x154);
  uVar6 = *(undefined4 *)(uVar11 + 0x158);
  uVar8 = *(undefined4 *)(uVar11 + 0x15c);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(uVar11 + 0x150);
  *(undefined4 *)(param_1 + 0x30) = uVar5;
  *(undefined4 *)(param_1 + 0x34) = uVar6;
  *(undefined4 *)(param_1 + 0x38) = uVar8;
  uVar5 = *(undefined4 *)(uVar11 + 0x164);
  uVar6 = *(undefined4 *)(uVar11 + 0x168);
  uVar8 = *(undefined4 *)(uVar11 + 0x16c);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(uVar11 + 0x160);
  *(undefined4 *)(param_1 + 0x40) = uVar5;
  *(undefined4 *)(param_1 + 0x44) = uVar6;
  *(undefined4 *)(param_1 + 0x48) = uVar8;
  uVar12 = uVar11 + 0x170 & 3;
  uVar10 = *(uint *)(uVar11 + 0x170 & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
  uVar5 = *(undefined4 *)(uVar11 + 0x9c);
  uVar6 = *(undefined4 *)(uVar11 + 0xa0);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(uVar11 + 0x98);
  *(undefined4 *)(param_1 + 0x54) = uVar5;
  *(undefined4 *)(param_1 + 0x58) = uVar6;
  uVar5 = *(undefined4 *)(uVar11 + 0xa8);
  uVar6 = *(undefined4 *)(uVar11 + 0xac);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(uVar11 + 0xa4);
  *(undefined4 *)(param_1 + 0x60) = uVar5;
  *(undefined4 *)(param_1 + 100) = uVar6;
  uVar12 = uVar11 + 0x2a4 & 3;
  uVar10 = *(uint *)(uVar11 + 0x2a4 & 0xfffffffc);
  *(uint *)(param_1 + 0x68) = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
  uVar12 = uVar11 + 0x2cc & 3;
  uVar3 = *(uint *)(uVar11 + 0x2cc & 0xfffffffc);
  uVar10 = uVar11 + 0xc4 & 3;
  uVar9 = *(uint *)(uVar11 + 0xc4 & 0xfffffffc);
  uVar12 = (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) + 8;
  uVar3 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) + 0x800;
  *(uint *)(param_1 + 0x78) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  uVar12 = uVar11 + 700 & 3;
  uVar10 = *(uint *)(uVar11 + 700 & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
  iVar4 = VecFx32_CrossProduct_0(param_1 + 0x44,(undefined4 *)(param_1 + 0x5c));
  *(uint *)(param_1 + 0x80) = (uint)(0 < iVar4);
  VecFx32_Subtract(param_1 + 0x50,uVar11 + 0x8c,param_1 + 0x6c);
  uVar12 = uVar11 + 0x41c & 3;
  uVar9 = *(uint *)(uVar11 + 0x41c & 0xfffffffc);
  uVar10 = uVar11 + 0x428 & 3;
  uVar3 = *(uint *)(uVar11 + 0x428 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20);
  uVar3 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = uVar11 + 0x420 & 3;
  uVar7 = *(uint *)(uVar11 + 0x420 & 0xfffffffc);
  uVar10 = uVar11 + 0x42c & 3;
  uVar9 = *(uint *)(uVar11 + 0x42c & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20);
  uVar13 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = uVar11 + 0x424 & 3;
  uVar7 = *(uint *)(uVar11 + 0x424 & 0xfffffffc);
  uVar10 = uVar11 + 0x430 & 3;
  uVar9 = *(uint *)(uVar11 + 0x430 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20);
  uVar9 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar12 = param_1 + 0x84U & 3;
  uVar10 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((((uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) == uVar3) &&
      (uVar12 = param_1 + 0x88U & 3, uVar10 = *(uint *)(param_1 + 0x88U & 0xfffffffc),
      (uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) == uVar13)) &&
     (uVar12 = param_1 + 0x8cU & 3, uVar10 = *(uint *)(param_1 + 0x8cU & 0xfffffffc),
     (uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) == uVar9)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    *(uint *)(param_1 + 0x84) = uVar3;
    *(uint *)(param_1 + 0x88) = uVar13;
    *(uint *)(param_1 + 0x8c) = uVar9;
    return 1;
  }
  return 0;
}

