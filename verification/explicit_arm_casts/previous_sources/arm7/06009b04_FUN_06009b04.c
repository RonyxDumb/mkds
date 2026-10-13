/* Decompiled C draft; module arm7; ROM address 06009b04. No matching claim. */
#include "types.h"
#include "deps/06009b04_FUN_06009b04.h"

/* WARNING: Type propagation algorithm not settling */

void FUN_06009b04(void)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  uint local_28 [3];
  
  iVar1 = DAT_06009c8c;
  psVar3 = (short *)((*(uint *)(DAT_06009c84 & 0xfffffffc) >> (DAT_06009c84 & 3) * 8 |
                     *(uint *)(DAT_06009c84 & 0xfffffffc) << (DAT_06009c84 & 3) * -8 + 0x20) +
                    DAT_06009c88);
  uVar4 = 0;
  local_28[1] = 0;
  do {
    FUN_06018844(uVar4 * 2 + 0x44,2,local_28 + 1);
    *(short *)(*(ushort *)(iVar1 + uVar4 * 2) + 0x4808000) = (short)local_28[1];
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x10);
  local_28[0] = (ushort)psVar3[1] & 0x7f | (uint)((ushort)psVar3[1] >> 7) << 8;
  *DAT_06009c90 = (short)local_28[0];
  iVar2 = 0xce;
  iVar1 = thunk_FUN_03806b2c((psVar3[1] & 0x7fU) + 7,8);
  uVar4 = (uint)(ushort)psVar3[2];
  if (*psVar3 == 3) {
    FUN_06018844(uVar4 + 0xce,1,psVar3 + 4);
    for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1) {
      local_28[0] = 0;
      FUN_06018844(iVar2,1,local_28);
      local_28[0] = local_28[0] | uVar5 * 0x100 + 0x50000;
      FUN_06009e30();
      iVar2 = iVar2 + 1;
    }
  }
  else {
    local_28[0] = 0;
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      FUN_06018844(iVar2,iVar1,local_28);
      FUN_06009e30(local_28[0]);
      if ((*psVar3 == 2) && (local_28[0] >> 0x12 == 9)) {
        *(uint *)(psVar3 + 6) = local_28[0] & 0xffff83ff;
      }
      iVar2 = iVar2 + iVar1;
    }
  }
  return;
}

