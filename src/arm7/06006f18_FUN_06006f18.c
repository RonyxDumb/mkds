/* Decompiled C draft; module arm7; ROM address 06006f18. No matching claim. */
#include "types.h"
#include "deps/06006f18_FUN_06006f18.h"

undefined4 FUN_06006f18(int param_1,ushort param_2)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  short *psVar13;
  ushort uVar14;
  int local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_38;
  
  iVar6 = FUN_06000680();
  uVar1 = iVar6 + 0x154cU & 3;
  uVar7 = *(uint *)(iVar6 + 0x154cU & 0xfffffffc);
  uVar7 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  psVar13 = (short *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  local_48 = 0;
  if (*psVar13 == 9) {
    bVar5 = true;
  }
  else {
    if (*psVar13 != 10) {
      return 0;
    }
    bVar5 = false;
  }
  thunk_FUN_037f9a0c((int)psVar13 + DAT_06007220);
  uVar1 = (uint)(psVar13 + 0x398) & 3;
  uVar7 = *(uint *)((uint)(psVar13 + 0x398) & 0xfffffffc);
  if (uVar7 >> uVar1 * 8 != 0 || uVar7 << uVar1 * -8 + 0x20 != 0) {
    if (bVar5) {
      thunk_FUN_037faf70();
      uVar14 = psVar13[0xbf];
      thunk_FUN_037faf84();
    }
    else {
      uVar14 = 1;
    }
    uVar1 = DAT_06007228;
    local_4c = 0;
    puVar12 = (ushort *)((int)psVar13 + DAT_06007224);
    local_38 = 1;
    do {
      uVar2 = *puVar12;
      uVar7 = uVar1;
      uVar4 = uVar1;
      while (uVar10 = (uint)uVar2, uVar10 != uVar1) {
        puVar11 = (ushort *)(psVar13 + uVar10 * 0x10 + 0x17a);
        if (param_1 == 0) {
          puVar11[4] = puVar11[4] | puVar11[5] & ~param_2;
          puVar11[3] = puVar11[3] & ~puVar11[4];
        }
        puVar11[3] = puVar11[3] & uVar14;
        puVar11[5] = 0;
        uVar3 = (ushort)uVar1;
        if ((puVar11[3] == 0) || (((puVar11[1] & 8) == 0 && (puVar11[9] == 0)))) {
          puVar8 = (undefined2 *)thunk_FUN_03807424();
          *puVar8 = 0x81;
          if (puVar11[3] == 0) {
            puVar8[1] = 0;
          }
          else {
            puVar8[1] = 0xf;
          }
          puVar8[4] = 0x14;
          puVar8[5] = puVar11[1];
          puVar8[6] = puVar11[2];
          puVar8[7] = puVar11[3];
          puVar8[8] = puVar11[4];
          puVar8[0xc] = puVar11[7];
          uVar10 = (uint)(puVar11 + 10) & 3;
          uVar9 = *(uint *)((uint)(puVar11 + 10) & 0xfffffffc);
          *(uint *)(puVar8 + 10) = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
          uVar10 = (uint)(puVar11 + 0xc) & 3;
          uVar9 = *(uint *)((uint)(puVar11 + 0xc) & 0xfffffffc);
          *(uint *)(puVar8 + 0xe) = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
          uVar10 = (uint)(puVar11 + 0xe) & 3;
          uVar9 = *(uint *)((uint)(puVar11 + 0xe) & 0xfffffffc);
          *(uint *)(puVar8 + 0x10) = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
          puVar8[0xd] = puVar11[8];
          thunk_FUN_038074cc();
          if (*puVar11 == uVar1) {
            puVar12[1] = uVar3;
          }
          *puVar12 = *puVar11;
          *puVar11 = uVar3;
          if ((ushort)psVar13[0x37b] == uVar1) {
            psVar13[0x37a] = uVar2;
          }
          else {
            psVar13[(uint)(ushort)psVar13[0x37b] * 0x10 + 0x17a] = uVar2;
          }
          psVar13[0x37b] = uVar2;
          uVar10 = uVar4;
          local_44 = uVar7;
        }
        else {
          if (puVar11[9] != 0) {
            puVar11[9] = puVar11[9] - 1;
          }
          if (*puVar11 == uVar1) {
            puVar12[1] = uVar3;
          }
          *puVar12 = *puVar11;
          *puVar11 = uVar3;
          local_48 = local_38;
          local_44 = uVar10;
          if (uVar4 != uVar1) {
            psVar13[uVar4 * 0x10 + 0x17a] = uVar2;
            local_44 = uVar7;
          }
        }
        uVar7 = local_44;
        uVar4 = uVar10;
        uVar2 = *puVar12;
      }
      if (uVar4 != uVar1) {
        psVar13[uVar4 * 0x10 + 0x17a] = psVar13[local_4c * 2 + 900];
        if ((ushort)psVar13[local_4c * 2 + 0x385] == uVar1) {
          psVar13[local_4c * 2 + 0x385] = (short)uVar4;
        }
        psVar13[local_4c * 2 + 900] = (short)uVar7;
      }
      puVar12 = puVar12 + 2;
      local_4c = local_4c + 1;
    } while (local_4c < 4);
    psVar13[0x398] = 0;
    psVar13[0x399] = 0;
    thunk_FUN_037f999c((int)psVar13 + DAT_06007220);
    return local_48;
  }
  thunk_FUN_037f999c((int)psVar13 + DAT_06007220);
  return 0;
}

