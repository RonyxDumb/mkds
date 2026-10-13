/* Decompiled C draft; module arm9_ov003; ROM address 021bc5e4. No matching claim. */
#include "types.h"
#include "deps/021bc5e4_FUN_021bc5e4.h"

int FUN_021bc5e4(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *local_1c;
  int local_18;
  
  iVar1 = FUN_021bc7a8();
  iVar5 = 0;
  iVar4 = iVar1 * 4;
  if (0 < iVar4) {
    puVar3 = param_1 + iVar1 * 4;
    local_1c = param_1;
    do {
      uVar2 = *local_1c;
      *local_1c = *puVar3;
      *puVar3 = uVar2;
      uVar2 = param_1[iVar5 + 1];
      param_1[iVar5 + 1] = param_1[iVar4 + 1];
      param_1[iVar4 + 1] = uVar2;
      uVar2 = param_1[iVar5 + 2];
      param_1[iVar5 + 2] = param_1[iVar4 + 2];
      param_1[iVar4 + 2] = uVar2;
      uVar2 = param_1[iVar5 + 3];
      param_1[iVar5 + 3] = param_1[iVar4 + 3];
      param_1[iVar4 + 3] = uVar2;
      local_1c = local_1c + 4;
      iVar5 = iVar5 + 4;
      puVar3 = puVar3 + -4;
      iVar4 = iVar4 + -4;
    } while (iVar5 < iVar4);
  }
  iVar4 = DAT_021bc794;
  local_18 = 1;
  if (1 < iVar1) {
    do {
      puVar3 = param_1 + 4;
      uVar2 = *puVar3;
      *puVar3 = *(uint *)(DAT_021bc798 + (*(uint *)(iVar4 + (uVar2 & 0xff) * 4) & 0xff) * 4) ^
                *(uint *)(DAT_021bc79c + (*(uint *)(iVar4 + (uVar2 >> 8 & 0xff) * 4) & 0xff) * 4) ^
                *(uint *)(DAT_021bc7a0 + (*(uint *)(iVar4 + (uVar2 >> 0x18) * 4) & 0xff) * 4) ^
                *(uint *)(DAT_021bc7a4 + (*(uint *)(iVar4 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff) * 4)
      ;
      uVar2 = param_1[5];
      param_1[5] = *(uint *)(DAT_021bc798 + (*(uint *)(iVar4 + (uVar2 & 0xff) * 4) & 0xff) * 4) ^
                   *(uint *)(DAT_021bc79c + (*(uint *)(iVar4 + (uVar2 >> 8 & 0xff) * 4) & 0xff) * 4)
                   ^ *(uint *)(DAT_021bc7a0 + (*(uint *)(iVar4 + (uVar2 >> 0x18) * 4) & 0xff) * 4) ^
                     *(uint *)(DAT_021bc7a4 +
                              (*(uint *)(iVar4 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff) * 4);
      uVar2 = param_1[6];
      param_1[6] = *(uint *)(DAT_021bc798 + (*(uint *)(iVar4 + (uVar2 & 0xff) * 4) & 0xff) * 4) ^
                   *(uint *)(DAT_021bc79c + (*(uint *)(iVar4 + (uVar2 >> 8 & 0xff) * 4) & 0xff) * 4)
                   ^ *(uint *)(DAT_021bc7a0 + (*(uint *)(iVar4 + (uVar2 >> 0x18) * 4) & 0xff) * 4) ^
                     *(uint *)(DAT_021bc7a4 +
                              (*(uint *)(iVar4 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff) * 4);
      uVar2 = param_1[7];
      param_1[7] = *(uint *)(DAT_021bc798 + (*(uint *)(iVar4 + (uVar2 & 0xff) * 4) & 0xff) * 4) ^
                   *(uint *)(DAT_021bc79c + (*(uint *)(iVar4 + (uVar2 >> 8 & 0xff) * 4) & 0xff) * 4)
                   ^ *(uint *)(DAT_021bc7a0 + (*(uint *)(iVar4 + (uVar2 >> 0x18) * 4) & 0xff) * 4) ^
                     *(uint *)(DAT_021bc7a4 +
                              (*(uint *)(iVar4 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff) * 4);
      local_18 = local_18 + 1;
      param_1 = puVar3;
    } while (local_18 < iVar1);
  }
  return iVar1;
}

