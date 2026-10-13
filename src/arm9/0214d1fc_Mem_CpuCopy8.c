/* Decompiled C draft; module arm9; ROM address 0214d1fc. No matching claim. */
#include "types.h"
#include "deps/0214d1fc_Mem_CpuCopy8.h"

void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  ushort *puVar4;
  ushort *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  
  if (param_3 == 0) {
    return;
  }
  if (((uint)param_2 & 1) != 0) {
    if (((uint)param_1 & 1) == 0) {
      uVar3 = *param_1;
    }
    else {
      uVar3 = *(ushort *)((int)param_1 + -1) >> 8;
    }
    *(ushort *)((int)param_2 + -1) = *(ushort *)((int)param_2 + -1) & 0xff | uVar3 << 8;
    param_1 = (ushort *)((int)param_1 + 1);
    param_2 = (uint *)((int)param_2 + 1);
    param_3 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
  }
  if ((((uint)param_2 ^ (uint)param_1) & 1) == 0) {
    puVar6 = param_2;
    if ((((uint)param_2 ^ (uint)param_1) & 2) == 0) {
      if (1 < param_3) {
        puVar5 = param_1;
        puVar7 = param_2;
        if (((uint)param_2 & 2) != 0) {
          puVar5 = param_1 + 1;
          puVar7 = (uint *)((int)param_2 + 2);
          *(ushort *)param_2 = *param_1;
          param_3 = param_3 - 2;
          if (param_3 == 0) {
            return;
          }
        }
        if ((param_3 & 0xfffffffc) != 0) {
          puVar8 = (uint *)((param_3 & 0xfffffffc) + (int)puVar7);
          puVar4 = puVar5;
          puVar6 = puVar7;
          do {
            puVar5 = puVar4 + 2;
            puVar7 = puVar6 + 1;
            *puVar6 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                      *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
            puVar4 = puVar5;
            puVar6 = puVar7;
          } while (puVar7 < puVar8);
        }
        param_1 = puVar5;
        puVar6 = puVar7;
        if ((param_3 & 2) != 0) {
          param_1 = puVar5 + 1;
          puVar6 = (uint *)((int)puVar7 + 2);
          *(ushort *)puVar7 = *puVar5;
        }
      }
    }
    else if ((param_3 & 0xfffffffe) != 0) {
      puVar5 = param_1;
      puVar7 = param_2;
      do {
        param_1 = puVar5 + 1;
        puVar6 = (uint *)((int)puVar7 + 2);
        *(ushort *)puVar7 = *puVar5;
        puVar5 = param_1;
        puVar7 = puVar6;
      } while (puVar6 < (uint *)((param_3 & 0xfffffffe) + (int)param_2));
    }
    if ((param_3 & 1) != 0) {
      *(ushort *)puVar6 = (ushort)*puVar6 & 0xff00 | *param_1 & 0xff;
      return;
    }
    return;
  }
  param_1 = (ushort *)((uint)param_1 & 0xfffffffe);
  uVar3 = *param_1 >> 8;
  uVar2 = (uint)uVar3;
  while (1 < param_3) {
    param_1 = param_1 + 1;
    uVar3 = *param_1;
    uVar1 = (uint)uVar3 << 8;
    *(ushort *)param_2 = (ushort)uVar2 | (ushort)uVar1;
    uVar2 = uVar1 >> 0x10;
    uVar3 = uVar3 >> 8;
    param_2 = (uint *)((int)param_2 + 2);
    param_3 = param_3 - 2;
  }
  if ((param_3 - 2 & 1) != 0) {
    *(ushort *)param_2 = (ushort)*param_2 & 0xff00 | uVar3;
    return;
  }
  return;
}

