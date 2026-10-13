/* Decompiled C draft; module arm9; ROM address 0213ee6c. No matching claim. */
#include "types.h"
#include "deps/0213ee6c_func_0213ee6c.h"

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff8c : 0x02140058 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

longlong func_0213ee6c(int param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 extraout_r1_00;
  undefined4 uVar9;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  longlong lVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined8 uVar22;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  
  uVar10 = param_4 & 0x7fffffff;
  uVar2 = param_2 & 0x7fffffff;
  if (uVar10 == 0 && param_3 == 0) {
    return (ulonglong)uRam0213f42c << 0x20;
  }
  if ((((int)uRam0213f430 < (int)uVar2) ||
      (((uVar2 == uRam0213f430 && (param_1 != 0)) || ((int)uRam0213f430 < (int)uVar10)))) ||
     ((uVar10 == uRam0213f430 && (param_3 != 0)))) {
    lVar16 = func_0212f884(param_1,param_2,param_3,param_4);
    return lVar16;
  }
  iVar15 = 0;
  if ((int)param_2 < 0) {
    if ((int)uVar10 < iRam0213f434) {
      if ((int)uRam0213f42c <= (int)uVar10) {
        iVar4 = iRam0213f438 + ((int)uVar10 >> 0x14);
        if (iVar4 < 0x15) {
          if ((param_3 == 0) &&
             (uVar12 = (int)uVar10 >> (0x14U - iVar4 & 0xff),
             uVar10 == uVar12 << (0x14U - iVar4 & 0xff))) {
            iVar15 = 2 - (uVar12 & 1);
          }
        }
        else {
          uVar12 = param_3 >> (0x34U - iVar4 & 0xff);
          if (param_3 == uVar12 << (0x34U - iVar4 & 0xff)) {
            iVar15 = 2 - (uVar12 & 1);
          }
        }
      }
    }
    else {
      iVar15 = 2;
    }
  }
  if (param_3 == 0) {
    if (uVar10 == uRam0213f430) {
      if (uVar2 + iRam0213f43c == 0 && param_1 == 0) {
        lVar16 = func_02130ccc(0,param_4,0,param_4);
        return lVar16;
      }
      if ((int)uVar2 < (int)uRam0213f42c) {
        if ((int)param_4 < 0) {
          lVar16 = func_02130ccc(0,0,0,param_4);
          return lVar16;
        }
        return 0;
      }
      if ((int)param_4 < 0) {
        param_4 = 0;
      }
      return (ulonglong)param_4 << 0x20;
    }
    if (uVar10 == uRam0213f42c) {
      if ((int)param_4 < 0) {
        lVar16 = FUN_021334a0(0,uRam0213f42c,param_1,param_2);
        return lVar16;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_4 == 0x40000000) {
      lVar16 = func_02130380(param_1,param_2,param_1,param_2);
      return lVar16;
    }
    if ((param_4 == uRam0213f440) && (-1 < (int)param_2)) {
      lVar16 = func_02130a70(param_1,param_2);
      return lVar16;
    }
  }
  uStack_78 = func_021400c8(param_1,param_2);
  uVar21 = CONCAT44(param_2,(int)uStack_78) & 0x7fffffffffffffff;
  uStack_70 = uStack_78;
  if ((param_1 == 0) && (((uVar2 == uRam0213f430 || (uVar2 == 0)) || (uVar2 == uRam0213f42c)))) {
    lVar16 = uStack_78;
    if ((int)param_4 < 0) {
      lVar16 = FUN_021334a0(0,uRam0213f42c);
    }
    MKDS_SLICE_4(uStack_78,4) = (int)((ulonglong)lVar16 >> 0x20);
    MKDS_SLICE_4(uStack_78,0) = (undefined4)lVar16;
    if ((int)param_2 < 0) {
      if (uVar2 + iRam0213f43c == 0 && iVar15 == 0) {
        uVar17 = func_02130ccc((undefined4)uStack_78,MKDS_SLICE_4(uStack_78,4),(undefined4)uStack_78,
                               MKDS_SLICE_4(uStack_78,4));
        uStack_78 = lVar16;
        uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
        lVar16 = FUN_021334a0((int)uVar17,uVar3,(int)uVar17,uVar3);
      }
      else if (iVar15 == 1) {
        lVar1 = lVar16;
        lVar16 = func_02130ccc(0,0,(undefined4)uStack_78,MKDS_SLICE_4(uStack_78,4));
        uStack_78 = lVar1;
      }
    }
    return lVar16;
  }
  if ((int)param_2 < 0 && iVar15 == 0) {
    uVar10 = uRam0213f444 & 3;
    uVar2 = *(uint *)(uRam0213f444 & 0xfffffffc);
    *puRam0213f448 = 0x21;
    lVar16 = func_02132200(uVar2 >> uVar10 * 8 | uVar2 << uVar10 * -8 + 0x20);
    return lVar16;
  }
  if (iRam0213f44c < (int)uVar10) {
    if (iRam0213f450 < (int)uVar10) {
      if ((int)uVar2 <= iRam0213f454) {
        uVar10 = uRam0213f430;
        if (-1 < (int)param_4) {
          uVar10 = 0;
        }
        return (ulonglong)uVar10 << 0x20;
      }
      if ((int)uRam0213f42c <= (int)uVar2) {
        uVar10 = uRam0213f430;
        if ((int)param_4 < 1) {
          uVar10 = 0;
        }
        return (ulonglong)uVar10 << 0x20;
      }
    }
    if ((int)uVar2 < iRam0213f454) {
      uVar10 = uRam0213f430;
      if (-1 < (int)param_4) {
        uVar10 = 0;
      }
      return (ulonglong)uVar10 << 0x20;
    }
    if ((int)uRam0213f42c < (int)uVar2) {
      uVar10 = uRam0213f430;
      if ((int)param_4 < 1) {
        uVar10 = 0;
      }
      return (ulonglong)uVar10 << 0x20;
    }
    uStack_50 = func_02130ccc(param_1,param_2,0);
    uVar5 = (undefined4)((ulonglong)uStack_50 >> 0x20);
    uVar3 = (undefined4)uStack_50;
    uVar17 = func_02130380(0x60000000,uRam0213f458,uVar3,uVar5);
    uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = func_02130380(uRam0213f45c,uRam0213f460,uVar3,uVar5);
    uVar19 = func_02130380(uVar3,uVar5,uVar3,uVar5);
    uVar20 = func_02130380(0,uRam0213f464,uVar3,uVar5);
    uVar20 = func_02130ccc(uRam0213f468,uRam0213f46c,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
    uVar20 = func_02130380(uVar3,uVar5,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
    uVar20 = func_02130ccc(0,uRam0213f440,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
    uVar19 = func_02130380((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                           (int)((ulonglong)uVar20 >> 0x20));
    uVar19 = func_02130380(uRam0213f470,uRam0213f458,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar18 = func_02130ccc((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                           (int)((ulonglong)uVar19 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar18 >> 0x20);
    func_0212f884((int)uVar17,uVar6,(int)uVar18,uVar3);
    MKDS_SLICE_4(uStack_58,0) = 0;
    MKDS_SLICE_4(uStack_58,4) = extraout_r1;
    uVar17 = func_02130ccc(0,extraout_r1,(int)uVar17,uVar6);
    uVar17 = func_02130ccc((int)uVar18,uVar3,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  }
  else {
    iVar4 = 0;
    if (uVar2 < 0x100000) {
      uVar21 = func_02130380((int)uStack_78,(int)((ulonglong)uStack_78 >> 0x20),0,iRam0213f434);
      iVar4 = -0x35;
    }
    uVar2 = (uint)(uVar21 >> 0x20);
    MKDS_SLICE_4(uStack_70,0) = (undefined4)uVar21;
    uVar3 = (undefined4)uStack_70;
    uVar10 = uVar2 & uRam0213f474;
    iVar4 = iVar4 + iRam0213f438 + ((int)uVar2 >> 0x14);
    uVar2 = uVar10 | uRam0213f42c;
    if (iRam0213f478 < (int)uVar10) {
      if ((int)uVar10 < iRam0213f47c) {
        iVar13 = 1;
      }
      else {
        iVar4 = iVar4 + 1;
        uVar2 = uVar2 - 0x100000;
        iVar13 = 0;
      }
    }
    else {
      iVar13 = 0;
    }
    uVar10 = iRam0213f480 + iVar13 * 8;
    uVar12 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar14 = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
    uVar10 = iRam0213f480 + iVar13 * 8 + 4;
    uVar12 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
    MKDS_SLICE_4(uStack_70,4) = uVar2;
    uVar17 = func_02130ccc((undefined4)uStack_70,uVar2,uVar14,uVar10);
    uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = func_0212f884(uVar3,uVar2,uVar14,uVar10);
    uVar18 = FUN_021334a0(0,uRam0213f42c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar19 = func_02130380((int)uVar17,uVar5,(int)uVar18,uVar6);
    uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar3 = (undefined4)uVar19;
    iVar11 = ((int)uVar2 >> 1 | 0x20000000U) + 0x80000 + iVar13 * 0x40000;
    uStack_48 = 0;
    uStack_40 = 0;
    uStack_44 = uVar7;
    iStack_3c = iVar11;
    uVar19 = func_02130380(0,uVar7,0,iVar11);
    uVar17 = func_02130ccc((int)uVar17,uVar5,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_02130ccc(0,iVar11,uVar14,uVar10);
    uVar19 = func_02130ccc((undefined4)uStack_70,MKDS_SLICE_4(uStack_70,4),(int)uVar19,
                           (int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_02130380(0,uVar7,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar17 = func_02130ccc((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                           (int)((ulonglong)uVar19 >> 0x20));
    uVar17 = func_02130380((int)uVar18,uVar6,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar18 = func_02130380(uVar3,uVar7,uVar3,uVar7);
    uVar8 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar5 = (undefined4)uVar18;
    uVar18 = func_02130380(uVar5,uVar8,uVar5,uVar8);
    uVar19 = func_02130380(uRam0213f484,uRam0213f488,uVar5,uVar8);
    uVar19 = func_0212f884(uRam0213f48c,uRam0213f490,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_02130380(uVar5,uVar8,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_0212f884(uRam0213f494,uRam0213f498,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_02130380(uVar5,uVar8,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_0212f884(uRam0213f49c,uRam0213f46c,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_02130380(uVar5,uVar8,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_0212f884(uRam0213f4a0,uRam0213f4a4,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_02130380(uVar5,uVar8,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_0212f884(uRam0213f4a8,uRam0213f4ac,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar18 = func_02130380((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                           (int)((ulonglong)uVar19 >> 0x20));
    uVar19 = func_0212f884(0,uVar7,uVar3,uVar7);
    uVar19 = func_02130380((int)uVar17,uVar6,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar18 = func_0212f884((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                           (int)((ulonglong)uVar19 >> 0x20));
    uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar19 = func_02130380(0,uVar7,0,uVar7);
    uVar8 = (undefined4)((ulonglong)uVar19 >> 0x20);
    uVar20 = func_0212f884(0,uRam0213f4b0,(int)uVar19,uVar8);
    func_0212f884((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar18,uVar5);
    uStack_40 = 0;
    iStack_3c = extraout_r1_00;
    uVar20 = func_02130380(uStack_48,uStack_44,0,extraout_r1_00);
    uVar9 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar17 = func_02130380((int)uVar17,uVar6,0,extraout_r1_00);
    uVar22 = func_02130ccc(0,extraout_r1_00,0,uRam0213f4b0);
    uVar19 = func_02130ccc((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),(int)uVar19,uVar8);
    uVar18 = func_02130ccc((int)uVar18,uVar5,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    uVar18 = func_02130380((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar3,uVar7);
    uVar17 = func_0212f884((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                           (int)((ulonglong)uVar18 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
    func_0212f884((int)uVar20,uVar9,(int)uVar17,uVar3);
    MKDS_SLICE_4(uStack_68,0) = 0;
    MKDS_SLICE_4(uStack_68,4) = extraout_r1_01;
    uVar18 = func_02130380(0xe0000000,uRam0213f4b4,0,extraout_r1_01);
    uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar19 = func_02130380(uRam0213f4b8,uRam0213f4bc,0,extraout_r1_01);
    uVar20 = func_02130ccc(0,extraout_r1_01,(int)uVar20,uVar9);
    uVar17 = func_02130ccc((int)uVar17,uVar3,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
    uVar17 = func_02130380(uRam0213f4c0,uRam0213f4b4,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar17 = func_0212f884((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,
                           (int)((ulonglong)uVar17 >> 0x20));
    uVar10 = iRam0213f4c4 + iVar13 * 8;
    uVar2 = uVar10 & 3;
    uVar14 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = iRam0213f4c4 + iVar13 * 8 + 4;
    uVar12 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar17 = func_0212f884(uVar14 >> uVar2 * 8 | uVar14 << uVar2 * -8 + 0x20,
                           uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20,(int)uVar17,
                           (int)((ulonglong)uVar17 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uStack_50 = _dflt(iVar4);
    uVar10 = iRam0213f4c8 + iVar13 * 8;
    uVar2 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar12 = uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20;
    uVar10 = iRam0213f4c8 + iVar13 * 8 + 4;
    uVar2 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20;
    uVar19 = func_0212f884((int)uVar18,uVar5,(int)uVar17,uVar3);
    uVar19 = func_0212f884((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar12,uVar10);
    func_0212f884((undefined4)uStack_50,MKDS_SLICE_4(uStack_50,4),(int)uVar19,(int)((ulonglong)uVar19 >> 0x20)
                 );
    MKDS_SLICE_4(uStack_58,0) = 0;
    MKDS_SLICE_4(uStack_58,4) = extraout_r1_02;
    uVar19 = func_02130ccc(0,extraout_r1_02,(undefined4)uStack_50,MKDS_SLICE_4(uStack_50,4));
    uVar19 = func_02130ccc((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar12,uVar10);
    uVar18 = func_02130ccc((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar5);
    uVar17 = func_02130ccc((int)uVar17,uVar3,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  }
  uVar5 = MKDS_SLICE_4(uStack_58,4);
  uVar3 = (undefined4)uStack_58;
  uVar10 = uRam0213f42c;
  if ((int)param_2 < 0 && iVar15 == 1) {
    uVar10 = uRam0213f4cc;
  }
  uStack_60 = 0;
  uStack_5c = param_4;
  uVar18 = func_02130ccc(param_3,param_4,0,param_4);
  uVar18 = func_02130380(uVar3,uVar5,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar17 = func_02130380(param_3,param_4,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  uVar17 = func_0212f884((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                         (int)((ulonglong)uVar17 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar6 = (undefined4)uVar17;
  uStack_68 = func_02130380(0,param_4,uVar3,uVar5);
  uVar5 = (undefined4)((ulonglong)uStack_68 >> 0x20);
  uVar3 = (undefined4)uStack_68;
  lVar16 = func_0212f884(uVar6,uVar7,uVar3,uVar5);
  uVar2 = (uint)((ulonglong)lVar16 >> 0x20);
  iVar15 = (int)lVar16;
  uStack_78 = lVar16;
  if ((int)uVar2 < iRam0213f4d0) {
    uVar17 = uStack_68;
    if (iRam0213f4e4 <= (int)(uVar2 & 0x7fffffff)) {
      if (uVar2 + iRam0213f4e8 != 0 || iVar15 != 0) {
        uVar17 = func_02130380(uRam0213f4ec,uRam0213f4f0,0,uVar10);
        lVar16 = func_02130380(uRam0213f4ec,uRam0213f4f0,(int)uVar17,
                               (int)((ulonglong)uVar17 >> 0x20));
        return lVar16;
      }
      uVar17 = func_02130ccc(iVar15,uVar2,uVar3,uVar5);
      iVar15 = FUN_02131d70(uVar6,uVar7,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
      uVar17 = uStack_68;
      if (iVar15 != 0) {
        uVar17 = func_02130380(uRam0213f4ec,uRam0213f4f0,0,uVar10);
        lVar16 = func_02130380(uRam0213f4ec,uRam0213f4f0,(int)uVar17,
                               (int)((ulonglong)uVar17 >> 0x20));
        return lVar16;
      }
    }
  }
  else {
    if (uVar2 + iRam0213f4d4 != 0 || iVar15 != 0) {
      uVar17 = func_02130380(uRam0213f4d8,uRam0213f4dc,0,uVar10);
      lVar16 = func_02130380(uRam0213f4d8,uRam0213f4dc,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20))
      ;
      return lVar16;
    }
    uVar17 = func_0212f884(uRam0213f470,uRam0213f4e0,uVar6,uVar7);
    uVar18 = func_02130ccc((undefined4)uStack_78,MKDS_SLICE_4(uStack_78,4),uVar3,uVar5);
    iVar15 = FUN_02131e60((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                          (int)((ulonglong)uVar18 >> 0x20));
    uVar17 = uStack_68;
    if (iVar15 != 0) {
      uVar17 = func_02130380(uRam0213f4d8,uRam0213f4dc,0,uVar10);
      lVar16 = func_02130380(uRam0213f4d8,uRam0213f4dc,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20))
      ;
      return lVar16;
    }
  }
  MKDS_SLICE_4(uStack_68,4) = (undefined4)((ulonglong)uVar17 >> 0x20);
  MKDS_SLICE_4(uStack_68,0) = (undefined4)uVar17;
  iVar15 = 0;
  if ((int)uRam0213f440 < (int)(uVar2 & 0x7fffffff)) {
    uVar2 = uVar2 + (0x100000 >> (iRam0213f438 + ((int)(uVar2 & 0x7fffffff) >> 0x14) + 1U & 0xff));
    uVar12 = iRam0213f438 + ((int)(uVar2 & 0x7fffffff) >> 0x14);
    MKDS_SLICE_4(uStack_50,4) = uVar2 & ~((int)uRam0213f474 >> (uVar12 & 0xff));
    MKDS_SLICE_4(uStack_50,0) = 0;
    iVar15 = (int)(uVar2 & uRam0213f474 | 0x100000) >> (0x14 - uVar12 & 0xff);
    if (lVar16 < 0) {
      iVar15 = -iVar15;
    }
    uVar18 = uVar17;
    uVar17 = func_02130ccc((undefined4)uStack_68,MKDS_SLICE_4(uStack_68,4),0,MKDS_SLICE_4(uStack_50,4));
    uStack_68 = uVar18;
  }
  MKDS_SLICE_4(uStack_68,4) = (undefined4)((ulonglong)uVar17 >> 0x20);
  MKDS_SLICE_4(uStack_68,0) = (undefined4)uVar17;
  func_0212f884(uVar6,uVar7,(undefined4)uStack_68,MKDS_SLICE_4(uStack_68,4));
  uStack_68 = uVar17;
  MKDS_SLICE_4(uStack_50,0) = 0;
  MKDS_SLICE_4(uStack_50,4) = extraout_r1_03;
  uVar17 = func_02130380(0,uRam0213f4f4,0,extraout_r1_03);
  uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar18 = func_02130ccc(0,extraout_r1_03,(undefined4)uStack_68,MKDS_SLICE_4(uStack_68,4));
  uVar18 = func_02130ccc(uVar6,uVar7,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_02130380(uRam0213f4f8,uRam0213f4fc,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar19 = func_02130380(uRam0213f500,uRam0213f504,0,extraout_r1_03);
  uVar18 = func_0212f884((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                         (int)((ulonglong)uVar19 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uVar19 = func_0212f884((int)uVar17,uVar5,(int)uVar18,uVar6);
  uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
  uVar3 = (undefined4)uVar19;
  uStack_78 = uVar19;
  uVar17 = func_02130ccc(uVar3,uVar7,(int)uVar17,uVar5);
  uVar17 = func_02130ccc((int)uVar18,uVar6,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uStack_50 = func_02130380(uVar3,uVar7,uVar3,uVar7);
  uVar8 = (undefined4)((ulonglong)uStack_50 >> 0x20);
  uVar5 = (undefined4)uStack_50;
  uVar18 = func_02130380(uRam0213f508,uRam0213f50c,uVar5,uVar8);
  uVar18 = func_0212f884(uRam0213f510,uRam0213f514,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_02130380(uVar5,uVar8,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_0212f884(uRam0213f518,uRam0213f51c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_02130380(uVar5,uVar8,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_0212f884(uRam0213f520,uRam0213f524,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_02130380(uVar5,uVar8,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_0212f884(uRam0213f528,uRam0213f52c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar18 = func_02130380(uVar5,uVar8,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uStack_58 = func_02130ccc(uVar3,uVar7,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  uVar8 = (undefined4)((ulonglong)uStack_58 >> 0x20);
  uVar5 = (undefined4)uStack_58;
  uVar18 = func_02130380(uVar3,uVar7,uVar5,uVar8);
  uVar19 = func_02130ccc(uVar5,uVar8,0,0x40000000);
  uVar18 = FUN_021334a0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                        (int)((ulonglong)uVar19 >> 0x20));
  uVar19 = func_02130380(uVar3,uVar7,(int)uVar17,uVar6);
  uVar17 = func_0212f884((int)uVar17,uVar6,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  uVar17 = func_02130ccc((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                         (int)((ulonglong)uVar17 >> 0x20));
  uVar17 = func_02130ccc((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar3,uVar7);
  uVar18 = func_02130ccc(0,uRam0213f42c,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
  iVar13 = (int)((ulonglong)uVar18 >> 0x20);
  iVar4 = iVar13 + iVar15 * 0x100000 >> 0x14;
  uVar17 = uVar18;
  if (0 < iVar4) {
    uVar17 = CONCAT44(&uStack_78,MKDS_SLICE_4(uStack_78,4));
  }
  iVar11 = (int)((ulonglong)uVar17 >> 0x20);
  if (iVar4 < 1) {
    uStack_78 = uVar18;
    uVar17 = Maybe_helper_134ae8((int)uVar17,iVar11,iVar15);
  }
  else {
    MKDS_SLICE_4(uStack_78,4) = iVar13;
    *(int *)(iVar11 + 4) = (int)uVar17 + iVar15 * 0x100000;
    uVar17 = CONCAT44(MKDS_SLICE_4(uStack_78,4),(int)uVar18);
  }
  MKDS_SLICE_4(uStack_78,4) = (int)((ulonglong)uVar17 >> 0x20);
  MKDS_SLICE_4(uStack_78,0) = (undefined4)uVar17;
  lVar16 = func_02130380(0,uVar10,(undefined4)uStack_78,MKDS_SLICE_4(uStack_78,4));
  uStack_78 = uVar17;
  return lVar16;
}

