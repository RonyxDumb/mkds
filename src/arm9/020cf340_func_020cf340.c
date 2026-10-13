/* Decompiled C draft; module arm9; ROM address 020cf340. No matching claim. */
#include "types.h"
#include "deps/020cf340_func_020cf340.h"

void func_020cf340(int param_1,undefined4 param_2,uint param_3)

{
  ushort *puVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  longlong lVar5;
  uint *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  byte *pbVar20;
  byte *pbVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  bool bVar26;
  undefined8 uVar27;
  int aiStack_b4 [4];
  uint uStack_a4;
  byte abStack_a0 [124];
  
  uVar9 = *(uint *)(uRam020cfc44 & 0xfffffffc) >> (uRam020cfc44 & 3) * 8 |
          *(uint *)(uRam020cfc44 & 0xfffffffc) << (uRam020cfc44 & 3) * -8 + 0x20;
  uVar10 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  if (0x1c < (int)uVar10) {
    if (0x20 < (int)uVar10) {
      if (uVar10 == 0x2e) {
        iVar11 = func_020d3e18();
        uVar10 = uRam020cfc4c;
        if (iVar11 != 0) {
          iVar11 = func_020d3dd8();
          uVar9 = func_020d3dbc();
          uVar8 = uRam020cfc94;
          uVar7 = uRam020cfc68;
          iVar22 = 0;
          do {
            uVar12 = FUN_02132440(iVar22);
            uVar12 = func_0213250c(uVar8,uVar12);
            uVar12 = func_02131234(uRam020cfc98,uVar12);
            iVar24 = FUN_02131860(uVar12,0);
            if (iVar24 == 0) {
              uVar12 = func_0213250c(uVar7,uVar12);
              func_021329f8(uVar12,0x3f000000);
            }
            else {
              uVar12 = func_0213250c(uVar7,uVar12);
              func_02131234(0x3f000000,uVar12);
            }
            uVar27 = func_021322c8();
            uVar10 = uRam020cfc4c;
            iVar24 = (int)((ulonglong)uVar27 >> 0x20);
          } while (((int)uVar27 <= iVar11) && (iVar22 = iVar22 + 1, iVar22 < 0x13));
          iVar11 = iVar22 + 2;
          iVar14 = 0;
          if (0 < iVar22) {
            do {
              uVar17 = uVar10 & 3;
              uVar13 = *(uint *)(uVar10 & 0xfffffffc);
              uVar4 = *(ushort *)((uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20) + 2);
              param_3 = (uint)uVar4;
              iVar24 = (iVar14 + 0xe0) * 2;
              iVar14 = iVar14 + 1;
              *(ushort *)(param_1 + iVar24) = uVar4;
            } while (iVar14 < iVar22);
          }
          uVar13 = uRam020cfc4c;
          iVar14 = iVar22 + -2;
          uVar17 = uRam020cfc4c;
          while (iVar25 = iVar22, uVar10 = uVar17, iVar14 < iVar22) {
            bVar26 = -1 < iVar14;
            if (bVar26) {
              uVar10 = uVar13 & 3;
              uVar16 = *(uint *)(uVar13 & 0xfffffffc);
              param_3 = (uint)*(ushort *)((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) + 4)
              ;
              iVar24 = (iVar14 + 0xe0) * 2;
            }
            iVar14 = iVar14 + 1;
            if (bVar26) {
              uRam020cfc4c = uVar17;
              *(short *)(param_1 + iVar24) = (short)param_3;
              uVar17 = uRam020cfc4c;
            }
          }
          for (; uRam020cfc4c = uVar10, iVar25 <= iVar11; iVar25 = iVar25 + 1) {
            *(undefined2 *)(param_1 + (iVar25 + 0xe0) * 2) =
                 *(undefined2 *)
                  ((*(uint *)(uVar17 & 0xfffffffc) >> (uVar17 & 3) * 8 |
                   *(uint *)(uVar17 & 0xfffffffc) << (uVar17 & 3) * -8 + 0x20) + 6);
            uVar10 = uRam020cfc4c;
          }
          if ((0x3fff < uVar9) && (uVar9 < 0xc000)) {
            for (iVar11 = iVar22 + 3; (iVar11 <= iVar22 + 4 && (iVar11 < 0x15)); iVar11 = iVar11 + 1
                ) {
              *(undefined2 *)(param_1 + (iVar11 + 0xe0) * 2) =
                   *(undefined2 *)
                    ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                     *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 8);
            }
            iVar11 = iVar22 + 4;
            uVar10 = uRam020cfc4c;
          }
          while (uVar9 = uRam020cfc4c, iVar11 + 1 < 0x15) {
            puVar6 = (uint *)(uRam020cfc4c & 0xfffffffc);
            uVar17 = uRam020cfc4c & 3;
            uRam020cfc4c = uVar10;
            *(undefined2 *)(param_1 + (iVar11 + 0xe1) * 2) =
                 *(undefined2 *)((*puVar6 >> uVar17 * 8 | *puVar6 << uVar17 * -8 + 0x20) + 10);
            uVar10 = uRam020cfc4c;
            iVar11 = iVar11 + 1;
            uRam020cfc4c = uVar9;
          }
        }
        uRam020cfc4c = uVar10;
        Arm_FlushRange(param_1 + 0x1c0,0x2c);
        func_0214b4dc();
        func_0214b468(param_1 + 0x1c0,uRam020cfc9c,0x2c);
        iVar11 = MaybeCircuitUsesLocal3();
        if (iVar11 != 0) {
          func_0214b468(param_1 + 0x1c0,uRam020cfca0,0x2c);
        }
        GXS_EndLoadBGExtPltt();
        return;
      }
      return;
    }
    if ((int)uVar10 < 0x1f) {
      return;
    }
    if (uVar10 == 0x1f) {
      iVar11 = func_020d3e18();
      if (iVar11 != 0) {
        iVar22 = func_020d3dd8();
        uVar8 = uRam020cfc6c;
        uVar7 = uRam020cfc68;
        iVar11 = 7;
        do {
          uVar12 = FUN_02132440(7 - iVar11);
          uVar12 = func_0213250c(uVar8,uVar12);
          uVar12 = func_02131234(uRam020cfc70,uVar12);
          iVar24 = FUN_02131860(uVar12,0);
          if (iVar24 == 0) {
            uVar12 = func_0213250c(uVar7,uVar12);
            func_021329f8(uVar12,0x3f000000);
          }
          else {
            uVar12 = func_0213250c(uVar7,uVar12);
            func_02131234(0x3f000000,uVar12);
          }
          iVar24 = func_021322c8();
          uVar10 = uRam020cfc4c;
        } while ((iVar24 <= iVar22) && (iVar11 = iVar11 + -1, 0 < iVar11));
        iVar24 = 0;
        iVar22 = iVar11;
        uVar9 = uRam020cfc4c;
        if (0 < iVar11) {
          do {
            uVar9 = uVar10 & 3;
            uVar17 = *(uint *)(uVar10 & 0xfffffffc);
            iVar22 = iVar24 + 0x50;
            iVar24 = iVar24 + 1;
            *(undefined2 *)(param_1 + iVar22 * 2) =
                 *(undefined2 *)((uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) + 2);
            iVar22 = iVar11;
            uVar9 = uRam020cfc4c;
          } while (iVar24 < iVar11);
        }
        do {
          iVar24 = iVar22 + 1;
          *(undefined2 *)(param_1 + (iVar22 + 0x50) * 2) =
               *(undefined2 *)
                ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 4);
          uVar10 = uRam020cfc4c;
          iVar22 = iVar24;
        } while (iVar24 == iVar11);
        while (iVar11 + 1 < 8) {
          uVar9 = uVar10 & 3;
          uVar17 = *(uint *)(uVar10 & 0xfffffffc);
          *(undefined2 *)(param_1 + (iVar11 + 0x51) * 2) =
               *(undefined2 *)((uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) + 6);
          iVar11 = iVar11 + 1;
        }
      }
      Arm_FlushRange(param_1 + 0xa0,0x10);
      func_0214b4dc();
      func_0214b468(param_1 + 0xa0,uRam020cfc74,0x10);
      iVar11 = MaybeCircuitUsesLocal3();
      if (iVar11 != 0) {
        func_0214b468(param_1 + 0xa0,uRam020cfc78,0x10);
      }
      GXS_EndLoadBGExtPltt();
      return;
    }
    if (uVar10 == 0x20) {
      iVar11 = func_021000d0(0xd0);
      if (iVar11 != 0) {
        uVar17 = func_02100084();
        iVar22 = iRam020cfc80;
        iVar11 = iRam020cfc7c;
        uVar9 = uRam020cfc4c;
        uVar10 = uVar17 + 4 & 3;
        uVar13 = *(uint *)(uVar17 + 4 & 0xfffffffc);
        uVar4 = *(ushort *)((uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20) + 0x7e);
        iVar24 = 0;
        do {
          iVar25 = (iVar24 + 0x48) - ((int)((uint)uVar4 * 0x48) >> 0x10);
          iVar14 = iVar24 + 0x54;
          iVar24 = iVar24 + 1;
          uVar10 = uVar9 & 3;
          uVar13 = *(uint *)(uVar9 & 0xfffffffc);
          *(undefined2 *)(param_1 + iVar14 * 2) =
               *(undefined2 *)
                ((uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20) +
                 (iVar25 - iVar22 * ((int)((ulonglong)((longlong)iVar11 * (longlong)iVar25) >> 0x20)
                                    - (iVar25 >> 0x1f))) * 2 + 2);
          iVar25 = iRam020cfc88;
          iVar14 = iRam020cfc84;
          uVar10 = uRam020cfc4c;
        } while (iVar24 < 6);
        iVar11 = 0;
        uVar4 = *(ushort *)
                 ((*(uint *)(uVar17 & 0xfffffffc) >> (uVar17 & 3) * 8 |
                  *(uint *)(uVar17 & 0xfffffffc) << (uVar17 & 3) * -8 + 0x20) + 0x7e);
        iVar24 = 0;
        iVar22 = 0;
        do {
          iVar23 = 0;
          do {
            iVar15 = (iVar23 + 0x20) - ((int)((uint)uVar4 << 5) >> 0x10);
            iVar19 = iVar23 + iVar22;
            uVar9 = uVar10 & 3;
            uVar17 = *(uint *)(uVar10 & 0xfffffffc);
            iVar23 = iVar23 + 1;
            *(undefined2 *)(param_1 + (iVar19 + 0x5a) * 2) =
                 *(undefined2 *)
                  (iVar24 + (uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) +
                   (iVar15 - iVar25 * ((int)((ulonglong)((longlong)iVar14 * (longlong)iVar15) >>
                                            0x20) - (iVar15 >> 0x1f))) * 2 + 0xe);
          } while (iVar23 < 3);
          iVar11 = iVar11 + 1;
          iVar24 = iVar24 + 6;
          iVar22 = iVar22 + 3;
        } while (iVar11 < 2);
      }
      iVar11 = func_021000d0(0xca);
      if (iVar11 != 0) {
        iVar11 = func_02100084();
        uVar10 = uRam020cfc4c;
        iVar22 = 0;
        iVar24 = 0;
        do {
          uVar9 = iVar11 + iVar22 * 4;
          uVar17 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          iVar14 = func_020dff4c(uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20);
          uVar9 = iVar22 >> 0x1f;
          if ((iVar22 * -0x80000000 + uVar9 >> 0x1f | uVar9 << 1) == uVar9) {
            iVar14 = 8 - ((iVar14 << 3) >> 0xc);
          }
          else {
            iVar14 = (iVar14 << 3) >> 0xc;
          }
          iVar25 = 0;
          if (0 < iVar14) {
            do {
              iVar23 = iVar25 + iVar24;
              iVar25 = iVar25 + 1;
              *(undefined2 *)(param_1 + (iVar23 + 0x60) * 2) =
                   *(undefined2 *)
                    ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                     *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x1a);
            } while (iVar25 < iVar14);
          }
          for (iVar25 = iVar14; iVar25 < iVar14 + 8; iVar25 = iVar25 + 1) {
            *(undefined2 *)(param_1 + (iVar25 + iVar24 + 0x60) * 2) =
                 *(undefined2 *)
                  ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                   *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x1c);
          }
          for (iVar14 = iVar14 + 8; iVar14 < 0x10; iVar14 = iVar14 + 1) {
            *(undefined2 *)(param_1 + (iVar14 + iVar24 + 0x60) * 2) =
                 *(undefined2 *)
                  ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                   *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x1a);
          }
          iVar22 = iVar22 + 1;
          iVar24 = iVar24 + 0x10;
        } while (iVar22 < 4);
      }
      Arm_FlushRange(param_1 + 0xa8,0x98);
      func_0214b4dc();
      func_0214b468(param_1 + 0xa8,uRam020cfc8c,0x98);
      iVar11 = MaybeCircuitUsesLocal3();
      if (iVar11 != 0) {
        func_0214b468(param_1 + 0xa8,uRam020cfc90,0x98);
      }
      GXS_EndLoadBGExtPltt();
      return;
    }
    return;
  }
  if (0x1b < (int)uVar10) {
    pbVar18 = abStack_a0;
    iVar11 = 0x3c;
    pbVar21 = pbRam020cfc5c;
    do {
      pbVar20 = pbVar21 + 1;
      bVar2 = *pbVar21;
      pbVar21 = pbVar21 + 2;
      bVar3 = *pbVar20;
      iVar11 = iVar11 + -1;
      pbVar20 = pbVar18 + 1;
      *pbVar18 = bVar2;
      pbVar18 = pbVar18 + 2;
      *pbVar20 = bVar3;
    } while (iVar11 != 0);
    iVar11 = func_020e3b08();
    uVar10 = uRam020cfc4c;
    if (iVar11 < 0x13) {
      iVar11 = 0;
    }
    else if (iVar11 < 0x2c) {
      iVar11 = 1;
    }
    else if (iVar11 < 0x38) {
      iVar11 = 2;
    }
    else if (iVar11 < 0x43) {
      iVar11 = 3;
    }
    else if (iVar11 < 0x4c) {
      iVar11 = 4;
    }
    else {
      iVar11 = 5;
    }
    pbVar21 = abStack_a0 + iVar11 * 0x14;
    iVar11 = 0;
    do {
      uVar9 = uVar10 & 3;
      uVar17 = *(uint *)(uVar10 & 0xfffffffc);
      iVar22 = iVar11 + 0x78;
      iVar11 = iVar11 + 1;
      *(undefined2 *)(param_1 + iVar22 * 2) =
           *(undefined2 *)
            ((uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) + (uint)*pbVar21 * 2 + 2);
      pbVar21 = pbVar21 + 1;
    } while (iVar11 < 0x14);
    Arm_FlushRange(param_1 + 0xf0,0x28);
    func_0214b4dc();
    func_0214b468(param_1 + 0xf0,uRam020cfc60,0x28);
    iVar11 = MaybeCircuitUsesLocal3();
    if (iVar11 != 0) {
      func_0214b468(param_1 + 0xf0,uRam020cfc64,0x28);
    }
    GXS_EndLoadBGExtPltt();
    return;
  }
  if (0x11 < (int)uVar10) {
    return;
  }
  if ((int)uVar10 < 0xf) {
    return;
  }
  if (uVar10 != 0xf) {
    if (uVar10 == 0x11) {
      aiStack_b4[0] = *piRam020cfc58;
      aiStack_b4[1] = piRam020cfc58[1];
      aiStack_b4[2] = piRam020cfc58[2];
      aiStack_b4[3] = piRam020cfc58[3];
      uVar10 = (uint)(piRam020cfc58 + 4) & 3;
      uVar9 = *(uint *)((uint)(piRam020cfc58 + 4) & 0xfffffffc);
      uStack_a4 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
      iVar11 = func_021000d0(0xcb);
      if (iVar11 != 0) {
        iVar11 = func_02100084();
        uVar10 = uRam020cfc4c;
        iVar22 = 0;
        do {
          uVar9 = iVar11 + iVar22 * 4;
          uVar17 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          uVar9 = uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20;
          puVar1 = (ushort *)(uVar9 + 0x7e);
          if (iVar22 == 4) {
            uVar9 = 0xb4;
          }
          iVar24 = aiStack_b4[iVar22];
          if (iVar22 == 4) {
            iVar14 = *puVar1 * uVar9;
          }
          else {
            iVar14 = (uint)*puVar1 * 0x48;
          }
          iVar25 = 0;
          do {
            iVar15 = iVar25 + (iVar14 >> 0x10);
            iVar23 = iVar15 >> 0x1f;
            uVar9 = uVar10 & 3;
            uVar17 = *(uint *)(uVar10 & 0xfffffffc);
            iVar25 = iVar25 + 1;
            *(undefined2 *)(param_1 + (iVar24 + 0x80) * 2) =
                 *(undefined2 *)
                  (iVar22 * 8 + (uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) +
                   (((uint)(iVar15 * 0x40000000 + iVar23) >> 0x1e | iVar23 << 2) - iVar23) * 2 + 2);
            iVar24 = iVar24 + 1;
          } while (iVar25 < 4);
          iVar22 = iVar22 + 1;
        } while (iVar22 < 5);
      }
      Arm_FlushRange(param_1 + 0x100,0x34);
      func_0214b4dc();
      func_0214b468(param_1 + 0x100,0x4100,0x34);
      iVar11 = MaybeCircuitUsesLocal3();
      if (iVar11 != 0) {
        func_0214b468(param_1 + 0x100,0x6100,0x34);
      }
      GXS_EndLoadBGExtPltt();
      return;
    }
    return;
  }
  iVar11 = GetCourseAnimNsbtpSomeValue();
  uVar10 = uRam020cfc4c;
  lVar5 = (longlong)iRam020cfc48;
  iVar22 = 0;
  do {
    uVar9 = uVar10 & 3;
    uVar17 = *(uint *)(uVar10 & 0xfffffffc);
    iVar14 = iVar22 + 0x40;
    iVar24 = iVar22 * 2;
    iVar22 = iVar22 + 1;
    *(undefined2 *)(param_1 + iVar14 * 2) =
         *(undefined2 *)
          (((int)(lVar5 * iVar11 >> 0x22) - (iVar11 >> 0x1f)) * 6 +
           (uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) + iVar24 + 2);
  } while (iVar22 < 3);
  Arm_FlushRange(param_1 + 0x80,6);
  func_0214b4dc();
  func_0214b468(param_1 + 0x80,uRam020cfc50,6);
  iVar11 = MaybeCircuitUsesLocal3();
  if (iVar11 != 0) {
    func_0214b468(param_1 + 0x80,uRam020cfc54,6);
  }
  GXS_EndLoadBGExtPltt();
  return;
}

