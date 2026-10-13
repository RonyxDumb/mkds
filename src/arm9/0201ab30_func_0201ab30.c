/* Decompiled C draft; module arm9; ROM address 0201ab30. No matching claim. */
#include "types.h"
#include "deps/0201ab30_func_0201ab30.h"

uint func_0201ab30(int param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 auStack_a8 [144];
  
  puVar3 = puRam0201ae64;
  uVar7 = (uint)*(ushort *)(param_2 + 0x2e);
  uVar5 = param_1 + 0x3cU & 3;
  uVar4 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  iVar1 = (int)((uVar7 & 0x1f) * (((uVar7 << 0x16) >> 0x1b) + 1)) >> 5;
  *puRam0201ae64 =
       uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0xc0 | ((uVar7 << 0x10) >> 0x1a) << 0x18 |
       iVar1 << 0x10;
  puVar10 = auStack_a8;
  if (iVar1 == 0) {
    puVar10 = &stack0xffffffe8;
  }
  uVar5 = (uint)puVar3 & 3;
  uVar4 = *(uint *)((uint)puVar3 & 0xfffffffc);
  if (iVar1 == 0) {
    return uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  uVar5 = param_1 + 0x40U & 3;
  uVar4 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar1 = (int)(uint)*(ushort *)(param_2 + 0x20) >> 4;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = iRam0201ae6c + (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) << 0xd) >> 0x1e) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  (*(code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))
            ((int)*(short *)(iRam0201ae68 + iVar1 * 4),
             (int)*(short *)(iRam0201ae68 + (iVar1 * 2 + 1) * 2),puVar10 + 0x30);
  uVar5 = param_1 + 0x40U & 3;
  uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar4 = param_2 + 0x30U & 3;
  uVar8 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar7 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar7 + 0x48;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  lVar2 = (longlong)(int)uVar8 * (longlong)(int)*(short *)(uVar7 + 0x30) + 0x800;
  uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  uVar5 = ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) << 1) >> 0x1d;
  if (uVar5 == 0) {
    uVar5 = (uint)*(short *)(param_2 + 0x34);
    uVar4 = (uint)((ulonglong)uVar5 * (ulonglong)uVar8);
    lVar2 = (longlong)(int)uVar7 * (longlong)(int)uVar5 + 0x800;
    uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uVar8 = uVar4 + 0x800 >> 0xc |
            (((int)uVar8 >> 0x1f) * uVar5 +
             uVar8 * ((int)uVar5 >> 0x1f) + (int)((ulonglong)uVar5 * (ulonglong)uVar8 >> 0x20) +
            (uint)(0xfffff7ff < uVar4)) * 0x100000;
  }
  else if (uVar5 == 1) {
    lVar2 = (longlong)(int)uVar7 * (longlong)(int)*(short *)(param_2 + 0x34) + 0x800;
    uVar7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  }
  else if (uVar5 == 2) {
    uVar5 = (uint)*(short *)(param_2 + 0x34);
    uVar4 = (uint)((ulonglong)uVar5 * (ulonglong)uVar8);
    uVar8 = uVar4 + 0x800 >> 0xc |
            (((int)uVar8 >> 0x1f) * uVar5 +
             uVar8 * ((int)uVar5 >> 0x1f) + (int)((ulonglong)uVar5 * (ulonglong)uVar8 >> 0x20) +
            (uint)(0xfffff7ff < uVar4)) * 0x100000;
  }
  MTX_Scale43__from_thumb((undefined4 *)(void *)(puVar10 + 0x60),uVar7,uVar8,uVar8);
  MTX_Concat43((uint)(uintptr_t)(puVar10 + 0x60),(uint *)(void *)(puVar10 + 0x30),(uint *)(void *)(puVar10));
  uVar5 = param_1 + 0x40U & 3;
  uVar4 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) << 8) < 0) {
    uVar4 = param_2 + 8U & 3;
    uVar9 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar7 = param_2 + 0x38U & 3;
    uVar6 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar8 = uVar5 + 4 & 3;
    uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    *(uint *)(puVar10 + 0x24) =
         ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) -
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar5 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar4 = param_2 + 0xcU & 3;
    uVar9 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x20;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x3cU & 3;
    uVar6 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 8;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(puVar10 + 0x28) =
         ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) -
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    uVar5 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar4 = param_2 + 0x10U & 3;
    uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x20;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar8 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x40U & 3;
    uVar6 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0xc;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(puVar10 + 0x2c) =
         ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) -
         (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
    *puRam0201ae70 = 0;
    puVar3 = puRam0201ae74;
    uVar5 = param_1 + 0x40U & 3;
    uVar4 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x20;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar8 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar8 + 0xc & 3;
    uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
    uVar4 = uVar8 + 8 & 3;
    uVar6 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    uVar7 = uVar8 + 4 & 3;
    uVar8 = *(uint *)(uVar8 + 4 & 0xfffffffc);
    *puRam0201ae74 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    *puVar3 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    *puVar3 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    G3_MultMtx43(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    G3_MultMtx43(puVar10);
  }
  else {
    uVar5 = param_2 + 8U & 3;
    uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar4 = param_2 + 0x38U & 3;
    uVar7 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    *(uint *)(puVar10 + 0x24) =
         (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) +
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    uVar5 = param_2 + 0xcU & 3;
    uVar8 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar4 = param_2 + 0x3cU & 3;
    uVar7 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    *(uint *)(puVar10 + 0x28) =
         (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) +
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    uVar5 = param_2 + 0x10U & 3;
    uVar8 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar4 = param_2 + 0x40U & 3;
    uVar7 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    *(uint *)(puVar10 + 0x2c) =
         (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) +
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    uVar5 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    G3_LoadMtx43(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    G3_MultMtx43(puVar10);
  }
  uVar5 = param_1 + 0x40U & 3;
  uVar4 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar7 = (uint)*(ushort *)(param_2 + 0x36);
  uVar5 = (uint)*(ushort *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x72);
  *puRam0201ae78 =
       (int)((uVar7 & 0x1f) * (uVar5 & 0x1f)) >> 5 |
       ((int)((uVar7 & 0x3e0) * (uVar5 & 0x3e0)) >> 0xf) << 5 |
       ((int)((uVar7 & 0x7c00) * (uVar5 & 0x7c00)) >> 0x19) << 10;
  uVar5 = param_1 + 0x40U & 3;
  uVar4 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar7 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar7 + 0x20 & 3;
  uVar4 = *(uint *)(uVar7 + 0x20 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar8 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = iRam0201ae7c +
          ((int)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                 *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) << 0xc) >> 0x1f) * -4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (*(code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))
                    ((int)*(short *)(uVar7 + 0x78),(int)*(short *)(uVar7 + 0x7a),
                     (int)*(short *)(uVar8 + 0x50),(int)*(short *)(uVar8 + 0x52));
  return uVar5;
}

