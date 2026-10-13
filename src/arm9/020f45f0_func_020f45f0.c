/* Decompiled C draft; module arm9; ROM address 020f45f0. No matching claim. */
#include "types.h"
#include "deps/020f45f0_func_020f45f0.h"

void func_020f45f0(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  int iVar8;
  uint uVar5;
  uint uVar7;
  
  uVar4 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) * 0x1c +
          (*(uint *)(uRam020f470c & 0xfffffffc) >> (uRam020f470c & 3) * 8 |
          *(uint *)(uRam020f470c & 0xfffffffc) << (uRam020f470c & 3) * -8 + 0x20) + 8;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  uVar4 = (*(uint *)(uRam020f4710 & 0xfffffffc) >> (uRam020f4710 & 3) * 8 |
          *(uint *)(uRam020f4710 & 0xfffffffc) << (uRam020f4710 & 3) * -8 + 0x20) + 8;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) == 5) &&
      (uVar4 = (uint)(param_1 + 9) & 3, uVar1 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc),
      uVar7 = (uint)(param_1 + 2) & 3, uVar6 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
      uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,
      uVar1 >> uVar4 * 8 == 0 && uVar1 << uVar4 * -8 + 0x20 == 0)) && (iVar8 = 0, 0 < (int)uVar7)) {
    do {
      func_020fe828(uVar5);
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)uVar7);
  }
  uVar7 = uRam020f4714;
  uVar4 = (uint)(param_1 + 8) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  if (uVar1 >> uVar4 * 8 == 0 && uVar1 << uVar4 * -8 + 0x20 == 0) {
    if (param_2 == 0) {
      uVar7 = (uint)(param_1 + 2) & 3;
      uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      iVar8 = uVar5 * 0x44 +
              (*(uint *)(uRam020f4714 & 0xfffffffc) >> (uRam020f4714 & 3) * 8 |
              *(uint *)(uRam020f4714 & 0xfffffffc) << (uRam020f4714 & 3) * -8 + 0x20);
      uVar4 = iVar8 + 0x1c;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(iVar8 + 0x1c) =
           (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) -
           (uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20);
    }
  }
  else {
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    iVar8 = 0;
    if (0 < (int)uVar4) {
      do {
        uVar5 = (uint)(param_1 + iVar8 + 5) & 3;
        uVar1 = *(uint *)((uint)(param_1 + iVar8 + 5) & 0xfffffffc);
        uVar6 = uVar7 & 3;
        uVar2 = *(uint *)(uVar7 & 0xfffffffc);
        uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 0x44;
        uVar1 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        func_020f0f70((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * 0x44 +
                      (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20));
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar4);
    }
  }
  *param_1 = 0x13;
  param_1[2] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  iVar8 = 0;
  do {
    iVar3 = iVar8 + 1;
    param_1[iVar8 + 5] = 0;
    iVar8 = iVar3;
  } while (iVar3 < 3);
  return;
}

