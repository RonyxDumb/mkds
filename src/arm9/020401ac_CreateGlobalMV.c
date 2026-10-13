/* Decompiled C draft; module arm9; ROM address 020401ac. No matching claim. */
#include "types.h"
#include "deps/020401ac_CreateGlobalMV.h"

void CreateGlobalMV(void)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint extraout_r1;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint uVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar21;
  uint uVar22;
  ushort *puVar23;
  uint local_30;
  uint local_2c;
  uint uVar6;
  uint uVar11;
  uint uVar20;
  
  uVar5 = DAT_02040714;
  puVar9 = (undefined4 *)
           (*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
           *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20);
  *puVar9 = 0;
  puVar9[1] = 0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  MaybeConvertElapsedTime
            ((undefined1 *)(uintptr_t)(uVar6 + 10),(undefined1 *)(uintptr_t)(uVar6 + 0xb),(undefined2 *)(uintptr_t)(uVar6 + 8),0,
             *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
             *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20);
  uVar5 = DAT_02040718;
  uVar6 = DAT_02040714;
  uVar16 = 0;
  *(undefined2 *)
   ((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
    *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0xe) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x4cc) = 0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) {
  case 0:
    iVar17 = func_02040bc0();
    if (iVar17 != 0) {
      uVar16 = 1;
    }
    break;
  case 1:
    goto LAB_02040238;
  case 2:
    goto LAB_02040238;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
LAB_02040238:
    uVar16 = 1;
  }
  uVar5 = DAT_02040714;
  *(undefined4 *)
   ((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
    *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0x4f0) = uVar16;
  uVar10 = DAT_02040718;
  *(undefined4 *)
   ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4e0) = 6;
  *(undefined4 *)
   ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4ec) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4f4) = 0;
  uVar6 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar11 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
  uVar6 = uVar11 + 8 & 3;
  uVar10 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
  if (uVar6 == 2) {
    uVar6 = uVar11 + 0x18 & 3;
    uVar10 = *(uint *)(uVar11 + 0x18 & 0xfffffffc);
    if ((uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) == 1) {
      *(undefined4 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4ec) = 1;
      uVar6 = (*(uint *)(DAT_0204071c & 0xfffffffc) >> (DAT_0204071c & 3) * 8 |
              *(uint *)(DAT_0204071c & 0xfffffffc) << (DAT_0204071c & 3) * -8 + 0x20) + 0x18;
      uVar10 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4f4) =
           (uint)*(ushort *)((uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) + 2) * 0x3c;
    }
  }
  else if (uVar6 == 4) {
    if (*(char *)(uVar11 + 0x2f) == '\x06') {
      *(undefined4 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4ec) = 0;
    }
    else {
      *(undefined4 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x4ec) = 1;
    }
    *(uint *)((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
              *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0x4f4) =
         (uint)*(ushort *)
                ((*(uint *)(DAT_02040718 & 0xfffffffc) >> (DAT_02040718 & 3) * 8 |
                 *(uint *)(DAT_02040718 & 0xfffffffc) << (DAT_02040718 & 3) * -8 + 0x20) + 0x28);
  }
  uVar6 = DAT_02040714;
  iVar21 = 0;
  iVar17 = 0;
  do {
    StructRC_SomeFn_2((undefined4 *)(uintptr_t)((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x14 + iVar17),
                      iVar21);
    iVar17 = iVar17 + 0x8c;
    iVar7 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + iVar21;
    iVar21 = iVar21 + 1;
    *(undefined1 *)(iVar7 + 0x474) = 0xff;
  } while (iVar21 < 8);
  uVar10 = *(uint *)(DAT_02040718 & 0xfffffffc) >> (DAT_02040718 & 3) * 8 |
           *(uint *)(DAT_02040718 & 0xfffffffc) << (DAT_02040718 & 3) * -8 + 0x20;
  uVar6 = uVar10 + 0xc & 3;
  uVar5 = *(uint *)(uVar10 + 0xc & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 == 2) {
    uVar6 = uVar10 + 0x5c & 3;
    uVar5 = *(uint *)(uVar10 + 0x5c & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  else {
    uVar5 = DAT_02040720;
    if ((((uVar6 != 5) && (uVar5 = DAT_02040724, uVar6 != 6)) &&
        (uVar6 = uVar10 + 8 & 3, uVar5 = *(uint *)(uVar10 + 8 & 0xfffffffc),
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20, uVar5 = DAT_02040728, uVar6 != 1))
       && ((uVar5 = DAT_0204072c, uVar6 != 4 && (uVar5 = DAT_02040730, uVar6 != 5)))) {
      bVar14 = false;
      uVar6 = *(uint *)(DAT_02040734 & 0xfffffffc) >> (DAT_02040734 & 3) * 8 |
              *(uint *)(DAT_02040734 & 0xfffffffc) << (DAT_02040734 & 3) * -8 + 0x20;
      if (uVar6 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      }
      if ((uVar5 != 0) &&
         (uVar5 = uVar6 + 4 & 3, uVar10 = *(uint *)(uVar6 + 4 & 0xfffffffc),
         (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) != 0xd)) {
        bVar14 = true;
      }
      if (bVar14) {
        uVar5 = uVar6 + 0x1eb0 & 3;
        uVar6 = *(uint *)(uVar6 + 0x1eb0 & 0xfffffffc);
        uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      }
      else {
        iVar17 = Os_GetTick();
        iVar21 = Os_GetTick();
        uVar5 = iVar17 * 0x10000 + iVar21;
      }
    }
  }
  iVar17 = DAT_02040738;
  uVar6 = *(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
          *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20;
  *(uint *)(uVar6 + 0x47c) = uVar5;
  uVar16 = DAT_0204073c;
  iVar17 = uVar6 + iVar17;
  *(undefined4 *)(iVar17 + 4) = 0;
  uVar2 = DAT_02040740;
  *(undefined4 *)(iVar17 + 8) = uVar16;
  uVar16 = DAT_02040744;
  *(undefined4 *)(iVar17 + 0xc) = uVar2;
  *(undefined4 *)(iVar17 + 0x10) = uVar16;
  *(undefined4 *)(iVar17 + 0x14) = 0;
  uVar10 = DAT_02040718;
  *(uint *)(uVar6 + 0x494) = uVar5;
  uVar6 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  *(uint *)((uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) + 0x244) = uVar5;
  iVar21 = Os_GetTick();
  iVar7 = Os_GetTick();
  iVar8 = Os_GetTick();
  iVar17 = DAT_02040748;
  uVar10 = *(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
           *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20;
  *(int *)(uVar10 + 0x498) = iVar21 + iVar7 * 0x1000000 + iVar8 * 0x100;
  uVar16 = DAT_0204073c;
  iVar17 = uVar10 + iVar17;
  *(undefined4 *)(iVar17 + 4) = 0;
  uVar2 = DAT_02040740;
  *(undefined4 *)(iVar17 + 8) = uVar16;
  uVar3 = DAT_02040744;
  *(undefined4 *)(iVar17 + 0xc) = uVar2;
  *(undefined4 *)(iVar17 + 0x10) = uVar3;
  uVar4 = DAT_0204074c;
  *(undefined4 *)(iVar17 + 0x14) = 0;
  *(undefined4 *)(uVar10 + 0x4b0) = uVar4;
  *(undefined4 *)(uVar10 + 0x4b4) = 0;
  *(undefined4 *)(uVar10 + 0x4b8) = uVar16;
  *(undefined4 *)(uVar10 + 0x4bc) = uVar2;
  *(undefined4 *)(uVar10 + 0x4c0) = uVar3;
  uVar5 = DAT_02040718;
  *(undefined4 *)(uVar10 + 0x4c4) = 0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 8;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) == 2) {
    func_020427d4((longlong *)(uintptr_t)(uVar10 + DAT_02040738));
  }
  uVar5 = DAT_0204071c;
  *(undefined4 *)
   ((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
    *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0x4d0) = 0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar16 = FX_Inv((*(ushort *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x9c) + 1) *
                  0x1000);
  *(undefined4 *)
   ((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
    *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0x4e4) = uVar16;
  iVar17 = GetCurrentLapCount();
  uVar16 = FX_Inv(iVar17 << 0xc);
  uVar5 = DAT_0204071c;
  uVar6 = DAT_02040714;
  iVar17 = 0;
  *(undefined4 *)
   ((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
    *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0x4e8) = uVar16;
  uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
           *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  uVar11 = (uint)*(ushort *)(uVar10 + 0x98);
  if (uVar11 != 0xffffffff) {
    local_2c = 0;
    local_30 = 0;
    do {
      _s32_div_f(iVar17);
      if (extraout_r1 == uVar11) {
        uVar10 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                 *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x4d4;
        uVar11 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        *(undefined4 *)((uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + iVar17 * 4) = 0x1000
        ;
      }
      else {
        uVar11 = local_30;
        if (*(short *)(uVar10 + 0x50) != 0) {
          do {
            uVar12 = uVar10 + 0x4c & 3;
            uVar10 = *(uint *)(uVar10 + 0x4c & 0xfffffffc);
            puVar23 = (ushort *)
                      (uVar11 * 0xc + (uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20));
            uVar12 = (uint)puVar23[1];
            uVar10 = local_2c;
            if (uVar12 != 0) {
              do {
                uVar13 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                         *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x44;
                uVar19 = uVar13 & 3;
                uVar15 = *(uint *)(uVar13 & 0xfffffffc);
                uVar13 = uVar10 + *puVar23 & 0xffff;
                if ((int)*(short *)(uVar13 * 0x24 +
                                    (uVar15 >> uVar19 * 8 | uVar15 << uVar19 * -8 + 0x20) + 0x20) ==
                    extraout_r1) {
                  if (uVar12 == 0) {
                    iVar21 = 0;
                  }
                  else {
                    iVar21 = FX_Div((uVar13 - *puVar23) * 0x1000 + 0x1000,uVar12 << 0xc);
                  }
                  uVar13 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                           *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
                  uVar12 = uVar13 + 0x4e4;
                  uVar19 = uVar12 & 3;
                  uVar15 = *(uint *)(uVar12 & 0xfffffffc);
                  uVar13 = uVar13 + 0x4d4;
                  uVar12 = uVar13 & 3;
                  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
                  lVar1 = (longlong)(int)(iVar21 + (uint)(byte)puVar23[5] * 0x1000) *
                          (longlong)(int)(uVar15 >> uVar19 * 8 | uVar15 << uVar19 * -8 + 0x20) +
                          0x800;
                  *(uint *)((uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) + iVar17 * 4) =
                       (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
                }
                uVar12 = (uint)puVar23[1];
                uVar10 = uVar10 + 1 & 0xffff;
              } while (uVar10 < uVar12);
            }
            uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                     *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
            uVar11 = uVar11 + 1 & 0xffff;
          } while (uVar11 < *(ushort *)(uVar10 + 0x50));
        }
      }
      uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      iVar17 = iVar17 + 1;
      uVar11 = (uint)*(ushort *)(uVar10 + 0x98);
    } while (iVar17 < (int)(uVar11 + 1));
  }
  uVar6 = (*(uint *)(DAT_02040718 & 0xfffffffc) >> (DAT_02040718 & 3) * 8 |
          *(uint *)(DAT_02040718 & 0xfffffffc) << (DAT_02040718 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) != 2) {
    *(undefined1 *)
     ((*(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
      *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20) + 0x4f8) = 0;
    return;
  }
  uVar11 = *(uint *)(DAT_02040714 & 0xfffffffc) >> (DAT_02040714 & 3) * 8 |
           *(uint *)(DAT_02040714 & 0xfffffffc) << (DAT_02040714 & 3) * -8 + 0x20;
  uVar6 = uVar11 + 0x47c & 3;
  uVar5 = *(uint *)(uVar11 + 0x47c & 0xfffffffc);
  uVar15 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  iVar17 = uVar11 + DAT_02040738;
  uVar6 = iVar17 + 8U & 3;
  uVar5 = *(uint *)(iVar17 + 8U & 0xfffffffc);
  uVar18 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = iVar17 + 4U & 3;
  uVar12 = *(uint *)(iVar17 + 4U & 0xfffffffc);
  lVar1 = (ulonglong)uVar15 * (ulonglong)uVar18;
  uVar22 = (uint)lVar1;
  uVar5 = iVar17 + 0xcU & 3;
  uVar13 = *(uint *)(iVar17 + 0xcU & 0xfffffffc);
  uVar10 = iVar17 + 0x10U & 3;
  uVar19 = *(uint *)(iVar17 + 0x10U & 0xfffffffc);
  uVar20 = uVar19 >> uVar10 * 8 | uVar19 << uVar10 * -8 + 0x20;
  uVar10 = iVar17 + 0x14U & 3;
  uVar19 = *(uint *)(iVar17 + 0x14U & 0xfffffffc);
  *(uint *)(uVar11 + 0x47c) = uVar20 + uVar22;
  *(uint *)(iVar17 + 4) =
       (uVar19 >> uVar10 * 8 | uVar19 << uVar10 * -8 + 0x20) +
       (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) * uVar15 +
       uVar18 * (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
       (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar20,uVar22);
  uVar6 = iVar17 + 4U & 3;
  uVar5 = *(uint *)(iVar17 + 4U & 0xfffffffc);
  *(byte *)(uVar11 + 0x4f8) =
       (byte)((byte)((uVar5 >> uVar6 * 8) >> 0x18) | (byte)((uVar5 << uVar6 * -8 + 0x20) >> 0x18))
       >> 5;
  return;
}

