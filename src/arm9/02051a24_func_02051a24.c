/* Decompiled C draft; module arm9; ROM address 02051a24. No matching claim. */
#include "types.h"
#include "deps/02051a24_func_02051a24.h"

void func_02051a24(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = uRam02051acc;
  *(undefined4 *)
   ((*(uint *)(uRam02051acc & 0xfffffffc) >> (uRam02051acc & 3) * 8 |
    *(uint *)(uRam02051acc & 0xfffffffc) << (uRam02051acc & 3) * -8 + 0x20) + 0xc) = 0xb;
  *(undefined4 *)
   ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar9 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  uVar5 = uVar9 + 0x30 & 3;
  uVar6 = *(uint *)(uVar9 + 0x30 & 0xfffffffc);
  uVar1 = uVar9 + 0x38 & 3;
  uVar8 = *(uint *)(uVar9 + 0x38 & 0xfffffffc);
  uVar2 = uVar9 + 0x3c & 3;
  uVar7 = *(uint *)(uVar9 + 0x3c & 0xfffffffc);
  uVar3 = uVar9 + 0x34 & 3;
  uVar9 = *(uint *)(uVar9 + 0x34 & 0xfffffffc);
  iVar4 = func_02144230(uRam02051ad0,uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20,
                        (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) & 0xffff,
                        uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20,
                        (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xffff,1,0,0,0,0,0);
  uVar5 = uRam02051acc;
  if (iVar4 != 2) {
    *(undefined4 *)
     ((*(uint *)(uRam02051acc & 0xfffffffc) >> (uRam02051acc & 3) * 8 |
      *(uint *)(uRam02051acc & 0xfffffffc) << (uRam02051acc & 3) * -8 + 0x20) + 8) = 2;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(undefined4 *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x10) = 0;
    return;
  }
  return;
}

