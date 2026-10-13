/* Decompiled C draft; module arm9; ROM address 01ffa4b4. No matching claim. */
#include "types.h"
#include "deps/01ffa4b4_func_01ffa4b4.h"

void func_01ffa4b4(int param_1,int *param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int unaff_r5;
  undefined4 unaff_r11;
  bool bVar12;
  undefined2 uStack_88;
  uint uStack_84;
  undefined1 auStack_80 [4];
  undefined1 auStack_7c [12];
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  undefined1 auStack_58 [12];
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  local_70 = *puRam01ffacd8;
  uStack_6c = puRam01ffacd8[1];
  uStack_68 = puRam01ffacd8[2];
  uVar3 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  bVar12 = ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x100000) != 0;
  if (bVar12) {
    unaff_r11 = 1;
  }
  uVar3 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (!bVar12) {
    unaff_r11 = 0;
  }
  bVar12 = ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x200000) != 0;
  if (bVar12) {
    unaff_r5 = 1;
  }
  iVar4 = *(int *)(param_1 + 0x248);
  iVar6 = *(int *)(param_1 + 0x24c);
  *param_2 = *(int *)(param_1 + 0x244);
  param_2[1] = iVar4;
  param_2[2] = iVar6;
  if (!bVar12) {
    unaff_r5 = 0;
  }
  iVar4 = func_01ffa1f8(param_1);
  if (iVar4 != 0) {
    return;
  }
  uVar3 = param_1 + 0x1d0U & 3;
  uVar2 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
  iVar4 = func_01ffdee4(param_1 + 0x1b8,param_1 + 0x1c4,param_1 + 0x50,
                        uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  if (iVar4 == 0) {
    func_01ffa350(param_1,0x90);
  }
  else {
    uVar11 = uStack_84 & uRam01ffacdc;
    VecFx32_Add(param_1 + 0x80,(uint)(uintptr_t)(auStack_7c),(int *)(uintptr_t)(param_1 + 0x80));
    uVar3 = param_1 + 0x590U & 3;
    uVar10 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar2 = param_1 + 0x2a4U & 3;
    uVar7 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
    func_0208ab98((ushort *)(uintptr_t)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) + 0x40),
                  (uStack_84 & 0x3c000000) >> 0x1a,uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
    func_01ff9c9c(param_1,uStack_84);
    func_0206f694(param_1,uStack_84,(int *)(void *)(auStack_58),uStack_88);
    if ((uStack_84 & uRam01fface0) == 0) {
      uVar3 = param_1 + 0x44U & 3;
      uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      *(uint *)(param_1 + 0x44) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xffffff7f;
      if (0 < *(short *)(param_1 + 0x4da)) {
        *(short *)(param_1 + 0x4da) = *(short *)(param_1 + 0x4da) + -1;
      }
    }
    else {
      func_0206f574(param_1,uStack_84,&local_70);
      if (uVar11 != 0) {
        iVar4 = Vector3_DotProduct((uint)(uintptr_t)(&iStack_4c),param_1 + 0x2d8);
        uVar3 = param_1 + 0x2d8U & 3;
        uVar2 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
        *(uint *)(param_1 + 0x2d8) =
             (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) -
             ((uint)((longlong)iStack_4c * (longlong)iVar4) >> 0xc |
             (int)((ulonglong)((longlong)iStack_4c * (longlong)iVar4) >> 0x20) << 0x14);
        uVar3 = param_1 + 0x2dcU & 3;
        uVar2 = *(uint *)(param_1 + 0x2dcU & 0xfffffffc);
        *(uint *)(param_1 + 0x2dc) =
             (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) -
             ((uint)((longlong)iStack_48 * (longlong)iVar4) >> 0xc |
             (int)((ulonglong)((longlong)iStack_48 * (longlong)iVar4) >> 0x20) << 0x14);
        uVar3 = param_1 + 0x2e0U & 3;
        uVar2 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
        *(uint *)(param_1 + 0x2e0) =
             (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) -
             ((uint)((longlong)iStack_44 * (longlong)iVar4) >> 0xc |
             (int)((ulonglong)((longlong)iStack_44 * (longlong)iVar4) >> 0x20) << 0x14);
        iVar4 = Vector3_DotProduct((uint)(uintptr_t)(&iStack_4c),param_1 + 0x2e4);
        uVar3 = param_1 + 0x2e4U & 3;
        uVar2 = *(uint *)(param_1 + 0x2e4U & 0xfffffffc);
        *(uint *)(param_1 + 0x2e4) =
             (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) -
             ((uint)((longlong)iStack_4c * (longlong)iVar4) >> 0xc |
             (int)((ulonglong)((longlong)iStack_4c * (longlong)iVar4) >> 0x20) << 0x14);
        uVar3 = param_1 + 0x2e8U & 3;
        uVar2 = *(uint *)(param_1 + 0x2e8U & 0xfffffffc);
        *(uint *)(param_1 + 0x2e8) =
             (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) -
             ((uint)((longlong)iStack_48 * (longlong)iVar4) >> 0xc |
             (int)((ulonglong)((longlong)iStack_48 * (longlong)iVar4) >> 0x20) << 0x14);
        uVar3 = param_1 + 0x2ecU & 3;
        uVar2 = *(uint *)(param_1 + 0x2ecU & 0xfffffffc);
        *(uint *)(param_1 + 0x2ec) =
             (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) -
             ((uint)((longlong)iStack_44 * (longlong)iVar4) >> 0xc |
             (int)((ulonglong)((longlong)iStack_44 * (longlong)iVar4) >> 0x20) << 0x14);
      }
      *(undefined2 *)(param_1 + 0x4da) = 3;
      iVar4 = (*(code *)(*(uint *)(uRam01fface4 & 0xfffffffc) >> (uRam01fface4 & 3) * 8 |
                        *(uint *)(uRam01fface4 & 0xfffffffc) << (uRam01fface4 & 3) * -8 + 0x20))
                        (param_1,uStack_84,&iStack_64);
      if ((iVar4 == 0) &&
         (uVar3 = param_1 + 0x44U & 3, uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
         ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x4000000) == 0)) {
        uVar5 = puRam01ffacf0[1];
        uVar8 = puRam01ffacf0[2];
        *(undefined4 *)(param_1 + 0x374) = *puRam01ffacf0;
        *(undefined4 *)(param_1 + 0x378) = uVar5;
        *(undefined4 *)(param_1 + 0x37c) = uVar8;
        uVar3 = param_1 + 0x44U & 3;
        uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfffffdff;
      }
      else {
        lVar1 = (longlong)iStack_5c * (longlong)iStack_5c +
                (longlong)iStack_64 * (longlong)iStack_64 +
                (longlong)iStack_60 * (longlong)iStack_60;
        iVar4 = 0;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          iVar4 = Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_64),&uStack_40);
        }
        if (iVar4 != 0) {
          uVar3 = param_1 + 0x44U & 3;
          uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
          iVar4 = iRam01fface8;
          if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x4000000) != 0) {
            iVar4 = iRam01fface8 * 3;
          }
          uStack_40 = (uint)((longlong)(int)-uStack_40 * (longlong)iVar4) >> 0xc |
                      (int)((ulonglong)((longlong)(int)-uStack_40 * (longlong)iVar4) >> 0x20) <<
                      0x14;
          uStack_38 = (uint)((longlong)(int)-uStack_38 * (longlong)iVar4) >> 0xc |
                      (int)((ulonglong)((longlong)(int)-uStack_38 * (longlong)iVar4) >> 0x20) <<
                      0x14;
          uStack_3c = (uint)((longlong)(int)-uStack_3c * (longlong)iVar4) >> 0xc |
                      (int)((ulonglong)((longlong)(int)-uStack_3c * (longlong)iVar4) >> 0x20) <<
                      0x14;
          *(uint *)(param_1 + 0x374) = uStack_40;
          *(uint *)(param_1 + 0x378) = uStack_3c;
          *(uint *)(param_1 + 0x37c) = uStack_38;
          *(undefined4 *)(param_1 + 0x378) = uRam01ffacec;
        }
        uVar3 = param_1 + 0x44U & 3;
        uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x200;
      }
    }
    if ((uStack_84 & uRam01ffacf4) != 0) {
      uVar3 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if ((((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 1) != 0) &&
         ((uStack_84 & 0x10) != 0)) {
        if (unaff_r5 == 0) {
          uVar3 = func_020d59f8(0x10);
          func_0210f458(((uVar3 & 0xe0) << 0xb) >> 0x10);
        }
        uVar3 = param_1 + 0x48U & 3;
        uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x200000;
      }
      if (((uStack_84 & 0x8c00) != 0) &&
         ((((uStack_84 & 0x400) == 0 ||
           (uVar3 = param_1 + 0x44U & 3, uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
           ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x80) == 0)) ||
          ((uStack_84 & 0x800) != 0)))) {
        func_0206ff50(param_1);
      }
    }
    if ((uStack_84 & 0x400000) != 0) {
      uVar3 = func_020d59f8(0x400000);
      func_020efc74((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                    (*(uint *)(uRam01ffacf8 & 0xfffffffc) >> (uRam01ffacf8 & 3) * 8 |
                    *(uint *)(uRam01ffacf8 & 0xfffffffc) << (uRam01ffacf8 & 3) * -8 + 0x20),
                    ((uVar3 & 0xe0) << 0xb) >> 0x10);
      uVar3 = param_1 + 0x4cU & 3;
      uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x10000000) != 0) {
        uVar3 = (uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam01ffacf8 & 0xfffffffc) >> (uRam01ffacf8 & 3) * 8 |
                *(uint *)(uRam01ffacf8 & 0xfffffffc) << (uRam01ffacf8 & 3) * -8 + 0x20) + 0x1f0;
        uVar2 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        func_02090838(param_1 + iRam01ffacfc,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
      }
      uVar3 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 2) != 0) &&
          ((uStack_84 & 0x400000) != 0)) &&
         (uVar3 = param_1 + 0x180U & 3, uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
         (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 6)) {
        uVar3 = param_1 + 0x310U & 3;
        uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
        func_0208c1f4(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      }
    }
    if (uVar11 == 0) {
      func_01ffa350(param_1,0x10);
    }
    else {
      *param_2 = iStack_4c;
      param_2[1] = iStack_48;
      param_2[2] = iStack_44;
      uVar3 = (uint)(param_2 + 1) & 3;
      uVar2 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
      uVar7 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar2 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
              *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      uVar3 = (uint)(param_2 + 2) & 3;
      uVar10 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      uVar3 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      lVar1 = (longlong)(int)uVar3 * (longlong)(int)uVar3 +
              (longlong)(int)uVar2 * (longlong)(int)uVar2 +
              (longlong)(int)uVar7 * (longlong)(int)uVar7;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        uVar3 = param_1 + 0x48U & 3;
        uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xefffffff;
        *(undefined2 *)(param_1 + 1000) = 0;
        func_01ff9e5c(param_1);
        if ((((uStack_84 & 0x20000) == 0) ||
            (uVar3 = param_1 + 0x4cU & 3, uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
            ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & uRam01ffad00) != 0)) ||
           (uVar3 = param_1 + 0x7cU & 3, uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
           ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & uRam01ffad04) != 0)) {
          uVar3 = param_1 + 0x4cU & 3;
          uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
          *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xbfffffff
          ;
        }
        else {
          uVar3 = param_1 + 0x4cU & 3;
          uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
          *(uint *)(param_1 + 0x4c) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x40000000;
          uVar3 = func_020d59f8(0x20000);
          *(short *)(param_1 + 0x4d8) = (short)((int)(uVar3 & 0xe0) >> 5);
        }
        func_01ffa11c(param_1,param_2);
        uVar3 = param_1 + 0x260U & 3;
        uVar2 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
        if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0) {
          uVar3 = param_1 + 0x48U & 3;
          uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          uVar5 = uRam01ffad08;
          if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 1) != 0) {
            uVar5 = 0xfffffd47;
          }
          *(undefined4 *)(param_1 + 0x260) = uVar5;
        }
        func_0206edac(param_1,(uint)(uintptr_t)(param_2));
        if ((uStack_84 & 0x80000000) != 0) {
          *(undefined4 *)(param_1 + 0x200) = 0;
        }
        uVar3 = param_1 + 0x44U & 3;
        uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
        *(uint *)(param_1 + 0x44) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x10;
        uVar3 = param_1 + 0x2a8U & 3;
        uVar2 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
        if ((uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) ||
           (iVar4 = func_02070398(param_1,uStack_84,(undefined4)(uintptr_t)(auStack_80)), iVar4 == 0)) {
          func_01ff9cb0(param_1);
          iVar4 = (*(code *)(*(uint *)(uRam01fface4 & 0xfffffffc) >> (uRam01fface4 & 3) * 8 |
                            *(uint *)(uRam01fface4 & 0xfffffffc) << (uRam01fface4 & 3) * -8 + 0x20))
                            (param_1,uStack_84,&iStack_64);
          if (iVar4 == 0) {
            uVar5 = puRam01ffacf0[1];
            uVar8 = puRam01ffacf0[2];
            *(undefined4 *)(param_1 + 0x374) = *puRam01ffacf0;
            *(undefined4 *)(param_1 + 0x378) = uVar5;
            *(undefined4 *)(param_1 + 0x37c) = uVar8;
            uVar3 = param_1 + 0x44U & 3;
            uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
            *(uint *)(param_1 + 0x44) =
                 (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfffffdff;
          }
          else {
            lVar1 = (longlong)iStack_5c * (longlong)iStack_5c +
                    (longlong)iStack_64 * (longlong)iStack_64 +
                    (longlong)iStack_60 * (longlong)iStack_60;
            iVar4 = 0;
            if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
              iVar4 = Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_64),&uStack_34);
            }
            if (iVar4 != 0) {
              uVar3 = param_1 + 0x44U & 3;
              uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
              iVar4 = iRam01fface8;
              if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x4000000) != 0) {
                iVar4 = iRam01fface8 * 3;
              }
              uStack_30 = (uint)((longlong)(int)-uStack_30 * (longlong)iVar4) >> 0xc |
                          (int)((ulonglong)((longlong)(int)-uStack_30 * (longlong)iVar4) >> 0x20) <<
                          0x14;
              uStack_34 = (uint)((longlong)(int)-uStack_34 * (longlong)iVar4) >> 0xc |
                          (int)((ulonglong)((longlong)(int)-uStack_34 * (longlong)iVar4) >> 0x20) <<
                          0x14;
              uStack_2c = (uint)((longlong)(int)-uStack_2c * (longlong)iVar4) >> 0xc |
                          (int)((ulonglong)((longlong)(int)-uStack_2c * (longlong)iVar4) >> 0x20) <<
                          0x14;
              *(uint *)(param_1 + 0x374) = uStack_34;
              *(uint *)(param_1 + 0x378) = uStack_30;
              *(uint *)(param_1 + 0x37c) = uStack_2c;
              *(undefined4 *)(param_1 + 0x378) = uRam01ffacec;
            }
            uVar3 = param_1 + 0x44U & 3;
            uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
            *(uint *)(param_1 + 0x44) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x200;
          }
        }
      }
    }
  }
  if (0 < *(short *)(param_1 + 0x4dc)) {
    *(short *)(param_1 + 0x4dc) = *(short *)(param_1 + 0x4dc) + -1;
  }
  iVar4 = func_020d3d94();
  if (iVar4 != 0) {
    func_0206fe08(param_1);
  }
  uVar3 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if ((((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x40000000) != 0) &&
     (uVar3 = param_1 + 0x180U & 3, uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
     uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0)) {
    func_0206f824(param_1,(undefined4)(uintptr_t)(param_2),unaff_r11);
  }
  uVar3 = param_1 + 0x274U & 3;
  uVar2 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uRam01ffad0c * (ulonglong)uVar3;
  *(uint *)(param_1 + 0x274) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uRam01ffad0c + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar3 = param_1 + 0x274U & 3;
  uVar2 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 1) {
    uVar3 = -uVar3;
  }
  if ((int)uVar3 < 0x29) {
    *(undefined4 *)(param_1 + 0x274) = 0;
  }
  func_01ffa0c4(param_1);
  uVar3 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x20) != 0) {
    uVar3 = param_1 + 0x368U & 3;
    uVar10 = *(uint *)(param_1 + 0x368U & 0xfffffffc);
    uVar2 = param_1 + 0x36cU & 3;
    uVar7 = *(uint *)(param_1 + 0x36cU & 0xfffffffc);
    *(uint *)(param_1 + 0x368) =
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) +
         (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
    uVar3 = param_1 + 0x368U & 3;
    uVar2 = *(uint *)(param_1 + 0x368U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    iVar4 = (uint)*(ushort *)(param_1 + 0x366) * iRam01ffad10;
    if ((int)uVar3 < 1) {
      uVar3 = -uVar3;
    }
    iVar6 = iVar4;
    if (iVar4 < (int)uVar3) {
      iVar6 = 0;
    }
    if (iVar4 < (int)uVar3) {
      *(short *)(param_1 + 0x364) = (short)iVar6;
    }
    else {
      uVar2 = param_1 + 0x36cU & 3;
      uVar7 = *(uint *)(param_1 + 0x36cU & 0xfffffffc);
      *(ushort *)(param_1 + 0x364) =
           *(short *)(param_1 + 0x364) +
           ((ushort)(uVar7 >> uVar2 * 8) | (ushort)(uVar7 << uVar2 * -8 + 0x20));
    }
    uVar2 = param_1 + 0x4cU & 3;
    uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20 | 2;
    puVar9 = (uint *)(param_1 + 0x4c);
    if (iVar4 < (int)uVar3) {
      *(undefined2 *)(param_1 + 0x364) = 0;
      *puVar9 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
                *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffffdf
      ;
      return;
    }
    return;
  }
  return;
}

