/* Decompiled C draft; module arm9; ROM address 02046024. No matching claim. */
#include "types.h"
#include "deps/02046024_func_02046024.h"

void func_02046024(int param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint extraout_r1;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int unaff_r6;
  uint uVar16;
  int unaff_r7;
  uint unaff_r8;
  int iVar17;
  uint uVar18;
  uint unaff_r9;
  uint uVar19;
  uint uVar20;
  undefined1 *puVar22;
  int unaff_r10;
  uint uVar23;
  bool bVar24;
  uint uVar21;
  
  bVar24 = false;
  CreateGlobalLU();
  uVar4 = uRam02046504;
  *(undefined1 *)
   ((*(uint *)(uRam02046504 & 0xfffffffc) >> (uRam02046504 & 3) * 8 |
    *(uint *)(uRam02046504 & 0xfffffffc) << (uRam02046504 & 3) * -8 + 0x20) + 0x3e0) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x248) = 1;
  if (param_1 == 0) {
    uVar9 = (*(uint *)(uRam02046508 & 0xfffffffc) >> (uRam02046508 & 3) * 8 |
            *(uint *)(uRam02046508 & 0xfffffffc) << (uRam02046508 & 3) * -8 + 0x20) + 0x1c;
    uVar11 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if ((int)((uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) << 0x1d) < 0) {
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 500) = 0;
    }
    else {
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 500) = 4;
    }
  }
  else {
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 500) = 0;
  }
  uVar4 = uRam02046504;
  uVar9 = 0;
  do {
    uVar11 = uVar4 & 3;
    uVar10 = *(uint *)(uVar4 & 0xfffffffc);
    uVar11 = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0x3dc;
    uVar10 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    *(undefined1 *)((uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) + uVar9) = 0;
    uVar11 = uRam02046504;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0x21);
  uVar4 = (*(uint *)(uRam02046508 & 0xfffffffc) >> (uRam02046508 & 3) * 8 |
          *(uint *)(uRam02046508 & 0xfffffffc) << (uRam02046508 & 3) * -8 + 0x20) + 0x20;
  uVar9 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  if (((uVar4 == 1) || (uVar4 == 2)) &&
     (bVar24 = (*(ushort *)
                 ((*(uint *)(uRam0204650c & 0xfffffffc) >> (uRam0204650c & 3) * 8 |
                  *(uint *)(uRam0204650c & 0xfffffffc) << (uRam0204650c & 3) * -8 + 0x20) + 0x454) &
               0x40) != 0, !bVar24)) {
    bVar24 = false;
  }
  uVar10 = *(uint *)(uRam02046504 & 0xfffffffc) >> (uRam02046504 & 3) * 8 |
           *(uint *)(uRam02046504 & 0xfffffffc) << (uRam02046504 & 3) * -8 + 0x20;
  uVar4 = uVar10 + 0x208 & 3;
  uVar9 = *(uint *)(uVar10 + 0x208 & 0xfffffffc);
  uVar4 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
  if (uVar4 != 1) {
    if (uVar4 == 2) {
      if (param_1 == 0) {
        piVar8 = (int *)func_0204aa60();
        uVar4 = uRam02046504;
        if (bVar24) {
          uVar9 = 3;
          unaff_r6 = iRam0204651c;
        }
        else {
          uVar9 = 6;
        }
        uVar11 = 0;
        if (!bVar24) {
          unaff_r6 = iRam02046520;
        }
        if (uVar9 != 0) {
          do {
            uVar12 = uVar4 & 3;
            uVar13 = *(uint *)(uVar4 & 0xfffffffc);
            uVar10 = unaff_r6 + uVar11 * 4;
            uVar15 = uVar10 & 3;
            uVar14 = *(uint *)(uVar10 & 0xfffffffc);
            uVar10 = (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) + 0x3dc;
            uVar12 = uVar10 & 3;
            uVar10 = *(uint *)(uVar10 & 0xfffffffc);
            *(byte *)((uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) + uVar11) =
                 (byte)(uVar14 >> uVar15 * 8) | (byte)(uVar14 << uVar15 * -8 + 0x20);
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar9);
        }
        uVar4 = uRam02046504;
        uVar11 = 0;
        if ((uVar9 != 0) && (uVar10 = uVar9 - 1 & 0xffff, uVar9 != 0)) {
          do {
            if (uVar10 == 0) {
              uVar15 = 0;
            }
            else {
              uVar15 = (uint)(piVar8 + 2) & 3;
              uVar12 = *(uint *)((uint)(piVar8 + 2) & 0xfffffffc);
              uVar19 = uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20;
              uVar18 = *(uint *)((uint)piVar8 & 0xfffffffc) >> ((uint)piVar8 & 3) * 8 |
                       *(uint *)((uint)piVar8 & 0xfffffffc) << ((uint)piVar8 & 3) * -8 + 0x20;
              uVar15 = (uint)(piVar8 + 1) & 3;
              uVar14 = *(uint *)((uint)(piVar8 + 1) & 0xfffffffc);
              lVar2 = (ulonglong)uVar18 * (ulonglong)uVar19;
              uVar23 = (uint)lVar2;
              uVar12 = (uint)(piVar8 + 3) & 3;
              uVar16 = *(uint *)((uint)(piVar8 + 3) & 0xfffffffc);
              uVar13 = (uint)(piVar8 + 4) & 3;
              uVar20 = *(uint *)((uint)(piVar8 + 4) & 0xfffffffc);
              uVar21 = uVar20 >> uVar13 * 8 | uVar20 << uVar13 * -8 + 0x20;
              uVar13 = (uint)(piVar8 + 5) & 3;
              uVar20 = *(uint *)((uint)(piVar8 + 5) & 0xfffffffc);
              *piVar8 = uVar21 + uVar23;
              piVar8[1] = (uVar20 >> uVar13 * 8 | uVar20 << uVar13 * -8 + 0x20) +
                          (uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) * uVar18 +
                          uVar19 * (uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) +
                          (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar21,uVar23);
              if (uVar10 == 0) {
                uVar15 = (uint)(piVar8 + 1) & 3;
                uVar12 = *(uint *)((uint)(piVar8 + 1) & 0xfffffffc);
                uVar15 = uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20;
              }
              else {
                uVar15 = (uint)(piVar8 + 1) & 3;
                uVar12 = *(uint *)((uint)(piVar8 + 1) & 0xfffffffc);
                uVar15 = (uint)((ulonglong)uVar10 *
                                (ulonglong)(uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20) >>
                               0x20);
              }
            }
            uVar12 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3dc;
            uVar13 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            uVar12 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
            uVar15 = uVar15 & 0xff;
            if ((int)uVar11 <= (int)uVar15) {
              uVar15 = uVar15 + 1 & 0xff;
            }
            uVar1 = *(undefined1 *)(uVar12 + uVar11);
            puVar22 = (undefined1 *)(uVar12 + uVar11);
            uVar11 = uVar11 + 1;
            *puVar22 = *(undefined1 *)(uVar12 + uVar15);
            uVar12 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3dc;
            uVar13 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            *(undefined1 *)((uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + uVar15) = uVar1;
          } while (uVar11 < uVar9);
        }
      }
      else {
        uVar5 = func_0204aa60();
        iVar17 = iRam02046518;
        uVar4 = 0;
        if (bVar24) {
          iVar6 = 2;
          unaff_r10 = iRam02046510;
        }
        else {
          iVar6 = 8;
        }
        uVar9 = 0;
        if (!bVar24) {
          unaff_r10 = iRam02046514;
        }
        if (iVar6 != 0) {
          do {
            iVar3 = (int)uVar9 >> 0x1f;
            uVar15 = (int)(uVar9 + ((uint)((int)uVar9 >> 1) >> 0x1e)) >> 2 & 0xff;
            uVar11 = unaff_r10 + uVar15 * 4;
            uVar10 = uVar11 & 3;
            uVar11 = *(uint *)(uVar11 & 0xfffffffc);
            iVar7 = HasSomeSecretFlag(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
            if (iVar7 != 0) {
              uVar11 = unaff_r10 + uVar15 * 4;
              uVar10 = uVar11 & 3;
              uVar11 = *(uint *)(uVar11 & 0xfffffffc);
              uVar11 = iVar17 + (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * 0x10 +
                       ((uVar9 * 0x40000000 + iVar3 >> 0x1e | iVar3 << 2) - iVar3 & 0xff) * 4;
              uVar10 = uVar11 & 3;
              uVar12 = *(uint *)(uVar11 & 0xfffffffc);
              uVar11 = (*(uint *)(uRam02046504 & 0xfffffffc) >> (uRam02046504 & 3) * 8 |
                       *(uint *)(uRam02046504 & 0xfffffffc) << (uRam02046504 & 3) * -8 + 0x20) +
                       0x3dc;
              uVar15 = uVar11 & 3;
              uVar11 = *(uint *)(uVar11 & 0xfffffffc);
              *(byte *)((uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20) + uVar4) =
                   (byte)(uVar12 >> uVar10 * 8) | (byte)(uVar12 << uVar10 * -8 + 0x20);
              uVar4 = uVar4 + 1 & 0xff;
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < (uint)(iVar6 << 2));
        }
        uVar9 = uRam02046504;
        iVar17 = 0;
        if (uVar4 != 0) {
          do {
            uVar15 = func_02046524(uVar5,uVar4 - 1 & 0xffff);
            uVar15 = uVar15 & 0xff;
            _s32_div_f(iVar17,uVar4);
            uVar12 = extraout_r1 & 0xff;
            uVar11 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                     *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x3dc;
            uVar10 = uVar11 & 3;
            uVar11 = *(uint *)(uVar11 & 0xfffffffc);
            uVar11 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
            uVar1 = *(undefined1 *)(uVar11 + uVar12);
            if (uVar12 <= uVar15) {
              uVar15 = uVar15 + 1 & 0xff;
            }
            iVar17 = iVar17 + 1;
            *(undefined1 *)(uVar11 + uVar12) = *(undefined1 *)(uVar11 + uVar15);
            uVar11 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                     *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x3dc;
            uVar10 = uVar11 & 3;
            uVar11 = *(uint *)(uVar11 & 0xfffffffc);
            *(undefined1 *)((uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) + uVar15) = uVar1;
          } while ((int)(iVar17 + uVar4 * -2) < 0 != SBORROW4(iVar17,uVar4 * 2));
        }
      }
      uVar11 = *(uint *)(uRam02046504 & 0xfffffffc) >> (uRam02046504 & 3) * 8 |
               *(uint *)(uRam02046504 & 0xfffffffc) << (uRam02046504 & 3) * -8 + 0x20;
      uVar4 = uVar11 + 0x3dc;
      uVar9 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar11 + 0x1e8) = (uint)*(byte *)(uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20);
      return;
    }
    return;
  }
  if (param_1 == 0) {
    if (bVar24) {
      uVar4 = 3;
      unaff_r7 = iRam0204651c;
    }
    else {
      uVar4 = 6;
    }
    uVar9 = uVar10 + 0x1e8 & 3;
    uVar10 = *(uint *)(uVar10 + 0x1e8 & 0xfffffffc);
    if (!bVar24) {
      unaff_r7 = iRam02046520;
    }
    uVar12 = 0;
    uVar15 = 0;
    if (uVar4 != 0) {
      do {
        uVar12 = uVar15;
        uVar15 = unaff_r7 + uVar12 * 4;
        uVar13 = uVar15 & 3;
        uVar15 = *(uint *)(uVar15 & 0xfffffffc);
        if ((uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) ==
            (uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20)) break;
        uVar15 = uVar12 + 1;
      } while (uVar12 + 1 < uVar4);
    }
    uVar9 = 0;
    if (uVar4 != 0) {
      do {
        uVar13 = uVar11 & 3;
        uVar14 = *(uint *)(uVar11 & 0xfffffffc);
        uVar10 = unaff_r7 + uVar12 * 4;
        uVar15 = uVar10 & 3;
        uVar16 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + 0x3dc;
        uVar13 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar12 = uVar12 + 1;
        *(byte *)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + uVar9) =
             (byte)(uVar16 >> uVar15 * 8) | (byte)(uVar16 << uVar15 * -8 + 0x20);
        uVar9 = uVar9 + 1;
        if (uVar4 <= uVar12) {
          uVar12 = 0;
        }
      } while (uVar9 < uVar4);
      return;
    }
    return;
  }
  if (bVar24) {
    uVar4 = 2;
    unaff_r10 = iRam02046510;
  }
  else {
    uVar4 = 8;
  }
  uVar9 = uVar10 + 0x1e8 & 3;
  uVar11 = *(uint *)(uVar10 + 0x1e8 & 0xfffffffc);
  if (!bVar24) {
    unaff_r10 = iRam02046514;
  }
  uVar10 = 0;
  if (uVar4 != 0) {
    do {
      unaff_r9 = (int)(uVar10 + ((uint)((int)uVar10 >> 1) >> 0x1e)) >> 2 & 0xff;
      iVar17 = (int)uVar10 >> 0x1f;
      uVar15 = unaff_r10 + unaff_r9 * 4;
      uVar12 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      unaff_r8 = (uVar10 * 0x40000000 + iVar17 >> 0x1e | iVar17 << 2) - iVar17 & 0xff;
      uVar15 = iRam02046518 + (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20) * 0x10 +
               unaff_r8 * 4;
      uVar12 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      if ((uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) ==
          (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20)) break;
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar4 * 4);
  }
  uVar10 = 0;
  uVar11 = 0;
  uVar9 = uVar10;
  if (uVar4 != 0) {
    do {
      uVar15 = unaff_r10 + unaff_r9 * 4;
      uVar12 = uVar15 & 3;
      uVar15 = *(uint *)(uVar15 & 0xfffffffc);
      iVar17 = HasSomeSecretFlag(uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20);
      if (iVar17 != 0) {
        uVar15 = unaff_r10 + unaff_r9 * 4;
        uVar12 = uVar15 & 3;
        uVar16 = *(uint *)(uVar15 & 0xfffffffc);
        uVar15 = (*(uint *)(uRam02046504 & 0xfffffffc) >> (uRam02046504 & 3) * 8 |
                 *(uint *)(uRam02046504 & 0xfffffffc) << (uRam02046504 & 3) * -8 + 0x20) + 0x3dc;
        uVar13 = uVar15 & 3;
        uVar14 = *(uint *)(uVar15 & 0xfffffffc);
        uVar15 = iRam02046518 + (uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) * 0x10 +
                 unaff_r8 * 4;
        uVar12 = uVar15 & 3;
        uVar15 = *(uint *)(uVar15 & 0xfffffffc);
        *(byte *)((uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) + uVar9) =
             (byte)(uVar15 >> uVar12 * 8) | (byte)(uVar15 << uVar12 * -8 + 0x20);
        uVar9 = uVar9 + 1 & 0xff;
      }
      unaff_r8 = unaff_r8 + 1 & 0xff;
      if ((3 < unaff_r8) && (unaff_r9 = unaff_r9 + 1 & 0xff, unaff_r8 = uVar10, uVar4 <= unaff_r9))
      {
        unaff_r9 = uVar10;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar4 * 4);
    return;
  }
  return;
}

