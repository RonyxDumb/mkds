/* Decompiled C draft; module arm9; ROM address 020ea37c. No matching claim. */
#include "types.h"
#include "deps/020ea37c_func_020ea37c.h"

void func_020ea37c(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  piVar1 = piRam020ea488;
  iVar6 = piRam020ea484[1];
  iVar8 = piRam020ea484[2];
  *piRam020ea488 = *piRam020ea484;
  piVar1[1] = iVar6;
  piVar1[2] = iVar8;
  piVar5 = piRam020ea490;
  iVar6 = piRam020ea48c[1];
  iVar8 = piRam020ea48c[2];
  *piRam020ea490 = *piRam020ea48c;
  piVar5[1] = iVar6;
  piVar5[2] = iVar8;
  piVar2 = piRam020ea498;
  iVar6 = piRam020ea494[1];
  iVar8 = piRam020ea494[2];
  *piRam020ea498 = *piRam020ea494;
  piVar2[1] = iVar6;
  piVar2[2] = iVar8;
  iVar6 = iRam020ea49c;
  uVar9 = *(uint *)((uint)piVar5 & 0xfffffffc);
  *piVar1 = (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
            *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) + iRam020ea49c;
  uVar7 = *(uint *)((uint)piVar2 & 0xfffffffc);
  *piRam020ea4a0 = iVar6;
  puVar4 = puRam020ea4a8;
  uVar3 = uRam020ea4a4;
  *piVar5 = (uVar9 >> ((uint)piVar5 & 3) * 8 | uVar9 << ((uint)piVar5 & 3) * -8 + 0x20) + iVar6;
  *puVar4 = uVar3;
  *piVar2 = (uVar7 >> ((uint)piVar2 & 3) * 8 | uVar7 << ((uint)piVar2 & 3) * -8 + 0x20) + iVar6;
  iVar6 = func_0203c5e4();
  piVar1 = piRam020ea4b0;
  piVar5 = piRam020ea4ac;
  if (iVar6 == 0) {
    piVar5 = piRam020ea4b4;
  }
  iVar6 = piVar5[1];
  iVar8 = piVar5[2];
  *piRam020ea4b0 = *piVar5;
  piVar1[1] = iVar6;
  piVar1[2] = iVar8;
  uVar7 = uRam020ea4b8 & 3;
  uVar9 = *(uint *)(uRam020ea4b8 & 0xfffffffc);
  iVar6 = (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
          *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) +
          (*(uint *)((uint)piRam020ea4a0 & 0xfffffffc) >> ((uint)piRam020ea4a0 & 3) * 8 |
          *(uint *)((uint)piRam020ea4a0 & 0xfffffffc) << ((uint)piRam020ea4a0 & 3) * -8 + 0x20);
  *piVar1 = iVar6;
  piVar2 = piRam020ea498;
  piVar5 = piRam020ea490;
  if (uVar9 >> uVar7 * 8 == 0 && uVar9 << uVar7 * -8 + 0x20 == 0) {
    uVar7 = (uint)piRam020ea490 & 3;
    uVar11 = *(uint *)((uint)piRam020ea490 & 0xfffffffc);
    uVar9 = (uint)piRam020ea498 & 3;
    uVar10 = *(uint *)((uint)piRam020ea498 & 0xfffffffc);
    *piRam020ea488 =
         -(*(uint *)((uint)piRam020ea488 & 0xfffffffc) >> ((uint)piRam020ea488 & 3) * 8 |
          *(uint *)((uint)piRam020ea488 & 0xfffffffc) << ((uint)piRam020ea488 & 3) * -8 + 0x20);
    *piVar5 = -(uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20);
    *piVar1 = -iVar6;
    *piVar2 = -(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20);
  }
  uVar7 = (uint)(piRam020ea498 + 1) & 3;
  uVar9 = *(uint *)((uint)(piRam020ea498 + 1) & 0xfffffffc);
  piRam020ea498[1] =
       (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
       (*(uint *)((uint)puRam020ea4a8 & 0xfffffffc) >> ((uint)puRam020ea4a8 & 3) * 8 |
       *(uint *)((uint)puRam020ea4a8 & 0xfffffffc) << ((uint)puRam020ea4a8 & 3) * -8 + 0x20);
  return;
}

