/* Decompiled C draft; module arm9; ROM address 0208c284. No matching claim. */
#include "types.h"
#include "deps/0208c284_func_0208c284.h"

void func_0208c284(void)

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
  undefined4 uVar17;
  uint uVar18;
  uint uVar19;
  
  uVar17 = uRam0208c4e4;
  uVar16 = uRam0208c4e0;
  uVar14 = uRam0208c4c0;
  uVar12 = uRam0208c4b4;
  puVar13 = puRam0208c4a4;
  uVar10 = uRam0208c4a0;
  puVar11 = puRam0208c49c;
  uVar8 = uRam0208c498;
  puVar9 = puRam0208c494;
  uVar6 = uRam0208c490;
  puVar7 = puRam0208c48c;
  uVar4 = uRam0208c488;
  puVar5 = puRam0208c484;
  puVar3 = puRam0208c47c;
  uVar2 = uRam0208c478;
  uVar18 = *(uint *)(uRam0208c46c & 0xfffffffc) >> (uRam0208c46c & 3) * 8 |
           *(uint *)(uRam0208c46c & 0xfffffffc) << (uRam0208c46c & 3) * -8 + 0x20;
  uVar19 = uVar18 + 0xc;
  uVar1 = uVar19 & 3;
  uVar19 = *(uint *)(uVar19 & 0xfffffffc);
  uVar19 = uVar19 >> uVar1 * 8 | uVar19 << uVar1 * -8 + 0x20;
  if ((uVar19 == 5) ||
     (uVar18 = uVar18 + 8, uVar1 = uVar18 & 3, uVar18 = *(uint *)(uVar18 & 0xfffffffc),
     uVar18 = uVar18 >> uVar1 * 8 | uVar18 << uVar1 * -8 + 0x20, uVar18 == 4)) {
    *puRam0208c474 = uRam0208c470;
    puVar13 = puRam0208c4ac;
    uVar14 = uRam0208c4a8;
    puVar11 = puRam0208c4a4;
    uVar12 = uRam0208c4a0;
    puVar9 = puRam0208c49c;
    uVar10 = uRam0208c498;
    puVar7 = puRam0208c494;
    uVar8 = uRam0208c490;
    puVar5 = puRam0208c48c;
    uVar6 = uRam0208c488;
    puVar3 = puRam0208c484;
    uVar4 = uRam0208c480;
    *puRam0208c47c = uVar2;
    *puVar3 = uVar4;
    *puVar5 = uVar6;
    *puVar7 = uVar8;
    *puVar9 = uVar10;
    *puVar11 = uVar12;
    *puVar13 = uVar14;
    return;
  }
  if (uVar19 == 6) {
    *puRam0208c474 = uRam0208c4b0;
    uVar14 = uRam0208c4b8;
    puVar13 = puRam0208c4ac;
    uVar10 = uRam0208c4a8;
    puVar11 = puRam0208c4a4;
    uVar8 = uRam0208c4a0;
    puVar9 = puRam0208c49c;
    uVar6 = uRam0208c498;
    puVar7 = puRam0208c494;
    uVar4 = uRam0208c490;
    puVar5 = puRam0208c48c;
    uVar2 = uRam0208c488;
    puVar3 = puRam0208c484;
    *puRam0208c47c = uVar12;
    *puVar3 = uVar14;
    *puVar5 = uVar2;
    *puVar7 = uVar4;
    *puVar9 = uVar6;
    *puVar11 = uVar8;
    *puVar13 = uVar10;
    return;
  }
  if (uVar18 == 2) {
    *puRam0208c474 = uRam0208c4bc;
    uVar12 = uRam0208c4d8;
    uVar10 = uRam0208c4d4;
    uVar8 = uRam0208c4d0;
    uVar6 = uRam0208c4cc;
    uVar4 = uRam0208c4c8;
    uVar2 = uRam0208c4c4;
    puVar13 = puRam0208c4ac;
    puVar11 = puRam0208c4a4;
    puVar9 = puRam0208c49c;
    puVar7 = puRam0208c494;
    puVar5 = puRam0208c48c;
    puVar3 = puRam0208c484;
    *puRam0208c47c = uVar14;
    *puVar3 = uVar2;
    *puVar5 = uVar4;
    *puVar7 = uVar6;
    *puVar9 = uVar8;
    *puVar11 = uVar10;
    *puVar13 = uVar12;
    return;
  }
  *puRam0208c474 = uRam0208c4dc;
  puVar15 = puRam0208c4ac;
  uVar2 = uRam0208c4a8;
  *puVar3 = uVar16;
  *puVar5 = uVar17;
  *puVar7 = uVar4;
  *puVar9 = uVar6;
  *puVar11 = uVar8;
  *puVar13 = uVar10;
  *puVar15 = uVar2;
  return;
}

