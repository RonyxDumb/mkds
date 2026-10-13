/* Decompiled C draft; module arm9; ROM address 020e7b7c. No matching claim. */
#include "types.h"
#include "deps/020e7b7c_E7Fn2_12.h"

void E7Fn2_12(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  
  puVar2 = puRam020e7d2c;
  uVar10 = *(uint *)(uRam020e7d24 & 0xfffffffc) >> (uRam020e7d24 & 3) * 8 |
           *(uint *)(uRam020e7d24 & 0xfffffffc) << (uRam020e7d24 & 3) * -8 + 0x20;
  *puRam020e7d28 = 1;
  *puVar2 = 0;
  if (uVar10 != 4) {
    uVar10 = iRam020e7d30 + uVar10 * 0x10;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    if (uVar10 != 0) {
      *(undefined4 *)(uVar10 + 0xc) = 0;
      uVar8 = uVar10 + 0x1c & 3;
      uVar7 = *(uint *)(uVar10 + 0x1c & 0xfffffffc);
      uVar1 = uVar10 + 0xc & 3;
      uVar11 = *(uint *)(uVar10 + 0xc & 0xfffffffc);
      uVar10 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) +
               (uint)*(ushort *)(uVar10 + 0x1a) * 4;
      uVar8 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      *(uint *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) =
           uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20;
    }
    uVar10 = iRam020e7d34 +
             (*(uint *)(uRam020e7d24 & 0xfffffffc) >> (uRam020e7d24 & 3) * 8 |
             *(uint *)(uRam020e7d24 & 0xfffffffc) << (uRam020e7d24 & 3) * -8 + 0x20) * 0x10;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    if (uVar10 != 0) {
      *(undefined4 *)(uVar10 + 0xc) = 0;
      uVar8 = uVar10 + 0x1c & 3;
      uVar7 = *(uint *)(uVar10 + 0x1c & 0xfffffffc);
      uVar1 = uVar10 + 0xc & 3;
      uVar11 = *(uint *)(uVar10 + 0xc & 0xfffffffc);
      uVar10 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) +
               (uint)*(ushort *)(uVar10 + 0x1a) * 4;
      uVar8 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      *(uint *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) =
           uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20;
    }
  }
  func_02147288(puRam020e7d38,uRam020e7d3c);
  piVar4 = piRam020e7d4c;
  piVar3 = piRam020e7d48;
  puVar2 = puRam020e7d38;
  iVar16 = 0;
  iVar17 = 0;
  iVar15 = 0;
  do {
    iVar12 = -0x3000;
    if (iVar17 < -0x2fff) {
      iVar12 = iVar17;
    }
    iVar16 = iVar16 + 1;
    iVar15 = iVar15 - iVar12;
    iVar17 = iVar17 + iRam020e7d44;
  } while (iVar16 < 0x1e);
  uVar10 = (uint)(puRam020e7d38 + 1) & 3;
  uVar8 = *(uint *)((uint)(puRam020e7d38 + 1) & 0xfffffffc);
  puRam020e7d38[1] = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + iVar15;
  puVar5 = puRam020e7d50;
  uVar9 = puVar2[1];
  uVar13 = puVar2[2];
  *puRam020e7d50 = *puVar2;
  puVar5[1] = uVar9;
  puVar5[2] = uVar13;
  puVar2 = puRam020e7d54;
  uVar9 = puVar5[1];
  uVar13 = puVar5[2];
  *puRam020e7d54 = *puVar5;
  puVar2[1] = uVar9;
  puVar2[2] = uVar13;
  puVar5 = puRam020e7d58;
  uVar9 = *puVar2;
  uVar13 = puVar2[1];
  uVar14 = puVar2[2];
  *piVar3 = iVar15;
  *puVar5 = uVar9;
  puVar5[1] = uVar13;
  puVar5[2] = uVar14;
  puVar2 = puRam020e7d5c;
  uVar9 = *puVar5;
  uVar13 = puVar5[1];
  uVar14 = puVar5[2];
  *piVar4 = iVar17;
  *puVar2 = uVar9;
  puVar2[1] = uVar13;
  puVar2[2] = uVar14;
  puVar5 = puRam020e7d60;
  uVar9 = puVar2[1];
  uVar13 = puVar2[2];
  *puRam020e7d60 = *puVar2;
  puVar5[1] = uVar9;
  puVar5[2] = uVar13;
  puVar6 = puRam020e7d68;
  puVar2 = puRam020e7d64;
  *puRam020e7d64 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6[2] = 0;
  puVar2 = puRam020e7d70;
  *puRam020e7d6c = 0;
  *puVar2 = 0;
  puVar2 = puRam020e7d78;
  *puRam020e7d74 = 0;
  *puVar2 = 0;
  puVar2 = puRam020e7d80;
  *puRam020e7d7c = 0;
  puVar6 = puRam020e7d88;
  *puRam020e7d84 = 1;
  *puVar6 = 1;
  puVar6 = puRam020e7d8c;
  uVar9 = puVar5[1];
  uVar13 = puVar5[2];
  *puVar2 = *puVar5;
  puVar2[1] = uVar9;
  puVar2[2] = uVar13;
  *puVar6 = 0;
  return;
}

