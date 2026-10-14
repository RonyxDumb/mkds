/* Decompiled C draft; module arm9; ROM address 0207be40. No matching claim. */
#include "types.h"
#include "deps/0207be40_StructVC_SomeFnLinkedRouteRelated.h"

void StructVC_SomeFnLinkedRouteRelated(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar2 = *(ushort *)(param_2 + 0x40);
  uVar8 = (*(uint *)(uRam0207bec8 & 0xfffffffc) >> (uRam0207bec8 & 3) * 8 |
          *(uint *)(uRam0207bec8 & 0xfffffffc) << (uRam0207bec8 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar8 & 3;
  uVar5 = *(uint *)(uVar8 & 0xfffffffc);
  uVar8 = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uint)uVar2 * 4 + 2) < 4) {
    return;
  }
  do {
    puVar3 = (undefined4 *)GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_2 + 0x40),uVar8);
    puVar7 = (undefined4 *)(uVar8 * 0xc + param_1);
    uVar4 = puVar3[1];
    uVar6 = puVar3[2];
    *puVar7 = *puVar3;
    puVar7[1] = uVar4;
    puVar7[2] = uVar6;
    *(uint *)(param_1 + 0x34) = uVar8;
    uVar8 = uVar8 + 1 & 0xffff;
  } while (uVar8 < 4);
  return;
}

