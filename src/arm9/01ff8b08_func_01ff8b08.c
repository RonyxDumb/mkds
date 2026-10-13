/* Decompiled C draft; module arm9; ROM address 01ff8b08. No matching claim. */
#include "types.h"
#include "deps/01ff8b08_func_01ff8b08.h"

void func_01ff8b08(int *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint unaff_r5;
  uint local_10;
  uint uVar4;
  
  uVar4 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (((uVar4 & 0x200) == 0) && ((uVar4 & 1) != 0)) {
    uVar4 = (uint)(param_1 + 6) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    bVar1 = uVar3 >> uVar4 * 8 != 0;
    bVar2 = uVar3 << uVar4 * -8 + 0x20 != 0;
    if (bVar1 || bVar2) {
      unaff_r5 = (uint)*(byte *)((int)param_1 + 0x8f);
    }
    local_10 = (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                               *(uint *)((uint)param_1 & 0xfffffffc) <<
                               ((uint)param_1 & 3) * -8 + 0x20) + 1);
    if (!bVar1 && !bVar2) {
      unaff_r5 = 0;
    }
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x100) == 0) {
      func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_10),1);
    }
    if (unaff_r5 == 3) {
      uVar4 = (uint)(param_1 + 2) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffffbf;
      uVar4 = (uint)(param_1 + 6) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
      (*(code *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20))(param_1);
    }
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 2;
  return;
}

