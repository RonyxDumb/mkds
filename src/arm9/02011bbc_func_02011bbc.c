/* Decompiled C draft; module arm9; ROM address 02011bbc. No matching claim. */
#include "types.h"
#include "deps/02011bbc_func_02011bbc.h"

void func_02011bbc(int *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_r4;
  
  uVar4 = (uint)(param_1 + 0xd) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 0xd) & 0xfffffffc);
  bVar1 = uVar3 >> uVar4 * 8 != 0;
  bVar2 = uVar3 << uVar4 * -8 + 0x20 != 0;
  if (bVar1 || bVar2) {
    unaff_r4 = (uint)*(byte *)((int)param_1 + 0x96);
  }
  uVar4 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (!bVar1 && !bVar2) {
    unaff_r4 = 0;
  }
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x100) == 0) {
    uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    func_01ff9144(uVar4 + *(int *)(uVar4 + 1),*(undefined4 *)(uVar4 + 5));
  }
  if (unaff_r4 == 3) {
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffffbf;
    uVar4 = (uint)(param_1 + 0xd) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 0xd) & 0xfffffffc);
    (*(code *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20))(param_1);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 9;
  return;
}

