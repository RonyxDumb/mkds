/* Decompiled C draft; module arm9; ROM address 0207bc9c. No matching claim. */
#include "types.h"
#include "deps/0207bc9c_func_0207bc9c.h"

void func_0207bc9c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar6;
  
  uVar4 = param_2 + 0x30U & 3;
  uVar3 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  uVar1 = *(ushort *)(param_3 + 0x40);
  uVar6 = (*(uint *)(uRam0207bd68 & 0xfffffffc) >> (uRam0207bd68 & 3) * 8 |
          *(uint *)(uRam0207bd68 & 0xfffffffc) << (uRam0207bd68 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar6 & 3;
  uVar11 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(param_2 + 0x30) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + param_4;
  uVar6 = param_2 + 0x30U & 3;
  uVar4 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  if (0x1000 < (int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20)) {
    uVar6 = param_2 + 0x34U & 3;
    uVar4 = *(uint *)(param_2 + 0x34U & 0xfffffffc);
    *(uint *)(param_2 + 0x34) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 1;
    uVar4 = (uint)*(ushort *)
                   ((uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) + (uint)uVar1 * 4 + 2);
    uVar6 = param_2 + 0x34U & 3;
    uVar5 = *(uint *)(param_2 + 0x34U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)uVar6 < (int)uVar4) {
      puVar2 = (undefined4 *)
               GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_3 + 0x40),uVar6 & 0xffff);
      uVar6 = 0;
      do {
        puVar7 = (undefined4 *)((uVar6 + 1) * 0xc + param_2);
        puVar10 = (undefined4 *)(uVar6 * 0xc + param_2);
        uVar6 = uVar6 + 1 & 0xffff;
        uVar8 = puVar7[1];
        uVar9 = puVar7[2];
        *puVar10 = *puVar7;
        puVar10[1] = uVar8;
        puVar10[2] = uVar9;
      } while (uVar6 < 3);
      uVar8 = puVar2[1];
      uVar9 = puVar2[2];
      *(undefined4 *)(param_2 + 0x24) = *puVar2;
      *(undefined4 *)(param_2 + 0x28) = uVar8;
      *(undefined4 *)(param_2 + 0x2c) = uVar9;
      uVar6 = param_2 + 0x30U & 3;
      uVar4 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
      *(uint *)(param_2 + 0x30) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) - 0x1000;
    }
    else {
      *(uint *)(param_2 + 0x34) = uVar4;
      *(undefined4 *)(param_2 + 0x30) = 0x1000;
    }
  }
  func_0207b960(param_1,param_2);
  return;
}

