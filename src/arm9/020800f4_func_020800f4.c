/* Decompiled C draft; module arm9; ROM address 020800f4. No matching claim. */
#include "types.h"
#include "deps/020800f4_func_020800f4.h"

void func_020800f4(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  int param_5,int param_6)

{
  longlong lVar1;
  uint *puVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar18;
  int iVar19;
  uint uVar20;
  bool bVar21;
  uint local_c4;
  int local_c0;
  uint local_b8;
  uint local_b4;
  uint local_b0 [11];
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58 [3];
  undefined1 auStack_4c [12];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint uStack_30;
  uint uStack_2c;
  uint uVar17;
  
  uVar4 = *(uint *)((uint)param_1 & 0xfffffffc);
  sVar3 = 0;
  local_b0[2] = 0;
  local_b0[3] = 0;
  local_b0[4] = 0;
  local_b0[5] = 0;
  local_b0[6] = 0;
  local_b0[7] = 0;
  local_b0[8] = 0;
  local_b0[9] = 0;
  uVar5 = 0x1000;
  uVar18 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  iVar19 = -0x1000;
  local_c0 = 0x1000;
  local_c4 = 0;
  bVar21 = *(short *)(uVar18 + 0x2c) == 1;
  if (bVar21) {
    uVar5 = *(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
            *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20;
  }
  local_b8 = 0;
  if (!bVar21) {
    local_b0[0] = 0;
    uVar18 = 0;
    sVar10 = 0;
    uVar5 = 0;
    local_b0[1] = 0;
    if (param_5 == 0) {
      if (param_6 == -1) {
        uVar13 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
        uVar7 = 0;
        if (*(short *)(uVar13 + 0x2c) != 0) {
          do {
            uVar11 = (uint)(param_1 + 1) & 3;
            uVar14 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
            uVar12 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                     uVar7 * 4;
            uVar16 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            uVar12 = uVar12 >> uVar16 * 8 | uVar12 << uVar16 * -8 + 0x20;
            if (((uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) != uVar12) &&
               (((uint)*(byte *)(uVar13 + 0x2e) & 1 << (uVar7 & 0xff)) == 0)) {
              local_b0[uVar5] = uVar12;
              sVar10 = 1;
              uVar5 = uVar5 + 1 & 0xffff;
            }
            uVar13 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
            uVar7 = uVar7 + 1 & 0xffff;
          } while (uVar7 < *(ushort *)(uVar13 + 0x2c));
        }
        if (sVar10 == 0) {
          uVar5 = 0;
          if (*(short *)(uVar13 + 0x2c) != 0) {
            local_34 = *puRam020808d0;
            uStack_30 = puRam020808d0[1];
            uStack_2c = puRam020808d0[2];
            local_b4 = 0;
            do {
              uVar12 = (uint)(param_1 + 1) & 3;
              uVar16 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
              uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                      uVar5 * 4;
              uVar11 = uVar7 & 3;
              uVar7 = *(uint *)(uVar7 & 0xfffffffc);
              if (((uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) !=
                   (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20)) &&
                 (((uint)*(byte *)(uVar13 + 0x2e) & 1 << (uVar5 & 0xff)) != 0)) {
                local_40 = local_34;
                local_3c = uStack_30;
                local_38 = uStack_2c;
                uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                        uVar5 * 4;
                uVar13 = uVar7 & 3;
                uVar7 = *(uint *)(uVar7 & 0xfffffffc);
                uVar7 = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20;
                if (*(ushort *)(uVar7 + 0x2c) != 0) {
                  uVar13 = local_b4;
                  do {
                    if ((((uint)*(byte *)(uVar7 + 0x2e) & 1 << uVar13) == 0) &&
                       (uVar12 = uVar7 + uVar13 * 4, uVar11 = uVar12 & 3,
                       uVar12 = *(uint *)(uVar12 & 0xfffffffc),
                       uVar12 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20,
                       (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) !=
                       uVar12)) {
                      uVar12 = uVar12 + 0x20;
                      uVar13 = uVar12 & 3;
                      uVar11 = *(uint *)(uVar12 & 0xfffffffc);
                      uVar12 = uVar7 + 0x20 & 3;
                      uVar7 = *(uint *)(uVar7 + 0x20 & 0xfffffffc);
                      VecFx32_Subtract(uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20,
                                       uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20,&local_40);
                      lVar1 = (longlong)(int)local_38 * (longlong)(int)local_38 +
                              (longlong)(int)local_40 * (longlong)(int)local_40 +
                              (longlong)(int)local_3c * (longlong)(int)local_3c;
                      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
                        Vector3_MaybeNormalize((uint)(uintptr_t)(&local_40),&local_40);
                      }
                      break;
                    }
                    uVar13 = uVar13 + 1 & 0xff;
                  } while (uVar13 < *(ushort *)(uVar7 + 0x2c));
                }
                iVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_40),param_3);
                if (iVar6 < -0x800) {
                  if ((iVar19 <= iVar6) || (sVar3 == 0)) {
                    uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20
                            ) + uVar5 * 4;
                    uVar13 = uVar7 & 3;
                    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
                    local_b8 = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20;
                    sVar3 = sVar3 + 1;
                    iVar19 = iVar6;
                  }
                }
                else {
                  uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                          + uVar5 * 4;
                  uVar13 = uVar7 & 3;
                  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
                  local_b0[uVar18 + 2] = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20;
                  uVar18 = uVar18 + 1 & 0xffff;
                }
              }
              uVar5 = uVar5 + 1 & 0xffff;
              uVar13 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
            } while (uVar5 < *(ushort *)(uVar13 + 0x2c));
          }
        }
        else {
          iVar19 = 0;
          if (1 < uVar5) {
            uVar5 = 0;
            do {
              uVar7 = local_b0[uVar5] + 0x20 & 3;
              uVar12 = *(uint *)(local_b0[uVar5] + 0x20 & 0xfffffffc);
              uVar18 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                       0x20;
              uVar13 = uVar18 & 3;
              uVar18 = *(uint *)(uVar18 & 0xfffffffc);
              VecFx32_Subtract(uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20,
                               uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20,
                               local_58 + uVar5 * 3);
              lVar1 = (longlong)*(int *)(auStack_4c + uVar5 * 0xc + -4) *
                      (longlong)*(int *)(auStack_4c + uVar5 * 0xc + -4) +
                      (longlong)local_58[uVar5 * 3] * (longlong)local_58[uVar5 * 3] +
                      (longlong)local_58[uVar5 * 3 + 1] * (longlong)local_58[uVar5 * 3 + 1];
              if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
                Vector3_MaybeNormalize((uint)(uintptr_t)(local_58 + uVar5 * 3),local_58 + uVar5 * 3);
              }
              uVar5 = uVar5 + 1 & 0xffff;
            } while (uVar5 < 2);
            iVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(local_58),param_3);
            iVar8 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_4c),param_3);
            if (iVar6 < iVar8) {
              iVar19 = 1;
            }
          }
          local_b0[2] = local_b0[iVar19];
          uVar18 = 1;
        }
      }
      else {
        iVar6 = GetDriverEntry();
        uVar7 = iVar6 + 0x4cU & 3;
        uVar13 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc);
        iVar6 = GetDriverEntry(param_4);
        iVar8 = GetDriverEntry(param_6);
        VecFx32_Subtract(iVar8 + 0x80,iVar6 + 0x80,&local_70);
        lVar1 = (longlong)local_68 * (longlong)local_68 +
                (longlong)local_70 * (longlong)local_70 + (longlong)local_6c * (longlong)local_6c;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          Vector3_MaybeNormalize((uint)(uintptr_t)(&local_70),&local_70);
        }
        uVar12 = 0;
        iVar6 = iVar19;
        if (*(short *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                      0x2c) != 0) {
          do {
            uVar16 = (uint)(param_1 + 1) & 3;
            uVar15 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
            uVar11 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                     uVar12 * 4;
            uVar14 = uVar11 & 3;
            uVar11 = *(uint *)(uVar11 & 0xfffffffc);
            if ((uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) !=
                (uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20)) {
              iVar8 = GetDriverEntry(param_4);
              uVar11 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                       uVar12 * 4;
              uVar16 = uVar11 & 3;
              uVar11 = *(uint *)(uVar11 & 0xfffffffc);
              uVar11 = (uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20) + 0x20;
              uVar16 = uVar11 & 3;
              uVar11 = *(uint *)(uVar11 & 0xfffffffc);
              VecFx32_Subtract(uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20,iVar8 + 0x80,
                               &local_64);
              lVar1 = (longlong)local_5c * (longlong)local_5c +
                      (longlong)local_64 * (longlong)local_64 +
                      (longlong)local_60 * (longlong)local_60;
              if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
                Vector3_MaybeNormalize((uint)(uintptr_t)(&local_64),&local_64);
              }
              iVar8 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_64),param_3);
              if (iVar8 < -0x800) {
                if ((iVar6 <= iVar8) || (sVar3 == 0)) {
                  sVar3 = sVar3 + 1;
                  uVar11 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                           + uVar12 * 4;
                  uVar16 = uVar11 & 3;
                  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
                  local_b8 = uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20;
                  iVar6 = iVar8;
                }
              }
              else if (((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) & 0x40) == 0) {
                iVar8 = Vector3_DotProduct((uint)(uintptr_t)(&local_70),(uint)(uintptr_t)(&local_64));
                if ((iVar19 < iVar8) || (uVar5 == 0)) {
                  uVar11 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                           + uVar12 * 4;
                  uVar16 = uVar11 & 3;
                  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
                  local_c4 = uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20;
                  uVar5 = uVar5 + 1 & 0xffff;
                  iVar19 = iVar8;
                }
              }
              else {
                iVar8 = Vector3_DotProduct((uint)(uintptr_t)(&local_70),(uint)(uintptr_t)(&local_64));
                if ((iVar8 < local_c0) || (sVar10 == 0)) {
                  sVar10 = sVar10 + 1;
                  uVar11 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                           + uVar12 * 4;
                  uVar16 = uVar11 & 3;
                  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
                  local_c4 = uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20;
                  local_c0 = iVar8;
                }
              }
            }
            uVar12 = uVar12 + 1 & 0xffff;
          } while (uVar12 < *(ushort *)
                             ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                              *(uint *)((uint)param_1 & 0xfffffffc) <<
                              ((uint)param_1 & 3) * -8 + 0x20) + 0x2c));
        }
      }
    }
    else {
      sVar10 = 0;
      iVar6 = GetDriverEntry(param_4);
      VecFx32_Subtract(param_5 + 4,iVar6 + 0x80,local_b0 + 10);
      lVar1 = (longlong)local_80 * (longlong)local_80 +
              (longlong)(int)local_b0[10] * (longlong)(int)local_b0[10] +
              (longlong)local_84 * (longlong)local_84;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(local_b0 + 10),local_b0 + 10);
      }
      uVar5 = 0;
      if (*(short *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                    0x2c) != 0) {
        iVar6 = iVar19;
        do {
          uVar13 = (uint)(param_1 + 1) & 3;
          uVar11 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
          uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                  *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                  uVar5 * 4;
          uVar12 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          if ((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) !=
              (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20)) {
            iVar8 = GetDriverEntry(param_4);
            uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                    uVar5 * 4;
            uVar13 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            uVar7 = (uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20) + 0x20;
            uVar13 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            VecFx32_Subtract(uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20,iVar8 + 0x80,
                             &local_7c);
            lVar1 = (longlong)local_74 * (longlong)local_74 +
                    (longlong)local_7c * (longlong)local_7c +
                    (longlong)local_78 * (longlong)local_78;
            if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
              Vector3_MaybeNormalize((uint)(uintptr_t)(&local_7c),&local_7c);
            }
            iVar8 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_7c),param_3);
            if (iVar8 < -0x800) {
              if ((iVar6 <= iVar8) || (sVar3 == 0)) {
                uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                        uVar5 * 4;
                uVar13 = uVar7 & 3;
                uVar7 = *(uint *)(uVar7 & 0xfffffffc);
                local_b8 = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20;
                sVar3 = sVar3 + 1;
                iVar6 = iVar8;
              }
            }
            else {
              iVar8 = Vector3_DotProduct((uint)(uintptr_t)(local_b0 + 10),(uint)(uintptr_t)(&local_7c));
              if ((iVar19 < iVar8) || (sVar10 == 0)) {
                sVar10 = sVar10 + 1;
                uVar7 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                        uVar5 * 4;
                uVar13 = uVar7 & 3;
                uVar7 = *(uint *)(uVar7 & 0xfffffffc);
                local_c4 = uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20;
                iVar19 = iVar8;
              }
            }
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < *(ushort *)
                          ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)
                          + 0x2c));
      }
    }
    uVar5 = local_c4;
    if (local_c4 == 0) {
      if (uVar18 == 0) {
        uVar5 = local_b8;
      }
      else {
        if (uVar18 == 1) {
          uVar5 = 0;
        }
        else {
          piVar9 = (int *)func_0208537c();
          if (uVar18 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = (uint)(piVar9 + 2) & 3;
            uVar7 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
            uVar15 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
            uVar14 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                     *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
            uVar5 = (uint)(piVar9 + 1) & 3;
            uVar12 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
            lVar1 = (ulonglong)uVar14 * (ulonglong)uVar15;
            uVar20 = (uint)lVar1;
            uVar7 = (uint)(piVar9 + 3) & 3;
            uVar11 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
            uVar13 = (uint)(piVar9 + 4) & 3;
            uVar16 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
            uVar17 = uVar16 >> uVar13 * 8 | uVar16 << uVar13 * -8 + 0x20;
            uVar13 = (uint)(piVar9 + 5) & 3;
            uVar16 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
            *piVar9 = uVar17 + uVar20;
            piVar9[1] = (uVar16 >> uVar13 * 8 | uVar16 << uVar13 * -8 + 0x20) +
                        (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) * uVar14 +
                        uVar15 * (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) +
                        (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar17,uVar20);
            if (uVar18 == 0) {
              uVar5 = (uint)(piVar9 + 1) & 3;
              uVar18 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
              uVar5 = uVar18 >> uVar5 * 8 | uVar18 << uVar5 * -8 + 0x20;
            }
            else {
              uVar5 = (uint)(piVar9 + 1) & 3;
              uVar7 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
              uVar5 = (uint)((ulonglong)uVar18 *
                             (ulonglong)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) >> 0x20);
            }
          }
          uVar5 = uVar5 & 0xffff;
        }
        uVar5 = local_b0[uVar5 + 2];
      }
    }
  }
  local_c4 = uVar5;
  puVar2 = puRam020808d0;
  *param_1 = local_c4;
  param_1[1] = uVar4 >> ((uint)param_1 & 3) * 8 | uVar4 << ((uint)param_1 & 3) * -8 + 0x20;
  uVar5 = puVar2[1];
  uVar4 = puVar2[2];
  param_1[2] = *puVar2;
  param_1[3] = uVar5;
  param_1[4] = uVar4;
  uVar4 = (uint)(param_1 + 1) & 3;
  uVar13 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x20;
  uVar18 = uVar5 & 3;
  uVar7 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  VecFx32_Subtract(uVar7 >> uVar18 * 8 | uVar7 << uVar18 * -8 + 0x20,
                   uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,param_1 + 2);
  uVar5 = (uint)(param_1 + 3) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar18 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = (uint)(param_1 + 4) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
          (longlong)(int)uVar4 * (longlong)(int)uVar4 +
          (longlong)(int)uVar18 * (longlong)(int)uVar18;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(param_1 + 2),param_1 + 2);
    return;
  }
  return;
}

