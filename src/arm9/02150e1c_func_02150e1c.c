/* Decompiled C draft; module arm9; ROM address 02150e1c. No matching claim. */
#include "types.h"
#include "deps/02150e1c_func_02150e1c.h"

void func_02150e1c(uint *param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_ac [16];
  uint local_6c [16];
  int local_2c;
  
  uVar3 = *param_1;
  uVar7 = param_1[1];
  uVar10 = param_1[2];
  uVar11 = param_1[3];
  uVar12 = param_1[4];
  local_2c = param_3;
  do {
    iVar4 = 0;
    uVar2 = param_2;
    puVar5 = local_ac;
    do {
      uVar9 = uVar11;
      uVar11 = uVar10;
      uVar8 = uVar3;
      param_2 = uVar2 + 4;
      uVar10 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
               *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar10 = DAT_02150e08 & (uVar10 >> 0x18 | uVar10 << 8) |
               (uVar10 & DAT_02150e08) >> 8 | (uVar10 & DAT_02150e08) << 0x18;
      puVar5[0x10] = uVar10;
      *puVar5 = uVar10;
      uVar3 = DAT_02150e0c + uVar12 + (uVar8 >> 0x1b | uVar8 << 5) + uVar10 +
              ((uVar11 ^ uVar9) & uVar7 ^ uVar9);
      uVar10 = uVar7 >> 2 | uVar7 << 0x1e;
      iVar4 = iVar4 + 4;
      uVar2 = param_2;
      puVar5 = puVar5 + 1;
      uVar7 = uVar8;
      uVar12 = uVar9;
    } while (iVar4 < 0x40);
    iVar4 = 0;
    puVar5 = local_ac;
    do {
      uVar12 = uVar11;
      uVar11 = uVar10;
      uVar7 = uVar3;
      uVar10 = *puVar5 ^ puVar5[2] ^ puVar5[8] ^ puVar5[0xd];
      uVar10 = uVar10 >> 0x1f | uVar10 << 1;
      puVar5[0x10] = uVar10;
      puVar6 = puVar5 + 1;
      *puVar5 = uVar10;
      uVar3 = uVar10 + uVar9 + DAT_02150e0c + (uVar7 >> 0x1b | uVar7 << 5) +
              ((uVar11 ^ uVar12) & uVar8 ^ uVar12);
      uVar10 = uVar8 >> 2 | uVar8 << 0x1e;
      iVar4 = iVar4 + 4;
      puVar5 = puVar6;
      uVar8 = uVar7;
      uVar9 = uVar12;
    } while (iVar4 < 0x10);
    iVar4 = 0;
    do {
      uVar8 = uVar11;
      uVar11 = uVar10;
      uVar2 = uVar3;
      uVar10 = *puVar6 ^ puVar6[2] ^ puVar6[8] ^ puVar6[0xd];
      uVar10 = uVar10 >> 0x1f | uVar10 << 1;
      puVar6[0x10] = uVar10;
      *puVar6 = uVar10;
      uVar3 = uVar10 + uVar12 + DAT_02150e10 + (uVar2 >> 0x1b | uVar2 << 5) +
              (uVar7 ^ uVar11 ^ uVar8);
      uVar10 = uVar7 >> 2 | uVar7 << 0x1e;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 1;
      if (iVar4 == 0xc) {
        puVar6 = local_ac;
      }
      uVar7 = uVar2;
      uVar12 = uVar8;
    } while (iVar4 < 0x14);
    iVar4 = 0;
    do {
      uVar13 = uVar11;
      uVar11 = uVar10;
      uVar9 = uVar3;
      uVar10 = *puVar6 ^ puVar6[2] ^ puVar6[8] ^ puVar6[0xd];
      uVar10 = uVar10 >> 0x1f | uVar10 << 1;
      puVar6[0x10] = uVar10;
      *puVar6 = uVar10;
      uVar3 = uVar10 + uVar8 + DAT_02150e14 + (uVar9 >> 0x1b | uVar9 << 5) +
              ((uVar2 | uVar11) & uVar13 | uVar2 & uVar11);
      uVar10 = uVar2 >> 2 | uVar2 << 0x1e;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 1;
      if (iVar4 == 8) {
        puVar6 = local_ac;
      }
      uVar2 = uVar9;
      uVar8 = uVar13;
    } while (iVar4 < 0x14);
    iVar4 = 0;
    do {
      uVar12 = uVar11;
      uVar11 = uVar10;
      uVar7 = uVar3;
      uVar10 = *puVar6 ^ puVar6[2] ^ puVar6[8] ^ puVar6[0xd];
      uVar10 = uVar10 >> 0x1f | uVar10 << 1;
      puVar6[0x10] = uVar10;
      *puVar6 = uVar10;
      uVar3 = uVar10 + uVar13 + DAT_02150e18 + (uVar7 >> 0x1b | uVar7 << 5) +
              (uVar9 ^ uVar11 ^ uVar12);
      uVar10 = uVar9 >> 2 | uVar9 << 0x1e;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 1;
      if (iVar4 == 4) {
        puVar6 = local_ac;
      }
      uVar9 = uVar7;
      uVar13 = uVar12;
    } while (iVar4 < 0x14);
    uVar3 = uVar3 + *param_1;
    uVar7 = uVar7 + param_1[1];
    uVar10 = uVar10 + param_1[2];
    uVar11 = uVar11 + param_1[3];
    uVar12 = uVar12 + param_1[4];
    *param_1 = uVar3;
    param_1[1] = uVar7;
    param_1[2] = uVar10;
    param_1[3] = uVar11;
    param_1[4] = uVar12;
    iVar4 = local_2c + -0x40;
    bVar1 = 0x3f < local_2c;
    local_2c = iVar4;
  } while (iVar4 != 0 && bVar1);
  return;
}

