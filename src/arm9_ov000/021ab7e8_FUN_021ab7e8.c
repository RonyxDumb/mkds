/* Decompiled C draft; module arm9_ov000; ROM address 021ab7e8. No matching claim. */
#include "types.h"
#include "deps/021ab7e8_FUN_021ab7e8.h"

void FUN_021ab7e8(uint *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_124;
  byte *local_120;
  int *local_11c;
  byte *local_118;
  int *local_114;
  byte *local_110;
  int *local_10c;
  byte *local_108;
  int *local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int aiStack_54 [16];
  
  uVar3 = *param_1;
  uVar2 = param_1[1];
  uVar4 = param_1[2];
  uVar5 = param_1[3];
  FUN_021abc04(aiStack_54,param_2,0x40);
  iVar1 = 0;
  local_124 = 0;
  local_108 = DAT_021abba0;
  local_104 = DAT_021abba4;
  do {
    uVar3 = uVar3 + *local_104 + (uVar5 ^ uVar2 & (uVar4 ^ uVar5)) + aiStack_54[*local_108];
    uVar3 = uVar2 + (uVar3 * 0x80 | uVar3 >> 0x19);
    uVar5 = uVar5 + DAT_021abba4[iVar1 + 1] +
                    (uVar4 ^ uVar3 & (uVar2 ^ uVar4)) + aiStack_54[DAT_021abba0[iVar1 + 1]];
    uVar5 = uVar3 + (uVar5 * 0x1000 | uVar5 >> 0x14);
    uVar4 = uVar4 + DAT_021abba4[iVar1 + 2] +
                    (uVar2 ^ uVar5 & (uVar3 ^ uVar2)) + aiStack_54[DAT_021abba0[iVar1 + 2]];
    uVar4 = uVar5 + (uVar4 * 0x20000 | uVar4 >> 0xf);
    uVar2 = uVar2 + DAT_021abba4[iVar1 + 3] +
                    (uVar3 ^ uVar4 & (uVar5 ^ uVar3)) + aiStack_54[DAT_021abba0[iVar1 + 3]];
    uVar2 = uVar4 + (uVar2 * 0x400000 | uVar2 >> 10);
    local_108 = local_108 + 4;
    local_104 = local_104 + 4;
    iVar1 = iVar1 + 4;
    local_124 = local_124 + 1;
  } while (local_124 < 4);
  local_f8 = 0;
  local_110 = DAT_021abba0 + iVar1;
  local_10c = DAT_021abba4 + iVar1;
  do {
    uVar3 = uVar3 + *local_10c + aiStack_54[*local_110] + (uVar2 & uVar5 | uVar4 & ~uVar5);
    uVar3 = uVar2 + (uVar3 * 0x20 | uVar3 >> 0x1b);
    uVar5 = uVar5 + DAT_021abba4[iVar1 + 1] +
                    aiStack_54[DAT_021abba0[iVar1 + 1]] + (uVar3 & uVar4 | uVar2 & ~uVar4);
    uVar5 = uVar3 + (uVar5 * 0x200 | uVar5 >> 0x17);
    uVar4 = uVar4 + DAT_021abba4[iVar1 + 2] +
                    aiStack_54[DAT_021abba0[iVar1 + 2]] + (uVar5 & uVar2 | uVar3 & ~uVar2);
    uVar4 = uVar5 + (uVar4 * 0x4000 | uVar4 >> 0x12);
    uVar2 = uVar2 + DAT_021abba4[iVar1 + 3] +
                    aiStack_54[DAT_021abba0[iVar1 + 3]] + (uVar4 & uVar3 | uVar5 & ~uVar3);
    uVar2 = uVar4 + (uVar2 * 0x100000 | uVar2 >> 0xc);
    local_110 = local_110 + 4;
    local_10c = local_10c + 4;
    iVar1 = iVar1 + 4;
    local_f8 = local_f8 + 1;
  } while (local_f8 < 4);
  local_fc = 0;
  local_118 = DAT_021abba0 + iVar1;
  local_114 = DAT_021abba4 + iVar1;
  do {
    uVar3 = uVar3 + *local_114 + (uVar5 ^ uVar2 ^ uVar4) + aiStack_54[*local_118];
    uVar3 = uVar2 + (uVar3 * 0x10 | uVar3 >> 0x1c);
    uVar5 = uVar5 + DAT_021abba4[iVar1 + 1] +
                    (uVar4 ^ uVar3 ^ uVar2) + aiStack_54[DAT_021abba0[iVar1 + 1]];
    uVar5 = uVar3 + (uVar5 * 0x800 | uVar5 >> 0x15);
    uVar4 = uVar4 + DAT_021abba4[iVar1 + 2] +
                    (uVar2 ^ uVar5 ^ uVar3) + aiStack_54[DAT_021abba0[iVar1 + 2]];
    uVar4 = uVar5 + (uVar4 * 0x10000 | uVar4 >> 0x10);
    uVar2 = uVar2 + DAT_021abba4[iVar1 + 3] +
                    (uVar3 ^ uVar4 ^ uVar5) + aiStack_54[DAT_021abba0[iVar1 + 3]];
    uVar2 = uVar4 + (uVar2 * 0x800000 | uVar2 >> 9);
    local_118 = local_118 + 4;
    local_114 = local_114 + 4;
    iVar1 = iVar1 + 4;
    local_fc = local_fc + 1;
  } while (local_fc < 4);
  local_100 = 0;
  local_120 = DAT_021abba0 + iVar1;
  local_11c = DAT_021abba4 + iVar1;
  do {
    uVar3 = uVar3 + *local_11c + (uVar4 ^ (uVar2 | ~uVar5)) + aiStack_54[*local_120];
    uVar3 = uVar2 + (uVar3 * 0x40 | uVar3 >> 0x1a);
    uVar5 = uVar5 + DAT_021abba4[iVar1 + 1] +
                    (uVar2 ^ (uVar3 | ~uVar4)) + aiStack_54[DAT_021abba0[iVar1 + 1]];
    uVar5 = uVar3 + (uVar5 * 0x400 | uVar5 >> 0x16);
    uVar4 = uVar4 + DAT_021abba4[iVar1 + 2] +
                    (uVar3 ^ (uVar5 | ~uVar2)) + aiStack_54[DAT_021abba0[iVar1 + 2]];
    uVar4 = uVar5 + (uVar4 * 0x8000 | uVar4 >> 0x11);
    uVar2 = uVar2 + DAT_021abba4[iVar1 + 3] +
                    (uVar5 ^ (uVar4 | ~uVar3)) + aiStack_54[DAT_021abba0[iVar1 + 3]];
    uVar2 = uVar4 + (uVar2 * 0x200000 | uVar2 >> 0xb);
    local_120 = local_120 + 4;
    local_11c = local_11c + 4;
    iVar1 = iVar1 + 4;
    local_100 = local_100 + 1;
  } while (local_100 < 4);
  *param_1 = *param_1 + uVar3;
  param_1[1] = param_1[1] + uVar2;
  param_1[2] = param_1[2] + uVar4;
  param_1[3] = param_1[3] + uVar5;
  return;
}

