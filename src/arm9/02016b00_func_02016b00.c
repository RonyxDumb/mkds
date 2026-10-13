/* Decompiled C draft; module arm9; ROM address 02016b00. No matching claim. */
#include "types.h"
#include "deps/02016b00_func_02016b00.h"

undefined4 func_02016b00(uint *param_1,uint *param_2,uint *param_3,uint param_4,uint param_5)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_r6;
  uint unaff_r7;
  uint uVar5;
  uint unaff_r8;
  uint *puVar6;
  uint uVar7;
  
  piVar1 = (int *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                  *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  piVar3 = (int *)0x0;
  piVar4 = piVar3;
  if (piVar1 != (int *)0x0) {
    do {
      if (param_5 < 2) {
        unaff_r8 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
                   *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
        unaff_r6 = piVar3;
        unaff_r7 = param_4;
      }
      else {
        uVar5 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
                *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
        unaff_r8 = ~(param_5 - 1) & uVar5 + (param_5 - 1);
        unaff_r6 = (int *)(unaff_r8 - uVar5);
        unaff_r7 = param_4 + (int)unaff_r6;
      }
      uVar5 = (uint)(piVar1 + 1) & 3;
      uVar7 = *(uint *)((uint)(piVar1 + 1) & 0xfffffffc);
      piVar4 = piVar1;
    } while (((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) < unaff_r7) &&
            (uVar5 = (uint)(piVar1 + 3) & 3, uVar7 = *(uint *)((uint)(piVar1 + 3) & 0xfffffffc),
            piVar1 = (int *)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20), piVar4 = piVar3,
            piVar1 != (int *)0x0));
  }
  if (piVar4 != (int *)0x0) {
    if (unaff_r6 != (int *)0x0) {
      puVar6 = (uint *)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                       *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20);
      if (puVar6 == (uint *)0x0) goto LAB_02016c34;
      uVar5 = (uint)(puVar6 + 3) & 3;
      uVar7 = *(uint *)((uint)(puVar6 + 3) & 0xfffffffc);
      *param_2 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
      *puVar6 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
                *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
      puVar6[1] = (uint)unaff_r6;
      puVar6[2] = 0;
      puVar6[3] = 0;
      uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
      if (uVar5 != 0) {
        *(uint **)(uVar5 + 8) = puVar6;
      }
      puVar6[3] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                  *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
      puVar6[2] = 0;
      *param_1 = (uint)puVar6;
    }
    uVar5 = (uint)(piVar4 + 1) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    piVar4[1] = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) - unaff_r7;
    *piVar4 = (*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
              *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20) + unaff_r7;
    uVar5 = (uint)(piVar4 + 1) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    if (uVar7 >> uVar5 * 8 == 0 && uVar7 << uVar5 * -8 + 0x20 == 0) {
      uVar5 = (uint)(piVar4 + 2) & 3;
      uVar7 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
      uVar2 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
      uVar5 = (uint)(piVar4 + 3) & 3;
      uVar7 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
      uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
      if (uVar2 == 0) {
        *param_1 = uVar5;
      }
      else {
        *(uint *)(uVar2 + 0xc) = uVar5;
      }
      if (uVar5 != 0) {
        *(uint *)(uVar5 + 8) = uVar2;
      }
      uVar5 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
              *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      if (uVar5 != 0) {
        *(int **)(uVar5 + 8) = piVar4;
      }
      piVar4[3] = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                  *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      piVar4[2] = 0;
      *param_2 = (uint)piVar4;
    }
    *param_3 = unaff_r8;
    return 1;
  }
LAB_02016c34:
  *param_3 = 0;
  return 0;
}

