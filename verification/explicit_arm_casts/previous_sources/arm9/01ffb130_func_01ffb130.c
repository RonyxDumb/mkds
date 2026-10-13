/* Decompiled C draft; module arm9; ROM address 01ffb130. No matching claim. */
#include "types.h"
#include "deps/01ffb130_func_01ffb130.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_01ffb130(int param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint *puStack_94;
  uint local_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  undefined1 auStack_80 [4];
  int iStack_7c;
  undefined1 auStack_74 [36];
  undefined1 auStack_50 [36];
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  
  uVar6 = param_1 + 0x3f8U & 3;
  uVar5 = *(uint *)(param_1 + 0x3f8U & 0xfffffffc);
  local_90 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x8000000) != 0) {
    StructMQRacerEntry_SomeFn_40();
  }
  uVar6 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar6 & 0x10000000) == 0) {
    if ((uVar6 & 0x80) != 0) {
      StructMQRacerEntry_SomeFn_82(param_1);
    }
    uVar6 = param_1 + 0x4cU & 3;
    uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10000) != 0) {
      StructMQRacerEntry_SomeFn_81(param_1);
    }
    uVar6 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & uRam01ffb8f8) != 0) {
      StructMQRacerEntry_SomeFn_80(param_1);
    }
  }
  else {
    StructMQRacerEntry_SomeFn_79(param_1);
  }
  uVar6 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x2000) != 0) {
    uVar6 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    iVar12 = param_1 + iRam01ffb8fc;
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 1) != 0) {
      uVar3 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
      func_0210ddf4(uRam01ffb900,uVar3,uRam01ffb904,param_1);
    }
    *(short *)(iVar12 + 10) = *(short *)(iVar12 + 10) + 1;
    if ((0xb4 < *(short *)(iVar12 + 10)) &&
       (uVar6 = param_1 + 0x4cU & 3, uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
       ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x2000) != 0)) {
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffffdfff;
      *(undefined4 *)(param_1 + 0xd8) = 0x1000;
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x8000000) == 0) {
        StructMQRacerEntry_SomeFn_2(param_1);
      }
      StructMQRacerEntry_SomeFn_3(param_1);
    }
  }
  uVar6 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x40) != 0) {
    iVar12 = param_1 + iRam01ffb8fc;
    func_0208181c(*(undefined2 *)(param_1 + 0x74));
    uVar6 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10) != 0) &&
       (uVar6 = param_1 + 0x590U & 3, uVar5 = *(uint *)(param_1 + 0x590U & 0xfffffffc),
       uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 8, uVar5 = uVar6 & 3,
       uVar6 = *(uint *)(uVar6 & 0xfffffffc),
       *(short *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x1a) == 0)) {
      DriverContext_UpdateCharacterAnimation(param_1,2,1);
    }
    iVar2 = iRam01ffb908;
    *(short *)(iVar12 + 6) = *(short *)(iVar12 + 6) + 1;
    if (iVar2 < *(short *)(iVar12 + 6)) {
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffffffbf;
      func_0207b1a8(param_1);
      *(undefined4 *)(param_1 + 0x29c) = 0;
      func_020817b8(*(undefined2 *)(param_1 + 0x74));
      DriverContext_UpdateCharacterAnimation(param_1,0,1);
      uVar6 = param_1 + 0x7cU & 3;
      uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if ((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 1) != 0) &&
         (uVar6 = (*(uint *)(uRam01ffb90c & 0xfffffffc) >> (uRam01ffb90c & 3) * 8 |
                  *(uint *)(uRam01ffb90c & 0xfffffffc) << (uRam01ffb90c & 3) * -8 + 0x20) + 0xc,
         uVar5 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
         uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0)) {
        func_02106dc8();
      }
      uVar6 = param_1 + 0x4cU & 3;
      uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x2000) != 0) {
        StructMQRacerEntry_SomeFn_36(param_1);
      }
    }
  }
  uVar6 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if ((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x800) != 0) &&
     (iVar12 = func_02072d84(param_1,&local_90), iVar12 != 0)) {
    return;
  }
  uVar6 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x20) != 0) {
    return;
  }
  uVar6 = param_1 + 0x180U & 3;
  uVar5 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  uVar6 = iRam01ffb910 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 4;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  (*(code *)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20))(param_1);
  func_01ffb9e0(param_1);
  uVar6 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x40) == 0) {
    func_01ffb9cc(param_1);
  }
  else {
    *(short *)(param_1 + 0x3ac) = *(short *)(param_1 + 0x3ac) + 1;
    if (*(ushort *)(param_1 + 0x3ac) < 0x42) {
      uVar6 = param_1 + 0x84U & 3;
      uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
      *(uint *)(param_1 + 0x84) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - uRam01ffb914;
    }
    else {
      uVar6 = param_1 + 0x48U & 3;
      uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xfffffdbf;
      uVar6 = param_1 + 0x7cU & 3;
      uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 1) != 0) {
        func_020e7a18();
      }
    }
  }
  uVar6 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10) != 0) &&
      (GetMQRacerVector333(param_1,auStack_80), uVar6 = param_1 + 0x48U & 3,
      uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
      ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 6) == 0)) &&
     (uVar6 = param_1 + 0x248U & 3, uVar5 = *(uint *)(param_1 + 0x248U & 0xfffffffc),
     0 < (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20))) {
    iVar12 = iStack_7c;
    if (iStack_7c < 1) {
      iVar12 = -iStack_7c;
    }
    if ((0xcd < iVar12) &&
       (uVar6 = param_1 + 0x38cU & 3, uVar5 = *(uint *)(param_1 + 0x38cU & 0xfffffffc),
       (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 1)) {
      lVar1 = (ulonglong)uRam01ffb914 * (ulonglong)(uint)-iStack_7c;
      uVar6 = param_1 + 0x2a8U & 3;
      uVar5 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
      *(uint *)(param_1 + 0x2a8) =
           (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
           ((uint)lVar1 >> 0xc |
           ((-iStack_7c >> 0x1f) * uRam01ffb914 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    }
  }
  uVar6 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10) == 0) &&
     (uVar6 = param_1 + 0x4cU & 3, uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
     ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10000000) == 0)) {
    iVar12 = VecFx32_CrossProduct_0(param_1 + 0x278,param_1 + 0x244);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x278);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x27c);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x280);
    if (*(short *)(param_1 + 1000) < 1) {
      if (iVar12 < 0) {
        *(int *)(param_1 + 0xd4) = 0x1000 - iVar12;
      }
      else {
        *(undefined4 *)(param_1 + 0xd4) = 0x1000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xd4) = 0x1000;
    }
  }
  else {
    iVar12 = (int)(uint)*(ushort *)(param_1 + 0x388) >> 4;
    func_02146f98(auStack_74,param_1 + 0x244,(int)*(short *)(iRam01ffb918 + iVar12 * 4),
                  (int)*(short *)(iRam01ffb918 + (iVar12 * 2 + 1) * 2));
    uVar6 = param_1 + 0x48U & 3;
    uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 1) != 0) {
      func_02146f98(auStack_50,param_1 + 0x120,(int)*(short *)(iRam01ffb91c + 0x74),
                    (int)*(short *)(iRam01ffb91c + 0x76));
      MTX_Concat33(auStack_50,auStack_74,auStack_74);
    }
    MTX_MultVec33(param_1 + 0x278,auStack_74,param_1 + 0x50);
    iVar12 = Vector3_DotProduct(param_1 + 0x244,param_1 + 0x50);
    uVar6 = param_1 + 0x244U & 3;
    uVar7 = *(uint *)(param_1 + 0x244U & 0xfffffffc);
    uVar5 = param_1 + 0x50U & 3;
    uVar11 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)iVar12;
    iStack_2c = (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) -
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar6 = param_1 + 0x248U & 3;
    uVar7 = *(uint *)(param_1 + 0x248U & 0xfffffffc);
    uVar5 = param_1 + 0x54U & 3;
    uVar11 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)iVar12;
    iStack_28 = (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) -
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar6 = param_1 + 0x24cU & 3;
    uVar7 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
    uVar5 = param_1 + 0x58U & 3;
    uVar11 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)iVar12;
    iStack_24 = (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) -
                ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
    uVar3 = VecFx32_Norm(&iStack_2c);
    *(undefined4 *)(param_1 + 0xd4) = uVar3;
  }
  puStack_94 = (uint *)func_01ffaf18(param_1);
  func_01ffb930(&puStack_94,param_1);
  uVar6 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x90) != 0) ||
     (uVar6 = param_1 + 0x4cU & 3, uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
     ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10000000) != 0)) {
    uVar6 = param_1 + 0x240U & 3;
    uVar5 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    VecFx32_Subtract(param_1 + 0x50,param_1 + 0x68,&uStack_20);
    uStack_20 = (uint)((longlong)(int)uStack_20 * (longlong)(int)uVar6) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_20 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    uStack_18 = (uint)((longlong)(int)uStack_18 * (longlong)(int)uVar6) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_18 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    uStack_1c = (uint)((longlong)(int)uStack_1c * (longlong)(int)uVar6) >> 0xc |
                (int)((ulonglong)((longlong)(int)uStack_1c * (longlong)(int)uVar6) >> 0x20) << 0x14;
    VecFx32_Add(param_1 + 0x68,&uStack_20,param_1 + 0x68);
    uVar6 = param_1 + 0x54U & 3;
    uVar5 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    *(uint *)(param_1 + 0x6c) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  uVar6 = param_1 + 0x68U & 3;
  uVar5 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) *
          (longlong)(int)puStack_94;
  uStack_8c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x6cU & 3;
  uVar5 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) *
          (longlong)(int)puStack_94;
  uStack_88 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x70U & 3;
  uVar5 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) *
          (longlong)(int)puStack_94;
  uStack_84 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = uStack_84;
  puVar10 = puStack_94;
  if (-1 < (int)puStack_94) {
    puVar10 = (uint *)(param_1 + 0x5c);
    uVar6 = *(uint *)(param_1 + 0x50);
    lVar1 = CONCAT44(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58));
  }
  if (-1 < (int)puStack_94) {
    *puVar10 = uVar6;
    puVar10[1] = (uint)((ulonglong)lVar1 >> 0x20);
    puVar10[2] = (uint)lVar1;
  }
  else {
    uVar6 = param_1 + 0x50U & 3;
    uVar5 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
    *(uint *)(param_1 + 0x5c) = -(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 0x54U & 3;
    uVar5 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    *(uint *)(param_1 + 0x60) = -(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 0x58U & 3;
    uVar5 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    *(uint *)(param_1 + 100) = -(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  }
  uVar6 = param_1 + 0x180U & 3;
  uVar5 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  puVar10 = (uint *)(param_1 + 0xa4);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 6) {
    uStack_88 = 0;
  }
  *puVar10 = uStack_8c;
  *(uint *)(param_1 + 0xa8) = uStack_88;
  *(uint *)(param_1 + 0xac) = uStack_84;
  VecFx32_Add(puVar10,param_1 + 0x374,puVar10);
  uVar6 = param_1 + 0xa8U & 3;
  uVar11 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar5 = param_1 + 0x260U & 3;
  uVar7 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  *(uint *)(param_1 + 0xa8) =
       (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
       (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  uVar6 = param_1 + 0x274U & 3;
  uVar5 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  VecFx32_AddScale1(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,param_1 + 0x268,param_1 + 0xa4,
                    param_1 + 0xa4);
  uVar6 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10) == 0) &&
      (uVar6 = param_1 + 0x380U & 3, uVar5 = *(uint *)(param_1 + 0x380U & 0xfffffffc),
      5 < (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20))) &&
     (uVar6 = param_1 + 0xa8U & 3, uVar5 = *(uint *)(param_1 + 0xa8U & 0xfffffffc),
     (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < -0x6000)) {
    *(undefined4 *)(param_1 + 0xa8) = 0xffffa000;
  }
  VecFx32_Add(param_1 + 0xa4,param_1 + 0x2f0,param_1 + 0xa4);
  VecFx32_Add(param_1 + 0xa4,param_1 + 0x1fc,param_1 + 0xa4);
  func_01ff9c40(param_1);
  func_01ffae14(param_1,local_90);
  uVar6 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 1) != 0) {
    VecFx32_CrossProduct_0(param_1 + 0xa4,param_1 + 0x50);
    func_0207a74c();
    uVar6 = param_1 + 0x44U & 3;
    uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x1000000) != 0) &&
        (uVar6 = param_1 + 0x4d4U & 3, uVar5 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc),
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20, uVar6 != 0)) &&
       (*(uint *)(param_1 + 0x4d4) =
             (uint)((ulonglong)uRam01ffb920 * (ulonglong)uVar6) >> 0xc |
             (((int)uVar6 >> 0x1f) * uRam01ffb920 +
             (int)((ulonglong)uRam01ffb920 * (ulonglong)uVar6 >> 0x20)) * 0x100000,
       uVar6 = param_1 + 0x4d4U & 3, uVar5 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc),
       (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 0xcd)) {
      *(undefined4 *)(param_1 + 0x4d4) = 0;
    }
  }
  uVar6 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x20) == 0) {
    VecFx32_Add(param_1 + 0x80,param_1 + 0xa4,param_1 + 0x80);
    *(undefined4 *)(param_1 + 0x38c) = 0x1000;
  }
  uVar7 = uRam01ffb928;
  uVar6 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar5 = param_1 + 0x2d8U & 3;
  uVar8 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
  uVar11 = uRam01ffb924;
  if (((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x10) == 0) {
    uVar11 = uRam01ffb920;
  }
  lVar1 = (longlong)(int)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) * (longlong)(int)uVar11;
  *(uint *)(param_1 + 0x2d8) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x2dcU & 3;
  uVar5 = *(uint *)(param_1 + 0x2dcU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * (longlong)(int)uVar11;
  *(uint *)(param_1 + 0x2dc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x2e0U & 3;
  uVar5 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * (longlong)(int)uVar11;
  *(uint *)(param_1 + 0x2e0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x2dcU & 3;
  uVar5 = *(uint *)(param_1 + 0x2dcU & 0xfffffffc);
  uVar4 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x2d8U & 3;
  uVar5 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x2e0U & 3;
  uVar11 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
  uVar6 = uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar5 * (longlong)(int)uVar5 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < uVar7)) {
    uVar3 = puRam01ffb92c[1];
    uVar9 = puRam01ffb92c[2];
    *(undefined4 *)(param_1 + 0x2d8) = *puRam01ffb92c;
    *(undefined4 *)(param_1 + 0x2dc) = uVar3;
    *(undefined4 *)(param_1 + 0x2e0) = uVar9;
    uVar6 = param_1 + 0x44U & 3;
    uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffffdfff;
  }
  else {
    uVar6 = param_1 + 0x44U & 3;
    uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20 | 0x2000;
  }
  func_01ffd900((int)*(short *)(param_1 + 0x2c8),0xe800);
  func_0206e874(param_1);
  uVar6 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x8000000) == 0) {
    uVar6 = param_1 + 0x2ccU & 3;
    uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar5 = param_1 + 0x510U & 3;
    uVar11 = *(uint *)(param_1 + 0x510U & 0xfffffffc);
    uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 4;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    func_01ffc064(param_1 + 0x1d8,uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20,
                  uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,param_1);
    func_0206d18c(param_1);
    func_0206dfd0(param_1);
    func_0206d578(param_1);
    return;
  }
  return;
}

