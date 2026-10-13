/* Decompiled C draft; module arm9; ROM address 01ffdee4. No matching claim. */
#include "types.h"
#include "deps/01ffdee4_func_01ffdee4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int func_01ffdee4(int *param_1,undefined4 *param_2,uint param_3,int param_4,uint param_5,
                 short param_6,int *param_7,int *param_8,int *param_9,uint *param_10,
                 undefined4 *param_11,int *param_12,undefined2 *param_13,uint *param_14)

{
  longlong lVar1;
  longlong lVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  bool bVar26;
  ushort *puStack_1a0;
  uint local_198;
  int local_194;
  int local_188;
  uint local_184;
  uint *local_180;
  ushort uStack_144;
  uint uStack_140;
  uint *puStack_13c;
  ushort uStack_12a;
  int local_128;
  int iStack_124;
  int iStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  uint *apuStack_110 [2];
  uint *puStack_108;
  uint auStack_104 [3];
  uint *local_f8;
  uint *local_f4;
  uint *local_f0;
  uint *local_ec;
  uint *puStack_e8;
  uint *puStack_e4;
  uint *puStack_e0;
  uint *local_dc;
  uint *puStack_d8;
  int iStack_d4;
  int iStack_d0;
  int local_cc;
  uint *puStack_c8;
  uint *local_c4;
  uint *puStack_c0;
  uint *puStack_bc;
  uint *puStack_b8;
  uint *local_b4;
  uint *puStack_b0;
  int iStack_ac;
  int iStack_a8;
  int local_a4;
  uint *puStack_a0;
  uint *local_9c;
  uint *local_98;
  uint *local_94;
  uint *local_90;
  uint *local_8c;
  uint *local_88;
  uint *local_84;
  uint *local_80;
  uint *local_7c;
  uint *local_78;
  uint *local_74;
  uint *local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  int iStack_5c;
  uint *puStack_58;
  int iStack_54;
  int iStack_50;
  uint *puStack_4c;
  int iStack_48;
  int iStack_44;
  uint *puStack_40;
  int iStack_3c;
  int iStack_38;
  uint *puStack_34;
  uint *puStack_30;
  uint *puStack_2c;
  uint *puStack_28;
  
  uVar13 = uRam01ffee3c;
  local_188 = 0;
  local_f8 = (uint *)0x0;
  local_f4 = (uint *)0x0;
  local_180 = (uint *)0x1;
  if (((param_7 == (int *)0x0) && (param_8 == (int *)0x0)) && (param_9 == (int *)0x0)) {
    local_180 = local_f4;
  }
  local_184 = 0;
  local_ec = (uint *)*puRam01ffee30;
  puStack_e8 = (uint *)puRam01ffee30[1];
  puStack_e4 = (uint *)puRam01ffee30[2];
  puStack_e0 = (uint *)puRam01ffee30[3];
  local_dc = (uint *)puRam01ffee30[4];
  puStack_d8 = (uint *)puRam01ffee30[5];
  iStack_d4 = puRam01ffee30[6];
  iStack_d0 = puRam01ffee30[7];
  local_cc = puRam01ffee30[8];
  puStack_c8 = (uint *)puRam01ffee30[9];
  local_c4 = (uint *)*puRam01ffee34;
  puStack_c0 = (uint *)puRam01ffee34[1];
  puStack_bc = (uint *)puRam01ffee34[2];
  puStack_b8 = (uint *)puRam01ffee34[3];
  local_b4 = (uint *)puRam01ffee34[4];
  puStack_b0 = (uint *)puRam01ffee34[5];
  iStack_ac = puRam01ffee34[6];
  iStack_a8 = puRam01ffee34[7];
  local_a4 = puRam01ffee34[8];
  puStack_a0 = (uint *)puRam01ffee34[9];
  local_9c = (uint *)0x0;
  if (param_11 != (undefined4 *)0x0) {
    puStack_2c = (uint *)(param_4 << 1);
    puStack_30 = local_9c;
    puStack_28 = local_9c;
  }
  *piRam01ffee38 = 0;
  local_128 = *param_1;
  iStack_124 = param_1[1];
  iStack_120 = param_1[2];
  if (param_2 != (undefined4 *)0x0) {
    uStack_11c = *param_2;
    uStack_118 = param_2[1];
    uStack_114 = param_2[2];
  }
  uVar25 = uVar13 + 0x14 & 3;
  uVar15 = *(uint *)(uVar13 + 0x14 & 0xfffffffc);
  uVar8 = uVar13 + 0x20 & 3;
  uVar5 = *(uint *)(uVar13 + 0x20 & 0xfffffffc);
  uVar25 = (int)(local_128 - (uVar15 >> uVar25 * 8 | uVar15 << uVar25 * -8 + 0x20)) >> 0xc;
  if ((uVar25 & (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20)) != 0) {
    return 0;
  }
  uVar8 = uVar13 + 0x18 & 3;
  uVar16 = *(uint *)(uVar13 + 0x18 & 0xfffffffc);
  uVar5 = uVar13 + 0x24 & 3;
  uVar15 = *(uint *)(uVar13 + 0x24 & 0xfffffffc);
  uVar8 = (int)(iStack_124 - (uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20)) >> 0xc;
  if ((uVar8 & (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20)) != 0) {
    return 0;
  }
  uVar5 = uVar13 + 0x1c & 3;
  uVar17 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
  uVar15 = uVar13 + 0x28 & 3;
  uVar16 = *(uint *)(uVar13 + 0x28 & 0xfffffffc);
  uVar5 = (int)(iStack_120 - (uVar17 >> uVar5 * 8 | uVar17 << uVar5 * -8 + 0x20)) >> 0xc;
  if ((uVar5 & (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20)) != 0) {
    return 0;
  }
  uVar15 = uVar13 + 0x2c & 3;
  uVar16 = *(uint *)(uVar13 + 0x2c & 0xfffffffc);
  puVar19 = (uint *)(uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20);
  uVar15 = uVar13 + 0x34 & 3;
  uVar6 = *(uint *)(uVar13 + 0x34 & 0xfffffffc);
  uVar16 = uVar13 + 0x30 & 3;
  uVar7 = *(uint *)(uVar13 + 0x30 & 0xfffffffc);
  uVar17 = uVar13 + 0xc & 3;
  uVar18 = *(uint *)(uVar13 + 0xc & 0xfffffffc);
  uVar17 = uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20;
  uVar15 = uVar17 + ((uVar5 >> ((uint)puVar19 & 0xff)) <<
                     ((uVar6 >> uVar15 * 8 | uVar6 << uVar15 * -8 + 0x20) & 0xff) |
                     (uVar8 >> ((uint)puVar19 & 0xff)) <<
                     ((uVar7 >> uVar16 * 8 | uVar7 << uVar16 * -8 + 0x20) & 0xff) |
                    uVar25 >> ((uint)puVar19 & 0xff)) * 4;
  uVar16 = uVar15 & 3;
  uVar15 = *(uint *)(uVar15 & 0xfffffffc);
  for (uVar15 = uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20; -1 < (int)uVar15;
      uVar15 = uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20) {
    uVar17 = uVar17 + uVar15;
    puVar19 = (uint *)((int)puVar19 - 1);
    uVar15 = uVar17 + (uVar25 >> ((uint)puVar19 & 0xff) & 1 |
                      (uVar5 >> ((uint)puVar19 & 0xff) & 1) << 2 |
                      (uVar8 >> ((uint)puVar19 & 0xff) & 1) << 1) * 4;
    uVar16 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
  }
  puStack_1a0 = (ushort *)(uVar17 + (uVar15 & 0x7fffffff));
  uVar25 = uVar13 + 8 & 3;
  uVar5 = *(uint *)(uVar13 + 8 & 0xfffffffc);
  uVar15 = *(uint *)(uVar13 & 0xfffffffc);
  uVar8 = uVar13 + 4 & 3;
  uVar16 = *(uint *)(uVar13 + 4 & 0xfffffffc);
  uVar8 = uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20;
  uVar16 = (uint)puStack_1a0[1];
  local_f0 = local_f4;
  local_98 = local_9c;
  local_94 = local_9c;
  local_90 = local_9c;
  local_8c = local_9c;
  local_88 = local_9c;
  local_84 = local_9c;
  local_80 = local_9c;
  local_7c = local_9c;
  local_78 = local_9c;
  local_74 = local_9c;
  local_70 = local_9c;
  if (uVar16 != 0) {
    uVar17 = uRam01ffee44 & 3;
    uVar7 = *(uint *)(uRam01ffee44 & 0xfffffffc);
    uVar6 = uRam01ffee40 & 3;
    uVar18 = *(uint *)(uRam01ffee40 & 0xfffffffc);
    puStack_1a0 = puStack_1a0 + 1;
    do {
      piVar9 = (int *)((uVar5 >> uVar25 * 8 | uVar5 << uVar25 * -8 + 0x20) + uVar16 * 0x10);
      iVar10 = *piVar9;
      uVar16 = piVar9[1];
      uVar20 = piVar9[2];
      uVar21 = piVar9[3];
      puVar11 = (undefined4 *)
                ((uVar16 & 0xffff) * 0xc +
                (uVar15 >> (uVar13 & 3) * 8 | uVar15 << (uVar13 & 3) * -8 + 0x20));
      uStack_6c = *puVar11;
      uStack_68 = puVar11[1];
      uStack_64 = puVar11[2];
      VecFx32_Subtract(&local_128,&uStack_6c,apuStack_110);
      iVar22 = (uVar21 & 0xffff) * 6;
      iStack_3c = (int)*(short *)(uVar8 + iVar22);
      iVar22 = uVar8 + iVar22;
      iStack_38 = (int)*(short *)(iVar22 + 2);
      puVar19 = (uint *)(int)*(short *)(iVar22 + 4);
      puStack_34 = puVar19;
      iVar22 = VecFx32_CrossProduct_0(apuStack_110,&iStack_3c);
      puVar3 = local_7c;
      if ((-param_4 <= iVar22) && (uVar23 = iVar22 - iVar10, (int)uVar23 < param_4)) {
        iVar22 = (uVar20 & 0xffff) * 6;
        iStack_54 = (int)*(short *)(uVar8 + iVar22);
        iVar22 = uVar8 + iVar22;
        iStack_50 = (int)*(short *)(iVar22 + 2);
        puVar19 = (uint *)(int)*(short *)(iVar22 + 4);
        puStack_4c = puVar19;
        uVar12 = VecFx32_CrossProduct_0(apuStack_110,&iStack_54);
        puVar3 = local_7c;
        if ((int)uVar12 < param_4) {
          iVar22 = (uVar20 >> 0x10) * 6;
          iStack_48 = (int)*(short *)(uVar8 + iVar22);
          iVar22 = uVar8 + iVar22;
          iStack_44 = (int)*(short *)(iVar22 + 2);
          puVar19 = (uint *)(int)*(short *)(iVar22 + 4);
          puStack_40 = puVar19;
          uVar20 = VecFx32_CrossProduct_0(apuStack_110,&iStack_48);
          puVar3 = local_7c;
          if ((int)uVar20 < param_4) {
            iVar22 = (uVar16 >> 0x10) * 6;
            iStack_60 = (int)*(short *)(uVar8 + iVar22);
            iVar22 = uVar8 + iVar22;
            iStack_5c = (int)*(short *)(iVar22 + 2);
            puVar19 = (uint *)(int)*(short *)(iVar22 + 4);
            puStack_58 = puVar19;
            iVar22 = VecFx32_CrossProduct_0(apuStack_110,&iStack_60);
            iVar24 = param_4 - iVar22;
            puVar3 = local_7c;
            if ((-1 < iVar24) && (iVar24 < 0x1e001)) {
              uStack_12a = (ushort)(uVar21 >> 0x10);
              uVar16 = (uint)uStack_12a;
              if ((((uRam01ffee48 & uVar16) == 0) ||
                  ((((param_5 & 4) == 0 || ((uVar21 & 0x20000000) == 0)) &&
                   (((param_5 & 1) == 0 || ((uVar21 & 0x100000) == 0)))))) &&
                 (((param_5 & 0x10) == 0 || ((uVar21 & 0xa0000000) == 0)))) {
                puVar19 = (uint *)((uint)((longlong)iVar22 * (longlong)iStack_5c) >> 0xc |
                                  (int)((ulonglong)((longlong)iVar22 * (longlong)iStack_5c) >> 0x20)
                                  << 0x14);
                local_f4 = (uint *)-(int)puVar19;
                local_f8 = (uint *)-((uint)((longlong)iVar22 * (longlong)iStack_60) >> 0xc |
                                    (int)((ulonglong)((longlong)iVar22 * (longlong)iStack_60) >>
                                         0x20) << 0x14);
                bVar26 = true;
                local_f0 = (uint *)-((uint)((longlong)iVar22 * (longlong)(int)puStack_58) >> 0xc |
                                    (int)((ulonglong)((longlong)iVar22 * (longlong)(int)puStack_58)
                                         >> 0x20) << 0x14);
                local_198 = (uint)((longlong)param_4 * (longlong)param_4);
                local_194 = (int)((ulonglong)((longlong)param_4 * (longlong)param_4) >> 0x20);
                if ((int)uVar20 < (int)uVar12) {
                  if ((int)uVar23 < (int)uVar12) {
                    if (0 < (int)uVar12) {
                      if (iVar22 < 0) {
                        if (param_2 != (undefined4 *)0x0) {
                          puVar19 = auStack_104;
                          VecFx32_Subtract(&uStack_11c,&uStack_6c);
                          iVar10 = VecFx32_CrossProduct_0(auStack_104,&iStack_60);
                          puVar3 = local_7c;
                          if ((-1 < iVar10) &&
                             (iVar10 = VecFx32_CrossProduct_0(auStack_104,&iStack_54),
                             puVar3 = local_7c, iVar10 < 1)) goto LAB_01ffe490;
                        }
                        goto LAB_01ffed90;
                      }
LAB_01ffe490:
                      if ((int)uVar23 < (int)uVar20) {
                        iVar10 = VecFx32_CrossProduct_0(&iStack_54,&iStack_48);
                        if ((int)((uint)((longlong)iVar10 * (longlong)(int)uVar12) >> 0xc |
                                 (int)((ulonglong)((longlong)iVar10 * (longlong)(int)uVar12) >> 0x20
                                      ) << 0x14) <= (int)uVar20) goto LAB_01ffe788;
                      }
                      else {
                        iVar10 = VecFx32_CrossProduct_0(&iStack_54,&iStack_3c);
                        if ((int)((uint)((longlong)iVar10 * (longlong)(int)uVar12) >> 0xc |
                                 (int)((ulonglong)((longlong)iVar10 * (longlong)(int)uVar12) >> 0x20
                                      ) << 0x14) <= (int)uVar23) {
LAB_01ffe7e0:
                          func_01fff434(iVar10,uVar12,uVar23,apuStack_110);
                          goto LAB_01ffe808;
                        }
                      }
                      uVar20 = (uint)((ulonglong)uVar12 * (ulonglong)uVar12);
                      uStack_140 = local_198 - uVar20;
                      puStack_13c = (uint *)(local_194 -
                                            (((int)uVar12 >> 0x1f) * uVar12 +
                                             uVar12 * ((int)uVar12 >> 0x1f) +
                                             (int)((ulonglong)uVar12 * (ulonglong)uVar12 >> 0x20) +
                                            (uint)(local_198 < uVar20)));
                      if ((iRam01ffee4c < iStack_50) || (iStack_50 < iRam01ffee50)) {
                        bVar26 = false;
                      }
                      if (param_11 != (undefined4 *)0x0) {
                        VecFx32_AddScale1(-uVar12,&iStack_54,&local_f8,&local_f8);
                      }
                      goto LAB_01ffe858;
                    }
                  }
                  else {
LAB_01ffe594:
                    if (0 < (int)uVar23) {
                      if (iVar22 < 0) {
                        if (param_2 != (undefined4 *)0x0) {
                          puVar19 = auStack_104;
                          VecFx32_Subtract(&uStack_11c,&uStack_6c);
                          iVar24 = VecFx32_CrossProduct_0(auStack_104,&iStack_60);
                          puVar3 = local_7c;
                          if ((-1 < iVar24) &&
                             (iVar24 = VecFx32_CrossProduct_0(auStack_104,&iStack_3c),
                             puVar3 = local_7c, iVar24 <= iVar10)) goto LAB_01ffe5ec;
                        }
                        goto LAB_01ffed90;
                      }
LAB_01ffe5ec:
                      if ((int)uVar20 < (int)uVar12) {
                        iVar10 = VecFx32_CrossProduct_0(&iStack_3c,&iStack_54);
                        if ((int)((uint)((longlong)iVar10 * (longlong)(int)uVar23) >> 0xc |
                                 (int)((ulonglong)((longlong)iVar10 * (longlong)(int)uVar23) >> 0x20
                                      ) << 0x14) <= (int)uVar12) goto LAB_01ffe7e0;
                      }
                      else {
                        iVar10 = VecFx32_CrossProduct_0(&iStack_3c,&iStack_48);
                        if ((int)((uint)((longlong)iVar10 * (longlong)(int)uVar23) >> 0xc |
                                 (int)((ulonglong)((longlong)iVar10 * (longlong)(int)uVar23) >> 0x20
                                      ) << 0x14) <= (int)uVar20) {
LAB_01ffe7b4:
                          func_01fff434(iVar10,uVar23,uVar20,apuStack_110);
                          goto LAB_01ffe808;
                        }
                      }
                      uVar20 = (uint)((ulonglong)uVar23 * (ulonglong)uVar23);
                      uStack_140 = local_198 - uVar20;
                      puStack_13c = (uint *)(local_194 -
                                            (((int)uVar23 >> 0x1f) * uVar23 +
                                             uVar23 * ((int)uVar23 >> 0x1f) +
                                             (int)((ulonglong)uVar23 * (ulonglong)uVar23 >> 0x20) +
                                            (uint)(local_198 < uVar20)));
                      if ((iRam01ffee4c < iStack_38) || (iStack_38 < iRam01ffee50)) {
                        bVar26 = false;
                      }
                      if (param_11 != (undefined4 *)0x0) {
                        VecFx32_AddScale1(-uVar23,&iStack_3c,&local_f8,&local_f8);
                      }
                      goto LAB_01ffe858;
                    }
                  }
LAB_01ffe89c:
                  if ((iVar22 < 0) && (param_2 != (undefined4 *)0x0)) {
                    puVar19 = auStack_104;
                    VecFx32_Subtract(&uStack_11c,&uStack_6c);
                    iVar22 = VecFx32_CrossProduct_0(auStack_104,&iStack_60);
                    if ((iVar22 < 0) &&
                       ((((puVar3 = local_7c, (param_5 & 0x20) != 0 ||
                          (iVar22 = VecFx32_CrossProduct_0(auStack_104,&iStack_54),
                          puVar3 = local_7c, 0 < iVar22)) ||
                         (iVar22 = VecFx32_CrossProduct_0(auStack_104,&iStack_48), puVar3 = local_7c
                         , 0 < iVar22)) ||
                        (iVar22 = VecFx32_CrossProduct_0(auStack_104,&iStack_3c), puVar3 = local_7c,
                        iVar10 < iVar22)))) goto LAB_01ffed90;
                  }
                  bVar26 = false;
                }
                else {
                  if ((int)uVar20 <= (int)uVar23) goto LAB_01ffe594;
                  if ((int)uVar20 < 1) goto LAB_01ffe89c;
                  if (iVar22 < 0) {
                    if (param_2 != (undefined4 *)0x0) {
                      puVar19 = auStack_104;
                      VecFx32_Subtract(&uStack_11c,&uStack_6c);
                      iVar10 = VecFx32_CrossProduct_0(auStack_104,&iStack_60);
                      puVar3 = local_7c;
                      if ((-1 < iVar10) &&
                         (iVar10 = VecFx32_CrossProduct_0(auStack_104,&iStack_48), puVar3 = local_7c
                         , iVar10 < 1)) goto LAB_01ffe53c;
                    }
                    goto LAB_01ffed90;
                  }
LAB_01ffe53c:
                  if ((int)uVar12 < (int)uVar23) {
                    iVar10 = VecFx32_CrossProduct_0(&iStack_48,&iStack_3c);
                    if ((int)((uint)((longlong)iVar10 * (longlong)(int)uVar20) >> 0xc |
                             (int)((ulonglong)((longlong)iVar10 * (longlong)(int)uVar20) >> 0x20) <<
                             0x14) <= (int)uVar23) goto LAB_01ffe7b4;
LAB_01ffe6b0:
                    uVar21 = (uint)((ulonglong)uVar20 * (ulonglong)uVar20);
                    uStack_140 = local_198 - uVar21;
                    puStack_13c = (uint *)(local_194 -
                                          (((int)uVar20 >> 0x1f) * uVar20 +
                                           uVar20 * ((int)uVar20 >> 0x1f) +
                                           (int)((ulonglong)uVar20 * (ulonglong)uVar20 >> 0x20) +
                                          (uint)(local_198 < uVar21)));
                    if ((iRam01ffee4c < iStack_44) || (iStack_44 < iRam01ffee50)) {
                      bVar26 = false;
                    }
                    if (param_11 != (undefined4 *)0x0) {
                      VecFx32_AddScale1(-uVar20,&iStack_48,&local_f8,&local_f8);
                    }
                  }
                  else {
                    iVar10 = VecFx32_CrossProduct_0(&iStack_48,&iStack_54);
                    if ((int)uVar12 <
                        (int)((uint)((longlong)iVar10 * (longlong)(int)uVar20) >> 0xc |
                             (int)((ulonglong)((longlong)iVar10 * (longlong)(int)uVar20) >> 0x20) <<
                             0x14)) goto LAB_01ffe6b0;
LAB_01ffe788:
                    func_01fff434(iVar10,uVar20,uVar12,apuStack_110);
LAB_01ffe808:
                    bVar26 = local_198 < uStack_140;
                    uStack_140 = local_198 - uStack_140;
                    puStack_13c = (uint *)(local_194 - ((int)puStack_13c + (uint)bVar26));
                    puVar19 = puStack_13c;
                    puVar3 = local_7c;
                    if (0 < (int)((int)puStack_13c + (uint)(uStack_140 != 0)) ==
                        SBORROW4(-(int)puStack_13c,(uint)(uStack_140 != 0))) goto LAB_01ffed90;
                    if (param_11 != (undefined4 *)0x0) {
                      VecFx32_Subtract(&local_f8,apuStack_110,&local_f8);
                    }
                    bVar26 = false;
                  }
LAB_01ffe858:
                  *puRam01ffee54 = 1;
                  puVar19 = puRam01ffee58;
                  *puRam01ffee58 = uStack_140;
                  puVar19[1] = (uint)puStack_13c;
                  do {
                  } while ((*puRam01ffee54 & 0x8000) != 0);
                  iVar24 = (*(uint *)(uRam01ffee5c & 0xfffffffc) >> (uRam01ffee5c & 3) * 8 |
                           *(uint *)(uRam01ffee5c & 0xfffffffc) << (uRam01ffee5c & 3) * -8 + 0x20) -
                           iVar22;
                  puVar19 = puStack_13c;
                  puVar3 = local_7c;
                  if (iVar24 < 0) goto LAB_01ffed90;
                }
                puVar19 = (uint *)(1 << ((int)(uVar16 & 0x1f00) >> 8));
                uVar20 = (uint)puVar19 | 1 << ((int)(uVar16 & 0xc) >> 2) + 0x1a;
                uVar16 = uVar20 | (uVar16 & 2) << 0x17;
                if (param_2 != (undefined4 *)0x0) {
                  puVar19 = auStack_104;
                  VecFx32_Subtract(&uStack_11c,&uStack_6c);
                  iVar10 = VecFx32_CrossProduct_0(auStack_104,&iStack_60);
                  if (iVar10 < 0) {
                    puVar3 = local_7c;
                    if (((bVar26) && ((uVar16 & uRam01ffee60) != 0)) && (param_3 != 0)) {
                      apuStack_110[0] =
                           (uint *)((uint)((longlong)iVar24 * (longlong)iStack_60) >> 2 |
                                   (int)((ulonglong)((longlong)iVar24 * (longlong)iStack_60) >> 0x20
                                        ) << 0x1e);
                      puVar19 = (uint *)((uint)((longlong)iVar24 * (longlong)(int)puStack_58) >> 2 |
                                        (int)((ulonglong)
                                              ((longlong)iVar24 * (longlong)(int)puStack_58) >> 0x20
                                             ) << 0x1e);
                      puVar3 = apuStack_110[0];
                      if (((int)apuStack_110[0] <= (int)local_84) &&
                         (puVar3 = local_84, (int)apuStack_110[0] < (int)local_78)) {
                        local_78 = apuStack_110[0];
                      }
                      local_84 = puVar3;
                      puVar3 = puVar19;
                      puStack_108 = puVar19;
                      if (((int)puVar19 <= (int)local_7c) &&
                         (puVar3 = local_7c, (int)puVar19 < (int)local_70)) {
                        local_70 = puVar19;
                      }
                    }
                    local_7c = puVar3;
                    puVar3 = local_7c;
                    if (((param_5 & 0x3b) != 0) || (iVar10 < -0xa000)) goto LAB_01ffed90;
                  }
                  puVar19 = auStack_104;
                  VecFx32_Subtract(&local_128,&uStack_11c);
                  iVar10 = VecFx32_CrossProduct_0(auStack_104,&iStack_60);
                  if (iRam01ffee64 < iVar10) {
                    puVar3 = local_7c;
                    if (((bVar26) && ((uVar16 & uRam01ffee60) != 0)) && (param_3 != 0)) {
                      puVar19 = (uint *)((ulonglong)((longlong)iVar24 * (longlong)iStack_60) >> 0x20
                                        );
                      puStack_108 = (uint *)((uint)((longlong)iVar24 * (longlong)(int)puStack_58) >>
                                             2 | (int)((ulonglong)
                                                       ((longlong)iVar24 * (longlong)(int)puStack_58
                                                       ) >> 0x20) << 0x1e);
                      apuStack_110[0] =
                           (uint *)((uint)((longlong)iVar24 * (longlong)iStack_60) >> 2 |
                                   (int)puVar19 << 0x1e);
                      puVar3 = apuStack_110[0];
                      if (((int)apuStack_110[0] <= (int)local_84) &&
                         (puVar3 = local_84, (int)apuStack_110[0] < (int)local_78)) {
                        local_78 = apuStack_110[0];
                      }
                      local_84 = puVar3;
                      puVar3 = puStack_108;
                      if (((int)puStack_108 <= (int)local_7c) &&
                         (puVar3 = local_7c, (int)puStack_108 < (int)local_70)) {
                        local_70 = puStack_108;
                      }
                    }
                    goto LAB_01ffed90;
                  }
                }
                if (((param_5 & 2) == 0) || (puVar3 = local_7c, (uVar20 & 0x200) == 0)) {
                  if ((param_11 != (undefined4 *)0x0) && ((int)local_f4 < (int)puStack_2c)) {
                    puStack_30 = local_f8;
                    puStack_2c = local_f4;
                    puStack_28 = local_f0;
                  }
                  puVar19 = local_7c;
                  if (local_180 != (uint *)0x0) {
                    local_f8 = (uint *)((uint)((longlong)iVar24 * (longlong)iStack_60) >> 2 |
                                       (int)((ulonglong)((longlong)iVar24 * (longlong)iStack_60) >>
                                            0x20) << 0x1e);
                    local_f4 = (uint *)((uint)((longlong)iVar24 * (longlong)iStack_5c) >> 2 |
                                       (int)((ulonglong)((longlong)iVar24 * (longlong)iStack_5c) >>
                                            0x20) << 0x1e);
                    local_f0 = (uint *)((uint)((longlong)iVar24 * (longlong)(int)puStack_58) >> 2 |
                                       (int)((ulonglong)
                                             ((longlong)iVar24 * (longlong)(int)puStack_58) >> 0x20)
                                       << 0x1e);
                    if ((uVar16 & uRam01ffee68) == 0) {
                      if ((uVar16 & uRam01ffee60) != 0) {
                        puVar3 = puStack_bc;
                        puVar4 = local_94;
                        if ((uVar20 & 0x10000) == 0) {
                          puVar3 = local_f8;
                          if (((int)local_f8 <= (int)local_c4) &&
                             (puVar3 = local_c4, (int)local_f8 < (int)puStack_b8)) {
                            puStack_b8 = local_f8;
                          }
                          local_c4 = puVar3;
                          puVar3 = local_f4;
                          if (((int)local_f4 <= (int)puStack_c0) &&
                             (puVar3 = puStack_c0, (int)local_f4 < (int)local_b4)) {
                            local_b4 = local_f4;
                          }
                          puStack_c0 = puVar3;
                          puVar3 = local_f0;
                          if (((int)local_f0 <= (int)puStack_bc) &&
                             (puVar3 = puStack_bc, (int)local_f0 < (int)puStack_b0)) {
                            puStack_b0 = local_f0;
                          }
                        }
                        else {
                          uVar16 = uVar16 | uVar7 >> uVar17 * 8 | uVar7 << uVar17 * -8 + 0x20;
                          puVar4 = local_f8;
                          if (((int)local_f8 <= (int)local_9c) &&
                             (puVar4 = local_9c, (int)local_f8 < (int)local_90)) {
                            local_90 = local_f8;
                          }
                          local_9c = puVar4;
                          puVar4 = local_f4;
                          if (((int)local_f4 <= (int)local_98) &&
                             (puVar4 = local_98, (int)local_f4 < (int)local_8c)) {
                            local_8c = local_f4;
                          }
                          local_98 = puVar4;
                          puVar4 = local_f0;
                          if (((int)local_f0 <= (int)local_94) &&
                             (puVar4 = local_94, (int)local_f0 < (int)local_88)) {
                            local_88 = local_f0;
                          }
                        }
                        local_94 = puVar4;
                        puStack_bc = puVar3;
                        if ((param_9 != (int *)0x0) && (iStack_ac <= iVar24)) {
                          iStack_a8 = iStack_60;
                          local_a4 = iStack_5c;
                          puStack_a0 = puStack_58;
                          iStack_ac = iVar24;
                        }
                        if (param_3 != 0) {
                          puVar19 = local_f8;
                          if (((int)local_f8 <= (int)local_84) &&
                             (puVar19 = local_84, (int)local_f8 < (int)local_78)) {
                            local_78 = local_f8;
                          }
                          local_84 = puVar19;
                          puVar19 = local_f0;
                          if (((int)local_f0 <= (int)local_7c) &&
                             (puVar19 = local_7c, (int)local_f0 < (int)local_70)) {
                            local_70 = local_f0;
                          }
                        }
                      }
                    }
                    else {
                      puVar3 = local_f8;
                      if (((int)local_f8 <= (int)local_ec) &&
                         (puVar3 = local_ec, (int)local_f8 < (int)puStack_e0)) {
                        puStack_e0 = local_f8;
                      }
                      local_ec = puVar3;
                      puVar3 = local_f4;
                      if (((int)local_f4 <= (int)puStack_e8) &&
                         (puVar3 = puStack_e8, (int)local_f4 < (int)local_dc)) {
                        local_dc = local_f4;
                      }
                      puStack_e8 = puVar3;
                      puVar3 = local_f0;
                      if (((int)local_f0 <= (int)puStack_e4) &&
                         (puVar3 = puStack_e4, (int)local_f0 < (int)puStack_d8)) {
                        puStack_d8 = local_f0;
                      }
                      puStack_e4 = puVar3;
                      if ((param_8 != (int *)0x0) && (iStack_d4 <= iVar24)) {
                        iStack_d0 = iStack_60;
                        local_cc = iStack_5c;
                        puStack_c8 = puStack_58;
                        iStack_d4 = iVar24;
                      }
                    }
                  }
                  local_7c = puVar19;
                  local_184 = local_184 | uVar18 >> uVar6 * 8 | uVar18 << uVar6 * -8 + 0x20 | uVar16
                  ;
                  if ((*(uint *)((uint)piRam01ffee38 & 0xfffffffc) >> ((uint)piRam01ffee38 & 3) * 8
                      | *(uint *)((uint)piRam01ffee38 & 0xfffffffc) <<
                        ((uint)piRam01ffee38 & 3) * -8 + 0x20) == 0x10) {
                    *piRam01ffee38 = 0xf;
                  }
                  puVar19 = (uint *)(*(uint *)((uint)piRam01ffee38 & 0xfffffffc) >>
                                     ((uint)piRam01ffee38 & 3) * 8 |
                                    *(uint *)((uint)piRam01ffee38 & 0xfffffffc) <<
                                    ((uint)piRam01ffee38 & 3) * -8 + 0x20);
                  local_188 = 1;
                  *(uint *)(iRam01ffee6c + (int)puVar19 * 4) = uVar16;
                  *(ushort *)(iRam01ffee70 + (int)puVar19 * 2) = uStack_12a;
                  *piRam01ffee38 = (int)puVar19 + 1;
                  puVar3 = local_7c;
                }
              }
            }
          }
        }
      }
LAB_01ffed90:
      local_7c = puVar3;
      puStack_1a0 = puStack_1a0 + 1;
      uVar16 = (uint)*puStack_1a0;
    } while (uVar16 != 0);
  }
  if (param_12 != (int *)0x0) {
    puStack_1a0 = (ushort *)0x0;
    *param_12 = 0;
    param_12[1] = 0;
    param_12[2] = 0;
  }
  if (param_13 != (undefined2 *)0x0) {
    puStack_1a0 = (ushort *)0x0;
    *param_13 = 0;
  }
  puVar3 = puRam01ffee74;
  if (param_14 != (uint *)0x0) {
    puStack_1a0 = (ushort *)0x0;
    *param_14 = (uint)puRam01ffee74;
    puVar3[1] = 0;
    puVar19 = puVar3;
  }
  uVar13 = *(uint *)(uRam01ffee78 & 0xfffffffc);
  if (param_14 != (uint *)0x0) {
    *puVar19 = (uint)puStack_1a0;
  }
  if ((uVar13 >> (uRam01ffee78 & 3) * 8 != 0 || uVar13 << (uRam01ffee78 & 3) * -8 + 0x20 != 0) &&
     (iVar10 = (int)param_6, iVar10 != -2)) {
    if (iVar10 == -1) {
      func_020d5180(param_1,param_4);
    }
    else {
      func_01ffd900(iVar10,0x1000);
    }
    puVar19 = puRam01ffee74;
    piVar9 = piRam01ffee38;
    iVar10 = 0;
    if (0 < *psRam01ffee7c) {
      uVar13 = uRam01ffee80 & 3;
      uVar25 = *(uint *)(uRam01ffee80 & 0xfffffffc);
      iVar22 = 0;
      do {
        uVar8 = (*(uint *)(uRam01ffee84 & 0xfffffffc) >> (uRam01ffee84 & 3) * 8 |
                *(uint *)(uRam01ffee84 & 0xfffffffc) << (uRam01ffee84 & 3) * -8 + 0x20) + iVar10 * 4
        ;
        uVar5 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
        iVar14 = func_020e1d10(uVar8,param_1);
        iVar24 = iVar22;
        if (iVar14 != 0) {
          local_184 = local_184 | uVar25 >> uVar13 * 8 | uVar25 << uVar13 * -8 + 0x20 |
                      1 << (uStack_144 & 0xff);
          if ((*(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
              *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20) == 0x10) {
            *piVar9 = 0xf;
          }
          uVar5 = 1 << (uStack_144 & 0xff);
          uVar15 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                   *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
          *(uint *)(iRam01ffee6c + uVar15 * 4) = uVar5;
          *(ushort *)(iRam01ffee70 + uVar15 * 2) = uStack_144 << 8;
          *piVar9 = uVar15 + 1;
          if (param_14 != (uint *)0x0) {
            if ((uVar5 & uRam01ffee68) == 0) {
              puVar19[iVar22] = uVar8;
            }
            else {
              puVar19[iVar22] =
                   *(uint *)((uint)puVar19 & 0xfffffffc) >> ((uint)puVar19 & 3) * 8 |
                   *(uint *)((uint)puVar19 & 0xfffffffc) << ((uint)puVar19 & 3) * -8 + 0x20;
              *puVar19 = uVar8;
            }
            iVar24 = iVar22 + 1;
            puVar19[iVar24] = 0;
            if (0xe < iVar24) {
              iVar24 = iVar22;
            }
          }
          local_188 = 1;
        }
        iVar10 = iVar10 + 1;
        iVar22 = iVar24;
      } while (iVar10 < *psRam01ffee7c);
    }
  }
  if (local_188 == 0) {
    return 0;
  }
  if (param_8 != (int *)0x0) {
    *param_8 = iStack_d0;
    param_8[1] = local_cc;
    param_8[2] = (int)puStack_c8;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = iStack_a8;
    param_9[1] = local_a4;
    param_9[2] = (int)puStack_a0;
  }
  if (param_11 != (undefined4 *)0x0) {
    *param_11 = puStack_30;
    param_11[1] = puStack_2c;
    param_11[2] = puStack_28;
  }
  if (param_7 == (int *)0x0) goto LAB_01fff40c;
  local_f4 = puStack_e8;
  if ((int)puStack_e8 <= (int)puStack_c0) {
    local_f4 = puStack_c0;
  }
  puVar19 = local_dc;
  if ((int)local_b4 <= (int)local_dc) {
    puVar19 = local_b4;
  }
  local_f4 = (uint *)((int)local_f4 + (int)puVar19);
  if ((local_184 & 0x10000) != 0) {
    if ((((param_11 == (undefined4 *)0x0) || ((local_184 & uRam01ffee68) == 0)) ||
        ((local_184 & 0x400) != 0)) || ((local_184 & 0x800) != 0)) {
      local_184 = local_184 & 0xfffeffff |
                  *(uint *)(uRam01fff42c & 0xfffffffc) >> (uRam01fff42c & 3) * 8 |
                  *(uint *)(uRam01fff42c & 0xfffffffc) << (uRam01fff42c & 3) * -8 + 0x20;
    }
    else {
      puStack_28 = (uint *)((int)puStack_28 >> 4);
      puStack_30 = (uint *)((int)puStack_30 >> 4);
      puStack_2c = (uint *)((int)puStack_2c >> 4);
      if ((int)puStack_30 * (int)puStack_30 + (int)puStack_28 * (int)puStack_28 <=
          (int)puStack_2c * (int)puStack_2c) {
        local_184 = local_184 & 0xfffeffff;
        goto LAB_01fff184;
      }
      local_f4 = (uint *)0x0;
      local_184 = local_184 & uRam01fff430 |
                  *(uint *)(uRam01fff42c & 0xfffffffc) >> (uRam01fff42c & 3) * 8 |
                  *(uint *)(uRam01fff42c & 0xfffffffc) << (uRam01fff42c & 3) * -8 + 0x20;
      if (param_8 != (int *)0x0) {
        *param_8 = 0;
        param_8[1] = 0;
        param_8[2] = 0;
      }
    }
    if ((int)local_f4 < (int)local_98) {
      local_f4 = local_98;
    }
    if ((int)local_c4 < (int)local_9c) {
      local_c4 = local_9c;
    }
    if ((int)local_90 < (int)puStack_b8) {
      puStack_b8 = local_90;
    }
    if ((int)puStack_bc < (int)local_94) {
      puStack_bc = local_94;
    }
    if ((int)local_88 < (int)puStack_b0) {
      puStack_b0 = local_88;
    }
  }
LAB_01fff184:
  local_f8 = local_ec;
  if ((int)local_ec <= (int)local_c4) {
    local_f8 = local_c4;
  }
  puVar19 = puStack_e0;
  if ((int)puStack_b8 <= (int)puStack_e0) {
    puVar19 = puStack_b8;
  }
  local_f8 = (uint *)((int)local_f8 + (int)puVar19);
  local_f0 = puStack_e4;
  if ((int)puStack_e4 <= (int)puStack_bc) {
    local_f0 = puStack_bc;
  }
  puVar19 = puStack_d8;
  if ((int)puStack_b0 <= (int)puStack_d8) {
    puVar19 = puStack_b0;
  }
  local_f0 = (uint *)((int)local_f0 + (int)puVar19);
  *param_7 = (int)local_f8 >> 10;
  uVar13 = uRam01ffee60;
  param_7[1] = (int)local_f4 >> 10;
  param_7[2] = (int)local_f0 >> 10;
  if ((((local_184 & uVar13) != 0) && (param_3 != 0)) &&
     ((param_12 != (int *)0x0 && (param_9 != (int *)0x0)))) {
    uVar25 = (int)local_84 + (int)local_78;
    uVar15 = (int)local_7c + (int)local_70;
    uVar13 = (uint)(param_9 + 2) & 3;
    uVar8 = *(uint *)((uint)(param_9 + 2) & 0xfffffffc);
    lVar1 = (longlong)(int)uVar25 *
            (longlong)(int)(uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20);
    uVar8 = (uint)lVar1;
    lVar2 = (longlong)(int)uVar15 *
            (longlong)
            (int)(*(uint *)((uint)param_9 & 0xfffffffc) >> ((uint)param_9 & 3) * 8 |
                 *(uint *)((uint)param_9 & 0xfffffffc) << ((uint)param_9 & 3) * -8 + 0x20);
    uVar13 = (uint)lVar2;
    uVar5 = uVar8 - uVar13;
    iVar10 = (int)((ulonglong)lVar1 >> 0x20) -
             ((int)((ulonglong)lVar2 >> 0x20) + (uint)(uVar8 < uVar13));
    if (((int)(iVar10 - ((uVar5 < 0xfffffff0) - 1)) < 0 !=
         (SBORROW4(iVar10,-1) != SBORROW4(iVar10 + 1,(uint)(uVar5 < 0xfffffff0)))) ||
       (0 < (int)(iVar10 + (uint)(0x10 < uVar5)) != SBORROW4(-iVar10,(uint)(0x10 < uVar5)))) {
      uVar13 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
      local_78 = (uint *)((uint)((ulonglong)uVar13 * (ulonglong)uVar25) >> 0xc |
                         (((int)uVar25 >> 0x1f) * uVar13 +
                         uVar25 * ((int)uVar13 >> 0x1f) +
                         (int)((ulonglong)uVar13 * (ulonglong)uVar25 >> 0x20)) * 0x100000);
      uVar13 = param_3 + 8 & 3;
      uVar8 = *(uint *)(param_3 + 8 & 0xfffffffc);
      uVar13 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
      local_70 = (uint *)((uint)((ulonglong)uVar13 * (ulonglong)uVar15) >> 0xc |
                         (((int)uVar15 >> 0x1f) * uVar13 +
                         uVar15 * ((int)uVar13 >> 0x1f) +
                         (int)((ulonglong)uVar13 * (ulonglong)uVar15 >> 0x20)) * 0x100000);
      lVar1 = (longlong)(int)local_78 *
              (longlong)
              (int)(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                   *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20);
      local_84 = (uint *)(uVar25 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14));
      uVar13 = param_3 + 8 & 3;
      uVar25 = *(uint *)(param_3 + 8 & 0xfffffffc);
      lVar1 = (longlong)(int)local_70 *
              (longlong)(int)(uVar25 >> uVar13 * 8 | uVar25 << uVar13 * -8 + 0x20);
      local_7c = (uint *)(uVar15 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14));
      VecFx32_Add(&local_ec,&puStack_e0,apuStack_110);
      iVar10 = VecFx32_CrossProduct_0(&local_84,apuStack_110);
      if (-1 < iVar10) {
        lVar1 = (longlong)(int)local_7c * (longlong)(int)local_7c +
                (longlong)(int)local_84 * (longlong)(int)local_84 +
                (longlong)(int)local_80 * (longlong)(int)local_80;
        if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
          Vector3_MaybeNormalize(&local_84,&local_84);
        }
        lVar1 = (longlong)(int)local_84 * (longlong)(param_4 >> 5);
        lVar2 = (longlong)(int)local_7c * (longlong)(param_4 >> 5);
        *param_12 = (*(uint *)((uint)param_12 & 0xfffffffc) >> ((uint)param_12 & 3) * 8 |
                    *(uint *)((uint)param_12 & 0xfffffffc) << ((uint)param_12 & 3) * -8 + 0x20) +
                    ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
        uVar13 = (uint)(param_12 + 2) & 3;
        uVar25 = *(uint *)((uint)(param_12 + 2) & 0xfffffffc);
        param_12[2] = (uVar25 >> uVar13 * 8 | uVar25 << uVar13 * -8 + 0x20) +
                      ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
      }
    }
  }
LAB_01fff40c:
  if (param_10 != (uint *)0x0) {
    *param_10 = local_184;
  }
  return local_188;
}

