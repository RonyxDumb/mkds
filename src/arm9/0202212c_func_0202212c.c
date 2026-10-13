/* Decompiled C draft; module arm9; ROM address 0202212c. No matching claim. */
#include "types.h"
#include "deps/0202212c_func_0202212c.h"

code * func_0202212c(int *param_1,int param_2)

{
  ushort *puVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  code *pcVar8;
  code *pcVar9;
  ushort *puVar10;
  uint uVar11;
  int *piVar12;
  code *pcVar13;
  code *pcVar14;
  
  uVar7 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  pcVar13 = (code *)0x0;
  if ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 1) {
    uVar7 = (uint)(param_1 + 4) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    pcVar9 = (code *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
    lVar2 = (longlong)(int)pcVar9 * (longlong)param_2 + 0x800;
    iVar4 = abs((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000);
    uVar7 = (uint)(param_1 + 3) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    piVar12 = param_1 + 3;
    param_1[3] = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar4;
    pcVar14 = pcVar13;
    while( true ) {
      uVar7 = (uint)(param_1 + 2) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      pcVar8 = pcVar13;
      if ((uVar3 >> uVar7 * 8 != 0 || uVar3 << uVar7 * -8 + 0x20 != 0) &&
         (uVar7 = (uint)(param_1 + 3) & 3, uVar3 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc),
         uVar3 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,
         uVar7 = (uint)*(ushort *)
                        ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
                        4), (int)(uVar3 + uVar7 * -0x1000) < 0 == SBORROW4(uVar3,uVar7 * 0x1000))) {
        pcVar8 = (code *)0x1;
      }
      if (pcVar8 == (code *)0x0) break;
      pcVar8 = (code *)(*(uint *)((uint)piVar12 & 0xfffffffc) >> ((uint)piVar12 & 3) * 8 |
                       *(uint *)((uint)piVar12 & 0xfffffffc) << ((uint)piVar12 & 3) * -8 + 0x20);
      pcVar14 = (code *)0x1;
      *piVar12 = (int)(pcVar8 + (uint)*(ushort *)
                                       ((*(uint *)((uint)param_1 & 0xfffffffc) >>
                                         ((uint)param_1 & 3) * 8 |
                                        *(uint *)((uint)param_1 & 0xfffffffc) <<
                                        ((uint)param_1 & 3) * -8 + 0x20) + 4) * -0x1000);
      uVar7 = (uint)(param_1 + 4) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
      uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      if (0 < (int)uVar7) {
        pcVar8 = (code *)0x1;
      }
      uVar3 = (uint)(param_1 + 1) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      if ((int)uVar7 < 1) {
        pcVar8 = pcVar13;
      }
      if (pcVar8 == (code *)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20)) {
        *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) - 8;
      }
      else {
        *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 8;
      }
      uVar7 = (uint)(param_1 + 4) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
      uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
      pcVar8 = (code *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
      if (0 < (int)uVar7) {
        pcVar9 = (code *)0x1;
      }
      uVar3 = (uint)(param_1 + 1) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
      if ((int)uVar7 < 1) {
        pcVar9 = pcVar13;
      }
      if (pcVar9 == (code *)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20)) {
        uVar7 = (uint)(param_1 + 6) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
        uVar5 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
        uVar7 = uVar5 + 0xc;
        uVar3 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        pcVar9 = (code *)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
        pcVar6 = pcVar13;
        if (pcVar8 <= pcVar9 + (uint)*(ushort *)(uVar5 + 2) * 8 + -8) {
          pcVar6 = (code *)0x1;
        }
      }
      else {
        uVar7 = (uint)(param_1 + 6) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
        puVar10 = (ushort *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
        puVar1 = puVar10 + 6;
        uVar7 = (uint)puVar1 & 3;
        uVar3 = *(uint *)((uint)puVar1 & 0xfffffffc);
        pcVar9 = (code *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
        pcVar6 = (code *)(uint)(pcVar9 + (uint)*puVar10 * 8 <= pcVar8);
      }
      if (pcVar6 != (code *)0x0) {
        func_02022310(param_1);
      }
      uVar7 = (uint)(param_1 + 7) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
      if (uVar3 >> uVar7 * 8 != 0 || uVar3 << uVar7 * -8 + 0x20 != 0) {
        uVar7 = (uint)(param_1 + 6) & 3;
        uVar5 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
        uVar3 = (uint)(param_1 + 7) & 3;
        uVar11 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
        pcVar9 = (code *)(uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20);
        uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0xc;
        uVar3 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        if (pcVar9 == (code *)0x2) {
          if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) -
              (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20)) * 0x2000 >> 0x10 ==
              (uint)*(ushort *)(param_1 + 10)) {
            uVar7 = (uint)(param_1 + 8) & 3;
            uVar5 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
            uVar3 = (uint)(param_1 + 9) & 3;
            uVar11 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
            pcVar9 = (code *)(uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20);
            (*pcVar9)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
          }
        }
        else if (pcVar9 == (code *)0x3) {
          uVar7 = (uint)(param_1 + 8) & 3;
          uVar5 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
          uVar3 = (uint)(param_1 + 9) & 3;
          uVar11 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
          pcVar9 = (code *)(uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20);
          (*pcVar9)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
        }
      }
    }
    return pcVar14;
  }
  return (code *)0x0;
}

