/* Decompiled C draft; module arm9; ROM address 020e8ac8. No matching claim. */
#include "types.h"
#include "deps/020e8ac8_func_020e8ac8.h"

void func_020e8ac8(void)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  int *piVar7;
  int *piVar8;
  uint *puVar9;
  short *psVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  bool bVar22;
  uint *local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64 [2];
  int local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  puVar19 = puRam020e95cc;
  puVar18 = puRam020e95c8;
  if ((*(short *)(iRam020e95bc + 0xe) == 4) ||
     (*(uint *)(uRam020e95c0 & 0xfffffffc) >> (uRam020e95c0 & 3) * 8 == 0 &&
      *(uint *)(uRam020e95c0 & 0xfffffffc) << (uRam020e95c0 & 3) * -8 + 0x20 == 0)) {
    uVar12 = puRam020e95c4[1];
    uVar15 = puRam020e95c4[2];
    *puRam020e95c8 = *puRam020e95c4;
    puVar18[1] = uVar12;
    puVar18[2] = uVar15;
    puVar19 = puRam020e95cc;
    uVar12 = puVar18[1];
    uVar15 = puVar18[2];
    *puRam020e95cc = *puVar18;
    puVar19[1] = uVar12;
    puVar19[2] = uVar15;
    puVar18 = puRam020e95d0;
    uVar12 = puVar19[1];
    uVar15 = puVar19[2];
    *puRam020e95d0 = *puVar19;
    puVar18[1] = uVar12;
    puVar18[2] = uVar15;
    puVar19 = puRam020e95d4;
    uVar12 = puVar18[1];
    uVar15 = puVar18[2];
    *puRam020e95d4 = *puVar18;
    puVar19[1] = uVar12;
    puVar19[2] = uVar15;
    puVar18 = puRam020e95d8;
    uVar12 = puVar19[1];
    uVar15 = puVar19[2];
    *puRam020e95d8 = *puVar19;
    puVar18[1] = uVar12;
    puVar18[2] = uVar15;
    puVar19 = puRam020e95e0;
    puVar5 = puRam020e95dc;
    *puRam020e95dc = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *puVar19 = 0;
    puVar19[1] = 0;
    puVar19[2] = 0;
    puVar19 = puRam020e95e8;
    *puRam020e95e4 = 0;
    *puVar19 = 0;
    piVar7 = piRam020e95f0;
    *piRam020e95ec = 0;
    *piVar7 = 0;
    puVar19 = puRam020e95f8;
    *piRam020e95f4 = 0;
    puVar9 = puRam020e9600;
    *puRam020e95fc = 1;
    *puVar9 = 1;
    puVar5 = puRam020e9604;
    uVar12 = puVar18[1];
    uVar15 = puVar18[2];
    *puVar19 = *puVar18;
    puVar19[1] = uVar12;
    puVar19[2] = uVar15;
    *puVar5 = 0;
  }
  else {
    bVar22 = false;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    if ((*(short *)(iRam020e95bc + 0xe) == 6) || (*(short *)(iRam020e95bc + 0xe) == 2)) {
      local_80 = (uint *)0x0;
    }
    else {
      local_80 = puRam020e95cc;
    }
    uVar12 = uRam020e9608 & 3;
    uVar14 = *(uint *)(uRam020e9608 & 0xfffffffc);
    uVar15 = puRam020e95d0[1];
    uVar11 = puRam020e95d0[2];
    *puRam020e95cc = *puRam020e95d0;
    puVar19[1] = uVar15;
    puVar19[2] = uVar11;
    if (uVar14 >> uVar12 * 8 == 0 && uVar14 << uVar12 * -8 + 0x20 == 0) {
      iVar20 = (int)(*(uint *)(uRam020e960c & 0xfffffffc) >> (uRam020e960c & 3) * 8 |
                    *(uint *)(uRam020e960c & 0xfffffffc) << (uRam020e960c & 3) * -8 + 0x20) >> 1;
      uVar12 = uRam020e9610 + 4 & 3;
      uVar14 = *(uint *)(uRam020e9610 + 4 & 0xfffffffc);
      uVar15 = uRam020e9610 + 8 & 3;
      uVar11 = *(uint *)(uRam020e9610 + 8 & 0xfffffffc);
      lVar2 = (longlong)
              (int)(*(uint *)(uRam020e9610 & 0xfffffffc) >> (uRam020e9610 & 3) * 8 |
                   *(uint *)(uRam020e9610 & 0xfffffffc) << (uRam020e9610 & 3) * -8 + 0x20) *
              (longlong)iVar20;
      lVar3 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) *
              (longlong)iVar20;
      lVar4 = (longlong)(int)(uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20) *
              (longlong)iVar20;
      local_7c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      local_78 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
      local_74 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    }
    else {
      iVar20 = (int)-(*(uint *)(uRam020e960c & 0xfffffffc) >> (uRam020e960c & 3) * 8 |
                     *(uint *)(uRam020e960c & 0xfffffffc) << (uRam020e960c & 3) * -8 + 0x20) >> 1;
      uVar12 = uRam020e9610 + 4 & 3;
      uVar14 = *(uint *)(uRam020e9610 + 4 & 0xfffffffc);
      uVar15 = uRam020e9610 + 8 & 3;
      uVar11 = *(uint *)(uRam020e9610 + 8 & 0xfffffffc);
      lVar2 = (longlong)
              (int)(*(uint *)(uRam020e9610 & 0xfffffffc) >> (uRam020e9610 & 3) * 8 |
                   *(uint *)(uRam020e9610 & 0xfffffffc) << (uRam020e9610 & 3) * -8 + 0x20) *
              (longlong)iVar20;
      lVar3 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) *
              (longlong)iVar20;
      lVar4 = (longlong)(int)(uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20) *
              (longlong)iVar20;
      local_7c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      local_78 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
      local_74 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    }
    VecFx32_Add((uint)(uintptr_t)(puRam020e95d8),(uint)(uintptr_t)(&local_7c),puRam020e95d0);
    uVar12 = uRam020e9610 + 0xc & 3;
    uVar16 = *(uint *)(uRam020e9610 + 0xc & 0xfffffffc);
    uVar15 = uRam020e9610 + 0x10 & 3;
    uVar13 = *(uint *)(uRam020e9610 + 0x10 & 0xfffffffc);
    iVar20 = (int)-(*(uint *)(uRam020e9614 & 0xfffffffc) >> (uRam020e9614 & 3) * 8 |
                   *(uint *)(uRam020e9614 & 0xfffffffc) << (uRam020e9614 & 3) * -8 + 0x20) >> 1;
    uVar11 = uRam020e9610 + 0x14 & 3;
    uVar14 = *(uint *)(uRam020e9610 + 0x14 & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) * (longlong)iVar20;
    lVar3 = (longlong)(int)(uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20) * (longlong)iVar20;
    lVar4 = (longlong)(int)(uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20) * (longlong)iVar20;
    local_74 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    local_7c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    local_78 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
    VecFx32_Add((uint)(uintptr_t)(puRam020e95d0),(uint)(uintptr_t)(&local_7c),puRam020e95d0);
    uVar12 = uRam020e9618 & 3;
    uVar11 = *(uint *)(uRam020e9618 & 0xfffffffc);
    *puRam020e961c = 0;
    uVar15 = local_44;
    if ((uVar11 >> uVar12 * 8 == 0 && uVar11 << uVar12 * -8 + 0x20 == 0) &&
       ((*(uint *)((uint)puRam020e9600 & 0xfffffffc) >> ((uint)puRam020e9600 & 3) * 8 != 0 ||
         *(uint *)((uint)puRam020e9600 & 0xfffffffc) << ((uint)puRam020e9600 & 3) * -8 + 0x20 != 0
        || (*(uint *)((uint)puRam020e95fc & 0xfffffffc) >> ((uint)puRam020e95fc & 3) * 8 != 0 ||
            *(uint *)((uint)puRam020e95fc & 0xfffffffc) << ((uint)puRam020e95fc & 3) * -8 + 0x20 !=
            0)))) {
      func_020d5180((uint)(uintptr_t)(puRam020e95d0),0x12000,0x2000);
      uVar12 = uRam020e9624;
      psVar10 = psRam020e9620;
      puVar18 = puRam020e95d0;
      iVar20 = 0;
      if (0 < *psRam020e9620) {
        do {
          uVar15 = uVar12 & 3;
          uVar11 = *(uint *)(uVar12 & 0xfffffffc);
          uVar15 = (uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20) + iVar20 * 4;
          uVar11 = uVar15 & 3;
          uVar15 = *(uint *)(uVar15 & 0xfffffffc);
          uVar11 = uVar15 >> uVar11 * 8 | uVar15 << uVar11 * -8 + 0x20;
          uVar15 = local_44;
          if (((*(ushort *)(uVar11 + 2) & 0x40) == 0) &&
             (iVar21 = func_020d3e34(puVar18,0x12000,uVar11,&local_7c), uVar15 = local_44,
             iVar21 != 0)) {
            if ((int)local_7c < (int)local_58) {
              local_58 = local_7c;
            }
            if ((int)local_78 < (int)local_54) {
              local_54 = local_78;
            }
            if ((int)local_74 < (int)local_50) {
              local_50 = local_74;
            }
            bVar22 = true;
            uVar15 = local_7c;
            if ((int)local_7c <= (int)local_4c) {
              uVar15 = local_4c;
            }
            uVar11 = local_78;
            if ((int)local_78 <= (int)local_48) {
              uVar11 = local_48;
            }
            local_4c = uVar15;
            local_48 = uVar11;
            uVar15 = local_74;
            if ((int)local_74 <= (int)local_44) {
              uVar15 = local_44;
            }
          }
          local_44 = uVar15;
          iVar20 = iVar20 + 1;
        } while (iVar20 < *psVar10);
      }
      iVar20 = func_01ffdee4(puRam020e95d0,local_80,0,0x12000);
      uVar15 = local_44;
      if (iVar20 != 0) {
        if ((int)local_7c < (int)local_58) {
          local_58 = local_7c;
        }
        if ((int)local_78 < (int)local_54) {
          local_54 = local_78;
        }
        if ((int)local_74 < (int)local_50) {
          local_50 = local_74;
        }
        bVar22 = true;
        uVar12 = local_7c;
        if ((int)local_7c <= (int)local_4c) {
          uVar12 = local_4c;
        }
        uVar15 = local_78;
        if ((int)local_78 <= (int)local_48) {
          uVar15 = local_48;
        }
        local_4c = uVar12;
        local_48 = uVar15;
        uVar15 = local_74;
        if ((int)local_74 <= (int)local_44) {
          uVar15 = local_44;
        }
      }
    }
    local_44 = uVar15;
    if (bVar22) {
      if (((*(uint *)((uint)puRam020e961c & 0xfffffffc) >> ((uint)puRam020e961c & 3) * 8 |
           *(uint *)((uint)puRam020e961c & 0xfffffffc) << ((uint)puRam020e961c & 3) * -8 + 0x20) &
          0x80000) == 0) {
        *puRam020e9604 = 0;
      }
      local_7c = local_58;
      local_78 = local_54;
      local_74 = local_50;
      VecFx32_Add((uint)(uintptr_t)(&local_7c),(uint)(uintptr_t)(&local_4c),&local_7c);
      if (((int)local_78 < 0) && (*(short *)(iRam020e95bc + 0xe) == 5)) {
        local_78 = 0;
      }
      VecFx32_Add((uint)(uintptr_t)(puRam020e95d8),(uint)(uintptr_t)(&local_7c),puRam020e95d8);
      VecFx32_Add((uint)(uintptr_t)(puRam020e95d0),(uint)(uintptr_t)(&local_7c),puRam020e95d0);
    }
    puVar6 = puRam020e95e4;
    puVar18 = puRam020e95d8;
    if (*(uint *)(uRam020e9618 & 0xfffffffc) >> (uRam020e9618 & 3) * 8 == 0 &&
        *(uint *)(uRam020e9618 & 0xfffffffc) << (uRam020e9618 & 3) * -8 + 0x20 == 0) {
      uVar12 = (uint)(puRam020e95d8 + 2) & 3;
      uVar15 = *(uint *)((uint)(puRam020e95d8 + 2) & 0xfffffffc);
      *puRam020e95e4 = *puRam020e95e4 + 1;
      if (0xc < *puVar6) {
        *puVar6 = 0;
      }
      puVar19 = puRam020e95c8;
      uVar14 = *(uint *)(uRam020e9628 & 0xfffffffc) >> (uRam020e9628 & 3) * 8 |
               *(uint *)(uRam020e9628 & 0xfffffffc) << (uRam020e9628 & 3) * -8 + 0x20;
      uVar11 = uVar14 + 0xa4;
      uVar13 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      lVar2 = (ulonglong)(uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) * 0x5000;
      uVar1 = *puRam020e95e4;
      *puRam020e95c8 =
           (uint)uVar1 * ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
           (*(uint *)((uint)puVar18 & 0xfffffffc) >> ((uint)puVar18 & 3) * 8 |
           *(uint *)((uint)puVar18 & 0xfffffffc) << ((uint)puVar18 & 3) * -8 + 0x20);
      uVar14 = uVar14 + 0xac;
      uVar11 = uVar14 & 3;
      uVar16 = *(uint *)(uVar14 & 0xfffffffc);
      uVar14 = (uint)(puVar18 + 1) & 3;
      uVar13 = *(uint *)((uint)(puVar18 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)(uVar16 >> uVar11 * 8 | uVar16 << uVar11 * -8 + 0x20) * 0x5000;
      puVar19[1] = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
      puVar19[2] = (uint)uVar1 * ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
                   (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20);
      iVar20 = func_01ffdee4(puVar19,0,0,uRam020e962c);
      if (iVar20 != 0) {
        uVar12 = (*(uint *)(uRam020e9628 & 0xfffffffc) >> (uRam020e9628 & 3) * 8 |
                 *(uint *)(uRam020e9628 & 0xfffffffc) << (uRam020e9628 & 3) * -8 + 0x20) + 0x2a8;
        uVar15 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        uVar12 = uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20;
        if ((int)uVar12 < 1) {
          uVar12 = -uVar12;
        }
        iVar20 = VecFx32_CrossProduct_0((uint)(uintptr_t)(local_64),uRam020e9610);
        if (iVar20 < 1) {
          *puRam020e95e8 =
               -((uVar12 << 0xb) >> 0xc | (((int)uVar12 >> 0x1f) << 0xb | uVar12 >> 0x15) << 0x14);
        }
        else {
          *puRam020e95e8 =
               (uVar12 << 0xb) >> 0xc | (((int)uVar12 >> 0x1f) << 0xb | uVar12 >> 0x15) << 0x14;
        }
        puVar6 = puRam020e95e4;
        *puRam020e9630 =
             (*(uint *)((uint)puRam020e9630 & 0xfffffffc) >> ((uint)puRam020e9630 & 3) * 8 |
             *(uint *)((uint)puRam020e9630 & 0xfffffffc) << ((uint)puRam020e9630 & 3) * -8 + 0x20) +
             0xc;
        *puVar6 = 0xc;
      }
      puVar18 = puRam020e95e8;
      uVar15 = *(uint *)((uint)piRam020e95ec & 0xfffffffc) >> ((uint)piRam020e95ec & 3) * 8 |
               *(uint *)((uint)piRam020e95ec & 0xfffffffc) << ((uint)piRam020e95ec & 3) * -8 + 0x20;
      uVar12 = (*(uint *)((uint)puRam020e95e8 & 0xfffffffc) >> ((uint)puRam020e95e8 & 3) * 8 |
               *(uint *)((uint)puRam020e95e8 & 0xfffffffc) << ((uint)puRam020e95e8 & 3) * -8 + 0x20)
               - ((uint)((ulonglong)uVar15 * 0x29) >> 0xc |
                 (((int)uVar15 >> 0x1f) * 0x29 + (int)((ulonglong)uVar15 * 0x29 >> 0x20)) * 0x100000
                 );
      *puRam020e95e8 = uVar12;
      if ((longlong)(int)uVar15 * (longlong)(int)uVar12 < 0) {
        *puVar18 = uVar12 - ((uint)((ulonglong)uRam020e9634 * (ulonglong)uVar12) >> 0xc |
                            (((int)uVar12 >> 0x1f) * uRam020e9634 +
                            (int)((ulonglong)uRam020e9634 * (ulonglong)uVar12 >> 0x20)) * 0x100000);
      }
      uVar12 = (uint)puRam020e9600 & 3;
      uVar15 = *(uint *)((uint)puRam020e9600 & 0xfffffffc);
      *piRam020e95ec =
           (*(uint *)((uint)piRam020e95ec & 0xfffffffc) >> ((uint)piRam020e95ec & 3) * 8 |
           *(uint *)((uint)piRam020e95ec & 0xfffffffc) << ((uint)piRam020e95ec & 3) * -8 + 0x20) +
           (*(uint *)((uint)puRam020e95e8 & 0xfffffffc) >> ((uint)puRam020e95e8 & 3) * 8 |
           *(uint *)((uint)puRam020e95e8 & 0xfffffffc) << ((uint)puRam020e95e8 & 3) * -8 + 0x20);
      piVar8 = piRam020e95f4;
      piVar7 = piRam020e95f0;
      if (uVar15 >> uVar12 * 8 == 0 && uVar15 << uVar12 * -8 + 0x20 == 0) {
        uVar12 = (uint)piRam020e95f4 & 3;
        uVar15 = *(uint *)((uint)piRam020e95f4 & 0xfffffffc);
        iVar20 = (*(uint *)((uint)piRam020e95f0 & 0xfffffffc) >> ((uint)piRam020e95f0 & 3) * 8 |
                 *(uint *)((uint)piRam020e95f0 & 0xfffffffc) <<
                 ((uint)piRam020e95f0 & 3) * -8 + 0x20) + 0xcd;
        *piRam020e95f0 = iVar20;
        *piVar8 = (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20) + iVar20;
      }
      else {
        uVar12 = *(uint *)((uint)piRam020e95f4 & 0xfffffffc) >> ((uint)piRam020e95f4 & 3) * 8 |
                 *(uint *)((uint)piRam020e95f4 & 0xfffffffc) <<
                 ((uint)piRam020e95f4 & 3) * -8 + 0x20;
        if ((int)uVar12 < 1) {
          *piRam020e95f4 = 0;
          *piVar7 = 0;
        }
        else {
          uVar15 = *(uint *)((uint)piRam020e95f0 & 0xfffffffc) >> ((uint)piRam020e95f0 & 3) * 8 |
                   *(uint *)((uint)piRam020e95f0 & 0xfffffffc) <<
                   ((uint)piRam020e95f0 & 3) * -8 + 0x20;
          *piRam020e95f4 = uVar12 - uVar15;
          *piVar7 = uVar15 - 0xcd;
        }
      }
    }
    uVar15 = uRam020e9628;
    puVar18 = puRam020e95d4;
    uVar12 = puRam020e95d8[1];
    uVar11 = puRam020e95d8[2];
    *puRam020e95d4 = *puRam020e95d8;
    puVar18[1] = uVar12;
    puVar18[2] = uVar11;
    uVar12 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar12 = (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20) + 0x180;
    uVar15 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    if (3 < (int)(uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20)) {
      *puRam020e9638 = 0;
    }
    puVar19 = puRam020e9630;
    puVar18 = puRam020e95d8;
    if ((*(uint *)(uRam020e9618 & 0xfffffffc) >> (uRam020e9618 & 3) * 8 == 0 &&
         *(uint *)(uRam020e9618 & 0xfffffffc) << (uRam020e9618 & 3) * -8 + 0x20 == 0) ||
       (*(uint *)((uint)puRam020e9638 & 0xfffffffc) >> ((uint)puRam020e9638 & 3) * 8 == 0 &&
        *(uint *)((uint)puRam020e9638 & 0xfffffffc) << ((uint)puRam020e9638 & 3) * -8 + 0x20 == 0))
    {
      uVar12 = *(uint *)(uRam020e963c & 0xfffffffc) >> (uRam020e963c & 3) * 8 |
               *(uint *)(uRam020e963c & 0xfffffffc) << (uRam020e963c & 3) * -8 + 0x20;
      uVar15 = (*(uint *)((uint)puRam020e9630 & 0xfffffffc) >> ((uint)puRam020e9630 & 3) * 8 |
               *(uint *)((uint)puRam020e9630 & 0xfffffffc) << ((uint)puRam020e9630 & 3) * -8 + 0x20)
               - 0x29;
      *puRam020e9630 = uVar15;
      if ((int)uVar12 < (int)uVar15) {
        *puVar19 = uVar12;
      }
      if ((int)(*(uint *)((uint)puRam020e9630 & 0xfffffffc) >> ((uint)puRam020e9630 & 3) * 8 |
               *(uint *)((uint)puRam020e9630 & 0xfffffffc) << ((uint)puRam020e9630 & 3) * -8 + 0x20)
          < 0x7b) {
        *puRam020e9630 = 0x7b;
      }
      VecFx32_Subtract((uint)(uintptr_t)(puRam020e95c4),(uint)(uintptr_t)(puRam020e95d8),&local_7c);
      local_78 = local_78 +
                 (*(uint *)((uint)piRam020e95f4 & 0xfffffffc) >> ((uint)piRam020e95f4 & 3) * 8 |
                 *(uint *)((uint)piRam020e95f4 & 0xfffffffc) <<
                 ((uint)piRam020e95f4 & 3) * -8 + 0x20);
      local_70 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_7c),uRam020e9610);
      local_68 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&local_7c),uRam020e9640);
      uVar15 = uRam020e9610;
      puVar18 = puRam020e95e0;
      puVar5 = puRam020e95dc;
      uVar12 = uRam020e963c + 8 & 3;
      uVar11 = *(uint *)(uRam020e963c + 8 & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) *
              (longlong)local_68;
      uVar12 = (uint)(puRam020e95e0 + 2) & 3;
      uVar11 = *(uint *)((uint)(puRam020e95e0 + 2) & 0xfffffffc);
      uVar14 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
      uVar12 = iRam020e9644 + 8U & 3;
      uVar11 = *(uint *)(iRam020e9644 + 8U & 0xfffffffc);
      lVar3 = (longlong)(int)(uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) *
              (longlong)(int)uVar14;
      lVar4 = (longlong)
              (int)(*(uint *)((uint)puRam020e9630 & 0xfffffffc) >> ((uint)puRam020e9630 & 3) * 8 |
                   *(uint *)((uint)puRam020e9630 & 0xfffffffc) <<
                   ((uint)puRam020e9630 & 3) * -8 + 0x20) * (longlong)local_70;
      *puRam020e95e0 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
      puVar18[2] = uVar14 + (((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14) -
                            ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14));
      local_64[0] = VecFx32_CrossProduct_0(puVar5,uVar15);
      local_5c = VecFx32_CrossProduct_0(puRam020e95dc,uRam020e9640);
      puVar18 = puRam020e95e0;
      uVar15 = (uint)puRam020e95fc & 3;
      uVar11 = *(uint *)((uint)puRam020e95fc & 0xfffffffc);
      uVar12 = (uint)(puRam020e95e0 + 2) & 3;
      uVar14 = *(uint *)((uint)(puRam020e95e0 + 2) & 0xfffffffc);
      *puRam020e95e0 =
           (*(uint *)((uint)puRam020e95e0 & 0xfffffffc) >> ((uint)puRam020e95e0 & 3) * 8 |
           *(uint *)((uint)puRam020e95e0 & 0xfffffffc) << ((uint)puRam020e95e0 & 3) * -8 + 0x20) -
           local_64[0];
      puVar18[2] = (uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) - local_5c;
      if ((uVar11 >> uVar15 * 8 != 0 || uVar11 << uVar15 * -8 + 0x20 != 0) ||
         (*(uint *)((uint)puRam020e9600 & 0xfffffffc) >> ((uint)puRam020e9600 & 3) * 8 != 0 ||
          *(uint *)((uint)puRam020e9600 & 0xfffffffc) << ((uint)puRam020e9600 & 3) * -8 + 0x20 != 0)
         ) {
        uVar12 = *(uint *)((uint)puRam020e9604 & 0xfffffffc) >> ((uint)puRam020e9604 & 3) * 8;
        iVar20 = *(uint *)((uint)puRam020e9604 & 0xfffffffc) <<
                 ((uint)puRam020e9604 & 3) * -8 + 0x20;
        if (uVar12 != 0 || iVar20 != 0) {
          puVar18 = (uint *)0x1000;
        }
        uVar15 = *(uint *)((uint)puRam020e95e0 & 0xfffffffc) >> ((uint)puRam020e95e0 & 3) * 8 |
                 *(uint *)((uint)puRam020e95e0 & 0xfffffffc) <<
                 ((uint)puRam020e95e0 & 3) * -8 + 0x20;
        if (uVar12 == 0 && iVar20 == 0) {
          puVar18 = (uint *)0x800;
        }
        if ((int)puVar18 < (int)uVar15) {
          *puRam020e95e0 = (uint)puVar18;
          puVar19 = puVar18;
        }
        else {
          puVar19 = (uint *)-(int)puVar18;
          if ((int)(uVar15 + (int)puVar18) < 0 != SBORROW4(uVar15,(int)puVar19)) {
            *puRam020e95e0 = (uint)puVar19;
          }
        }
        if (uVar12 != 0 || iVar20 != 0) {
          puVar19 = (uint *)0x2000;
        }
        uVar15 = (uint)(puRam020e95e0 + 2) & 3;
        uVar11 = *(uint *)((uint)(puRam020e95e0 + 2) & 0xfffffffc);
        uVar15 = uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20;
        if (uVar12 == 0 && iVar20 == 0) {
          puVar19 = (uint *)0x1000;
        }
        if ((int)puVar19 < (int)uVar15) {
          puRam020e95e0[2] = (uint)puVar19;
        }
        else if ((int)(uVar15 + (int)puVar19) < 0 != SBORROW4(uVar15,-(int)puVar19)) {
          puRam020e95e0[2] = -(int)puVar19;
        }
      }
      uVar15 = uRam020e9610;
      puVar18 = puRam020e95e0;
      uVar12 = (uint)(puRam020e95e0 + 2) & 3;
      uVar11 = *(uint *)((uint)(puRam020e95e0 + 2) & 0xfffffffc);
      *puRam020e95e0 =
           (*(uint *)((uint)puRam020e95e0 & 0xfffffffc) >> ((uint)puRam020e95e0 & 3) * 8 |
           *(uint *)((uint)puRam020e95e0 & 0xfffffffc) << ((uint)puRam020e95e0 & 3) * -8 + 0x20) +
           local_64[0];
      puVar18[2] = (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) + local_5c;
      MTX_MultVec33(puVar18,uVar15,&local_70);
    }
    else {
      uVar12 = (uint)(puRam020e95c4 + 1) & 3;
      uVar16 = *(uint *)((uint)(puRam020e95c4 + 1) & 0xfffffffc);
      uVar15 = (uint)(puRam020e95d8 + 1) & 3;
      uVar13 = *(uint *)((uint)(puRam020e95d8 + 1) & 0xfffffffc);
      uVar11 = (uint)(puRam020e95c4 + 2) & 3;
      uVar14 = *(uint *)((uint)(puRam020e95c4 + 2) & 0xfffffffc);
      local_78 = ((uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) -
                 (uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20)) +
                 (*(uint *)((uint)piRam020e95f4 & 0xfffffffc) >> ((uint)piRam020e95f4 & 3) * 8 |
                 *(uint *)((uint)piRam020e95f4 & 0xfffffffc) <<
                 ((uint)piRam020e95f4 & 3) * -8 + 0x20);
      *puRam020e95d8 =
           *(uint *)((uint)puRam020e95c4 & 0xfffffffc) >> ((uint)puRam020e95c4 & 3) * 8 |
           *(uint *)((uint)puRam020e95c4 & 0xfffffffc) << ((uint)puRam020e95c4 & 3) * -8 + 0x20;
      puVar18[2] = uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20;
      local_68 = 0;
      local_70 = 0;
    }
    puVar18 = puRam020e95d8;
    uVar12 = (uint)(puRam020e95e0 + 1) & 3;
    uVar15 = *(uint *)((uint)(puRam020e95e0 + 1) & 0xfffffffc);
    local_6c = uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20;
    uVar12 = iRam020e9644 + 4U & 3;
    uVar11 = *(uint *)(iRam020e9644 + 4U & 0xfffffffc);
    uVar15 = uRam020e963c + 4 & 3;
    uVar14 = *(uint *)(uRam020e963c + 4 & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) *
            (longlong)(int)local_6c;
    lVar3 = (longlong)(int)(uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) *
            (longlong)(int)local_78;
    local_6c = local_6c +
               (((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14) -
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14));
    puRam020e95e0[1] = local_6c;
    VecFx32_Add(puVar18,&local_70,puVar18);
    VecFx32_Subtract(puRam020e95d8,puRam020e95f8,local_64);
    VecFx32_AddScale1(uRam020e9648,local_64,puRam020e95f8,puRam020e95f8);
  }
  if (*(uint *)(uRam020e95c0 & 0xfffffffc) >> (uRam020e95c0 & 3) * 8 == 0 &&
      *(uint *)(uRam020e95c0 & 0xfffffffc) << (uRam020e95c0 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar17 = uRam020e964c;
  uVar12 = func_01ffd648(puRam020e95d8,0x12000,uRam020e964c,uRam020e9650);
  bVar22 = (uVar12 & 3) == 0;
  uVar12 = (uint)(puRam020e95d8 + 2) & 3;
  uVar14 = *(uint *)((uint)(puRam020e95d8 + 2) & 0xfffffffc);
  uVar15 = uRam020e9610 + 0x2c & 3;
  uVar11 = *(uint *)(uRam020e9610 + 0x2c & 0xfffffffc);
  if (bVar22) {
    uVar17 = 1;
  }
  iVar21 = (uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) -
           (uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20);
  uVar12 = uRam020e9610 + 0x24 & 3;
  uVar15 = *(uint *)(uRam020e9610 + 0x24 & 0xfffffffc);
  iVar20 = (*(uint *)((uint)puRam020e95d8 & 0xfffffffc) >> ((uint)puRam020e95d8 & 3) * 8 |
           *(uint *)((uint)puRam020e95d8 & 0xfffffffc) << ((uint)puRam020e95d8 & 3) * -8 + 0x20) -
           (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20);
  lVar2 = (longlong)iVar20 * (longlong)iVar20 + (longlong)iVar21 * (longlong)iVar21;
  iVar20 = (int)((ulonglong)lVar2 >> 0x20);
  if (!bVar22) {
    uVar17 = 0;
  }
  bVar22 = (uint)lVar2 < 0xe4000000;
  uVar12 = (uint)((int)(iVar20 - (bVar22 + 0x57)) < 0 !=
                 (SBORROW4(iVar20,0x57) != SBORROW4(iVar20 + -0x57,(uint)bVar22)));
  *puRam020e95fc = uVar17;
  if (uVar12 != 0) {
    lVar2 = ZEXT48(puRam020e9654) << 0x20;
  }
  puVar18 = (uint *)((ulonglong)lVar2 >> 0x20);
  uVar15 = (uint)lVar2;
  *puRam020e9600 = uVar12;
  if (uVar12 != 0) {
    *puVar18 = uVar15;
    return;
  }
  *puRam020e9654 =
       (uint)((int)((int)puVar18 - ((uVar15 < 0x90000000) + 0x3d0)) < 0 ==
             (SBORROW4((int)puVar18,0x3d0) !=
             SBORROW4((int)(puVar18 + -0xf4),(uint)(uVar15 < 0x90000000))));
  return;
}

