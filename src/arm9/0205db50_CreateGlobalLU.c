/* Decompiled C draft; module arm9; ROM address 0205db50. No matching claim. */
#include "types.h"
#include "deps/0205db50_CreateGlobalLU.h"

void CreateGlobalLU(void)

{
  bool bVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  
  iVar8 = 0;
  puVar2 = (undefined2 *)
           (*(uint *)(uRam0205dc4c & 0xfffffffc) >> (uRam0205dc4c & 3) * 8 |
           *(uint *)(uRam0205dc4c & 0xfffffffc) << (uRam0205dc4c & 3) * -8 + 0x20);
  puVar9 = puVar2 + 0xa2;
  bVar1 = false;
  puVar10 = puVar2;
  do {
    iVar7 = 0;
    puVar6 = puVar10;
    do {
      *(undefined1 *)((int)puVar6 + 3) = 0;
      *(undefined1 *)(puVar6 + 2) = 0;
      *puVar6 = 0;
      *(undefined1 *)((int)puVar6 + 5) = 0;
      *(undefined1 *)(puVar6 + 1) = 0;
      *(undefined1 *)(puVar6 + 4) = 0;
      *(undefined1 *)((int)puVar6 + 9) = 0;
      iVar7 = iVar7 + 1;
      puVar6[3] = 0;
      puVar6 = puVar6 + 5;
    } while (iVar7 < 8);
    iVar7 = 0;
    puVar6 = puVar9;
    do {
      *puVar6 = 0;
      iVar7 = iVar7 + 1;
      *(undefined1 *)(puVar6 + 1) = 0;
      puVar6 = puVar6 + 2;
    } while (iVar7 < 2);
    iVar8 = iVar8 + 1;
    puVar10 = puVar10 + 0x28;
    puVar9 = puVar9 + 4;
  } while (iVar8 < 4);
  uVar3 = *(uint *)(uRam0205dc50 & 0xfffffffc) >> (uRam0205dc50 & 3) * 8 |
          *(uint *)(uRam0205dc50 & 0xfffffffc) << (uRam0205dc50 & 3) * -8 + 0x20;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  if ((uVar4 != 0) &&
     (uVar4 = uVar3 + 4 & 3, uVar3 = *(uint *)(uVar3 + 4 & 0xfffffffc),
     (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 0xd)) {
    bVar1 = true;
  }
  if (bVar1) {
    uVar5 = *(uint *)(uRam0205dc4c & 0xfffffffc) >> (uRam0205dc4c & 3) * 8 |
            *(uint *)(uRam0205dc4c & 0xfffffffc) << (uRam0205dc4c & 3) * -8 + 0x20;
    uVar3 = uVar5 + 0x164;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar5 + 0x164) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffffe | 1;
  }
  else {
    uVar5 = *(uint *)(uRam0205dc4c & 0xfffffffc) >> (uRam0205dc4c & 3) * 8 |
            *(uint *)(uRam0205dc4c & 0xfffffffc) << (uRam0205dc4c & 3) * -8 + 0x20;
    uVar3 = uVar5 + 0x164;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar5 + 0x164) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffffe;
  }
  *(undefined4 *)(puVar2 + 0xa0) = 0;
  return;
}

