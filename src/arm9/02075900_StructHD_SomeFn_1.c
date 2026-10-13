/* Decompiled C draft; module arm9; ROM address 02075900. No matching claim. */
#include "types.h"
#include "deps/02075900_StructHD_SomeFn_1.h"

void StructHD_SomeFn_1(int param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar7;
  
  uVar3 = param_1 + 0x218U & 3;
  uVar6 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  puVar7 = (undefined4 *)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
  switch(*(undefined2 *)((int)puVar7 + 0x3e)) {
  case 0:
    uVar5 = puVar7[1];
    uVar8 = puVar7[2];
    *(undefined4 *)(param_1 + 0x24) = *puVar7;
    *(undefined4 *)(param_1 + 0x28) = uVar5;
    *(undefined4 *)(param_1 + 0x2c) = uVar8;
    uVar3 = (*(uint *)(DAT_02075a90 & 0xfffffffc) >> (DAT_02075a90 & 3) * 8 |
            *(uint *)(DAT_02075a90 & 0xfffffffc) << (DAT_02075a90 & 3) * -8 + 0x20) + 0xc;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) == 5) {
      uVar3 = param_1 + 0x218U & 3;
      uVar6 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
      uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + 0x2c;
      uVar6 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(short *)(param_1 + 0x210) =
           (short)((int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) >> 0xc) + -1;
      GetDriverMaybeSfxPosition((undefined4 *)(uintptr_t)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x210));
      uVar3 = param_1 + 0x218U & 3;
      uVar9 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
      uVar6 = param_1 + 0x1cU & 3;
      uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      uVar3 = (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + 0x1c;
      uVar9 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) =
           (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
           (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
    }
    else {
      GetDriverMaybeSfxPosition((undefined4 *)(uintptr_t)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x210));
      uVar3 = param_1 + 0x1cU & 3;
      uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + 0x6000;
    }
    StructHD_SomeLookAt((undefined4 *)(uintptr_t)(param_1));
    break;
  case 1:
    StructHD_SomeFn_3();
    break;
  case 2:
    uVar5 = puVar7[1];
    uVar8 = puVar7[2];
    *(undefined4 *)(param_1 + 0x24) = *puVar7;
    *(undefined4 *)(param_1 + 0x28) = uVar5;
    *(undefined4 *)(param_1 + 0x2c) = uVar8;
    StructHD_SomeFn_8(param_1);
    StructHD_SomeFn_10((undefined4 *)(uintptr_t)(param_1));
    break;
  case 3:
    StructHD_SomeFn_9();
    break;
  case 4:
    break;
  case 5:
    goto LAB_020759c8;
  case 6:
LAB_020759c8:
    StructHD_SomeFn_12();
  }
  uVar3 = param_1 + 0x218U & 3;
  uVar6 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  if (*(short *)(uVar3 + 0x3c) != 0) {
    sVar1 = *(short *)(uVar3 + 0x34);
    sVar2 = *(short *)(uVar3 + 0x3a);
    uVar6 = param_1 + 0x240U & 3;
    uVar9 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
    uVar6 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
    *(short *)(param_1 + 0x68) =
         *(short *)(uVar3 + 0x32) +
         (short)(((int)*(short *)(uVar3 + 0x38) - (int)*(short *)(uVar3 + 0x32)) * uVar6 >> 0xc);
    *(short *)(param_1 + 0x6a) = sVar1 + (short)(((int)sVar2 - (int)sVar1) * uVar6 >> 0xc);
    uVar6 = param_1 + 0x240U & 3;
    uVar9 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
    *(uint *)(param_1 + 0x240) =
         (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + (int)*(short *)(uVar3 + 0x3c);
    uVar3 = param_1 + 0x240U & 3;
    uVar6 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
    if (0x1000 < (int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x240) = 0x1000;
    }
    return;
  }
  *(undefined2 *)(param_1 + 0x68) = *(undefined2 *)(uVar3 + 0x32);
  *(undefined2 *)(param_1 + 0x6a) = *(undefined2 *)(uVar3 + 0x34);
  return;
}

