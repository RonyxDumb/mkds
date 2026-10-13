/* Decompiled C draft; module arm9; ROM address 0206dfd0. No matching claim. */
#include "types.h"
#include "deps/0206dfd0_func_0206dfd0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0206dfd0(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_d4;
  int iStack_c0;
  int iStack_bc;
  uint uStack_ac;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  local_d4 = 0;
  if ((0 < *(short *)(param_1 + 0x3d4)) &&
     (*(short *)(param_1 + 0x3d4) = *(short *)(param_1 + 0x3d4) + -1,
     *(short *)(param_1 + 0x3d4) < 1)) {
    *(undefined2 *)(param_1 + 0x3d4) = 0;
  }
  uVar10 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) & uRam0206e84c) != 0) {
    return;
  }
  uVar10 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) & 0x40) != 0) {
    return;
  }
  iVar11 = 0;
  if (*psRam0206e850 < 1) {
    return;
  }
  uStack_30 = *puRam0206e854;
  uStack_2c = puRam0206e854[1];
  uStack_28 = puRam0206e854[2];
  uStack_ac = 0x14;
  iStack_c0 = 0;
  iStack_bc = 0;
  do {
    if (((((*(ushort *)
             ((*(uint *)(uRam0206e858 & 0xfffffffc) >> (uRam0206e858 & 3) * 8 |
              *(uint *)(uRam0206e858 & 0xfffffffc) << (uRam0206e858 & 3) * -8 + 0x20) + iVar11 * 2)
           & 0x8000) != 0) &&
         (uVar10 = (*(uint *)(uRam0206e85c & 0xfffffffc) >> (uRam0206e85c & 3) * 8 |
                   *(uint *)(uRam0206e85c & 0xfffffffc) << (uRam0206e85c & 3) * -8 + 0x20) +
                   iVar11 * 4, uVar4 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
         uVar10 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20,
         ((uint)*(ushort *)(param_1 + 0x2b0) & 1 << (*(ushort *)(uVar10 + 0x74) & 0xff)) == 0)) &&
        (uVar4 = uVar10 + 0x7c & 3, uVar6 = *(uint *)(uVar10 + 0x7c & 0xfffffffc),
        ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & uRam0206e860) == 0)) &&
       (uVar4 = uVar10 + 0x48 & 3, uVar6 = *(uint *)(uVar10 + 0x48 & 0xfffffffc),
       ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x40) == 0)) {
      uVar4 = param_1 + 0x1d0U & 3;
      uVar9 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
      uVar6 = uVar10 + 0x1d0 & 3;
      uVar7 = *(uint *)(uVar10 + 0x1d0 & 0xfffffffc);
      iVar8 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
              (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
      iVar3 = -iVar8;
      *(ushort *)(uVar10 + 0x2b0) =
           *(ushort *)(uVar10 + 0x2b0) | (ushort)(1 << (*(ushort *)(param_1 + 0x74) & 0xff));
      *(ushort *)(param_1 + 0x2b0) =
           *(ushort *)(param_1 + 0x2b0) | (ushort)(1 << (*(ushort *)(uVar10 + 0x74) & 0xff));
      uVar4 = param_1 + 0x1e0U & 3;
      uVar9 = *(uint *)(param_1 + 0x1e0U & 0xfffffffc);
      uVar6 = uVar10 + 0x1e0 & 3;
      uVar7 = *(uint *)(uVar10 + 0x1e0 & 0xfffffffc);
      iVar5 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) -
              (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
      bVar13 = false;
      if ((iVar5 <= iVar8) && (iVar5 + iVar8 < 0 == SBORROW4(iVar5,iVar3))) {
        uVar4 = param_1 + 0x1d8U & 3;
        uVar9 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
        uVar6 = uVar10 + 0x1d8 & 3;
        uVar7 = *(uint *)(uVar10 + 0x1d8 & 0xfffffffc);
        iVar2 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) -
                (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
        if ((iVar8 < iVar2) || (iVar2 + iVar8 < 0 != SBORROW4(iVar2,iVar3))) {
          bVar13 = false;
        }
        else {
          uVar4 = param_1 + 0x1dcU & 3;
          uVar9 = *(uint *)(param_1 + 0x1dcU & 0xfffffffc);
          uVar6 = uVar10 + 0x1dc & 3;
          uVar7 = *(uint *)(uVar10 + 0x1dc & 0xfffffffc);
          iVar12 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) -
                   (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
          if ((iVar8 < iVar12) || (iVar12 + iVar8 < 0 != SBORROW4(iVar12,iVar3))) {
            bVar13 = false;
          }
          else {
            lVar1 = (longlong)iVar5 * (longlong)iVar5 +
                    (longlong)iVar2 * (longlong)iVar2 + (longlong)iVar12 * (longlong)iVar12;
            iVar5 = (int)((ulonglong)lVar1 >> 0x20);
            iVar3 = (int)((ulonglong)((longlong)iVar8 * (longlong)iVar8) >> 0x20);
            bVar13 = (uint)lVar1 < (uint)((longlong)iVar8 * (longlong)iVar8);
            if ((int)(iVar5 - (iVar3 + (uint)bVar13)) < 0 ==
                (SBORROW4(iVar5,iVar3) != SBORROW4(iVar5 - iVar3,(uint)bVar13))) {
              bVar13 = false;
            }
            else {
              bVar13 = true;
            }
          }
        }
      }
      if (bVar13) {
        func_020eb3f0(param_1 + 0x1d8,uVar10 + 0x1d8,iVar8,&iStack_90);
        lVar1 = (longlong)iStack_88 * (longlong)iStack_88 +
                (longlong)iStack_90 * (longlong)iStack_90 +
                (longlong)iStack_8c * (longlong)iStack_8c;
        iVar3 = iStack_c0;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          iVar3 = Vector3_MaybeNormalize(&iStack_90,&iStack_9c);
        }
        if (0 < iVar3) {
          iStack_84 = iStack_90 >> 1;
          iStack_80 = iStack_8c >> 1;
          iStack_78 = -iStack_84;
          iStack_74 = -iStack_80;
          iVar5 = 0;
          iStack_7c = iStack_88 >> 1;
          iStack_70 = -iStack_7c;
          uVar4 = param_1 + 0x44U & 3;
          uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x10) != 0) {
            iVar8 = Vector3_DotProduct(param_1 + 0x244,&iStack_84);
            uVar4 = param_1 + 0x244U & 3;
            uVar6 = *(uint *)(param_1 + 0x244U & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_84 = iStack_84 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = param_1 + 0x248U & 3;
            uVar6 = *(uint *)(param_1 + 0x248U & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_80 = iStack_80 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = param_1 + 0x24cU & 3;
            uVar6 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_7c = iStack_7c - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
          }
          uVar4 = param_1 + 0x44U & 3;
          uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          if ((((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x80) != 0) &&
             (iVar8 = Vector3_DotProduct(param_1 + 0x244,&iStack_84), iVar8 < 0)) {
            iVar8 = Vector3_DotProduct(param_1 + 0x250,&iStack_84);
            uVar4 = param_1 + 0x250U & 3;
            uVar6 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_84 = iStack_84 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = param_1 + 0x254U & 3;
            uVar6 = *(uint *)(param_1 + 0x254U & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_80 = iStack_80 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = param_1 + 600U & 3;
            uVar6 = *(uint *)(param_1 + 600U & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_7c = iStack_7c - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
          }
          uVar4 = uVar10 + 0x44 & 3;
          uVar6 = *(uint *)(uVar10 + 0x44 & 0xfffffffc);
          if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x10) != 0) {
            iVar8 = Vector3_DotProduct(uVar10 + 0x244,&iStack_78);
            uVar4 = uVar10 + 0x244 & 3;
            uVar6 = *(uint *)(uVar10 + 0x244 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_78 = iStack_78 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = uVar10 + 0x248 & 3;
            uVar6 = *(uint *)(uVar10 + 0x248 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_74 = iStack_74 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = uVar10 + 0x24c & 3;
            uVar6 = *(uint *)(uVar10 + 0x24c & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_70 = iStack_70 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
          }
          uVar4 = uVar10 + 0x44 & 3;
          uVar6 = *(uint *)(uVar10 + 0x44 & 0xfffffffc);
          if ((((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x80) != 0) &&
             (iVar8 = Vector3_DotProduct(uVar10 + 0x244,&iStack_78), iVar8 < 0)) {
            iVar8 = Vector3_DotProduct(uVar10 + 0x250,&iStack_78);
            uVar4 = uVar10 + 0x250 & 3;
            uVar6 = *(uint *)(uVar10 + 0x250 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_78 = iStack_78 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = uVar10 + 0x254 & 3;
            uVar6 = *(uint *)(uVar10 + 0x254 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_74 = iStack_74 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            uVar4 = uVar10 + 600 & 3;
            uVar6 = *(uint *)(uVar10 + 600 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
                    (longlong)iVar8;
            iStack_70 = iStack_70 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
          }
          uVar4 = param_1 + 0x510U & 3;
          uVar6 = *(uint *)(param_1 + 0x510U & 0xfffffffc);
          uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
          VecFx32_Add(uVar4,&iStack_84,uVar4);
          uVar4 = uVar10 + 0x510 & 3;
          uVar6 = *(uint *)(uVar10 + 0x510 & 0xfffffffc);
          uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
          VecFx32_Add(uVar4,&iStack_78,uVar4);
          uVar4 = uVar10 + 0x44 & 3;
          uVar6 = *(uint *)(uVar10 + 0x44 & 0xfffffffc);
          if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xc0) != 0) {
            VecFx32_Subtract(uVar10 + 0xa4,param_1 + 0xa4,&uStack_6c);
            iVar8 = Vector3_DotProduct(&iStack_9c,&uStack_6c);
            uStack_6c = (uint)((longlong)iStack_9c * (longlong)iVar8) >> 0xc |
                        (int)((ulonglong)((longlong)iStack_9c * (longlong)iVar8) >> 0x20) << 0x14;
            uStack_68 = (uint)((longlong)iStack_98 * (longlong)iVar8) >> 0xc |
                        (int)((ulonglong)((longlong)iStack_98 * (longlong)iVar8) >> 0x20) << 0x14;
            uStack_64 = (uint)((longlong)iStack_94 * (longlong)iVar8) >> 0xc |
                        (int)((ulonglong)((longlong)iStack_94 * (longlong)iVar8) >> 0x20) << 0x14;
            iVar8 = Vector3_DotProduct(param_1 + 0x50,&uStack_6c);
            uVar4 = param_1 + 0x2a8U & 3;
            uVar6 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
            *(uint *)(param_1 + 0x2a8) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + iVar8;
          }
          uVar4 = param_1 + 0x44U & 3;
          uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xc0) != 0) {
            VecFx32_Subtract(param_1 + 0xa4,uVar10 + 0xa4,&uStack_60);
            iVar8 = Vector3_DotProduct(&iStack_9c,&uStack_60);
            uStack_60 = (uint)((longlong)iStack_9c * (longlong)iVar8) >> 0xc |
                        (int)((ulonglong)((longlong)iStack_9c * (longlong)iVar8) >> 0x20) << 0x14;
            uStack_5c = (uint)((longlong)iStack_98 * (longlong)iVar8) >> 0xc |
                        (int)((ulonglong)((longlong)iStack_98 * (longlong)iVar8) >> 0x20) << 0x14;
            uStack_58 = (uint)((longlong)iStack_94 * (longlong)iVar8) >> 0xc |
                        (int)((ulonglong)((longlong)iStack_94 * (longlong)iVar8) >> 0x20) << 0x14;
            iVar8 = Vector3_DotProduct(uVar10 + 0x50,&uStack_60);
            uVar4 = uVar10 + 0x2a8 & 3;
            uVar6 = *(uint *)(uVar10 + 0x2a8 & 0xfffffffc);
            *(uint *)(uVar10 + 0x2a8) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + iVar8;
          }
          uVar4 = (*(uint *)(uRam0206e864 & 0xfffffffc) >> (uRam0206e864 & 3) * 8 |
                  *(uint *)(uRam0206e864 & 0xfffffffc) << (uRam0206e864 & 3) * -8 + 0x20) + 8;
          uVar6 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          iVar8 = iStack_bc;
          if ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) == 2) {
            iVar8 = func_020a1ee4(*(undefined2 *)(param_1 + 0x74),*(undefined2 *)(uVar10 + 0x74));
          }
          uVar4 = param_1 + 0x4cU & 3;
          uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
          uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
          if ((uVar4 & 0x10000000) == 0) {
            uVar6 = uVar10 + 0x4c & 3;
            uVar7 = *(uint *)(uVar10 + 0x4c & 0xfffffffc);
            uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
            if ((uVar6 & 0x10000000) == 0) {
              if ((uVar4 & 0x40) == 0) {
                if ((uVar6 & 0x40) == 0) {
                  if ((*(short *)(param_1 + 0x3d4) < 1) &&
                     ((uVar4 = param_1 + 0x2a4U & 3,
                      uVar6 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc),
                      0x1000 < (int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) ||
                      (uVar4 = uVar10 + 0x2a4 & 3, uVar6 = *(uint *)(uVar10 + 0x2a4 & 0xfffffffc),
                      0x1000 < (int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20))))) {
                    if (0x78 < (*(uint *)(uRam0206e86c & 0xfffffffc) >> (uRam0206e86c & 3) * 8 |
                               *(uint *)(uRam0206e86c & 0xfffffffc) <<
                               (uRam0206e86c & 3) * -8 + 0x20)) {
                      DriverContext_MaybeQueuePlaySfx(param_1,0x80,0x7f,0);
                    }
                    uVar4 = param_1 + 0x2a4U & 3;
                    uVar6 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
                    uVar7 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
                    uVar4 = uVar10 + 0x2a4 & 3;
                    uVar6 = *(uint *)(uVar10 + 0x2a4 & 0xfffffffc);
                    uVar6 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
                    uVar4 = uVar6;
                    if ((int)uVar6 < (int)uVar7) {
                      uVar4 = uStack_ac;
                    }
                    if ((int)uVar6 < (int)uVar7) {
                      *(short *)(uVar10 + 0x3d2) = (short)uVar4;
                    }
                    else {
                      *(undefined2 *)(param_1 + 0x3d2) = 0x14;
                    }
                    DriverContext_SomeFn(param_1,2);
                    DriverContext_SomeFn(uVar10,2);
                    *(undefined2 *)(param_1 + 0x3d4) = 0xf;
                    if ((local_d4 == 0) &&
                       (local_d4 = func_0206c354(param_1,&iStack_9c,iVar8), local_d4 == 0)) {
                      iStack_48 = -iStack_9c;
                      iStack_44 = -iStack_98;
                      iStack_40 = -iStack_94;
                      local_d4 = func_0206c354(uVar10,&iStack_48,iVar8);
                    }
                  }
                }
                else if ((uVar4 & uRam0206e868) == 0) {
                  iVar5 = 1;
                  func_0206de18(uVar10,param_1,&iStack_9c);
                }
              }
              else if ((uVar6 & uRam0206e868) == 0) {
                iStack_50 = -iStack_98;
                iStack_54 = -iStack_9c;
                iStack_4c = -iStack_94;
                iVar5 = 1;
                func_0206de18(param_1,uVar10,&iStack_54);
              }
            }
            else if ((uVar4 & uRam0206e868) == 0) {
              iVar5 = 1;
              func_0206dbf8(uVar10,param_1);
            }
          }
          else {
            uVar4 = uVar10 + 0x4c & 3;
            uVar6 = *(uint *)(uVar10 + 0x4c & 0xfffffffc);
            iVar5 = iStack_bc;
            if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & uRam0206e868) == 0) {
              iVar5 = 1;
              func_0206dbf8(param_1,uVar10);
            }
          }
          if ((int)(*(uint *)(uRam0206e870 & 0xfffffffc) >> (uRam0206e870 & 3) * 8 |
                   *(uint *)(uRam0206e870 & 0xfffffffc) << (uRam0206e870 & 3) * -8 + 0x20) < iVar3)
          {
            uVar4 = param_1 + 0x4cU & 3;
            uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
            *(uint *)(param_1 + 0x4c) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20 | 0x100000;
            uVar4 = uVar10 + 0x4c & 3;
            uVar6 = *(uint *)(uVar10 + 0x4c & 0xfffffffc);
            *(uint *)(uVar10 + 0x4c) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20 | 0x100000;
          }
          if (iVar5 == 0) {
            uStack_3c = uStack_30;
            uStack_38 = uStack_2c;
            uStack_34 = uStack_28;
            func_0206d7c8(uVar10,param_1,&iStack_9c,1);
            iStack_9c = -iStack_9c;
            iStack_98 = -iStack_98;
            iStack_94 = -iStack_94;
            func_0206d7c8(param_1,uVar10,&iStack_9c,0);
          }
        }
        uVar4 = param_1 + 0x44U & 3;
        uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20 | 0x20;
        uVar4 = uVar10 + 0x44 & 3;
        uVar6 = *(uint *)(uVar10 + 0x44 & 0xfffffffc);
        *(uint *)(uVar10 + 0x44) = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20 | 0x20;
        *(ushort *)(param_1 + 0x2b2) =
             *(ushort *)(param_1 + 0x2b2) | (ushort)(1 << (*(ushort *)(uVar10 + 0x74) & 0xff));
        *(ushort *)(uVar10 + 0x2b2) =
             *(ushort *)(uVar10 + 0x2b2) | (ushort)(1 << (*(ushort *)(param_1 + 0x74) & 0xff));
      }
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < *psRam0206e850);
  return;
}

