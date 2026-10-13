/* Decompiled C draft; module arm9_ov003; ROM address 021bbd9c. No matching claim. */
#include "types.h"
#include "deps/021bbd9c_FUN_021bbd9c.h"

void FUN_021bbd9c(uint *param_1,int param_2,byte *param_3,undefined1 *param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_6c;
  uint local_68;
  int local_64;
  uint local_44;
  
  iVar1 = DAT_021bc1b4;
  local_6c = *param_1 ^
             (uint)param_3[3] ^
             (uint)param_3[2] << 8 ^ (uint)*param_3 << 0x18 ^ (uint)param_3[1] << 0x10;
  local_68 = param_1[1] ^
             (uint)param_3[7] ^
             (uint)param_3[6] << 8 ^ (uint)param_3[4] << 0x18 ^ (uint)param_3[5] << 0x10;
  local_44 = param_1[2] ^
             (uint)param_3[0xb] ^
             (uint)param_3[10] << 8 ^ (uint)param_3[8] << 0x18 ^ (uint)param_3[9] << 0x10;
  uVar7 = param_1[3] ^
          (uint)param_3[0xf] ^
          (uint)param_3[0xe] << 8 ^ (uint)param_3[0xc] << 0x18 ^ (uint)param_3[0xd] << 0x10;
  local_64 = param_2 >> 1;
  while( true ) {
    uVar3 = param_1[4] ^
            *(uint *)(DAT_021bc1a4 + (local_68 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1a8 + (local_44 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1ac + (local_6c >> 0x18) * 4) ^
            *(uint *)(DAT_021bc1b0 + (uVar7 >> 0x10 & 0xff) * 4);
    uVar4 = param_1[5] ^
            *(uint *)(DAT_021bc1a4 + (local_44 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1a8 + (uVar7 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1ac + (local_68 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc1b0 + (local_6c >> 0x10 & 0xff) * 4);
    uVar6 = param_1[6] ^
            *(uint *)(DAT_021bc1a4 + (uVar7 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1a8 + (local_6c >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1ac + (local_44 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc1b0 + (local_68 >> 0x10 & 0xff) * 4);
    uVar7 = param_1[7] ^
            *(uint *)(DAT_021bc1a4 + (local_6c & 0xff) * 4) ^
            *(uint *)(DAT_021bc1a8 + (local_68 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1ac + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc1b0 + (local_44 >> 0x10 & 0xff) * 4);
    puVar2 = param_1 + 8;
    local_64 = local_64 + -1;
    if (local_64 == 0) break;
    local_6c = *puVar2 ^ *(uint *)(DAT_021bc1a4 + (uVar4 & 0xff) * 4) ^
                         *(uint *)(DAT_021bc1a8 + (uVar6 >> 8 & 0xff) * 4) ^
                         *(uint *)(DAT_021bc1ac + (uVar3 >> 0x18) * 4) ^
                         *(uint *)(DAT_021bc1b0 + (uVar7 >> 0x10 & 0xff) * 4);
    local_68 = param_1[9] ^
               *(uint *)(DAT_021bc1a4 + (uVar6 & 0xff) * 4) ^
               *(uint *)(DAT_021bc1a8 + (uVar7 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_021bc1ac + (uVar4 >> 0x18) * 4) ^
               *(uint *)(DAT_021bc1b0 + (uVar3 >> 0x10 & 0xff) * 4);
    local_44 = param_1[10] ^
               *(uint *)(DAT_021bc1a4 + (uVar7 & 0xff) * 4) ^
               *(uint *)(DAT_021bc1a8 + (uVar3 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_021bc1ac + (uVar6 >> 0x18) * 4) ^
               *(uint *)(DAT_021bc1b0 + (uVar4 >> 0x10 & 0xff) * 4);
    uVar7 = param_1[0xb] ^
            *(uint *)(DAT_021bc1a4 + (uVar3 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1a8 + (uVar4 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc1ac + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc1b0 + (uVar6 >> 0x10 & 0xff) * 4);
    param_1 = puVar2;
  }
  uVar5 = *puVar2 ^ *(uint *)(DAT_021bc1b4 + (uVar4 & 0xff) * 4) & 0xff ^
                    *(uint *)(DAT_021bc1b4 + (uVar6 >> 8 & 0xff) * 4) & DAT_021bc1b8 ^
                    *(uint *)(DAT_021bc1b4 + (uVar3 >> 0x18) * 4) & DAT_021bc1bc ^
                    *(uint *)(DAT_021bc1b4 + (uVar7 >> 0x10 & 0xff) * 4) & DAT_021bc1c0;
  *param_4 = (char)(uVar5 >> 0x18);
  param_4[1] = (char)(uVar5 >> 0x10);
  param_4[2] = (char)(uVar5 >> 8);
  param_4[3] = (char)uVar5;
  uVar5 = param_1[9] ^
          *(uint *)(iVar1 + (uVar6 & 0xff) * 4) & 0xff ^
          *(uint *)(iVar1 + (uVar7 >> 8 & 0xff) * 4) & DAT_021bc1b8 ^
          *(uint *)(iVar1 + (uVar4 >> 0x18) * 4) & DAT_021bc1bc ^
          *(uint *)(iVar1 + (uVar3 >> 0x10 & 0xff) * 4) & DAT_021bc1c0;
  param_4[4] = (char)(uVar5 >> 0x18);
  param_4[5] = (char)(uVar5 >> 0x10);
  param_4[6] = (char)(uVar5 >> 8);
  param_4[7] = (char)uVar5;
  uVar5 = param_1[10] ^
          *(uint *)(iVar1 + (uVar7 & 0xff) * 4) & 0xff ^
          *(uint *)(iVar1 + (uVar3 >> 8 & 0xff) * 4) & DAT_021bc1b8 ^
          *(uint *)(iVar1 + (uVar6 >> 0x18) * 4) & DAT_021bc1bc ^
          *(uint *)(iVar1 + (uVar4 >> 0x10 & 0xff) * 4) & DAT_021bc1c0;
  param_4[8] = (char)(uVar5 >> 0x18);
  param_4[9] = (char)(uVar5 >> 0x10);
  param_4[10] = (char)(uVar5 >> 8);
  param_4[0xb] = (char)uVar5;
  uVar7 = param_1[0xb] ^
          *(uint *)(iVar1 + (uVar3 & 0xff) * 4) & 0xff ^
          *(uint *)(iVar1 + (uVar4 >> 8 & 0xff) * 4) & DAT_021bc1b8 ^
          *(uint *)(iVar1 + (uVar7 >> 0x18) * 4) & DAT_021bc1bc ^
          *(uint *)(iVar1 + (uVar6 >> 0x10 & 0xff) * 4) & DAT_021bc1c0;
  param_4[0xc] = (char)(uVar7 >> 0x18);
  param_4[0xd] = (char)(uVar7 >> 0x10);
  param_4[0xe] = (char)(uVar7 >> 8);
  param_4[0xf] = (char)uVar7;
  return;
}

