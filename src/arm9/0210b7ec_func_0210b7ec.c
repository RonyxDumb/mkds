/* Decompiled C draft; module arm9; ROM address 0210b7ec. No matching claim. */
#include "types.h"
#include "deps/0210b7ec_func_0210b7ec.h"

void func_0210b7ec(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar4 == 0xffffffff) {
    *param_1 = param_2;
    param_1[2] = 0;
    return;
  }
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[1] = uVar4;
  *param_1 = param_2;
  uVar4 = (uint)(param_1 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar3 = (uint)(param_1 + 3) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[2] = (int)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) -
                    (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)) >>
               ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xff);
  uVar4 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (((int)uVar4 < 0x601) && (-0x601 < (int)uVar4)) {
    return;
  }
  param_1[2] = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  return;
}

