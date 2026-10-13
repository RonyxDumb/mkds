/* Decompiled C draft; module arm9; ROM address 0210ddf4. No matching claim. */
#include "types.h"
#include "deps/0210ddf4_func_0210ddf4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0210ddf4(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar6;
  int iVar7;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uVar5;
  
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  iVar7 = 0;
  if ((int)uVar3 < 1) {
    return;
  }
  uVar5 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  while (uVar4 = uVar5 + iVar7 * 0x10, uVar1 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
        (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) <= param_2) {
    iVar7 = iVar7 + 1;
    if ((int)uVar3 <= iVar7) {
      return;
    }
  }
  puVar2 = (undefined4 *)(uVar5 + iVar7 * 0x10);
  uStack_20 = *puVar2;
  uStack_1c = puVar2[1];
  uStack_18 = puVar2[2];
  uStack_14 = puVar2[3];
  uVar3 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  puVar6 = (uint *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + iVar7 * 0x10);
  *puVar6 = param_2;
  puVar6[1] = param_3;
  puVar6[2] = param_4;
  puVar6[3] = param_5;
  if (iVar7 + 1 <
      (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)) {
    func_0210deac(param_1,&uStack_20);
    return;
  }
  return;
}

