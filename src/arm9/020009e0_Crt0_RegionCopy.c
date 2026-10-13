/* Decompiled C draft; module arm9; ROM address 020009e0. No matching claim. */
#include "types.h"
#include "deps/020009e0_Crt0_RegionCopy.h"

void Crt0_RegionCopy(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar6;
  
  uVar2 = *(uint *)(uRam02000a54 & 0xfffffffc) >> (uRam02000a54 & 3) * 8 |
          *(uint *)(uRam02000a54 & 0xfffffffc) << (uRam02000a54 & 3) * -8 + 0x20;
  uVar1 = uRam02000a54 + 4 & 3;
  uVar4 = *(uint *)(uRam02000a54 + 4 & 0xfffffffc);
  uVar6 = uRam02000a54 + 8 & 3;
  uVar5 = *(uint *)(uRam02000a54 + 8 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  while (uVar2 != (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
    puVar8 = (uint *)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
    uVar3 = uVar2 + 8;
    uVar5 = uVar2 + 4 & 3;
    uVar10 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    for (puVar7 = puVar8;
        (int)((int)puVar7 - ((int)puVar8 + (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20))) < 0
        ; puVar7 = puVar7 + 1) {
      *puVar7 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      uVar6 = uVar6 + 4;
    }
    uVar2 = uVar2 + 0xc;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    puVar9 = (uint *)((int)puVar7 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20));
    for (; puVar7 < puVar9; puVar7 = puVar7 + 1) {
      *puVar7 = 0;
    }
    uVar5 = (uint)puVar8 & 0xffffffe0;
    do {
      coproc_moveto_Data_Synchronization(0);
      coproc_moveto_Invalidate_Instruction_Cache_by_MVA(uVar5);
      coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar5);
      uVar5 = uVar5 + 0x20;
    } while ((int)uVar5 < (int)puVar9);
  }
  return;
}

