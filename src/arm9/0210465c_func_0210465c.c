/* Decompiled C draft; module arm9; ROM address 0210465c. No matching claim. */
#include "types.h"
#include "deps/0210465c_func_0210465c.h"

void func_0210465c(uint param_1)

{
  undefined2 uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  bool bVar22;
  uint uVar15;
  
  iVar17 = param_1 + 0x10;
  iVar16 = (*(uint *)(uRam02104944 & 0xfffffffc) >> (uRam02104944 & 3) * 8 |
           *(uint *)(uRam02104944 & 0xfffffffc) << (uRam02104944 & 3) * -8 + 0x20) -
           (*(uint *)(uRam02104948 & 0xfffffffc) >> (uRam02104948 & 3) * 8 |
           *(uint *)(uRam02104948 & 0xfffffffc) << (uRam02104948 & 3) * -8 + 0x20);
  if (iVar16 < 0) {
    iVar16 = 0;
    do {
      iVar17 = param_1 + iVar16 * 4;
      iVar16 = iVar16 + 1;
      *(short *)(iVar17 + 2) = *(short *)(iVar17 + 2) + -2;
    } while (iVar16 < 4);
    return;
  }
  if (((iVar16 == 0) &&
      (*(uint *)(uRam0210494c & 0xfffffffc) >> (uRam0210494c & 3) * 8 == 0 &&
       *(uint *)(uRam0210494c & 0xfffffffc) << (uRam0210494c & 3) * -8 + 0x20 == 0)) &&
     (param_1 ==
      (*(uint *)(uRam02104950 & 0xfffffffc) >> (uRam02104950 & 3) * 8 |
      *(uint *)(uRam02104950 & 0xfffffffc) << (uRam02104950 & 3) * -8 + 0x20))) {
    uVar4 = func_02108e6c(6);
    func_0212c6f0(uVar4,1);
    if ((((*(uint *)(uRam02104954 & 0xfffffffc) >> (uRam02104954 & 3) * 8 |
          *(uint *)(uRam02104954 & 0xfffffffc) << (uRam02104954 & 3) * -8 + 0x20) & 1) != 0) &&
       (uVar6 = iRam02104958 + 0xcU & 3, uVar5 = *(uint *)(iRam02104958 + 0xcU & 0xfffffffc),
       uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0)) {
      if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar4,0);
      }
      if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar4,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar4,0,0xef);
    }
  }
  iVar21 = iRam02104964;
  iVar19 = iRam02104960;
  iVar3 = iRam0210495c;
  uVar4 = param_1 + 0x28 & 3;
  uVar6 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
  uVar1 = (undefined2)iRam0210495c;
  if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) {
    uVar4 = 0;
    do {
      iVar19 = (int)*(short *)(iVar17 + uVar4 * 4 + 2);
      iVar21 = (int)*(short *)(iVar17 + uVar4 * 4);
      if (iVar19 < 0) {
        iVar19 = iVar19 * iVar19;
        iVar21 = iVar21 * iVar21;
        bVar22 = iVar19 - iVar21 != 0;
        iVar10 = iVar21;
        if (bVar22 && iVar21 <= iVar19) {
          iVar10 = 7;
        }
        uVar6 = param_1 + 0x30 & 3;
        uVar5 = *(uint *)(param_1 + 0x30 & 0xfffffffc);
        if (!bVar22 || iVar19 < iVar21) {
          iVar10 = 5;
        }
        if (uVar4 == (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
          iVar10 = iVar10 * 3 + (iVar10 * iVar16 >> 9);
        }
      }
      else if (iVar19 * iVar19 - iVar21 * iVar21 == 0 || iVar19 * iVar19 < iVar21 * iVar21) {
        iVar10 = 3;
      }
      else {
        iVar10 = 2;
      }
      iVar19 = param_1 + uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(short *)(iVar19 + 2) =
           *(short *)(iVar19 + 2) - ((short)iVar10 + (short)((uint)(iVar10 * iVar16) >> 8));
      if (*(short *)(iVar19 + 2) < iVar3) {
        *(undefined2 *)(iVar19 + 2) = uVar1;
      }
    } while ((int)uVar4 < 4);
  }
  else {
    iVar16 = 0;
    do {
      iVar10 = iVar16 * 4;
      iVar12 = param_1 + iVar16 * 4;
      iVar7 = iVar17 + iVar16 * 4;
      *(short *)(param_1 + iVar10) = *(short *)(param_1 + iVar10) + *(short *)(iVar17 + iVar10);
      *(short *)(iVar12 + 2) = *(short *)(iVar12 + 2) + *(short *)(iVar7 + 2);
      *(short *)(iVar17 + iVar10) = (short)((uint)(iVar21 * *(short *)(iVar17 + iVar10)) >> 0xc);
      *(short *)(iVar7 + 2) = (short)((uint)(iVar21 * *(short *)(iVar7 + 2)) >> 0xc);
      if (iVar19 < *(short *)(param_1 + iVar10)) {
        *(short *)(param_1 + iVar10) = (short)iVar19;
      }
      else if (*(short *)(param_1 + iVar10) < iVar3) {
        *(undefined2 *)(param_1 + iVar10) = uVar1;
      }
      iVar10 = param_1 + iVar16 * 4;
      if (iVar19 < *(short *)(iVar10 + 2)) {
        *(short *)(iVar10 + 2) = (short)iVar19;
      }
      else if (*(short *)(iVar10 + 2) < iVar3) {
        *(undefined2 *)(iVar10 + 2) = uVar1;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < 4);
  }
  uVar4 = param_1 + 0x2c & 3;
  uVar6 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) - 1;
  uVar4 = param_1 + 0x2c & 3;
  uVar6 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xf) == 0) {
    uVar20 = *(uint *)(uRam02104968 & 0xfffffffc) >> (uRam02104968 & 3) * 8 |
             *(uint *)(uRam02104968 & 0xfffffffc) << (uRam02104968 & 3) * -8 + 0x20;
    iVar16 = uVar20 + iRam0210496c;
    uVar4 = iVar16 + 8U & 3;
    uVar6 = *(uint *)(iVar16 + 8U & 0xfffffffc);
    uVar13 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    uVar4 = uVar20 + 0x498 & 3;
    uVar6 = *(uint *)(uVar20 + 0x498 & 0xfffffffc);
    uVar11 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    uVar4 = iVar16 + 4U & 3;
    uVar8 = *(uint *)(iVar16 + 4U & 0xfffffffc);
    lVar2 = (ulonglong)uVar11 * (ulonglong)uVar13;
    uVar18 = (uint)lVar2;
    uVar6 = iVar16 + 0xcU & 3;
    uVar9 = *(uint *)(iVar16 + 0xcU & 0xfffffffc);
    uVar5 = iVar16 + 0x10U & 3;
    uVar14 = *(uint *)(iVar16 + 0x10U & 0xfffffffc);
    uVar15 = uVar14 >> uVar5 * 8 | uVar14 << uVar5 * -8 + 0x20;
    uVar5 = iVar16 + 0x14U & 3;
    uVar14 = *(uint *)(iVar16 + 0x14U & 0xfffffffc);
    *(uint *)(uVar20 + 0x498) = uVar15 + uVar18;
    *(uint *)(iVar16 + 4) =
         (uVar14 >> uVar5 * 8 | uVar14 << uVar5 * -8 + 0x20) +
         (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) * uVar11 +
         uVar13 * (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
         (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar15,uVar18);
    uVar4 = iVar16 + 4U & 3;
    uVar6 = *(uint *)(iVar16 + 4U & 0xfffffffc);
    *(int *)(param_1 + 0x30) =
         (int)((ulonglong)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * 6 >> 0x20);
    return;
  }
  return;
}

