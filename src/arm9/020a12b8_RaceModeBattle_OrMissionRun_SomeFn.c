/* Decompiled C draft; module arm9; ROM address 020a12b8. No matching claim. */
#include "types.h"
#include "deps/020a12b8_RaceModeBattle_OrMissionRun_SomeFn.h"

void RaceModeBattle_OrMissionRun_SomeFn(void)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar8;
  uint uVar18;
  
  iVar3 = iRam020a151c;
  uVar10 = uRam020a1518;
  uVar5 = uRam020a1514;
  uVar2 = uRam020a1510;
  uVar11 = *(uint *)(uRam020a1510 & 0xfffffffc) >> (uRam020a1510 & 3) * 8 |
           *(uint *)(uRam020a1510 & 0xfffffffc) << (uRam020a1510 & 3) * -8 + 0x20;
  uVar8 = uVar11 + 0x3b4 & 3;
  uVar7 = *(uint *)(uVar11 + 0x3b4 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if (-1 < (int)uVar8) {
    return;
  }
  uVar6 = *(uint *)(uRam020a1514 & 0xfffffffc) >> (uRam020a1514 & 3) * 8 |
          *(uint *)(uRam020a1514 & 0xfffffffc) << (uRam020a1514 & 3) * -8 + 0x20;
  uVar7 = uVar6 + 8 & 3;
  uVar4 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  if (uVar7 != 2) {
    if (uVar7 != 4) {
      return;
    }
    uVar8 = 7;
    do {
      uVar7 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar10 = 0;
      uVar11 = uVar7;
      do {
        if ((uVar8 & 0xffff) == (uint)*(ushort *)(uVar11 + 0x48)) {
          uVar10 = uVar10 & 0xffff;
          goto LAB_020a14dc;
        }
        uVar10 = uVar10 + 1;
        uVar11 = uVar11 + 0x70;
      } while ((int)uVar10 < 8);
      uVar10 = 0;
LAB_020a14dc:
      uVar11 = uVar5 & 3;
      uVar4 = *(uint *)(uVar5 & 0xfffffffc);
      if ((uVar10 != (int)*(char *)((uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) + 0x62)) &&
         (uVar7 = uVar7 + 0x3b4, uVar10 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
         (int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) < 0)) {
        func_020a16d0();
      }
      uVar8 = uVar8 - 1;
      if ((int)uVar8 < 0) {
        return;
      }
    } while( true );
  }
  uVar5 = uVar6 + 0x18 & 3;
  uVar7 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar7 = (uint)*(byte *)(uVar6 + 0x3d0);
  if (uVar5 == 0) {
    if (-1 < (int)uVar8) {
      return;
    }
    do {
      uVar8 = uVar10 & 3;
      uVar5 = *(uint *)(uVar10 & 0xfffffffc);
      piVar9 = (int *)((uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + iVar3);
      if (uVar7 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = (uint)(piVar9 + 2) & 3;
        uVar5 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
        uVar16 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
        uVar15 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                 *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
        uVar8 = (uint)(piVar9 + 1) & 3;
        uVar12 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar15 * (ulonglong)uVar16;
        uVar6 = (uint)lVar1;
        uVar5 = (uint)(piVar9 + 3) & 3;
        uVar13 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
        uVar4 = (uint)(piVar9 + 4) & 3;
        uVar17 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
        uVar18 = uVar17 >> uVar4 * 8 | uVar17 << uVar4 * -8 + 0x20;
        uVar4 = (uint)(piVar9 + 5) & 3;
        uVar17 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
        *piVar9 = uVar18 + uVar6;
        piVar9[1] = (uVar17 >> uVar4 * 8 | uVar17 << uVar4 * -8 + 0x20) +
                    (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) * uVar15 +
                    uVar16 * (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20) +
                    (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar18,uVar6);
        if (uVar7 == 0) {
          uVar8 = (uint)(piVar9 + 1) & 3;
          uVar5 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
          uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
        }
        else {
          uVar8 = (uint)(piVar9 + 1) & 3;
          uVar5 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
          uVar8 = (uint)((ulonglong)uVar7 *
                         (ulonglong)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) >> 0x20);
        }
      }
      iVar14 = (uVar8 & 0xffff) * 0x70;
      uVar8 = uVar11 + iVar14 + 8;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      if (uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0) {
        func_020a16d0();
        *(undefined4 *)
         ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar14 + 8) = 2;
      }
      uVar11 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
               *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar8 = uVar11 + 0x3b4 & 3;
      uVar5 = *(uint *)(uVar11 + 0x3b4 & 0xfffffffc);
    } while ((int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) < 0);
    return;
  }
  if (uVar5 != 1) {
    return;
  }
  uVar7 = uVar7 - 1;
  if ((int)uVar7 < 0) {
    return;
  }
  do {
    uVar10 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    uVar8 = uVar10 + 0x3b4 & 3;
    uVar5 = *(uint *)(uVar10 + 0x3b4 & 0xfffffffc);
    if ((int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) < 0) {
      uVar8 = 0;
      uVar5 = uVar10;
      do {
        if ((uVar7 & 0xffff) == (uint)*(ushort *)(uVar5 + 0x48)) {
          uVar8 = uVar8 & 0xffff;
          goto LAB_020a1450;
        }
        uVar8 = uVar8 + 1;
        uVar5 = uVar5 + 0x70;
      } while ((int)uVar8 < 8);
      uVar8 = 0;
LAB_020a1450:
      uVar5 = uVar10 + uVar8 * 0x70 + 8;
      uVar10 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if (uVar5 >> uVar10 * 8 == 0 && uVar5 << uVar10 * -8 + 0x20 == 0) {
        func_020a16d0();
        *(undefined4 *)
         ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + uVar8 * 0x70 + 8) = 2;
      }
    }
    uVar7 = uVar7 - 1;
    if ((int)uVar7 < 0) {
      return;
    }
  } while( true );
}

