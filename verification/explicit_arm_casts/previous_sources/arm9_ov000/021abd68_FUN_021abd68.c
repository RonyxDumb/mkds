/* Decompiled C draft; module arm9_ov000; ROM address 021abd68. No matching claim. */
#include "types.h"
#include "deps/021abd68_FUN_021abd68.h"

void FUN_021abd68(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  int local_b8;
  int *local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_54 [15];
  int local_18;
  
  local_c4 = *param_1;
  uVar3 = param_1[1];
  local_c0 = param_1[2];
  local_bc = param_1[3];
  uVar5 = param_1[4];
  FUN_021ac34c(local_54,param_2,0x40);
  iVar2 = 0;
  local_b8 = 0;
  local_b4 = local_54;
  do {
    uVar5 = uVar5 + *local_b4 +
                    (local_c4 << 5 | local_c4 >> 0x1b) + (local_bc ^ uVar3 & (local_c0 ^ local_bc))
                    + DAT_021ac1ac;
    uVar3 = uVar3 << 0x1e | uVar3 >> 2;
    local_bc = local_bc +
               local_54[iVar2 + 1] +
               (uVar5 * 0x20 | uVar5 >> 0x1b) + (local_c0 ^ local_c4 & (uVar3 ^ local_c0)) +
               DAT_021ac1ac;
    local_c4 = local_c4 << 0x1e | local_c4 >> 2;
    local_c0 = local_c0 +
               local_54[iVar2 + 2] +
               (local_bc * 0x20 | local_bc >> 0x1b) + (uVar3 ^ uVar5 & (local_c4 ^ uVar3)) +
               DAT_021ac1ac;
    uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar3 = uVar3 + local_54[iVar2 + 3] +
                    (local_c0 * 0x20 | local_c0 >> 0x1b) +
                    (local_c4 ^ local_bc & (uVar5 ^ local_c4)) + DAT_021ac1ac;
    local_bc = local_bc * 0x40000000 | local_bc >> 2;
    local_c4 = local_c4 +
               local_54[iVar2 + 4] +
               (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar5 ^ local_c0 & (local_bc ^ uVar5)) +
               DAT_021ac1ac;
    local_c0 = local_c0 * 0x40000000 | local_c0 >> 2;
    local_b4 = local_b4 + 5;
    iVar2 = iVar2 + 5;
    local_b8 = local_b8 + 1;
  } while (local_b8 < 3);
  uVar5 = uVar5 + local_18 +
                  (local_c4 * 0x20 | local_c4 >> 0x1b) + (local_bc ^ uVar3 & (local_c0 ^ local_bc))
                  + DAT_021ac1ac;
  uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
  iVar2 = FUN_021ac3a8(0,local_54);
  local_bc = local_bc +
             (uVar5 * 0x20 | uVar5 >> 0x1b) + (local_c0 ^ local_c4 & (uVar3 ^ local_c0)) + iVar2 +
             DAT_021ac1ac;
  uVar4 = local_c4 * 0x40000000 | local_c4 >> 2;
  iVar2 = FUN_021ac3a8(1,local_54);
  local_c0 = local_c0 +
             (local_bc * 0x20 | local_bc >> 0x1b) + (uVar3 ^ uVar5 & (uVar4 ^ uVar3)) + iVar2 +
             DAT_021ac1ac;
  uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
  iVar2 = FUN_021ac3a8(2,local_54);
  uVar3 = uVar3 + (local_c0 * 0x20 | local_c0 >> 0x1b) + (uVar4 ^ local_bc & (uVar5 ^ uVar4)) +
                  iVar2 + DAT_021ac1ac;
  uVar6 = local_bc * 0x40000000 | local_bc >> 2;
  iVar2 = FUN_021ac3a8(3,local_54);
  uVar4 = uVar4 + (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar5 ^ local_c0 & (uVar6 ^ uVar5)) + iVar2 +
                  DAT_021ac1ac;
  local_b0 = local_c0 * 0x40000000 | local_c0 >> 2;
  local_ac = 4;
  local_a0 = 0;
  do {
    iVar2 = FUN_021ac3a8(local_ac,local_54);
    uVar5 = uVar5 + (uVar4 << 5 | uVar4 >> 0x1b) + (uVar6 ^ uVar3 ^ local_b0) + iVar2 + DAT_021ac1b0
    ;
    uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
    iVar2 = FUN_021ac3a8(local_ac + 1,local_54);
    uVar6 = uVar6 + (uVar5 * 0x20 | uVar5 >> 0x1b) + (local_b0 ^ uVar4 ^ uVar3) + iVar2 +
                    DAT_021ac1b0;
    uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar1 = local_ac + 2U & 0xf;
    iVar2 = FUN_021ac3a8(uVar1,local_54);
    local_b0 = local_b0 +
               (uVar6 * 0x20 | uVar6 >> 0x1b) + (uVar3 ^ uVar5 ^ uVar4) + iVar2 + DAT_021ac1b0;
    uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
    iVar2 = FUN_021ac3a8(uVar1 + 1,local_54);
    uVar3 = uVar3 + (local_b0 * 0x20 | local_b0 >> 0x1b) + (uVar4 ^ uVar6 ^ uVar5) + iVar2 +
                    DAT_021ac1b0;
    uVar6 = uVar6 * 0x40000000 | uVar6 >> 2;
    iVar2 = FUN_021ac3a8(uVar1 + 2,local_54);
    uVar4 = uVar4 + (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar5 ^ local_b0 ^ uVar6) + iVar2 +
                    DAT_021ac1b0;
    local_b0 = local_b0 * 0x40000000 | local_b0 >> 2;
    local_ac = uVar1 + 3;
    local_a0 = local_a0 + 1;
  } while (local_a0 < 4);
  local_a4 = 0;
  do {
    iVar2 = FUN_021ac3a8(local_ac,local_54);
    uVar5 = uVar5 + (((uVar4 << 5 | uVar4 >> 0x1b) + (uVar3 & (local_b0 | uVar6) | local_b0 & uVar6)
                     + iVar2) - DAT_021ac1b4);
    uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
    iVar2 = FUN_021ac3a8(local_ac + 1,local_54);
    uVar6 = uVar6 + (((uVar5 * 0x20 | uVar5 >> 0x1b) +
                      (uVar4 & (uVar3 | local_b0) | uVar3 & local_b0) + iVar2) - DAT_021ac1b4);
    uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
    iVar2 = FUN_021ac3a8(local_ac + 2,local_54);
    local_b0 = local_b0 +
               (((uVar6 * 0x20 | uVar6 >> 0x1b) + (uVar5 & (uVar4 | uVar3) | uVar4 & uVar3) + iVar2)
               - DAT_021ac1b4);
    uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar1 = local_ac + 3U & 0xf;
    iVar2 = FUN_021ac3a8(uVar1,local_54);
    uVar3 = uVar3 + (((local_b0 * 0x20 | local_b0 >> 0x1b) +
                      (uVar6 & (uVar5 | uVar4) | uVar5 & uVar4) + iVar2) - DAT_021ac1b4);
    uVar6 = uVar6 * 0x40000000 | uVar6 >> 2;
    iVar2 = FUN_021ac3a8(uVar1 + 1,local_54);
    uVar4 = uVar4 + (((uVar3 * 0x20 | uVar3 >> 0x1b) + (local_b0 & (uVar6 | uVar5) | uVar6 & uVar5)
                     + iVar2) - DAT_021ac344);
    local_b0 = local_b0 * 0x40000000 | local_b0 >> 2;
    local_ac = uVar1 + 2;
    local_a4 = local_a4 + 1;
  } while (local_a4 < 4);
  local_a8 = 0;
  do {
    iVar2 = FUN_021ac3a8(local_ac,local_54);
    uVar5 = uVar5 + (((uVar4 << 5 | uVar4 >> 0x1b) + (uVar6 ^ uVar3 ^ local_b0) + iVar2) -
                    DAT_021ac348);
    uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
    iVar2 = FUN_021ac3a8(local_ac + 1,local_54);
    uVar6 = uVar6 + (((uVar5 * 0x20 | uVar5 >> 0x1b) + (local_b0 ^ uVar4 ^ uVar3) + iVar2) -
                    DAT_021ac348);
    uVar4 = uVar4 * 0x40000000 | uVar4 >> 2;
    iVar2 = FUN_021ac3a8(local_ac + 2,local_54);
    local_b0 = local_b0 +
               (((uVar6 * 0x20 | uVar6 >> 0x1b) + (uVar3 ^ uVar5 ^ uVar4) + iVar2) - DAT_021ac348);
    uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
    iVar2 = FUN_021ac3a8(local_ac + 3,local_54);
    uVar3 = uVar3 + (((local_b0 * 0x20 | local_b0 >> 0x1b) + (uVar4 ^ uVar6 ^ uVar5) + iVar2) -
                    DAT_021ac348);
    uVar6 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar1 = local_ac + 4U & 0xf;
    iVar2 = FUN_021ac3a8(uVar1,local_54);
    uVar4 = uVar4 + (((uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar5 ^ local_b0 ^ uVar6) + iVar2) -
                    DAT_021ac348);
    local_b0 = local_b0 * 0x40000000 | local_b0 >> 2;
    local_ac = uVar1 + 1;
    local_a8 = local_a8 + 1;
  } while (local_a8 < 4);
  *param_1 = *param_1 + uVar4;
  param_1[1] = param_1[1] + uVar3;
  param_1[2] = param_1[2] + local_b0;
  param_1[3] = param_1[3] + uVar6;
  param_1[4] = param_1[4] + uVar5;
  return;
}

