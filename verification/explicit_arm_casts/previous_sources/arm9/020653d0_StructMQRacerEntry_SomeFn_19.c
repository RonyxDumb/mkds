/* Decompiled C draft; module arm9; ROM address 020653d0. No matching claim. */
#include "types.h"
#include "deps/020653d0_StructMQRacerEntry_SomeFn_19.h"

void StructMQRacerEntry_SomeFn_19(int param_1,short *param_2,int param_3)

{
  undefined2 uVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  ushort uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  int iVar16;
  int *piVar17;
  uint uVar18;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  undefined1 auStack_184 [4];
  int local_180;
  int local_17c;
  int local_178;
  uint local_174;
  uint local_170;
  uint local_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  undefined1 auStack_150 [12];
  int local_144;
  int iStack_140;
  int iStack_13c;
  undefined1 auStack_138 [36];
  undefined1 auStack_114 [36];
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  undefined1 auStack_90 [12];
  undefined1 auStack_84 [12];
  undefined1 auStack_78 [12];
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [12];
  undefined1 auStack_54 [12];
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [12];
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uVar19;
  
  uVar6 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = (uint)(param_2 + 6) & 3;
  uVar18 = *(uint *)((uint)(param_2 + 6) & 0xfffffffc);
  uVar19 = uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 0x514U & 3;
  uVar18 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  piVar17 = (int *)(uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20);
  local_180 = (int)*param_2 << 10;
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10;
  bVar20 = uVar6 != 0;
  local_17c = (int)param_2[1] << 10;
  if (bVar20) {
    uVar6 = 1;
  }
  local_178 = (int)param_2[2] << 10;
  if (!bVar20) {
    uVar6 = 0;
  }
  *(int *)(param_1 + 0x2a8) = (int)param_2[3] << 2;
  *(short *)(param_1 + 0x236) = param_2[5];
  uVar7 = (uint)(param_2 + 10) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 10) & 0xfffffffc);
  piVar17[0x11] = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_2 + 8) & 3;
  uVar5 = *(uint *)((uint)(param_2 + 8) & 0xfffffffc);
  piVar17[0x12] = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(piVar17 + 0x12) & 3;
  uVar5 = *(uint *)((uint)(piVar17 + 0x12) & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) >> 0x18;
  if ((uVar7 & 0x80) == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = 0xc000;
  }
  piVar17[0x26] = (int)(short)(uVar11 | (ushort)(uVar7 << 6));
  uVar7 = (uint)(piVar17 + 0x12) & 3;
  uVar5 = *(uint *)((uint)(piVar17 + 0x12) & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) >> 0x10;
  if ((uVar7 & 0x80) == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = 0xc000;
  }
  piVar17[0x27] = (int)(short)(uVar11 | (ushort)((uVar7 & 0xff) << 6));
  uVar7 = (uint)(piVar17 + 0x12) & 3;
  uVar5 = *(uint *)((uint)(piVar17 + 0x12) & 0xfffffffc);
  uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) >> 8;
  if ((uVar7 & 0x80) == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = 0xc000;
  }
  piVar17[0x28] = (int)(short)(uVar11 | (ushort)((uVar7 & 0xff) << 6));
  uVar7 = (uint)(piVar17 + 0x12) & 3;
  uVar5 = *(uint *)((uint)(piVar17 + 0x12) & 0xfffffffc);
  piVar17[0x12] = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0xff;
  *(short *)(piVar17 + 0x10) = param_2[4];
  *(short *)(param_1 + 0x388) = param_2[4];
  if (uVar6 == 0) {
    uVar6 = param_1 + 0x44U & 3;
    uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0xffffffef;
  }
  else {
    uVar6 = param_1 + 0x44U & 3;
    uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20 | 0x10;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x48;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 2) == 0) {
    uVar6 = param_1 + 0x44U & 3;
    uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0xfffffffd;
  }
  else {
    uVar6 = param_1 + 0x44U & 3;
    uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20 | 2;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x48;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 8) == 0) {
    uVar6 = param_1 + 0x44U & 3;
    uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0xfffffff7;
  }
  else {
    uVar6 = param_1 + 0x44U & 3;
    uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20 | 8;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x10000) != 0) !=
      ((uVar19 & 0x10000) != 0)) {
    uVar1 = *(undefined2 *)(param_1 + 0x236);
    StructMQRacerEntry_SomeFn_63(param_1,&local_180,0,0);
    *(undefined2 *)(param_1 + 0x236) = uVar1;
    local_168 = *DAT_020664c8;
    uStack_164 = DAT_020664c8[1];
    uStack_160 = DAT_020664c8[2];
    func_01ffd190(&local_168,*(undefined2 *)(param_1 + 0x236),param_1 + 0xe0);
    *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_1 + 0xe0);
    *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0xec);
    uVar6 = param_1 + 0x7cU & 3;
    uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x400) != 0) {
      uVar6 = param_1 + 0x514U & 3;
      uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      puVar15 = (undefined4 *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
      uVar10 = *(undefined4 *)(param_1 + 0x84);
      uVar12 = *(undefined4 *)(param_1 + 0x88);
      *puVar15 = *(undefined4 *)(param_1 + 0x80);
      puVar15[1] = uVar10;
      puVar15[2] = uVar12;
      puVar15[4] = *puVar15;
      puVar15[5] = puVar15[1];
      puVar15[6] = puVar15[2];
      uVar10 = *(undefined4 *)(param_1 + 0x114);
      uVar12 = *(undefined4 *)(param_1 + 0x118);
      uVar14 = *(undefined4 *)(param_1 + 0x11c);
      puVar15[0x13] = *(undefined4 *)(param_1 + 0x110);
      puVar15[0x14] = uVar10;
      puVar15[0x15] = uVar12;
      puVar15[0x16] = uVar14;
      uVar10 = DAT_020664cc[1];
      uVar12 = DAT_020664cc[2];
      puVar15[0x2a] = *DAT_020664cc;
      puVar15[0x2b] = uVar10;
      puVar15[0x2c] = uVar12;
      *(undefined2 *)(puVar15 + 0x2d) = 0;
    }
  }
  uVar6 = param_1 + 0x84U & 3;
  uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar7 = param_1 + 0x80U & 3;
  uVar18 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  iVar8 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - local_17c;
  uVar6 = param_1 + 0x88U & 3;
  uVar5 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
  iVar16 = (uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20) - local_180;
  iVar9 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - local_178;
  lVar4 = (longlong)iVar9 * (longlong)iVar9 +
          (longlong)iVar16 * (longlong)iVar16 + (longlong)iVar8 * (longlong)iVar8;
  iVar8 = (int)((ulonglong)lVar4 >> 0x20);
  bVar20 = (uint)lVar4 < 0x90000000;
  if ((int)(iVar8 - (DAT_020664d0 + (uint)bVar20)) < 0 ==
      (SBORROW4(iVar8,DAT_020664d0) != SBORROW4(iVar8 - DAT_020664d0,(uint)bVar20))) {
    switch((short)piVar17[0x2d]) {
    case 0:
      uVar6 = param_1 + 0x138U & 3;
      uVar7 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar4 = (ulonglong)uVar6 * 0xffff9000;
      local_15c = (uint)lVar4 >> 0xc | ((int)((ulonglong)lVar4 >> 0x20) - uVar6) * 0x100000;
      uVar6 = param_1 + 0x13cU & 3;
      uVar7 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar4 = (ulonglong)uVar6 * 0xffff9000;
      local_158 = (uint)lVar4 >> 0xc | ((int)((ulonglong)lVar4 >> 0x20) - uVar6) * 0x100000;
      uVar6 = param_1 + 0x140U & 3;
      uVar7 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar4 = (ulonglong)uVar6 * 0xffff9000;
      local_154 = (uint)lVar4 >> 0xc | ((int)((ulonglong)lVar4 >> 0x20) - uVar6) * 0x100000;
      break;
    case 1:
      uVar6 = param_1 + 0x138U & 3;
      uVar7 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x7000;
      local_15c = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      uVar6 = param_1 + 0x13cU & 3;
      uVar7 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
      lVar4 = (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x7000;
      local_158 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      uVar6 = param_1 + 0x140U & 3;
      uVar7 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x7000;
      local_154 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      break;
    case 2:
      uVar6 = param_1 + 0x120U & 3;
      uVar7 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x7000;
      local_15c = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      uVar6 = param_1 + 0x124U & 3;
      uVar7 = *(uint *)(param_1 + 0x124U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x7000;
      local_158 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      uVar6 = param_1 + 0x128U & 3;
      uVar7 = *(uint *)(param_1 + 0x128U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 0x7000;
      local_154 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      break;
    case 3:
    default:
      uVar6 = param_1 + 0x120U & 3;
      uVar7 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar4 = (ulonglong)uVar6 * 0xffff9000;
      local_15c = (uint)lVar4 >> 0xc | ((int)((ulonglong)lVar4 >> 0x20) - uVar6) * 0x100000;
      uVar6 = param_1 + 0x124U & 3;
      uVar7 = *(uint *)(param_1 + 0x124U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar4 = (ulonglong)uVar6 * 0xffff9000;
      local_158 = (uint)lVar4 >> 0xc | ((int)((ulonglong)lVar4 >> 0x20) - uVar6) * 0x100000;
      uVar6 = param_1 + 0x128U & 3;
      uVar7 = *(uint *)(param_1 + 0x128U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      lVar4 = (ulonglong)uVar6 * 0xffff9000;
      local_154 = (uint)lVar4 >> 0xc | ((int)((ulonglong)lVar4 >> 0x20) - uVar6) * 0x100000;
    }
    piVar17[0x2a] = local_15c;
    piVar17[0x2b] = local_158;
    piVar17[0x2c] = local_154;
    local_17c = local_17c + 0x14000;
    VecFx32_Add(&local_180,&local_15c,&local_180);
    *(int *)(param_1 + 0x80) = local_180;
    *(int *)(param_1 + 0x84) = local_17c;
    *(int *)(param_1 + 0x88) = local_178;
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x80);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
    *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x90);
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x94);
    iVar8 = *(int *)(param_1 + 0x9c);
    iVar9 = *(int *)(param_1 + 0xa0);
    *piVar17 = *(int *)(param_1 + 0x98);
    piVar17[1] = iVar8;
    piVar17[2] = iVar9;
    uVar10 = DAT_020664cc[1];
    uVar12 = DAT_020664cc[2];
    *(undefined4 *)(param_1 + 0x25c) = *DAT_020664cc;
    *(undefined4 *)(param_1 + 0x260) = uVar10;
    *(undefined4 *)(param_1 + 0x264) = uVar12;
    func_01ffc064(param_1 + 0x1b8,&local_180,0x400,param_1);
    func_01ffbfe4(param_1);
    *(short *)(piVar17 + 0x2d) = (short)piVar17[0x2d] + 1;
    if (3 < *(ushort *)(piVar17 + 0x2d)) {
      *(undefined2 *)(piVar17 + 0x2d) = 0;
    }
  }
  else {
    uVar6 = param_1 + 0x48U & 3;
    uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x20000) == 0) {
      local_144 = *(int *)(param_1 + 0x8c);
      iStack_140 = *(int *)(param_1 + 0x90);
      iStack_13c = *(int *)(param_1 + 0x94);
      VecFx32_Add(&local_180,piVar17 + 0x2a,&local_180);
      uVar6 = param_1 + 0x1d0U & 3;
      uVar7 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
      func_020d5180(&local_180,param_3 * 0xd000 + (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20))
      ;
      uVar6 = 0;
      if (0 < param_3) {
        local_30 = *DAT_020664cc;
        uStack_2c = DAT_020664cc[1];
        uStack_28 = DAT_020664cc[2];
        sVar2 = *(short *)(DAT_020664d4 + 0x76);
        sVar3 = *(short *)(DAT_020664d4 + 0x74);
        do {
          uVar7 = param_1 + 0x48U & 3;
          uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
          if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x40) == 0) {
            if ((uVar6 < 3) && ((int)uVar6 < param_3 / 2)) {
              uVar10 = func_01ffc27c(param_1,0);
              func_01ffc090(param_1,uVar10);
            }
            func_01ffd190(DAT_020664dc,*(undefined2 *)(param_1 + 0x236),param_1 + 0xe0);
            func_01ffcebc(param_1 + 0xf0,param_1 + 0xe0,param_1 + 0x110);
            func_01ffcd84(param_1 + 0x120,param_1 + 0x110);
            uVar7 = param_1 + 0x514U & 3;
            uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
            uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
            *(short *)(uVar7 + 0x5c) =
                 *(short *)(uVar7 + 0x5c) +
                 (short)(DAT_020664e0 *
                         ((int)*(short *)(uVar7 + 0x40) - (int)*(short *)(uVar7 + 0x5c)) + 0x800U >>
                        0xc);
            *(undefined2 *)(param_1 + 0x388) = *(undefined2 *)(uVar7 + 0x5c);
            iVar8 = (int)(uint)*(ushort *)(param_1 + 0x388) >> 4;
            func_02146f98(auStack_138,param_1 + 300,(int)*(short *)(DAT_020664e4 + iVar8 * 4),
                          (int)*(short *)(DAT_020664e4 + (iVar8 * 2 + 1) * 2));
            uVar7 = param_1 + 0x48U & 3;
            uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
            if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 1) != 0) {
              func_02146f98(auStack_114,param_1 + 0x120,(int)sVar3,(int)sVar2);
              MTX_Concat33(auStack_114,auStack_138,auStack_138);
            }
            MTX_MultVec33(param_1 + 0x278,auStack_138,param_1 + 0x50);
            uVar7 = param_1 + 0x2a8U & 3;
            uVar5 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
            uVar18 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
            uVar7 = param_1 + 0x50U & 3;
            uVar5 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
            lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
                    (longlong)(int)uVar18;
            local_174 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
            uVar7 = param_1 + 0x54U & 3;
            uVar5 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
            lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
                    (longlong)(int)uVar18;
            local_170 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
            uVar7 = param_1 + 0x58U & 3;
            uVar5 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
            lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
                    (longlong)(int)uVar18;
            local_16c = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
            VecFx32_Add(&local_180,&local_174,&local_180);
            VecFx32_Add(&local_180,param_1 + 0x2d8,&local_180);
            VecFx32_Add(param_1 + 0xa4,param_1 + 0x2d8,param_1 + 0xa4);
            uVar7 = param_1 + 0x514U & 3;
            uVar5 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
            uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x44;
            uVar5 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            if (((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & 1) != 0) {
              *(undefined4 *)(param_1 + 0x260) = 0;
            }
            uVar7 = param_1 + 0x44U & 3;
            uVar18 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
            uVar5 = param_1 + 0x2d8U & 3;
            uVar13 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
            iVar8 = DAT_020664e8;
            if (((uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20) & 0x10) == 0) {
              iVar8 = DAT_020664ec;
            }
            lVar4 = (longlong)(int)(uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) *
                    (longlong)iVar8;
            *(uint *)(param_1 + 0x2d8) =
                 (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
            uVar7 = param_1 + 0x2dcU & 3;
            uVar5 = *(uint *)(param_1 + 0x2dcU & 0xfffffffc);
            lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
                    (longlong)iVar8;
            *(uint *)(param_1 + 0x2dc) =
                 (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
            uVar7 = param_1 + 0x2e0U & 3;
            uVar5 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
            lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
                    (longlong)iVar8;
            *(uint *)(param_1 + 0x2e0) =
                 (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
            uVar7 = param_1 + 0x2dcU & 3;
            uVar5 = *(uint *)(param_1 + 0x2dcU & 0xfffffffc);
            uVar13 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
            uVar7 = param_1 + 0x2d8U & 3;
            uVar5 = *(uint *)(param_1 + 0x2d8U & 0xfffffffc);
            uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
            uVar7 = param_1 + 0x2e0U & 3;
            uVar18 = *(uint *)(param_1 + 0x2e0U & 0xfffffffc);
            uVar7 = uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20;
            lVar4 = (longlong)(int)uVar7 * (longlong)(int)uVar7 +
                    (longlong)(int)uVar5 * (longlong)(int)uVar5 +
                    (longlong)(int)uVar13 * (longlong)(int)uVar13;
            if ((int)((ulonglong)lVar4 >> 0x20) < (int)(uint)((uint)lVar4 < DAT_020664f0)) {
              *(undefined4 *)(param_1 + 0x2d8) = local_30;
              *(undefined4 *)(param_1 + 0x2dc) = uStack_2c;
              *(undefined4 *)(param_1 + 0x2e0) = uStack_28;
              uVar7 = param_1 + 0x44U & 3;
              uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
              *(uint *)(param_1 + 0x44) =
                   (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0xffffdfff;
            }
            else {
              uVar7 = param_1 + 0x44U & 3;
              uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
              *(uint *)(param_1 + 0x44) = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20 | 0x2000;
            }
          }
          else {
            uVar7 = param_1 + 0x84U & 3;
            uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
            *(uint *)(param_1 + 0x84) =
                 (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) - DAT_020664d8;
          }
          uVar7 = param_1 + 0x1d0U & 3;
          uVar5 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
          iVar8 = func_01ffdee4(&local_180,&local_144,0,
                                uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,1,
                                (int)*(short *)(param_1 + 0x2c8),auStack_150,0,0,auStack_184,0,0,0,0
                               );
          if (iVar8 != 0) {
            VecFx32_Add(&local_180,auStack_150,&local_180);
          }
          uVar6 = uVar6 + 1 & 0xffff;
          local_144 = local_180;
          iStack_140 = local_17c;
          iStack_13c = local_178;
        } while ((int)uVar6 < param_3);
      }
    }
  }
  uVar6 = param_1 + 0x48U & 3;
  uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x40) != 0) goto LAB_02066aac;
  *(int *)(param_1 + 0x80) = local_180;
  *(int *)(param_1 + 0x88) = local_178;
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 1) != 0) != ((uVar19 & 1) != 0)) &&
     (uVar6 = param_1 + 0x44U & 3, uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x10) != 0)) {
    uVar6 = param_1 + 0x514U & 3;
    uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    *(undefined4 *)(uVar6 + 100) = DAT_020664f4;
    *(undefined4 *)(uVar6 + 0x60) = 0;
    uVar6 = param_1 + 0x260U & 3;
    uVar7 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
    *(uint *)(param_1 + 0x260) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + DAT_020664f8;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  bVar20 = (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x20000) != 0) !=
           ((uVar19 & 0x20000) != 0);
  if (bVar20) {
    StructMQRacerEntry_SomeFn(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  bVar21 = (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 4) != 0) != ((uVar19 & 4) != 0);
  if (bVar21) {
    StructMQRacerEntry_SomeFn_0(param_1,1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  bVar22 = (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 8) != 0) != ((uVar19 & 8) != 0);
  if (bVar22) {
    StructMQRacerEntry_SomeFn_0(param_1,2);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  bVar23 = (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x10) != 0) !=
           ((uVar19 & 0x10) != 0);
  if (bVar23) {
    StructMQRacerEntry_SomeFn_56(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x2000) != 0) !=
      ((uVar19 & 0x2000) != 0)) {
    StructMQRacerEntry_SomeFn_55(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x4000) != 0) !=
      ((uVar19 & 0x4000) != 0)) {
    uVar11 = 0;
    func_02061874();
    func_02082e4c(*(undefined2 *)(param_1 + 0x74));
    uVar7 = DAT_020664fc;
    uVar6 = param_1 + 0x7cU & 3;
    uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x200;
    if (uVar6 == 0) {
      if (*(char *)((*(uint *)(DAT_020664fc & 0xfffffffc) >> (DAT_020664fc & 3) * 8 |
                    *(uint *)(DAT_020664fc & 0xfffffffc) << (DAT_020664fc & 3) * -8 + 0x20) + 0x3d0)
          != '\0') {
        do {
          if (uVar11 != *(ushort *)(param_1 + 0x74)) {
            GetDriverEntry(uVar11);
            DriverContext_ApplyThunderShrink();
          }
          uVar6 = uVar7 & 3;
          uVar5 = *(uint *)(uVar7 & 0xfffffffc);
          uVar11 = uVar11 + 1;
        } while (uVar11 < *(byte *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x3d0));
      }
    }
    else if (uVar6 != 0) {
      uVar6 = param_1 + 0x514U & 3;
      uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar5 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      uVar6 = uVar5 + 0x2c;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar5 + 0x2c) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) ^ 0x4000;
    }
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000) != 0) !=
      ((uVar19 & 0x8000) != 0)) {
    DriverContext_ApplyThunderShrink(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x100000) != 0) !=
      ((uVar19 & 0x100000) != 0)) {
    StructMQRacerEntry_SomeFn_42(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x200000) != 0) !=
      ((uVar19 & 0x200000) != 0)) {
    *(undefined4 *)(param_1 + 0x55c) = 1;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x4000000) != 0) !=
      ((uVar19 & 0x4000000) != 0)) {
    StructMQRacerEntry_SomeFn_54(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (((uVar6 & 0x40) != 0) == ((uVar19 & 0x40) != 0)) {
    if (((uVar6 & 0x20) != 0) != ((uVar19 & 0x20) != 0)) {
      uVar6 = param_1 + 0x7cU & 3;
      uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
        uVar6 = param_1 + 0x180U & 3;
        uVar7 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
joined_r0x02066088:
        if (uVar6 != 4) {
          StructMQRacerEntry_SomeFn_59(param_1,piVar17 + 0x26);
        }
      }
      else {
        uVar6 = param_1 + 0x4cU & 3;
        uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
        if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) == 0) {
          uVar6 = param_1 + 0x180U & 3;
          uVar7 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
          uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
          goto joined_r0x02066088;
        }
      }
      uVar6 = param_1 + 0x514U & 3;
      uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
      uVar7 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x80) != 0) !=
          ((uVar19 & 0x80) != 0)) {
        DriverContext_MaybeQueuePlaySfx(param_1,0xe8,0x7f,0);
      }
    }
  }
  else {
    uVar6 = param_1 + 0x7cU & 3;
    uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = param_1 + 0x180U & 3;
      uVar7 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
      if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) != 5) goto LAB_02065fd0;
    }
    else {
      uVar6 = param_1 + 0x4cU & 3;
      uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if ((((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) == 0) &&
         (uVar6 = param_1 + 0x180U & 3, uVar7 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
         (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) != 4)) {
LAB_02065fd0:
        DriverContext_MaybeQueuePlaySfx(param_1,0xe8,0x7f,0);
        StructMQRacerEntry_SomeFn_4(param_1,piVar17 + 0x26);
      }
    }
    uVar6 = param_1 + 0x514U & 3;
    uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x80) != 0) != ((uVar19 & 0x80) != 0))
    {
      DriverContext_MaybeQueuePlaySfx(param_1,0xe8,0x7f,0);
    }
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x40000) != 0) !=
      ((uVar19 & 0x40000) != 0)) {
    StructMQRacerEntry_SomeFn_39(param_1);
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x80000) != 0) !=
      ((uVar19 & 0x80000) != 0)) {
    *(undefined2 *)(param_1 + 0x554) = 0;
    uVar6 = param_1 + 0x4cU & 3;
    uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20 | 0x8000000;
    uVar6 = param_1 + 0x4cU & 3;
    uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0xfffdffff;
    uVar6 = param_1 + 0x4cU & 3;
    uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x2000) != 0) {
      StructMQRacerEntry_SomeFn_2(param_1);
    }
    uVar6 = param_1 + 0x590U & 3;
    uVar7 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SomeFn_1_0
              (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,0,DAT_02066504,0);
    uVar6 = param_1 + 0x7cU & 3;
    uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x10) != 0) {
      StructMQRacerEntry_SomeFn_7(param_1,1);
      uVar6 = param_1 + 0x590U & 3;
      uVar7 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      CharacterKartContext_SetNsbtpAnimationProgress
                (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,1);
    }
    uVar6 = param_1 + 0x48U & 3;
    uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x840) == 0) {
      uVar6 = param_1 + 0x3ccU & 3;
      uVar7 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
      StructMQRacerEntry_SomeFn_5(param_1,uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
    }
    func_021038f0(*(undefined2 *)(param_1 + 0x74),0);
  }
  if ((bVar23 || (bVar22 || (bVar21 || bVar20))) &&
     (iVar8 = GetDriverEntry((uVar19 & 0x60000000) >> 0x1d), iVar8 != param_1)) {
    uVar6 = iVar8 + 0x4cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
    *(uint *)(iVar8 + 0x4c) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20 | 0x1000;
  }
  iVar8 = GetDriverEntry((int)*(char *)((*(uint *)(DAT_020664fc & 0xfffffffc) >>
                                         (DAT_020664fc & 3) * 8 |
                                        *(uint *)(DAT_020664fc & 0xfffffffc) <<
                                        (DAT_020664fc & 3) * -8 + 0x20) + 0x62));
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  bVar20 = false;
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x400000) != 0) !=
       ((uVar19 & 0x400000) != 0)) && (*(short *)(iVar8 + 0x74) == 0)) {
    local_f0 = *DAT_02066508;
    local_ec = DAT_02066508[1];
    local_e8 = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
joined_r0x02066298:
      if (uVar6 != 4) {
        local_f0 = *(int *)(iVar9 + 0x120);
        local_ec = *(int *)(iVar9 + 0x124);
        local_e8 = *(int *)(iVar9 + 0x128);
        VecFx32_Subtract(iVar8 + 0x80,iVar9 + 0x80,auStack_90);
        VecFx32_CrossProduct(iVar9 + 0x138,auStack_90,auStack_84);
        iVar9 = Vector3_DotProduct(auStack_84,iVar9 + 300);
        if (iVar9 < 0) {
          local_f0 = -local_f0;
          local_ec = -local_ec;
          local_e8 = -local_e8;
        }
        DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
        StructMQRacerEntry_SomeFn_4(iVar8,&local_f0);
      }
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) == 0) {
        uVar6 = iVar8 + 0x180U & 3;
        uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        goto joined_r0x02066298;
      }
    }
    bVar20 = true;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x800000) != 0) !=
       ((uVar19 & 0x800000) != 0)) && (*(short *)(iVar8 + 0x74) == 1)) {
    local_e4 = *DAT_02066508;
    local_e0 = DAT_02066508[1];
    local_dc = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
joined_r0x020663b4:
      if (uVar6 != 4) {
        local_e4 = *(int *)(iVar9 + 0x120);
        local_e0 = *(int *)(iVar9 + 0x124);
        local_dc = *(int *)(iVar9 + 0x128);
        VecFx32_Subtract(iVar8 + 0x80,iVar9 + 0x80,auStack_78);
        VecFx32_CrossProduct(iVar9 + 0x138,auStack_78,auStack_6c);
        iVar9 = Vector3_DotProduct(auStack_6c,iVar9 + 300);
        if (iVar9 < 0) {
          local_e4 = -local_e4;
          local_e0 = -local_e0;
          local_dc = -local_dc;
        }
        DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
        StructMQRacerEntry_SomeFn_4(iVar8,&local_e4);
      }
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) == 0) {
        uVar6 = iVar8 + 0x180U & 3;
        uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        goto joined_r0x020663b4;
      }
    }
    bVar20 = true;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x1000000) != 0) !=
       ((uVar19 & 0x1000000) != 0)) && (*(short *)(iVar8 + 0x74) == 2)) {
    local_d8 = *DAT_02066508;
    local_d4 = DAT_02066508[1];
    local_d0 = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
joined_r0x02066514:
      if (uVar6 != 4) {
        local_d8 = *(int *)(iVar9 + 0x120);
        local_d4 = *(int *)(iVar9 + 0x124);
        local_d0 = *(int *)(iVar9 + 0x128);
        VecFx32_Subtract(iVar8 + 0x80,iVar9 + 0x80,auStack_60);
        VecFx32_CrossProduct(iVar9 + 0x138,auStack_60,auStack_54);
        iVar9 = Vector3_DotProduct(auStack_54,iVar9 + 300);
        if (iVar9 < 0) {
          local_d8 = -local_d8;
          local_d4 = -local_d4;
          local_d0 = -local_d0;
        }
        DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
        StructMQRacerEntry_SomeFn_4(iVar8,&local_d8);
      }
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) == 0) {
        uVar6 = iVar8 + 0x180U & 3;
        uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        goto joined_r0x02066514;
      }
    }
    bVar20 = true;
  }
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x2000000) != 0) !=
       ((uVar19 & 0x2000000) != 0)) && (*(short *)(iVar8 + 0x74) == 3)) {
    local_cc = *DAT_02066508;
    local_c8 = DAT_02066508[1];
    local_c4 = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
joined_r0x02066630:
      if (uVar6 != 4) {
        local_cc = *(int *)(iVar9 + 0x120);
        local_c8 = *(int *)(iVar9 + 0x124);
        local_c4 = *(int *)(iVar9 + 0x128);
        VecFx32_Subtract(iVar8 + 0x80,iVar9 + 0x80,auStack_48);
        VecFx32_CrossProduct(iVar9 + 0x138,auStack_48,auStack_3c);
        iVar9 = Vector3_DotProduct(auStack_3c,iVar9 + 300);
        if (iVar9 < 0) {
          local_cc = -local_cc;
          local_c8 = -local_c8;
          local_c4 = -local_c4;
        }
        DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
        StructMQRacerEntry_SomeFn_4(iVar8,&local_cc,0);
      }
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) == 0) {
        uVar6 = iVar8 + 0x180U & 3;
        uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
        uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        goto joined_r0x02066630;
      }
    }
    bVar20 = true;
  }
  if (bVar20) goto LAB_02066aac;
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x200) != 0) != ((uVar19 & 0x200) != 0)
      ) && (*(short *)(iVar8 + 0x74) == 0)) {
    local_c0 = *DAT_02066508;
    local_bc = DAT_02066508[1];
    local_b8 = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) != 0)
      goto LAB_020667c4;
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (uVar6 != 4) {
      VecFx32_Subtract(iVar8 + 0x1d8,iVar9 + 0x1d8,&local_c0);
      lVar4 = (longlong)local_b8 * (longlong)local_b8 +
              (longlong)local_c0 * (longlong)local_c0 + (longlong)local_bc * (longlong)local_bc;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        Vector3_MaybeNormalize(&local_c0,&local_c0);
      }
      DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
      StructMQRacerEntry_SomeFn_59(iVar8,&local_c0,0);
    }
  }
LAB_020667c4:
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x400) != 0) != ((uVar19 & 0x400) != 0)
      ) && (*(short *)(iVar8 + 0x74) == 1)) {
    local_b4 = *DAT_02066508;
    local_b0 = DAT_02066508[1];
    local_ac = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) != 0)
      goto LAB_020668bc;
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (uVar6 != 4) {
      VecFx32_Subtract(iVar8 + 0x1d8,iVar9 + 0x1d8,&local_b4);
      lVar4 = (longlong)local_ac * (longlong)local_ac +
              (longlong)local_b4 * (longlong)local_b4 + (longlong)local_b0 * (longlong)local_b0;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        Vector3_MaybeNormalize(&local_b4,&local_b4);
      }
      DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
      StructMQRacerEntry_SomeFn_59(iVar8,&local_b4,0);
    }
  }
LAB_020668bc:
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x800) != 0) != ((uVar19 & 0x800) != 0)
      ) && (*(short *)(iVar8 + 0x74) == 2)) {
    local_a8 = *DAT_02066508;
    local_a4 = DAT_02066508[1];
    local_a0 = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) != 0)
      goto LAB_020669b4;
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (uVar6 != 4) {
      VecFx32_Subtract(iVar8 + 0x1d8,iVar9 + 0x1d8,&local_a8);
      lVar4 = (longlong)local_a0 * (longlong)local_a0 +
              (longlong)local_a8 * (longlong)local_a8 + (longlong)local_a4 * (longlong)local_a4;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        Vector3_MaybeNormalize(&local_a8,&local_a8);
      }
      DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
      StructMQRacerEntry_SomeFn_59(iVar8,&local_a8,0);
    }
  }
LAB_020669b4:
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (((((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x1000) != 0) !=
       ((uVar19 & 0x1000) != 0)) && (*(short *)(iVar8 + 0x74) == 3)) {
    local_9c = *DAT_02066508;
    local_98 = DAT_02066508[1];
    local_94 = DAT_02066508[2];
    iVar9 = GetDriverEntry(*(undefined2 *)(param_1 + 0x74));
    uVar6 = iVar8 + 0x7cU & 3;
    uVar7 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0x200) == 0) {
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    else {
      uVar6 = iVar8 + 0x4cU & 3;
      uVar7 = *(uint *)(iVar8 + 0x4cU & 0xfffffffc);
      if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & DAT_02066500) != 0)
      goto LAB_02066aac;
      uVar6 = iVar8 + 0x180U & 3;
      uVar7 = *(uint *)(iVar8 + 0x180U & 0xfffffffc);
      uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    }
    if (uVar6 != 4) {
      VecFx32_Subtract(iVar8 + 0x1d8,iVar9 + 0x1d8,&local_9c);
      lVar4 = (longlong)local_94 * (longlong)local_94 +
              (longlong)local_9c * (longlong)local_9c + (longlong)local_98 * (longlong)local_98;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        Vector3_MaybeNormalize(&local_9c,&local_9c);
      }
      DriverContext_MaybeQueuePlaySfx(iVar8,0xe8,0x7f,0);
      StructMQRacerEntry_SomeFn_59(iVar8,&local_9c,0);
    }
  }
LAB_02066aac:
  uVar6 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  *(uint *)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 0x30) = uVar19;
  return;
}

