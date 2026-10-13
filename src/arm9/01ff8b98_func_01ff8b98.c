/* Decompiled C draft; module arm9; ROM address 01ff8b98. No matching claim. */
#include "types.h"
#include "deps/01ff8b98_func_01ff8b98.h"

void func_01ff8b98(int *param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint unaff_r4;
  uint uVar7;
  
  uVar5 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x200) == 0) {
    *(undefined1 *)(param_1 + 0x2b) =
         *(undefined1 *)
          ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 1);
    uVar5 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    param_1[2] = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20 | 4;
    param_1[0x2e] = (int)(param_1 + 0x61);
    uVar5 = (uint)(param_1 + 5) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar3 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
    bVar1 = uVar4 >> uVar5 * 8 != 0;
    bVar2 = uVar4 << uVar5 * -8 + 0x20 != 0;
    if (bVar1 || bVar2) {
      unaff_r4 = (uint)*(byte *)((int)param_1 + 0x8e);
    }
    uVar5 = uVar3 + 0x18 & 3;
    uVar4 = *(uint *)(uVar3 + 0x18 & 0xfffffffc);
    if (!bVar1 && !bVar2) {
      unaff_r4 = 0;
    }
    if (((uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) ||
        (uVar5 = uVar3 + (uint)(*(byte *)(param_1 + 0x2b) >> 5) * 4 + 0x4c, uVar4 = uVar5 & 3,
        uVar5 = *(uint *)(uVar5 & 0xfffffffc),
        (1 << (*(byte *)(param_1 + 0x2b) & 0x1f) & (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)
        ) == 0)) ||
       (uVar5 = (uint)(param_1 + 0x2e) & 3, uVar7 = *(uint *)((uint)(param_1 + 0x2e) & 0xfffffffc),
       uVar4 = uVar3 + 0x1c & 3, uVar3 = *(uint *)(uVar3 + 0x1c & 0xfffffffc),
       iVar6 = (*(code *)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20))
                         (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20), iVar6 == 0)) {
      uVar5 = (uint)(param_1 + 0x2e) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 0x2e) & 0xfffffffc);
      *(uint *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) =
           *(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 2)
           & 1;
    }
    uVar5 = (uint)(param_1 + 0x2e) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 0x2e) & 0xfffffffc);
    uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
      uVar5 = (uint)(param_1 + 2) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xfffffffe;
    }
    else {
      uVar5 = (uint)(param_1 + 2) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20 | 1;
    }
    if (unaff_r4 == 3) {
      uVar5 = (uint)(param_1 + 2) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xffffffbf;
      uVar5 = (uint)(param_1 + 5) & 3;
      uVar3 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
      (*(code *)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20))(param_1);
    }
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 3;
  return;
}

