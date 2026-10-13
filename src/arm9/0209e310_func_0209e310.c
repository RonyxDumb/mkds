/* Decompiled C draft; module arm9; ROM address 0209e310. No matching claim. */
#include "types.h"
#include "deps/0209e310_func_0209e310.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0209e310(uint param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  longlong lVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iStack_3c;
  int iStack_30;
  int iStack_2c;
  uint uVar19;
  
  if (param_1 == 0) {
    return;
  }
  iStack_3c = 0;
  iStack_2c = 0;
  iStack_30 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iStack_3c) {
      return;
    }
    uVar14 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iStack_3c * 4;
    uVar2 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    uVar14 = uVar14 >> uVar2 * 8 | uVar14 << uVar2 * -8 + 0x20;
    if (uVar14 == 0) break;
    uVar2 = uVar14 + 0x9c & 3;
    uVar6 = *(uint *)(uVar14 + 0x9c & 0xfffffffc);
    iVar7 = (int)*(short *)((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0x2a);
    if (iVar7 < 1) {
      uVar8 = FUN_02132440(iVar7 << 0xc);
      func_021329f8(uVar8,0x3f000000);
    }
    else {
      uVar8 = FUN_02132440(iVar7 << 0xc);
      func_02131234(0x3f000000,uVar8);
    }
    uVar8 = func_021322c8();
    *(undefined4 *)(uVar14 + 0xac) = uVar8;
    uVar2 = uVar14 + 0x9c & 3;
    uVar6 = *(uint *)(uVar14 + 0x9c & 0xfffffffc);
    sVar3 = *(short *)((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0x2c);
    lVar4 = (longlong)iRam0209e504 * (longlong)(sVar3 * 0x16c);
    *(short *)(uVar14 + 0xb0) = (short)(int)(lVar4 >> 0x25) - (sVar3 >> 0xf);
    uVar5 = _s32_div_f(0x10000,*(undefined2 *)(uVar14 + 0xa0),(int)lVar4);
    *(undefined2 *)(uVar14 + 0xa4) = uVar5;
    uVar2 = uVar14 + 0xac & 3;
    uVar6 = *(uint *)(uVar14 + 0xac & 0xfffffffc);
    uVar8 = _s32_div_f(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20,
                       *(undefined2 *)(uVar14 + 0xa2));
    *(undefined4 *)(uVar14 + 0xa8) = uVar8;
    piVar9 = (int *)func_020d22d0();
    uVar2 = (uint)(piVar9 + 2) & 3;
    uVar6 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
    uVar15 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    uVar11 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
             *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
    uVar2 = (uint)(piVar9 + 1) & 3;
    uVar10 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
    lVar4 = (ulonglong)uVar11 * (ulonglong)uVar15;
    uVar17 = (uint)lVar4;
    uVar6 = (uint)(piVar9 + 3) & 3;
    uVar12 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
    uVar1 = (uint)(piVar9 + 4) & 3;
    uVar18 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
    uVar19 = uVar18 >> uVar1 * 8 | uVar18 << uVar1 * -8 + 0x20;
    uVar1 = (uint)(piVar9 + 5) & 3;
    uVar18 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
    *piVar9 = uVar19 + uVar17;
    piVar9[1] = (uVar18 >> uVar1 * 8 | uVar18 << uVar1 * -8 + 0x20) +
                (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * uVar11 +
                uVar15 * (uVar10 >> uVar2 * 8 | uVar10 << uVar2 * -8 + 0x20) +
                (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar19,uVar17);
    uVar2 = (uint)(piVar9 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
    *(ushort *)(uVar14 + 0xc2) =
         (ushort)((uVar6 >> uVar2 * 8) >> 0x10) | (ushort)((uVar6 << uVar2 * -8 + 0x20) >> 0x10);
    iVar7 = iStack_30;
    if (*(short *)(uVar14 + 0xa2) != 0) {
      do {
        if (*(short *)(uVar14 + 0xa0) != 0) {
          iVar13 = uVar14 + iVar7 * 0x10;
          iVar16 = iStack_2c;
          do {
            piVar9 = (int *)func_020d22d0();
            uVar2 = (uint)(piVar9 + 2) & 3;
            uVar6 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
            uVar19 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
            uVar11 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                     *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
            uVar2 = (uint)(piVar9 + 4) & 3;
            uVar6 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
            uVar17 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
            uVar2 = (uint)(piVar9 + 5) & 3;
            uVar15 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
            uVar6 = (uint)(piVar9 + 3) & 3;
            uVar18 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
            uVar1 = (uint)(piVar9 + 1) & 3;
            uVar10 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
            iVar16 = iVar16 + 1;
            lVar4 = (ulonglong)uVar11 * (ulonglong)uVar19;
            uVar12 = (uint)lVar4;
            *piVar9 = uVar17 + uVar12;
            piVar9[1] = (uVar15 >> uVar2 * 8 | uVar15 << uVar2 * -8 + 0x20) +
                        (uVar18 >> uVar6 * 8 | uVar18 << uVar6 * -8 + 0x20) * uVar11 +
                        uVar19 * (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) +
                        (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar17,uVar12);
            uVar2 = (uint)(piVar9 + 1) & 3;
            uVar6 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
            *(ushort *)(iVar13 + 0xd2) =
                 (ushort)((uVar6 >> uVar2 * 8) >> 0x10) |
                 (ushort)((uVar6 << uVar2 * -8 + 0x20) >> 0x10);
            iVar13 = iVar13 + 0x140;
          } while (iVar16 < (int)(uint)*(ushort *)(uVar14 + 0xa0));
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)(uint)*(ushort *)(uVar14 + 0xa2));
    }
    iStack_3c = iStack_3c + 1;
  }
  return;
}

