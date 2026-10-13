/* Decompiled C draft; module arm7; ROM address 06006d24. No matching claim. */
#include "types.h"
#include "deps/06006d24_FUN_06006d24.h"

void FUN_06006d24(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ushort *puVar8;
  undefined2 *puVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint uVar13;
  int local_48;
  int local_44;
  
  iVar6 = FUN_06000680();
  uVar1 = iVar6 + 0x154cU & 3;
  uVar7 = *(uint *)(iVar6 + 0x154cU & 0xfffffffc);
  uVar7 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  iVar6 = uVar7 + 0x2f4;
  uVar3 = ~param_1 & *(ushort *)(uVar7 + 0x17e);
  thunk_FUN_037f9a0c(uVar7 + DAT_06006efc);
  uVar1 = DAT_06006f04;
  local_48 = 0;
  puVar8 = (ushort *)(uVar7 + DAT_06006f00);
  puVar11 = puVar8;
  local_44 = 0;
  do {
    uVar2 = *puVar11;
    puVar4 = puVar11;
    uVar5 = uVar1;
    while (uVar13 = (uint)uVar2, uVar13 != uVar1) {
      puVar12 = (ushort *)(iVar6 + uVar13 * 0x20);
      puVar12[3] = puVar12[3] & uVar3;
      puVar12[5] = puVar12[5] & uVar3;
      if (puVar12[3] == 0) {
        puVar9 = (undefined2 *)thunk_FUN_03807424();
        *puVar9 = 0x81;
        puVar9[1] = 0;
        puVar9[4] = 0x14;
        puVar9[5] = puVar12[1];
        puVar9[6] = puVar12[2];
        puVar9[7] = puVar12[3];
        puVar9[8] = puVar12[4];
        puVar9[0xc] = puVar12[7];
        uVar13 = (uint)(puVar12 + 10) & 3;
        uVar10 = *(uint *)((uint)(puVar12 + 10) & 0xfffffffc);
        *(uint *)(puVar9 + 10) = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(puVar12 + 0xc) & 3;
        uVar10 = *(uint *)((uint)(puVar12 + 0xc) & 0xfffffffc);
        *(uint *)(puVar9 + 0xe) = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(puVar12 + 0xe) & 3;
        uVar10 = *(uint *)((uint)(puVar12 + 0xe) & 0xfffffffc);
        *(uint *)(puVar9 + 0x10) = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
        puVar9[0xd] = puVar12[8];
        thunk_FUN_038074cc();
        if (*puVar12 == uVar1) {
          puVar11[1] = (ushort)uVar5;
        }
        *puVar4 = *puVar12;
        *puVar12 = (ushort)uVar1;
        if (*(ushort *)(uVar7 + 0x6f6) == uVar1) {
          *(ushort *)(uVar7 + 0x6f4) = uVar2;
        }
        else {
          *(ushort *)(iVar6 + (uint)*(ushort *)(uVar7 + 0x6f6) * 0x20) = uVar2;
        }
        *(ushort *)(uVar7 + 0x6f6) = uVar2;
        uVar13 = uVar5;
      }
      uVar5 = uVar13;
      if (uVar13 == uVar1) {
        uVar2 = *puVar11;
        puVar4 = puVar11;
      }
      else {
        uVar2 = *(ushort *)(iVar6 + uVar13 * 0x20);
        puVar4 = (ushort *)(iVar6 + uVar13 * 0x20);
      }
    }
    local_44 = local_44 + 1;
    puVar11 = puVar11 + 2;
  } while ((local_44 < 4) || (local_48 = local_48 + 1, puVar11 = puVar8, local_44 = 0, local_48 < 2)
          );
  thunk_FUN_037f999c(uVar7 + DAT_06006efc);
  return;
}

