/* Decompiled C draft; module arm9; ROM address 0207c78c. No matching claim. */
#include "types.h"
#include "deps/0207c78c_func_0207c78c.h"

void func_0207c78c(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  
  uVar11 = uRam0207c8d4;
  uVar10 = uRam0207c8d0;
  puVar9 = puRam0207c8c4;
  puVar8 = puRam0207c8c0;
  uVar7 = uRam0207c8bc;
  puVar6 = puRam0207c8b8;
  puVar5 = puRam0207c8b4;
  uVar4 = uRam0207c8b0;
  puVar3 = puRam0207c8ac;
  uVar2 = uRam0207c8a8;
  uVar12 = (*(uint *)(uRam0207c89c & 0xfffffffc) >> (uRam0207c89c & 3) * 8 |
           *(uint *)(uRam0207c89c & 0xfffffffc) << (uRam0207c89c & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  uVar12 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
  if (uVar12 == 1) {
    *puRam0207c8a4 = uRam0207c8a0;
    *puVar3 = uVar2;
    *puVar5 = uVar4;
    *puVar8 = uVar7;
    *puVar6 = uVar4;
    *puVar9 = uVar7;
    return;
  }
  if (uVar12 != 2) {
    *puRam0207c8a4 = uRam0207c8cc;
    *puVar3 = uVar2;
    *puVar5 = uVar10;
    *puVar8 = uVar11;
    *puVar6 = uVar10;
    *puVar9 = uVar11;
    return;
  }
  *puRam0207c8a4 = uRam0207c8c8;
  *puVar3 = uVar2;
  *puVar5 = uVar4;
  *puVar8 = uVar7;
  *puVar6 = uVar4;
  *puVar9 = uVar7;
  return;
}

