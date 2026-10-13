/* Decompiled C draft; module arm9; ROM address 02022310. No matching claim. */
#include "types.h"
#include "deps/02022310_func_02022310.h"

void func_02022310(uint *param_1)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar3;
  
  uVar3 = (uint)(param_1 + 5) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  if ((uVar3 == 3) || (uVar3 == 4)) {
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[1] = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) ^ 1;
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = uVar5 + 0xc;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) <=
        ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + (uint)*(ushort *)(uVar5 + 2) * 8) - 8)
    {
      uVar3 = (uint)(param_1 + 7) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
      if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
        uVar3 = (uint)(param_1 + 8) & 3;
        uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
        uVar2 = (uint)(param_1 + 3) & 3;
        uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
        uVar5 = (uint)(param_1 + 9) & 3;
        uVar8 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
        (*(code *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20))
                  (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                   uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
      }
      uVar3 = (uint)(param_1 + 5) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if (uVar3 == 0) {
        uVar3 = (uint)(param_1 + 6) & 3;
        uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
        uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
        uVar2 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      }
      if ((uVar3 == 2) || (uVar3 == 4)) {
        func_02022040(param_1);
      }
      else {
        param_1[2] = 0;
      }
    }
  }
  else {
    uVar3 = (uint)(param_1 + 7) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
      uVar3 = (uint)(param_1 + 8) & 3;
      uVar4 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
      uVar2 = (uint)(param_1 + 3) & 3;
      uVar6 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
      uVar5 = (uint)(param_1 + 9) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
      (*(code *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20))
                (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                 uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    }
    uVar3 = (uint)(param_1 + 5) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      uVar3 = (uint)(param_1 + 6) & 3;
      uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
      uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    }
    if ((uVar3 == 2) || (uVar3 == 4)) {
      func_02022040(param_1);
    }
    else {
      param_1[2] = 0;
    }
  }
  uVar3 = (uint)(param_1 + 6) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  puVar7 = (ushort *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  puVar1 = puVar7 + 6;
  uVar3 = (uint)puVar1 & 3;
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = (uVar2 + (uint)*puVar7 * 8) - 8;
  if (uVar5 <= uVar3) {
    if (uVar5 < uVar2) {
      *param_1 = uVar2;
    }
    return;
  }
  *param_1 = uVar3;
  return;
}

