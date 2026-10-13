/* Decompiled C draft; module arm9; ROM address 0206e874. No matching claim. */
#include "types.h"
#include "deps/0206e874_func_0206e874.h"

void func_0206e874(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  bool bVar21;
  int local_84;
  uint local_7c;
  int local_68;
  int local_64;
  uint local_60 [5];
  undefined4 uStack_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  uint uStack_28;
  uint uVar17;
  
  local_60[0] = 0;
  bVar6 = false;
  local_60[1] = 0;
  *(undefined4 *)(param_1 + 0x39c) = 0;
  local_7c = 0;
  uVar18 = param_1 + 0x39cU & 3;
  uVar19 = *(uint *)(param_1 + 0x39cU & 0xfffffffc);
  *(uint *)(param_1 + 0x3a0) = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
  iVar7 = func_020d41e0(param_1,(undefined4 *)(uintptr_t)(param_1 + 0x1b8),local_60 + 3);
  if (iVar7 != 0) {
    uVar18 = param_1 + 0x48U & 3;
    uVar13 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    uVar19 = local_7c;
    if (((uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) & 0x40) == 0) {
      uVar18 = param_1 + 0x44U & 3;
      uVar19 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      iVar7 = iVar7 + -1;
      *(uint *)(param_1 + 0x44) = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20 | 0x40000;
      uVar19 = 0;
      if (-1 < iVar7) {
        local_30 = *puRam0206ed9c;
        uStack_2c = puRam0206ed9c[1];
        uStack_28 = puRam0206ed9c[2];
        local_64 = 0x29;
        local_68 = 0x1000;
        do {
          bVar5 = false;
          uVar19 = func_020d411c(iVar7);
          iVar8 = func_020d6be0(param_1,(ushort *)(uintptr_t)(uVar19));
          uVar18 = iRam0206eda0 + iVar8 * 4;
          uVar13 = uVar18 & 3;
          uVar18 = *(uint *)(uVar18 & 0xfffffffc);
          uVar18 = (*(code *)(uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20))
                             (param_1,local_60 + 2,uVar19);
          if (uVar18 != 0) {
            local_48 = local_30;
            local_44 = uStack_2c;
            local_40 = uStack_28;
            puVar20 = (uint *)(uVar19 + 0x10);
            uVar9 = func_020d4104(iVar7);
            uVar13 = uVar9 + 4 & 3;
            uVar16 = *(uint *)(uVar9 + 4 & 0xfffffffc);
            uVar17 = uVar16 >> uVar13 * 8 | uVar16 << uVar13 * -8 + 0x20;
            uVar16 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                     *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
            uVar13 = uVar9 + 8 & 3;
            uVar14 = *(uint *)(uVar9 + 8 & 0xfffffffc);
            uVar13 = uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20;
            lVar1 = (longlong)(int)uVar13 * (longlong)(int)uVar13 +
                    (longlong)(int)uVar16 * (longlong)(int)uVar16 +
                    (longlong)(int)uVar17 * (longlong)(int)uVar17;
            if ((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < 0x10)) {
              local_84 = 0;
            }
            else {
              local_84 = Vector3_MaybeNormalize(uVar9,&local_48);
            }
            if (local_84 != 0) {
              if (local_60[2] != 2) {
                uVar13 = iRam0206eda4 + iVar8 * 4;
                uVar9 = uVar13 & 3;
                uVar13 = *(uint *)(uVar13 & 0xfffffffc);
                (*(code *)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20))
                          (param_1,&local_48,uVar19);
              }
              if ((uVar18 & 8) == 0) {
                if ((uVar18 & 2) != 0) {
                  iVar10 = VecFx32_CrossProduct_0(param_1 + 0x50,(uint)(uintptr_t)(&local_48));
                  iVar15 = iVar10 + 0x1000;
                  iVar11 = iVar15;
                  if (0x1000 < iVar15) {
                    iVar11 = local_68;
                  }
                  if ((iVar15 == 0x1000 || iVar10 < 0 != SBORROW4(iVar15,0x1000)) && (iVar11 < 0x29)
                     ) {
                    iVar11 = local_64;
                  }
                  uVar13 = param_1 + 0x38cU & 3;
                  uVar9 = *(uint *)(param_1 + 0x38cU & 0xfffffffc);
                  lVar1 = (longlong)(int)(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) *
                          (longlong)iVar11;
                  *(uint *)(param_1 + 0x38c) =
                       (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
                }
              }
              else {
                func_0206f04c(param_1,&local_48);
              }
            }
            if (((uVar18 & 1) != 0) &&
               (((*(uint *)((uint)puVar20 & 0xfffffffc) >> ((uint)puVar20 & 3) * 8 != 0 ||
                  *(uint *)((uint)puVar20 & 0xfffffffc) << ((uint)puVar20 & 3) * -8 + 0x20 != 0 ||
                 (uVar13 = uVar19 + 0x14 & 3, uVar9 = *(uint *)(uVar19 + 0x14 & 0xfffffffc),
                 uVar9 >> uVar13 * 8 != 0 || uVar9 << uVar13 * -8 + 0x20 != 0)) ||
                (uVar13 = uVar19 + 0x18 & 3, uVar9 = *(uint *)(uVar19 + 0x18 & 0xfffffffc),
                uVar9 >> uVar13 * 8 != 0 || uVar9 << uVar13 * -8 + 0x20 != 0)))) {
              bVar21 = (uVar18 & 4) != 0;
              local_3c = local_30;
              local_38 = uStack_2c;
              local_34 = uStack_28;
              uVar13 = local_30;
              uVar9 = uStack_2c;
              uVar16 = uStack_28;
              if (bVar21) {
                uVar13 = *puVar20;
                uVar9 = *(uint *)(uVar19 + 0x14);
                uVar16 = *(uint *)(uVar19 + 0x18);
              }
              bVar4 = true;
              if (!bVar21) {
                if (local_84 != 0) {
                  iVar11 = Vector3_DotProduct((uint)(uintptr_t)(&local_48),(uint)(uintptr_t)(puVar20));
                  local_3c = (uint)((longlong)(int)local_48 * (longlong)iVar11) >> 0xc |
                             (int)((ulonglong)((longlong)(int)local_48 * (longlong)iVar11) >> 0x20)
                             << 0x14;
                  local_38 = (uint)((longlong)(int)local_44 * (longlong)iVar11) >> 0xc |
                             (int)((ulonglong)((longlong)(int)local_44 * (longlong)iVar11) >> 0x20)
                             << 0x14;
                  local_34 = (uint)((longlong)(int)local_40 * (longlong)iVar11) >> 0xc |
                             (int)((ulonglong)((longlong)(int)local_40 * (longlong)iVar11) >> 0x20)
                             << 0x14;
                }
                iVar11 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_48),(uint)(uintptr_t)(&local_3c));
                uVar13 = local_3c;
                uVar9 = local_38;
                uVar16 = local_34;
                if (iVar11 < 0) {
                  bVar4 = false;
                }
              }
              local_34 = uVar16;
              local_38 = uVar9;
              local_3c = uVar13;
              uVar12 = VecFx32_Norm((uint)(uintptr_t)(&local_3c));
              *(undefined4 *)(param_1 + 0x39c) = uVar12;
              uVar13 = param_1 + 0x39cU & 3;
              uVar9 = *(uint *)(param_1 + 0x39cU & 0xfffffffc);
              if ((0x1000 < (int)(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20)) && (bVar4)) {
                uVar12 = VecFx32_CrossProduct_0(param_1 + 0x50,(uint)(uintptr_t)(&local_3c));
                *(undefined4 *)(param_1 + 0x3a0) = uVar12;
                iVar11 = Vector3_DotProduct(param_1 + 0x50,(uint)(uintptr_t)(&local_3c));
                uVar13 = param_1 + 0x54U & 3;
                uVar9 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
                lVar1 = (longlong)(int)(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) *
                        (longlong)iVar11;
                uVar13 = param_1 + 0x58U & 3;
                uVar9 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
                lVar2 = (longlong)(int)(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) *
                        (longlong)iVar11;
                uVar13 = param_1 + 0x50U & 3;
                uVar9 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
                lVar3 = (longlong)(int)(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) *
                        (longlong)iVar11;
                uVar13 = param_1 + 0x2d8U & 3;
                uVar9 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
                *(uint *)(param_1 + 0x2d8) =
                     (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) +
                     (local_3c - ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14));
                uVar13 = param_1 + 0x2e0U & 3;
                uVar9 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
                *(uint *)(param_1 + 0x2e0) =
                     (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) +
                     (local_34 - ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14));
                uVar13 = param_1 + 0x260U & 3;
                uVar9 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
                *(uint *)(param_1 + 0x260) =
                     (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) +
                     (local_38 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14));
              }
            }
            if ((uVar18 & 8) != 0) {
              bVar6 = true;
            }
          }
          uVar18 = param_1 + 0x2a4U & 3;
          uVar13 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
          if (((0x2000 < (int)(uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20)) ||
              ((*(ushort *)(uVar19 + 2) & 0x200) != 0)) && (local_7c < 2)) {
            uVar18 = 0;
            do {
              uVar13 = param_1 + uVar18 * 4 + 0x438;
              uVar9 = uVar13 & 3;
              uVar13 = *(uint *)(uVar13 & 0xfffffffc);
              if (uVar19 == (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20)) {
                bVar5 = true;
                break;
              }
              uVar18 = uVar18 + 1 & 0xffff;
            } while (uVar18 < 2);
            if (!bVar5) {
              uVar18 = 0;
              do {
                iVar11 = param_1 + uVar18 * 4;
                uVar13 = iVar11 + 0x438;
                uVar9 = uVar13 & 3;
                uVar13 = *(uint *)(uVar13 & 0xfffffffc);
                if ((uVar19 != (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20)) &&
                   (uVar13 = iVar11 + 0x444, uVar9 = uVar13 & 3,
                   uVar13 = *(uint *)(uVar13 & 0xfffffffc),
                   uVar13 >> uVar9 * 8 == 0 && uVar13 << uVar9 * -8 + 0x20 == 0)) {
                  func_020d2668(uVar19,param_1,local_60[2]);
                  *(undefined4 *)(param_1 + uVar18 * 4 + 0x444) = 1;
                  break;
                }
                uVar18 = uVar18 + 1 & 0xffff;
              } while (uVar18 < 2);
            }
            local_60[local_7c] = uVar19;
            local_7c = local_7c + 1 & 0xffff;
          }
          if (iVar8 == 0xb) {
            *(uint *)(param_1 + 0x44c) = uVar19;
          }
          iVar7 = iVar7 + -1;
        } while (-1 < iVar7);
      }
    }
    uVar18 = param_1 + 0x48U & 3;
    uVar13 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if ((((uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) & 0x4000000) != 0) &&
       (uVar18 = param_1 + 0x44cU & 3, uVar13 = *(uint *)(param_1 + 0x44cU & 0xfffffffc),
       (uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) == uVar19)) {
      uStack_4c = 0;
      local_60[3] = 0;
    }
    VecFx32_Add(param_1 + 0x80,(uint)(uintptr_t)(local_60 + 3),(int *)(uintptr_t)(param_1 + 0x80));
  }
  uVar18 = 0;
  do {
    iVar7 = param_1 + uVar18 * 4;
    *(uint *)(iVar7 + 0x438) = local_60[uVar18];
    uVar19 = iVar7 + 0x444U & 3;
    uVar13 = *(uint *)(iVar7 + 0x444U & 0xfffffffc);
    if (uVar13 >> uVar19 * 8 != 0 || uVar13 << uVar19 * -8 + 0x20 != 0) {
      iVar8 = param_1 + uVar18 * 2;
      *(short *)(iVar8 + 0x440) = *(short *)(iVar8 + 0x440) + 1;
      if (10 < *(ushort *)(iVar8 + 0x440)) {
        *(undefined4 *)(iVar7 + 0x444) = 0;
        *(undefined2 *)(iVar8 + 0x440) = 0;
      }
    }
    uVar18 = uVar18 + 1 & 0xffff;
  } while (uVar18 < 2);
  if (bVar6) {
    uVar18 = param_1 + 0x44U & 3;
    uVar19 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20 | 0x40;
  }
  else {
    uVar18 = param_1 + 0x44U & 3;
    uVar19 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20) & 0xffffffbf;
  }
  return;
}

