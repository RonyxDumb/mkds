/* Decompiled C draft; module arm9; ROM address 02090354. No matching claim. */
#include "types.h"
#include "deps/02090354_func_02090354.h"

void func_02090354(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  uint uVar17;
  
  uVar16 = uRam020905a0;
  uVar14 = uRam0209059c;
  uVar12 = uRam02090598;
  uVar10 = uRam02090594;
  uVar8 = uRam02090590;
  uVar6 = uRam0209058c;
  uVar4 = uRam0209057c;
  puVar13 = puRam0209056c;
  puVar11 = puRam02090564;
  puVar9 = puRam0209055c;
  puVar7 = puRam02090554;
  puVar5 = puRam0209054c;
  puVar3 = puRam02090544;
  uVar2 = uRam02090540;
  uVar17 = (*(uint *)(uRam02090534 & 0xfffffffc) >> (uRam02090534 & 3) * 8 |
           *(uint *)(uRam02090534 & 0xfffffffc) << (uRam02090534 & 3) * -8 + 0x20) + 0x14;
  uVar1 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  uVar17 = uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20;
  if (uVar17 == 1) {
    *puRam0209053c = uRam02090538;
    puVar13 = puRam02090574;
    uVar14 = uRam02090570;
    puVar11 = puRam0209056c;
    uVar12 = uRam02090568;
    puVar9 = puRam02090564;
    uVar10 = uRam02090560;
    puVar7 = puRam0209055c;
    uVar8 = uRam02090558;
    puVar5 = puRam02090554;
    uVar6 = uRam02090550;
    puVar3 = puRam0209054c;
    uVar4 = uRam02090548;
    *puRam02090544 = uVar2;
    *puVar3 = uVar4;
    *puVar5 = uVar6;
    *puVar7 = uVar8;
    *puVar9 = uVar10;
    *puVar11 = uVar12;
    *puVar13 = uVar14;
    return;
  }
  if (uVar17 != 2) {
    if (uVar17 != 3) {
      *puRam0209053c = uRam02090588;
      uVar2 = uRam020905a4;
      puVar15 = puRam02090574;
      *puVar3 = uVar6;
      *puVar5 = uVar8;
      *puVar7 = uVar10;
      *puVar9 = uVar12;
      *puVar11 = uVar14;
      *puVar13 = uVar16;
      *puVar15 = uVar2;
      return;
    }
    *puRam0209053c = uRam02090588;
    uVar14 = uRam020905a4;
    uVar12 = uRam020905a0;
    uVar10 = uRam0209059c;
    uVar8 = uRam02090598;
    uVar4 = uRam02090594;
    uVar2 = uRam02090590;
    puVar13 = puRam02090574;
    puVar11 = puRam0209056c;
    puVar9 = puRam02090564;
    puVar7 = puRam0209055c;
    puVar5 = puRam02090554;
    puVar3 = puRam0209054c;
    *puRam02090544 = uVar6;
    *puVar3 = uVar2;
    *puVar5 = uVar4;
    *puVar7 = uVar8;
    *puVar9 = uVar10;
    *puVar11 = uVar12;
    *puVar13 = uVar14;
    return;
  }
  *puRam0209053c = uRam02090578;
  uVar14 = uRam02090584;
  uVar12 = uRam02090580;
  puVar13 = puRam02090574;
  uVar10 = uRam02090570;
  puVar11 = puRam0209056c;
  uVar8 = uRam02090568;
  puVar9 = puRam02090564;
  uVar6 = uRam02090560;
  puVar7 = puRam0209055c;
  uVar2 = uRam02090558;
  puVar5 = puRam02090554;
  puVar3 = puRam0209054c;
  *puRam02090544 = uVar4;
  *puVar3 = uVar12;
  *puVar5 = uVar14;
  *puVar7 = uVar2;
  *puVar9 = uVar6;
  *puVar11 = uVar8;
  *puVar13 = uVar10;
  return;
}

