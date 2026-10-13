/* Decompiled C draft; module arm9_ov003; ROM address 021bc1c4. No matching claim. */
#include "types.h"
#include "deps/021bc1c4_FUN_021bc1c4.h"

void FUN_021bc1c4(uint *param_1,int param_2,byte *param_3,undefined1 *param_4)

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
  
  iVar1 = DAT_021bc5d4;
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
            *(uint *)(DAT_021bc5c4 + (uVar7 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5c8 + (local_44 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5cc + (local_6c >> 0x18) * 4) ^
            *(uint *)(DAT_021bc5d0 + (local_68 >> 0x10 & 0xff) * 4);
    uVar4 = param_1[5] ^
            *(uint *)(DAT_021bc5c4 + (local_6c & 0xff) * 4) ^
            *(uint *)(DAT_021bc5c8 + (uVar7 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5cc + (local_68 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc5d0 + (local_44 >> 0x10 & 0xff) * 4);
    uVar5 = param_1[6] ^
            *(uint *)(DAT_021bc5c4 + (local_68 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5c8 + (local_6c >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5cc + (local_44 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc5d0 + (uVar7 >> 0x10 & 0xff) * 4);
    uVar7 = param_1[7] ^
            *(uint *)(DAT_021bc5c4 + (local_44 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5c8 + (local_68 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5cc + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc5d0 + (local_6c >> 0x10 & 0xff) * 4);
    puVar2 = param_1 + 8;
    local_64 = local_64 + -1;
    if (local_64 == 0) break;
    local_6c = *puVar2 ^ *(uint *)(DAT_021bc5c4 + (uVar7 & 0xff) * 4) ^
                         *(uint *)(DAT_021bc5c8 + (uVar5 >> 8 & 0xff) * 4) ^
                         *(uint *)(DAT_021bc5cc + (uVar3 >> 0x18) * 4) ^
                         *(uint *)(DAT_021bc5d0 + (uVar4 >> 0x10 & 0xff) * 4);
    local_68 = param_1[9] ^
               *(uint *)(DAT_021bc5c4 + (uVar3 & 0xff) * 4) ^
               *(uint *)(DAT_021bc5c8 + (uVar7 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_021bc5cc + (uVar4 >> 0x18) * 4) ^
               *(uint *)(DAT_021bc5d0 + (uVar5 >> 0x10 & 0xff) * 4);
    local_44 = param_1[10] ^
               *(uint *)(DAT_021bc5c4 + (uVar4 & 0xff) * 4) ^
               *(uint *)(DAT_021bc5c8 + (uVar3 >> 8 & 0xff) * 4) ^
               *(uint *)(DAT_021bc5cc + (uVar5 >> 0x18) * 4) ^
               *(uint *)(DAT_021bc5d0 + (uVar7 >> 0x10 & 0xff) * 4);
    uVar7 = param_1[0xb] ^
            *(uint *)(DAT_021bc5c4 + (uVar5 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5c8 + (uVar4 >> 8 & 0xff) * 4) ^
            *(uint *)(DAT_021bc5cc + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_021bc5d0 + (uVar3 >> 0x10 & 0xff) * 4);
    param_1 = puVar2;
  }
  uVar6 = *puVar2 ^ *(uint *)(DAT_021bc5d4 + (uVar7 & 0xff) * 4) & 0xff ^
                    *(uint *)(DAT_021bc5d4 + (uVar5 >> 8 & 0xff) * 4) & DAT_021bc5d8 ^
                    *(uint *)(DAT_021bc5d4 + (uVar3 >> 0x18) * 4) & DAT_021bc5dc ^
                    *(uint *)(DAT_021bc5d4 + (uVar4 >> 0x10 & 0xff) * 4) & DAT_021bc5e0;
  *param_4 = (char)(uVar6 >> 0x18);
  param_4[1] = (char)(uVar6 >> 0x10);
  param_4[2] = (char)(uVar6 >> 8);
  param_4[3] = (char)uVar6;
  uVar6 = param_1[9] ^
          *(uint *)(iVar1 + (uVar3 & 0xff) * 4) & 0xff ^
          *(uint *)(iVar1 + (uVar7 >> 8 & 0xff) * 4) & DAT_021bc5d8 ^
          *(uint *)(iVar1 + (uVar4 >> 0x18) * 4) & DAT_021bc5dc ^
          *(uint *)(iVar1 + (uVar5 >> 0x10 & 0xff) * 4) & DAT_021bc5e0;
  param_4[4] = (char)(uVar6 >> 0x18);
  param_4[5] = (char)(uVar6 >> 0x10);
  param_4[6] = (char)(uVar6 >> 8);
  param_4[7] = (char)uVar6;
  uVar6 = param_1[10] ^
          *(uint *)(iVar1 + (uVar4 & 0xff) * 4) & 0xff ^
          *(uint *)(iVar1 + (uVar3 >> 8 & 0xff) * 4) & DAT_021bc5d8 ^
          *(uint *)(iVar1 + (uVar5 >> 0x18) * 4) & DAT_021bc5dc ^
          *(uint *)(iVar1 + (uVar7 >> 0x10 & 0xff) * 4) & DAT_021bc5e0;
  param_4[8] = (char)(uVar6 >> 0x18);
  param_4[9] = (char)(uVar6 >> 0x10);
  param_4[10] = (char)(uVar6 >> 8);
  param_4[0xb] = (char)uVar6;
  uVar7 = param_1[0xb] ^
          *(uint *)(iVar1 + (uVar5 & 0xff) * 4) & 0xff ^
          *(uint *)(iVar1 + (uVar4 >> 8 & 0xff) * 4) & DAT_021bc5d8 ^
          *(uint *)(iVar1 + (uVar7 >> 0x18) * 4) & DAT_021bc5dc ^
          *(uint *)(iVar1 + (uVar3 >> 0x10 & 0xff) * 4) & DAT_021bc5e0;
  param_4[0xc] = (char)(uVar7 >> 0x18);
  param_4[0xd] = (char)(uVar7 >> 0x10);
  param_4[0xe] = (char)(uVar7 >> 8);
  param_4[0xf] = (char)uVar7;
  return;
}

