/* Decompiled C draft; module arm9; ROM address 0205a140. No matching claim. */
#include "types.h"
#include "deps/0205a140_InitializeOverlayManager.h"

void InitializeOverlayManager(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  iVar4 = Mem_AllocateHeap(param_1,0xb0);
  piVar1 = piRam0205a284;
  *piRam0205a284 = iVar4;
  *(undefined4 *)(iVar4 + 0xa8) = 0xffffffff;
  *(undefined4 *)
   ((*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
    *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) + 0xac) = 0;
  uVar2 = uRam0205a28c;
  uVar9 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar9 + 8) = uRam0205a288;
  uVar3 = uRam0205a290;
  *(undefined4 *)(uVar9 + 0xc) = uVar2;
  *(undefined4 *)(uVar9 + 0x10) = uVar3;
  uVar8 = *(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20;
  uVar5 = uVar9 + 0xc & 3;
  uVar6 = *(uint *)(uVar9 + 0xc & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar8 + 0xa8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar7 < (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
    *(uint *)(uVar8 + 0xa8) = uVar7;
  }
  uVar5 = uVar9 + 0x10 & 3;
  uVar6 = *(uint *)(uVar9 + 0x10 & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar8 = *(uint *)((uint)piRam0205a284 & 0xfffffffc) >> ((uint)piRam0205a284 & 3) * 8 |
          *(uint *)((uint)piRam0205a284 & 0xfffffffc) << ((uint)piRam0205a284 & 3) * -8 + 0x20;
  uVar5 = uVar8 + 0xac;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < uVar7) {
    *(uint *)(uVar8 + 0xac) = uVar7;
  }
  uVar2 = uRam0205a298;
  piVar1 = piRam0205a284;
  uVar9 = *(uint *)((uint)piRam0205a284 & 0xfffffffc) >> ((uint)piRam0205a284 & 3) * 8 |
          *(uint *)((uint)piRam0205a284 & 0xfffffffc) << ((uint)piRam0205a284 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar9 + 0x14) = uRam0205a294;
  uVar3 = uRam0205a29c;
  *(undefined4 *)(uVar9 + 0x18) = uVar2;
  *(undefined4 *)(uVar9 + 0x1c) = uVar3;
  uVar5 = (uint)piVar1 & 3;
  uVar6 = *(uint *)((uint)piVar1 & 0xfffffffc);
  uVar8 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar9 + 0x18 & 3;
  uVar6 = *(uint *)(uVar9 + 0x18 & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar8 + 0xa8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar7 < (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
    *(uint *)(uVar8 + 0xa8) = uVar7;
  }
  uVar5 = uVar9 + 0x1c & 3;
  uVar6 = *(uint *)(uVar9 + 0x1c & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar8 = *(uint *)((uint)piRam0205a284 & 0xfffffffc) >> ((uint)piRam0205a284 & 3) * 8 |
          *(uint *)((uint)piRam0205a284 & 0xfffffffc) << ((uint)piRam0205a284 & 3) * -8 + 0x20;
  uVar5 = uVar8 + 0xac;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < uVar7) {
    *(uint *)(uVar8 + 0xac) = uVar7;
  }
  uVar2 = uRam0205a2a4;
  piVar1 = piRam0205a284;
  uVar9 = *(uint *)((uint)piRam0205a284 & 0xfffffffc) >> ((uint)piRam0205a284 & 3) * 8 |
          *(uint *)((uint)piRam0205a284 & 0xfffffffc) << ((uint)piRam0205a284 & 3) * -8 + 0x20;
  *(undefined4 *)(uVar9 + 0x20) = uRam0205a2a0;
  uVar3 = uRam0205a2a8;
  *(undefined4 *)(uVar9 + 0x24) = uVar2;
  *(undefined4 *)(uVar9 + 0x28) = uVar3;
  uVar5 = (uint)piVar1 & 3;
  uVar6 = *(uint *)((uint)piVar1 & 0xfffffffc);
  uVar8 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar9 + 0x24 & 3;
  uVar6 = *(uint *)(uVar9 + 0x24 & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar8 + 0xa8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar7 < (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
    *(uint *)(uVar8 + 0xa8) = uVar7;
  }
  uVar5 = uVar9 + 0x28 & 3;
  uVar6 = *(uint *)(uVar9 + 0x28 & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar8 = *(uint *)((uint)piRam0205a284 & 0xfffffffc) >> ((uint)piRam0205a284 & 3) * 8 |
          *(uint *)((uint)piRam0205a284 & 0xfffffffc) << ((uint)piRam0205a284 & 3) * -8 + 0x20;
  uVar5 = uVar8 + 0xac;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < uVar7) {
    *(uint *)(uVar8 + 0xac) = uVar7;
  }
  piVar1 = piRam0205a284;
  *(undefined4 *)
   ((*(uint *)((uint)piRam0205a284 & 0xfffffffc) >> ((uint)piRam0205a284 & 3) * 8 |
    *(uint *)((uint)piRam0205a284 & 0xfffffffc) << ((uint)piRam0205a284 & 3) * -8 + 0x20) + 0xa0) =
       0;
  uVar5 = (uint)piVar1 & 3;
  uVar6 = *(uint *)((uint)piVar1 & 0xfffffffc);
  *(undefined4 *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0xa4) = 0;
  return;
}

