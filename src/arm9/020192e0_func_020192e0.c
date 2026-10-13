/* Decompiled C draft; module arm9; ROM address 020192e0. No matching claim. */
#include "types.h"
#include "deps/020192e0_func_020192e0.h"

void func_020192e0(int param_1,int param_2)

{
  longlong lVar1;
  ushort *puVar2;
  int iVar3;
  uint *puVar4;
  int extraout_r1;
  undefined4 uVar5;
  uint uVar6;
  int extraout_r1_00;
  uint uVar7;
  undefined4 uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar20;
  bool bVar21;
  int local_80;
  int local_7c;
  uint local_70 [9];
  undefined4 uStack_4c;
  int local_30;
  int local_2c;
  int local_28;
  code *pcVar8;
  uint uVar11;
  uint uVar14;
  uint uVar19;
  
  uVar17 = param_2 + 0x20U & 3;
  uVar18 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
  uVar19 = uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20;
  uVar17 = uVar19 + 0x14 & 3;
  uVar18 = *(uint *)(uVar19 + 0x14 & 0xfffffffc);
  puVar2 = (ushort *)(uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20);
  uVar15 = *(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
           *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20;
  uVar18 = *(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
           *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20;
  uVar17 = param_2 + 0x90U & 3;
  uVar7 = *(uint *)(param_2 + 0x90U & 0xfffffffc);
  pcVar8 = (code *)(uVar7 >> uVar17 * 8 | uVar7 << uVar17 * -8 + 0x20);
  uVar17 = (uint)*(ushort *)(uVar19 + 0x1c);
  iVar3 = *(byte *)(uVar15 + 0x46) + 0x180;
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(param_2,0);
  }
  if ((((*(ushort *)(uVar15 + 0x3c) == 0) ||
       (*(ushort *)(param_2 + 0x4c) < *(ushort *)(uVar15 + 0x3c))) &&
      (_s32_div_f(*(undefined2 *)(param_2 + 0x4c),*(undefined1 *)(param_2 + 0x80)), extraout_r1 == 0
      )) && (((uVar7 = param_2 + 0x24U & 3, uVar15 = *(uint *)(param_2 + 0x24U & 0xfffffffc),
              uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20, -1 < (int)(uVar7 << 0x1f)
              && (-1 < (int)(uVar7 << 0x1e))) && ((int)(uVar7 << 0x1b) < 0)))) {
    func_0201ca6c(param_2,param_1 + 0x1c);
  }
  bVar21 = (int)(uVar18 << 0x17) < 0;
  if (bVar21) {
    local_70[0] = uRam02019b10;
    uVar7 = uVar19 + 4 & 3;
    uVar15 = *(uint *)(uVar19 + 4 & 0xfffffffc);
    local_70[1] = *(ushort *)((uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20) + 8) & 1;
  }
  uVar15 = (uint)bVar21;
  uVar7 = uVar15;
  if (((int)(uVar18 << 0x16) < 0) &&
     (uVar14 = uVar19 + 8 & 3, uVar13 = *(uint *)(uVar19 + 8 & 0xfffffffc),
     uVar14 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20,
     -1 < (int)((uint)*(ushort *)(uVar14 + 8) << 0x1f))) {
    local_70[uVar15 * 2] = uRam02019b14;
    uVar7 = uVar15 + 1;
    local_70[uVar15 * 2 + 1] = ((uint)*(ushort *)(uVar14 + 8) << 0x1e) >> 0x1f;
  }
  uVar15 = uVar7;
  if ((int)(uVar18 << 0x15) < 0) {
    local_70[uVar7 * 2] = uRam02019b18;
    uVar14 = uVar19 + 0xc & 3;
    uVar13 = *(uint *)(uVar19 + 0xc & 0xfffffffc);
    uVar15 = uVar7 + 1;
    local_70[uVar7 * 2 + 1] =
         ((uint)*(ushort *)((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) + 2) << 0x17) >>
         0x1f;
  }
  if (((int)(uVar18 << 0x14) < 0) &&
     (uVar7 = uVar19 + 0x10 & 3, uVar14 = *(uint *)(uVar19 + 0x10 & 0xfffffffc),
     uVar14 = uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20, uVar7 = uVar14 + 8,
     uVar13 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
     -1 < (int)((uVar7 >> uVar13 * 8 | uVar7 << uVar13 * -8 + 0x20) << 0xf))) {
    local_70[uVar15 * 2] = uRam02019b1c;
    uVar14 = uVar14 + 8;
    uVar7 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    local_70[uVar15 * 2 + 1] = ((uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20) << 0xe) >> 0x1f;
    uVar15 = uVar15 + 1;
  }
  uVar7 = param_2 + 8U & 3;
  uVar14 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar7 = uVar14 >> uVar7 * 8 | uVar14 << uVar7 * -8 + 0x20;
  if (uVar7 != 0) {
    local_80 = 0;
    do {
      uVar14 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
      iVar16 = local_80;
      if (uVar15 != 0) {
        do {
          (*(code *)local_70[iVar16 * 2])(uVar7,uVar19);
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar15);
      }
      local_28 = 0;
      local_2c = 0;
      local_30 = 0;
      if ((int)(uVar18 << 0x10) < 0) {
        uVar5 = *(undefined4 *)(param_2 + 0x2c);
        uVar9 = *(undefined4 *)(param_2 + 0x30);
        *(undefined4 *)(uVar7 + 0x38) = *(undefined4 *)(param_2 + 0x28);
        *(undefined4 *)(uVar7 + 0x3c) = uVar5;
        *(undefined4 *)(uVar7 + 0x40) = uVar9;
      }
      iVar16 = local_80;
      if (uVar17 != 0) {
        do {
          uVar13 = uVar19 + 0x18 & 3;
          uVar10 = *(uint *)(uVar19 + 0x18 & 0xfffffffc);
          uVar11 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
          uVar13 = uVar11 + iVar16 * 8;
          uVar10 = uVar13 & 3;
          uVar20 = *(uint *)(uVar13 & 0xfffffffc);
          uVar13 = uVar11 + iVar16 * 8 + 4;
          uVar11 = uVar13 & 3;
          uVar13 = *(uint *)(uVar13 & 0xfffffffc);
          (*(code *)(uVar20 >> uVar10 * 8 | uVar20 << uVar10 * -8 + 0x20))
                    (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20,uVar7,&local_30);
          iVar16 = iVar16 + 1;
        } while (iVar16 < (int)uVar17);
      }
      *(short *)(uVar7 + 0x20) = *(short *)(uVar7 + 0x20) + *(short *)(uVar7 + 0x22);
      uVar13 = uVar7 + 0x14 & 3;
      uVar10 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
      *(int *)(uVar7 + 0x14) =
           (int)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) * iVar3) >> 9;
      uVar13 = uVar7 + 0x18 & 3;
      uVar10 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
      *(int *)(uVar7 + 0x18) =
           (int)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) * iVar3) >> 9;
      uVar13 = uVar7 + 0x1c & 3;
      uVar10 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
      *(int *)(uVar7 + 0x1c) =
           (int)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) * iVar3) >> 9;
      uVar13 = uVar7 + 0x14 & 3;
      uVar10 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
      *(uint *)(uVar7 + 0x14) = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + local_30;
      uVar13 = uVar7 + 0x18 & 3;
      uVar10 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
      *(uint *)(uVar7 + 0x18) = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + local_2c;
      uVar13 = uVar7 + 0x1c & 3;
      uVar10 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
      *(uint *)(uVar7 + 0x1c) = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + local_28;
      uVar13 = uVar7 + 0x14 & 3;
      uVar6 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
      uVar10 = param_2 + 0x34U & 3;
      uVar20 = *(uint *)(param_2 + 0x34U & 0xfffffffc);
      uVar11 = uVar7 + 8 & 3;
      uVar12 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      *(uint *)(uVar7 + 8) =
           (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) +
           (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
           (uVar20 >> uVar10 * 8 | uVar20 << uVar10 * -8 + 0x20);
      uVar13 = uVar7 + 0x18 & 3;
      uVar6 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
      uVar10 = param_2 + 0x38U & 3;
      uVar20 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
      uVar11 = uVar7 + 0xc & 3;
      uVar12 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      *(uint *)(uVar7 + 0xc) =
           (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) +
           (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
           (uVar20 >> uVar10 * 8 | uVar20 << uVar10 * -8 + 0x20);
      uVar13 = uVar7 + 0x1c & 3;
      uVar6 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
      uVar10 = param_2 + 0x3cU & 3;
      uVar20 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
      uVar11 = uVar7 + 0x10 & 3;
      uVar12 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
      *(uint *)(uVar7 + 0x10) =
           (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) +
           (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
           (uVar20 >> uVar10 * 8 | uVar20 << uVar10 * -8 + 0x20);
      if ((((int)(uVar18 << 0xf) < 0) &&
          (lVar1 = (longlong)(int)((uint)*(ushort *)(uVar7 + 0x24) << 0xc) *
                   (longlong)(int)((uint)*(byte *)((int)puVar2 + 0xd) << 0xc) + 0x800,
          iVar16 = (uint)*(ushort *)(uVar7 + 0x26) * 0x1000 -
                   ((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 8),
          -1 < iVar16)) && (_s32_div_f(iVar16 >> 0xc,(char)puVar2[7]), extraout_r1_00 == 0)) {
        func_0201c74c(uVar7,param_2,param_1 + 0x1c);
      }
      uVar13 = param_2 + 0x20U & 3;
      uVar10 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
      uVar10 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      uVar10 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
      uVar13 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      if ((int)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) << 1) < 0) {
        uVar13 = param_1 + 0x38U & 3;
        uVar10 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
        *(ushort *)(uVar7 + 0x2e) =
             *(ushort *)(uVar7 + 0x2e) & 0x3ff |
             (ushort)((((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) << 8) >> 0x1a) << 10);
      }
      else {
        uVar13 = param_1 + 0x38U & 3;
        uVar10 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
        puVar4 = (uint *)(param_1 + 0x38);
        *(ushort *)(uVar7 + 0x2e) =
             *(ushort *)(uVar7 + 0x2e) & 0x3ff |
             (ushort)((((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) << 0xe) >> 0x1a) << 10
                     );
        uVar13 = param_1 + 0x38U & 3;
        uVar10 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
        uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
        *(uint *)(param_1 + 0x38) =
             uVar13 & 0xfffc0fff | (((uVar13 << 0xe) >> 0x1a) + 1 & 0x3f) << 0xc;
        uVar13 = param_1 + 0x38U & 3;
        uVar10 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
        uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
        if ((uVar13 << 0x14) >> 0x1a < (uVar13 << 0xe) >> 0x1a) {
          *puVar4 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                    *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) &
                    0xfffc0fff | (uVar13 & 0x3f) << 0xc;
        }
      }
      *(short *)(uVar7 + 0x26) = *(short *)(uVar7 + 0x26) + 1;
      if (*(ushort *)(uVar7 + 0x24) < *(ushort *)(uVar7 + 0x26)) {
        uVar5 = func_0201e3c8((uint *)(uintptr_t)(param_2 + 8),uVar7);
        func_0201e494((undefined4 *)(uintptr_t)(param_1 + 0x1c),(uint *)(uintptr_t)(uVar5));
      }
      uVar7 = uVar14;
    } while (uVar14 != 0);
  }
  if ((int)(uVar18 << 0xf) < 0) {
    bVar21 = (int)((uint)*puVar2 << 0x1e) < 0;
    if (bVar21) {
      uStack_4c = 0;
      local_70[8] = uRam02019b20;
    }
    uVar18 = (uint)bVar21;
    if ((int)((uint)*puVar2 << 0x1d) < 0) {
      local_70[uVar18 * 2 + 8] = uRam02019b24;
      local_70[uVar18 * 2 + 9] = 0;
      uVar18 = uVar18 + 1;
    }
    uVar7 = param_2 + 0x14U & 3;
    uVar15 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    uVar7 = uVar15 >> uVar7 * 8 | uVar15 << uVar7 * -8 + 0x20;
    if (-1 < (int)((uint)*puVar2 << 0x1f)) {
      uVar17 = 0;
    }
    if (uVar7 != 0) {
      local_7c = 0;
      do {
        uVar15 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                 *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
        _s32_div_f((uint)*(ushort *)(uVar7 + 0x26) << 8,*(undefined2 *)(uVar7 + 0x24));
        iVar16 = local_7c;
        if (uVar18 != 0) {
          do {
            (*(code *)local_70[iVar16 * 2 + 8])(uVar7,uVar19);
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar18);
        }
        local_30 = 0;
        if ((int)((uint)*puVar2 << 0x1a) < 0) {
          uVar5 = *(undefined4 *)(param_2 + 0x2c);
          uVar9 = *(undefined4 *)(param_2 + 0x30);
          *(undefined4 *)(uVar7 + 0x38) = *(undefined4 *)(param_2 + 0x28);
          *(undefined4 *)(uVar7 + 0x3c) = uVar5;
          *(undefined4 *)(uVar7 + 0x40) = uVar9;
        }
        iVar16 = local_7c;
        local_2c = local_30;
        local_28 = local_30;
        if (uVar17 != 0) {
          do {
            uVar14 = uVar19 + 0x18 & 3;
            uVar13 = *(uint *)(uVar19 + 0x18 & 0xfffffffc);
            uVar10 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
            uVar14 = uVar10 + iVar16 * 8;
            uVar13 = uVar14 & 3;
            uVar11 = *(uint *)(uVar14 & 0xfffffffc);
            uVar14 = uVar10 + iVar16 * 8 + 4;
            uVar10 = uVar14 & 3;
            uVar14 = *(uint *)(uVar14 & 0xfffffffc);
            (*(code *)(uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20))
                      (uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20,uVar7,&local_30);
            iVar16 = iVar16 + 1;
          } while (iVar16 < (int)uVar17);
        }
        *(short *)(uVar7 + 0x20) = *(short *)(uVar7 + 0x20) + *(short *)(uVar7 + 0x22);
        uVar14 = uVar7 + 0x14 & 3;
        uVar13 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
        *(int *)(uVar7 + 0x14) =
             (int)((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) * iVar3) >> 9;
        uVar14 = uVar7 + 0x18 & 3;
        uVar13 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
        *(int *)(uVar7 + 0x18) =
             (int)((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) * iVar3) >> 9;
        uVar14 = uVar7 + 0x1c & 3;
        uVar13 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
        *(int *)(uVar7 + 0x1c) =
             (int)((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) * iVar3) >> 9;
        uVar14 = uVar7 + 0x14 & 3;
        uVar13 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
        *(uint *)(uVar7 + 0x14) = (uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) + local_30;
        uVar14 = uVar7 + 0x18 & 3;
        uVar13 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
        *(uint *)(uVar7 + 0x18) = (uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) + local_2c;
        uVar14 = uVar7 + 0x1c & 3;
        uVar13 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
        *(uint *)(uVar7 + 0x1c) = (uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) + local_28;
        uVar14 = uVar7 + 0x14 & 3;
        uVar20 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
        uVar13 = param_2 + 0x34U & 3;
        uVar11 = *(uint *)(param_2 + 0x34U & 0xfffffffc);
        uVar10 = uVar7 + 8 & 3;
        uVar6 = *(uint *)(uVar7 + 8 & 0xfffffffc);
        *(uint *)(uVar7 + 8) =
             (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) +
             (uVar20 >> uVar14 * 8 | uVar20 << uVar14 * -8 + 0x20) +
             (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20);
        uVar14 = uVar7 + 0x18 & 3;
        uVar20 = *(uint *)(uVar7 + 0x18 & 0xfffffffc);
        uVar13 = param_2 + 0x38U & 3;
        uVar11 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
        uVar10 = uVar7 + 0xc & 3;
        uVar6 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
        *(uint *)(uVar7 + 0xc) =
             (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) +
             (uVar20 >> uVar14 * 8 | uVar20 << uVar14 * -8 + 0x20) +
             (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20);
        uVar14 = uVar7 + 0x1c & 3;
        uVar20 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
        uVar13 = param_2 + 0x3cU & 3;
        uVar11 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
        uVar10 = uVar7 + 0x10 & 3;
        uVar6 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
        *(uint *)(uVar7 + 0x10) =
             (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) +
             (uVar20 >> uVar14 * 8 | uVar20 << uVar14 * -8 + 0x20) +
             (uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20);
        uVar14 = param_2 + 0x20U & 3;
        uVar13 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
        uVar13 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
        uVar14 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        uVar13 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
        uVar14 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        if ((int)(uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) < 0) {
          uVar14 = param_1 + 0x38U & 3;
          uVar13 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
          *(ushort *)(uVar7 + 0x2e) =
               *(ushort *)(uVar7 + 0x2e) & 0x3ff |
               (ushort)((((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) << 8) >> 0x1a) << 10
                       );
        }
        else {
          uVar14 = param_1 + 0x38U & 3;
          uVar13 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
          *(ushort *)(uVar7 + 0x2e) =
               *(ushort *)(uVar7 + 0x2e) & 0x3ff |
               (ushort)((((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) << 0xe) >> 0x1a) <<
                       10);
          uVar14 = param_1 + 0x38U & 3;
          uVar13 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
          uVar14 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
          puVar4 = (uint *)(param_1 + 0x38);
          *(uint *)(param_1 + 0x38) =
               uVar14 & 0xfffc0fff | (((uVar14 << 0xe) >> 0x1a) + 1 & 0x3f) << 0xc;
          uVar14 = param_1 + 0x38U & 3;
          uVar13 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
          uVar14 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
          if ((uVar14 << 0x14) >> 0x1a < (uVar14 << 0xe) >> 0x1a) {
            *puVar4 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                      *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) &
                      0xfffc0fff | (uVar14 & 0x3f) << 0xc;
          }
        }
        *(short *)(uVar7 + 0x26) = *(short *)(uVar7 + 0x26) + 1;
        if (*(ushort *)(uVar7 + 0x24) < *(ushort *)(uVar7 + 0x26)) {
          uVar5 = func_0201e3c8((uint *)(uintptr_t)(param_2 + 0x14),uVar7);
          func_0201e494((undefined4 *)(uintptr_t)(param_1 + 0x1c),(uint *)(uintptr_t)(uVar5));
        }
        uVar7 = uVar15;
      } while (uVar15 != 0);
    }
  }
  *(short *)(param_2 + 0x4c) = *(short *)(param_2 + 0x4c) + 1;
  uVar17 = param_2 + 0x90U & 3;
  uVar18 = *(uint *)(param_2 + 0x90U & 0xfffffffc);
  pcVar8 = (code *)(uVar18 >> uVar17 * 8 | uVar18 << uVar17 * -8 + 0x20);
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(param_2,1);
    return;
  }
  return;
}

