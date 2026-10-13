/* Decompiled C draft; module arm9; ROM address 0204d28c. No matching claim. */
#include "types.h"
#include "deps/0204d28c_func_0204d28c.h"

void func_0204d28c(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint auStack_30 [2];
  undefined1 uStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined1 uStack_1c;
  
  uVar4 = uRam0204d5b4;
  puVar10 = (uint *)(uRam0204d5b4 + 0x440);
  if (*(uint *)(uRam0204d5b4 & 0xfffffffc) >> (uRam0204d5b4 & 3) * 8 == 0 &&
      *(uint *)(uRam0204d5b4 & 0xfffffffc) << (uRam0204d5b4 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar9 = uRam0204d5b4 + 0x4b14 & 3;
  uVar5 = *(uint *)(uRam0204d5b4 + 0x4b14 & 0xfffffffc);
  if (uVar5 >> uVar9 * 8 != 0 || uVar5 << uVar9 * -8 + 0x20 != 0) {
    return;
  }
  uVar9 = uRam0204d5b4 + 0x4b0c & 3;
  uVar8 = *(uint *)(uRam0204d5b4 + 0x4b0c & 0xfffffffc);
  uVar5 = uRam0204d5b4 + 0x4b18 & 3;
  uVar6 = *(uint *)(uRam0204d5b4 + 0x4b18 & 0xfffffffc);
  *(uint *)(uRam0204d5b4 + 0x4b0c) =
       (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) &
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  uVar9 = uVar4 + 0x4b10 & 3;
  uVar8 = *(uint *)(uVar4 + 0x4b10 & 0xfffffffc);
  uVar5 = uVar4 + 0x4b18 & 3;
  uVar6 = *(uint *)(uVar4 + 0x4b18 & 0xfffffffc);
  *(uint *)(uVar4 + 0x4b10) =
       (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) &
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  uVar9 = uVar4 + 0x4b1c & 3;
  uVar8 = *(uint *)(uVar4 + 0x4b1c & 0xfffffffc);
  uVar5 = uVar4 + 0x4b18 & 3;
  uVar6 = *(uint *)(uVar4 + 0x4b18 & 0xfffffffc);
  *(uint *)(uVar4 + 0x4b1c) =
       (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) &
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  uVar9 = uVar4 + 0x4b28 & 3;
  uVar8 = *(uint *)(uVar4 + 0x4b28 & 0xfffffffc);
  uVar5 = uVar4 + 0x4b18 & 3;
  uVar6 = *(uint *)(uVar4 + 0x4b18 & 0xfffffffc);
  *(uint *)(uVar4 + 0x4b28) =
       (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) &
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  uVar9 = uVar4 + 0x4b20 & 3;
  uVar5 = *(uint *)(uVar4 + 0x4b20 & 0xfffffffc);
  if ((uVar5 >> uVar9 * 8 != 0 || uVar5 << uVar9 * -8 + 0x20 != 0) &&
     (uVar9 = uVar4 + 0x4b24 & 3, uVar5 = *(uint *)(uVar4 + 0x4b24 & 0xfffffffc),
     uVar5 >> uVar9 * 8 == 0 && uVar5 << uVar9 * -8 + 0x20 == 0)) {
    uVar9 = uVar4 + 0x4b2c & 3;
    uVar5 = *(uint *)(uVar4 + 0x4b2c & 0xfffffffc);
    uVar5 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
    uVar9 = uVar4 + 0x2c & 3;
    uVar6 = *(uint *)(uVar4 + 0x2c & 0xfffffffc);
    *(undefined4 *)(uVar4 + 0x4b20) = 0;
    *(uint *)(uVar4 + 0x28) = uVar5;
    func_02006f14(uVar5,uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
    uVar9 = uVar4 + 0x4b28 & 3;
    uVar5 = *(uint *)(uVar4 + 0x4b28 & 0xfffffffc);
    uVar9 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
    if (uVar9 == 0) {
      return;
    }
    uVar5 = uRam0204d5b4 + 0x28 & 3;
    uVar6 = *(uint *)(uRam0204d5b4 + 0x28 & 0xfffffffc);
    uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    auStack_30[0] = ((int)uVar5 >> 8 & 0xfU) << 4 | 1;
    auStack_30[1] = 0;
    uStack_28 = (undefined1)uVar5;
    iVar7 = func_02006d3c(uVar9 & 0xffff,(undefined4)(uintptr_t)(auStack_30),9,uRam0204d5b8);
    if (iVar7 == 0) {
      return;
    }
    *(undefined4 *)(uVar4 + 0x4b14) = 1;
    *(undefined4 *)(uVar4 + 0x4b28) = 0;
    return;
  }
  uVar9 = uVar4 + 0x4b0c & 3;
  uVar5 = *(uint *)(uVar4 + 0x4b0c & 0xfffffffc);
  uVar9 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  if (uVar9 == 0) {
    return;
  }
  uVar5 = uVar4 + 0x4b10 & 3;
  uVar6 = *(uint *)(uVar4 + 0x4b10 & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  if ((uVar5 == 0) || (uVar5 != (uVar5 & uVar9))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  uVar6 = uVar5;
  if (!bVar3) {
    uVar6 = uVar9 & ~uVar5;
  }
  puVar13 = (uint *)0x0;
  for (uVar9 = 0; uVar8 = 1 << (uVar9 & 0xff), (int)uVar8 <= (int)uVar6; uVar9 = uVar9 + 1) {
    puVar14 = puVar13;
    if ((((uVar8 & uVar6) != 0) && (puVar14 = puVar10, puVar13 != (uint *)0x0)) &&
       ((((*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
          *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) & 0xf) !=
         ((*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
          *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) & 0xf) ||
        (uVar1 = (uint)(puVar13 + 1) & 3, uVar12 = *(uint *)((uint)(puVar13 + 1) & 0xfffffffc),
        uVar2 = (uint)(puVar10 + 1) & 3, uVar11 = *(uint *)((uint)(puVar10 + 1) & 0xfffffffc),
        puVar14 = puVar13,
        (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) !=
        (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20))))) {
      uVar6 = uVar6 & ~uVar8;
      puVar14 = puVar13;
    }
    puVar10 = puVar10 + 3;
    puVar13 = puVar14;
  }
  if ((bVar3) && (uVar6 != uVar5)) {
    *(undefined4 *)(uVar4 + 0x4b10) = 0;
  }
  if (puVar13 == (uint *)0x0) {
    return;
  }
  uVar9 = *(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
          *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20;
  if ((uVar9 & 0xf) == 0) {
    *puVar13 = uVar9 & 0xfffffff0 | 1;
  }
  else if ((uVar9 & 0xf) == 2) {
    *puVar13 = uVar9 & 0xfffffff0 | 3;
    uVar9 = uVar4 + 0x4b1c & 3;
    uVar5 = *(uint *)(uVar4 + 0x4b1c & 0xfffffffc);
    *(uint *)(uVar4 + 0x4b1c) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & ~uVar6;
  }
  uVar9 = uRam0204d5b4 + 0x28 & 3;
  uVar5 = *(uint *)(uRam0204d5b4 + 0x28 & 0xfffffffc);
  uVar5 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  uVar9 = (uint)(puVar13 + 1) & 3;
  uVar8 = *(uint *)((uint)(puVar13 + 1) & 0xfffffffc);
  uStack_20 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  uStack_24 = (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
              *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) & 0xf |
              0x100 | ((int)uVar5 >> 8 & 0xfU) << 4;
  uStack_1c = (undefined1)uVar5;
  iVar7 = func_02006d3c(uVar6 & 0xffff,(undefined4)(uintptr_t)(&uStack_24),9,uRam0204d5b8);
  if (iVar7 == 0) {
    return;
  }
  *(undefined4 *)(uVar4 + 0x4b14) = 1;
  uVar9 = uVar4 + 0x4b0c & 3;
  uVar5 = *(uint *)(uVar4 + 0x4b0c & 0xfffffffc);
  *(uint *)(uVar4 + 0x4b0c) = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & ~uVar6;
  return;
}

