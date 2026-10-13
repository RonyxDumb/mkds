/* Decompiled C draft; module arm9; ROM address 02019ee4. No matching claim. */
#include "types.h"
#include "deps/02019ee4_func_02019ee4.h"

uint func_02019ee4(int param_1,int param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 auStack_108 [240];
  
  puVar2 = puRam0201a340;
  uVar7 = (uint)*(ushort *)(param_2 + 0x2e);
  uVar4 = param_1 + 0x3cU & 3;
  uVar3 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  iVar5 = (int)((uVar7 & 0x1f) * (((uVar7 << 0x16) >> 0x1b) + 1)) >> 5;
  *puRam0201a340 =
       uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0xc0 | ((uVar7 << 0x10) >> 0x1a) << 0x18 |
       iVar5 << 0x10;
  puVar10 = auStack_108;
  if (iVar5 == 0) {
    puVar10 = &stack0xffffffe8;
  }
  uVar4 = (uint)puVar2 & 3;
  uVar3 = *(uint *)((uint)puVar2 & 0xfffffffc);
  if (iVar5 == 0) {
    return uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  uVar4 = param_1 + 0x40U & 3;
  uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x20;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x14;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar5 = (int)(uint)*(ushort *)(param_2 + 0x20) >> 4;
  uVar4 = iRam0201a348 +
          (((uint)*(ushort *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x15) >> 0x1e) * 4
  ;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  (*(code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))
            ((int)*(short *)(iRam0201a344 + iVar5 * 4),
             (int)*(short *)(iRam0201a344 + (iVar5 * 2 + 1) * 2),puVar10 + 0x30);
  Matrix4x3_Identity(puVar10 + 0xc0);
  uVar4 = param_1 + 0x40U & 3;
  uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x20;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x14;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x10;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((int)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x19) < 0) {
    VecFx32_Normalize(param_2 + 8,puVar10 + 0x90);
    *(int *)(puVar10 + 0x90) = -*(int *)(puVar10 + 0x90);
    *(int *)(puVar10 + 0x94) = -*(int *)(puVar10 + 0x94);
    *(int *)(puVar10 + 0x98) = -*(int *)(puVar10 + 0x98);
  }
  else {
    VecFx32_Normalize(param_2 + 0x14,puVar10 + 0x90);
  }
  *(undefined4 *)(puVar10 + 0xb4) = 0;
  *(undefined4 *)(puVar10 + 0xb8) = 0x1000;
  *(undefined4 *)(puVar10 + 0xbc) = 0;
  iVar5 = Vector3_DotProduct(puVar10 + 0x90,puVar10 + 0xb4);
  if ((iRam0201a34c < iVar5) || (iVar5 < iRam0201a350)) {
    *(undefined4 *)(puVar10 + 0xb4) = 0x1000;
    *(undefined4 *)(puVar10 + 0xb8) = 0;
    *(undefined4 *)(puVar10 + 0xbc) = 0;
  }
  VecFx32_CrossProduct(puVar10 + 0x90,puVar10 + 0xb4,puVar10 + 0x9c);
  VecFx32_CrossProduct(puVar10 + 0x90,puVar10 + 0x9c,puVar10 + 0xa8);
  *(undefined4 *)(puVar10 + 0xc0) = *(undefined4 *)(puVar10 + 0x9c);
  *(undefined4 *)(puVar10 + 0xc4) = *(undefined4 *)(puVar10 + 0xa0);
  *(undefined4 *)(puVar10 + 200) = *(undefined4 *)(puVar10 + 0xa4);
  *(undefined4 *)(puVar10 + 0xcc) = *(undefined4 *)(puVar10 + 0x90);
  *(undefined4 *)(puVar10 + 0xd0) = *(undefined4 *)(puVar10 + 0x94);
  *(undefined4 *)(puVar10 + 0xd4) = *(undefined4 *)(puVar10 + 0x98);
  *(undefined4 *)(puVar10 + 0xd8) = *(undefined4 *)(puVar10 + 0xa8);
  *(undefined4 *)(puVar10 + 0xdc) = *(undefined4 *)(puVar10 + 0xac);
  *(undefined4 *)(puVar10 + 0xe0) = *(undefined4 *)(puVar10 + 0xb0);
  MTX_Concat43(puVar10 + 0x30,puVar10 + 0xc0,puVar10 + 0x30);
  uVar4 = param_1 + 0x40U & 3;
  uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar3 = param_2 + 0x30U & 3;
  uVar8 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  uVar8 = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20;
  uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x20;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar7 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar7 + 0x48;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  lVar1 = (longlong)(int)uVar8 * (longlong)(int)*(short *)(uVar7 + 0x30) + 0x800;
  uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  uVar4 = ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 1) >> 0x1d;
  if (uVar4 == 0) {
    uVar4 = (uint)*(short *)(param_2 + 0x34);
    uVar3 = (uint)((ulonglong)uVar4 * (ulonglong)uVar8);
    lVar1 = (longlong)(int)uVar7 * (longlong)(int)uVar4 + 0x800;
    uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    uVar8 = uVar3 + 0x800 >> 0xc |
            (((int)uVar8 >> 0x1f) * uVar4 +
             uVar8 * ((int)uVar4 >> 0x1f) + (int)((ulonglong)uVar4 * (ulonglong)uVar8 >> 0x20) +
            (uint)(0xfffff7ff < uVar3)) * 0x100000;
  }
  else if (uVar4 == 1) {
    lVar1 = (longlong)(int)uVar7 * (longlong)(int)*(short *)(param_2 + 0x34) + 0x800;
    uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  }
  else if (uVar4 == 2) {
    uVar4 = (uint)*(short *)(param_2 + 0x34);
    uVar3 = (uint)((ulonglong)uVar4 * (ulonglong)uVar8);
    uVar8 = uVar3 + 0x800 >> 0xc |
            (((int)uVar8 >> 0x1f) * uVar4 +
             uVar8 * ((int)uVar4 >> 0x1f) + (int)((ulonglong)uVar4 * (ulonglong)uVar8 >> 0x20) +
            (uint)(0xfffff7ff < uVar3)) * 0x100000;
  }
  MTX_Scale43__from_thumb(puVar10 + 0x60,uVar7,uVar8,uVar8);
  MTX_Concat43(puVar10 + 0x30,puVar10 + 0x60,puVar10);
  uVar4 = param_1 + 0x40U & 3;
  uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x20;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) << 8) < 0) {
    uVar3 = param_2 + 8U & 3;
    uVar9 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar7 = param_2 + 0x38U & 3;
    uVar6 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar8 = uVar4 + 4 & 3;
    uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc);
    *(uint *)(puVar10 + 0x24) =
         ((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) -
         (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
    uVar4 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar3 = param_2 + 0xcU & 3;
    uVar9 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x20;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar8 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x3cU & 3;
    uVar6 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    uVar4 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar4 = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) + 8;
    uVar8 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(puVar10 + 0x28) =
         ((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) -
         (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
    uVar4 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar3 = param_2 + 0x10U & 3;
    uVar9 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x20;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar8 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x40U & 3;
    uVar6 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    uVar4 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar4 = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) + 0xc;
    uVar8 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(puVar10 + 0x2c) =
         ((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) -
         (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
    *puRam0201a354 = 0;
    puVar2 = puRam0201a358;
    uVar4 = param_1 + 0x40U & 3;
    uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x20;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar8 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = uVar8 + 0xc & 3;
    uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
    uVar3 = uVar8 + 8 & 3;
    uVar6 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    uVar7 = uVar8 + 4 & 3;
    uVar8 = *(uint *)(uVar8 + 4 & 0xfffffffc);
    *puRam0201a358 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    *puVar2 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
    *puVar2 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
    uVar4 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    G3_MultMtx43(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    G3_MultMtx43(puVar10);
  }
  else {
    uVar4 = param_2 + 8U & 3;
    uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar3 = param_2 + 0x38U & 3;
    uVar7 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    *(uint *)(puVar10 + 0x24) =
         (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
         (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
    uVar4 = param_2 + 0xcU & 3;
    uVar8 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar3 = param_2 + 0x3cU & 3;
    uVar7 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    *(uint *)(puVar10 + 0x28) =
         (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
         (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
    uVar4 = param_2 + 0x10U & 3;
    uVar8 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar3 = param_2 + 0x40U & 3;
    uVar7 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    *(uint *)(puVar10 + 0x2c) =
         (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
         (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
    uVar4 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    G3_LoadMtx43(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    G3_MultMtx43(puVar10);
  }
  uVar4 = param_1 + 0x40U & 3;
  uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar7 = (uint)*(ushort *)(param_2 + 0x36);
  uVar4 = (uint)*(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x72);
  *puRam0201a35c =
       (int)((uVar7 & 0x1f) * (uVar4 & 0x1f)) >> 5 |
       ((int)((uVar7 & 0x3e0) * (uVar4 & 0x3e0)) >> 0xf) << 5 |
       ((int)((uVar7 & 0x7c00) * (uVar4 & 0x7c00)) >> 0x19) << 10;
  uVar4 = param_1 + 0x40U & 3;
  uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar7 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar4 = uVar7 + 0x20 & 3;
  uVar3 = *(uint *)(uVar7 + 0x20 & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x14;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = iRam0201a360 +
          ((int)((uint)*(ushort *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) << 0x14) >> 0x1f
          ) * -4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (*(code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))
                    ((int)*(short *)(uVar7 + 0x7c),(int)*(short *)(uVar7 + 0x7e),0,0);
  return uVar4;
}

