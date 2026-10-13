/* Decompiled C draft; module arm9; ROM address 02076528. No matching claim. */
#include "types.h"
#include "deps/02076528_StructHD_SomeMQFn.h"

void StructHD_SomeMQFn(int param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar15;
  uint uVar16;
  bool bVar17;
  undefined4 local_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined1 auStack_5c [4];
  undefined4 local_58;
  undefined1 auStack_50 [12];
  uint local_44;
  uint local_40;
  uint local_3c;
  uint auStack_38 [3];
  uint local_2c;
  uint local_28;
  uint local_24;
  uint uVar14;
  
  uVar6 = *(undefined4 *)(param_2 + 0x80);
  iVar8 = *(int *)(param_2 + 0x84);
  uVar11 = *(undefined4 *)(param_2 + 0x88);
  uVar16 = param_2 + 700U & 3;
  uVar13 = *(uint *)(param_2 + 700U & 0xfffffffc);
  uVar14 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
  puVar7 = (undefined4 *)0xcd0;
  lVar3 = (ulonglong)uVar14 * 0xcd0;
  uVar16 = param_1 + 600U & 3;
  uVar13 = *(uint *)(param_1 + 600U & 0xfffffffc);
  bVar17 = uVar13 >> uVar16 * 8 == 0;
  bVar4 = uVar13 << uVar16 * -8 + 0x20 == 0;
  if (bVar17 && bVar4) {
    puVar7 = (undefined4 *)(param_1 + 0x24);
  }
  if (bVar17 && bVar4) {
    uVar9 = puVar7[1];
    uVar12 = puVar7[2];
    *(undefined4 *)(param_1 + 0x134) = *puVar7;
    *(undefined4 *)(param_1 + 0x138) = uVar9;
    *(undefined4 *)(param_1 + 0x13c) = uVar12;
  }
  uVar16 = param_2 + 0x4cU & 3;
  uVar13 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
  uVar14 = (uint)lVar3 >> 0xc |
           (((int)uVar14 >> 0x1f) * 0xcd0 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
  if (((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 0x20000000) == 0) {
    GetMQRacerVector333(param_2,&local_44);
    uVar16 = param_1 + 0xf0U & 3;
    uVar13 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    uVar16 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
    local_44 = (uint)((longlong)(int)local_44 * (longlong)(int)uVar16) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_44 * (longlong)(int)uVar16) >> 0x20) << 0x14;
    local_40 = (uint)((longlong)(int)local_40 * (longlong)(int)uVar16) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_40 * (longlong)(int)uVar16) >> 0x20) << 0x14;
    local_3c = (uint)((longlong)(int)local_3c * (longlong)(int)uVar16) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_3c * (longlong)(int)uVar16) >> 0x20) << 0x14;
  }
  else {
    uVar16 = param_1 + 0xf0U & 3;
    uVar13 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    uVar16 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
    lVar3 = (longlong)*(int *)(param_1 + 0x260) * (longlong)(int)uVar16;
    lVar1 = (longlong)*(int *)(param_1 + 0x264) * (longlong)(int)uVar16;
    lVar2 = (longlong)*(int *)(param_1 + 0x268) * (longlong)(int)uVar16;
    local_44 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
    local_40 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    local_3c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  }
  uVar16 = param_2 + 0x7cU & 3;
  uVar13 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
  if (((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 0x20) != 0) {
    iVar8 = func_020d3e18();
    if (iVar8 == 0) {
      return;
    }
    uVar16 = param_1 + 0x28U & 3;
    uVar13 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    iVar8 = func_020d3df4((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) - 0x5000);
    if (iVar8 < 0) {
      *(int *)(param_1 + 0x178) = -iVar8;
    }
    else {
      *(undefined4 *)(param_1 + 0x178) = 0;
    }
    return;
  }
  VecFx32_Subtract(param_2 + 0x80,param_2 + 0x8c,auStack_5c);
  uVar16 = param_1 + 100U & 3;
  uVar13 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar13 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
  uVar16 = param_1 + 0x60U & 3;
  uVar10 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar10 = uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20;
  uVar16 = uRam02076a44;
  if ((int)uVar13 < (int)uVar10) {
    uVar16 = 0xcd;
  }
  lVar3 = (longlong)(int)(uVar13 - uVar10) * (longlong)(int)uVar16 + 0x800;
  uVar16 = param_1 + 0x60U & 3;
  uVar13 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(uint *)(param_1 + 0x60) =
       (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) +
       ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000);
  iVar5 = iRam02076a48;
  uVar16 = param_1 + 0x60U & 3;
  uVar13 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(undefined2 *)(param_1 + 0x68) =
       *(undefined2 *)
        (iRam02076a48 +
        ((int)((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 0xffff) >> 4) * 4);
  uVar16 = param_1 + 0x60U & 3;
  uVar13 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(undefined2 *)(param_1 + 0x6a) =
       *(undefined2 *)
        (iVar5 + (((int)((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 0xffff) >> 4) * 2 +
                 1) * 2);
  uVar16 = param_2 + 0x48U & 3;
  uVar13 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  if (((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 0x10000) == 0) {
    uVar16 = param_1 + 0xe8U & 3;
    uVar13 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    uVar16 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
    uVar13 = 0x1000 - uVar16;
    lVar3 = (ulonglong)uRam02076a44 * (ulonglong)uVar13;
    uVar10 = (uint)lVar3;
    *(uint *)(param_1 + 0xe8) =
         uVar16 + (uVar10 + 0x800 >> 0xc |
                  (((int)uVar13 >> 0x1f) * uRam02076a44 + (int)((ulonglong)lVar3 >> 0x20) +
                  (uint)(0xfffff7ff < uVar10)) * 0x100000);
  }
  else {
    uVar16 = param_1 + 0xe8U & 3;
    uVar13 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    uVar16 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
    uVar13 = iRam02076a4c - uVar16;
    lVar3 = (ulonglong)uVar13 * 0xcd;
    uVar10 = (uint)lVar3;
    *(uint *)(param_1 + 0xe8) =
         uVar16 + (uVar10 + 0x800 >> 0xc |
                  (((int)uVar13 >> 0x1f) * 0xcd + (int)((ulonglong)lVar3 >> 0x20) +
                  (uint)(0xfffff7ff < uVar10)) * 0x100000);
  }
  local_58 = 0;
  StructMQRacerEntry_GetVec555(param_2,auStack_50);
  uVar16 = param_1 + 0xd4U & 3;
  uVar13 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  func_020745d4(param_1 + 0x18,param_1 + 0xb4,param_1 + 0xe4,param_2,uVar14,
                uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20);
  iStack_64 = iVar8 - uVar14;
  local_68 = uVar6;
  uStack_60 = uVar11;
  StructHD_SomeFn_6(param_1,param_2,&local_44);
  uVar16 = param_1 + 0x174U & 3;
  uVar13 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
  lVar3 = (ulonglong)(uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) * 0x3000;
  func_020741a0(param_1 + 0x24,param_1 + 0xa8,param_1,param_2,&local_68,&local_44,
                (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000);
  iVar8 = func_020d3e18();
  if (iVar8 != 0) {
    uVar16 = param_1 + 0x28U & 3;
    uVar13 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    iVar8 = func_020d3df4((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) - 0x5000);
    if (iVar8 < 0) {
      *(int *)(param_1 + 0x178) = -iVar8;
    }
    else {
      *(undefined4 *)(param_1 + 0x178) = 0;
    }
  }
  StructHD_SomeFn_5(param_1,param_2,&local_44);
  uVar16 = param_2 + 0x44U & 3;
  uVar13 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  uVar14 = 0;
  if ((((uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 8) != 0) &&
     (uVar16 = param_2 + 0x2c4U & 3, uVar13 = *(uint *)(param_2 + 0x2c4U & 0xfffffffc),
     uVar14 = *(uint *)(uRam02076a50 & 0xfffffffc) >> (uRam02076a50 & 3) * 8 |
              *(uint *)(uRam02076a50 & 0xfffffffc) << (uRam02076a50 & 3) * -8 + 0x20,
     0 < (int)(uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20))) {
    uVar14 = -uVar14;
  }
  uVar16 = param_1 + 0x16cU & 3;
  uVar13 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  uVar16 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
  uVar14 = uVar14 - uVar16;
  lVar3 = (ulonglong)uVar14 * 0xcd;
  uVar13 = (uint)lVar3;
  *(uint *)(param_1 + 0x16c) =
       uVar16 + (uVar13 + 0x800 >> 0xc |
                (((int)uVar14 >> 0x1f) * 0xcd + (int)((ulonglong)lVar3 >> 0x20) +
                (uint)(0xfffff7ff < uVar13)) * 0x100000);
  uVar16 = param_1 + 0x16cU & 3;
  uVar13 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
  uVar14 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
  uVar16 = param_2 + 0x120U & 3;
  uVar13 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) *
          (longlong)(int)uVar14;
  *(uint *)(param_1 + 0x188) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar16 = param_2 + 0x124U & 3;
  uVar13 = *(uint *)(param_2 + 0x124U & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) *
          (longlong)(int)uVar14;
  puVar15 = (uint *)lVar3;
  *(uint *)(param_1 + 0x18c) = (uint)puVar15 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar16 = param_2 + 0x128U & 3;
  uVar13 = *(uint *)(param_2 + 0x128U & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) *
          (longlong)(int)uVar14;
  *(uint *)(param_1 + 400) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar16 = param_2 + 0x48U & 3;
  uVar13 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  uVar16 = (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) & 0x40000000;
  bVar17 = uVar16 == 0;
  if (bVar17) {
    puVar15 = auStack_38;
    uVar16 = *puRam02076a54;
    lVar3 = CONCAT44(puRam02076a54[1],puRam02076a54[2]);
  }
  if (bVar17) {
    *puVar15 = uVar16;
    puVar15[1] = (uint)((ulonglong)lVar3 >> 0x20);
    puVar15[2] = (uint)lVar3;
  }
  else {
    StructMQRacerEntry_GetVec555(param_2,auStack_38);
  }
  VecFx32_Subtract(auStack_38,param_1 + 0xc0,&local_2c);
  local_24 = (local_24 << 0xb) >> 0xc | (((int)local_24 >> 0x1f) << 0xb | local_24 >> 0x15) << 0x14;
  local_28 = (local_28 << 0xb) >> 0xc | (((int)local_28 >> 0x1f) << 0xb | local_28 >> 0x15) << 0x14;
  local_2c = (local_2c << 0xb) >> 0xc | (((int)local_2c >> 0x1f) << 0xb | local_2c >> 0x15) << 0x14;
  VecFx32_Add(param_1 + 0xc0,&local_2c,param_1 + 0xc0);
  uVar16 = param_1 + 0x248U & 3;
  uVar13 = *(uint *)(param_1 + 0x248U & 0xfffffffc);
  if (uVar13 >> uVar16 * 8 == 0 && uVar13 << uVar16 * -8 + 0x20 == 0) {
    uVar16 = param_1 + 0xd4U & 3;
    uVar13 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    uVar13 = uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20;
    uVar16 = *(uint *)(uRam02076a58 & 0xfffffffc) >> (uRam02076a58 & 3) * 8 |
             *(uint *)(uRam02076a58 & 0xfffffffc) << (uRam02076a58 & 3) * -8 + 0x20;
    if ((int)uVar13 < (int)uVar16) {
      *(uint *)(param_1 + 0xd4) = uVar13 + 0x1000;
    }
    else {
      *(uint *)(param_1 + 0xd4) = uVar16;
    }
  }
  else {
    uVar16 = param_1 + 0xd4U & 3;
    uVar13 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    *(uint *)(param_1 + 0xd4) = (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) - 0x1000;
    uVar16 = param_1 + 0xd4U & 3;
    uVar13 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    if ((int)(uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20) < 0x5000) {
      *(undefined4 *)(param_1 + 0xd4) = 0x5000;
    }
    uVar16 = param_1 + 0xd0U & 3;
    uVar13 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    if ((uVar13 >> uVar16 * 8 == 0 && uVar13 << uVar16 * -8 + 0x20 == 0) &&
       (uVar16 = param_2 + 0x84U & 3, uVar10 = *(uint *)(param_2 + 0x84U & 0xfffffffc),
       uVar13 = param_1 + 0xccU & 3, uVar14 = *(uint *)(param_1 + 0xccU & 0xfffffffc),
       (int)(uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) <
       (int)(uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20))) {
      *(undefined4 *)(param_1 + 0xd0) = 1;
    }
  }
  StructHD_SomeFn_4(param_1);
  return;
}

