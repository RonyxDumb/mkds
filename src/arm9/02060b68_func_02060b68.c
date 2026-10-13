/* Decompiled C draft; module arm9; ROM address 02060b68. No matching claim. */
#include "types.h"
#include "deps/02060b68_func_02060b68.h"

void func_02060b68(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_40 [34];
  byte local_1e;
  
  iVar2 = iRam02060c08;
  uVar1 = uRam02060c04;
  uVar6 = 0;
  do {
    GlobalZ_GetOI(uVar6,(int)(uintptr_t)(auStack_40));
    if ((((int)((uint)local_1e << 0x1f) < 0) && ((int)((uint)local_1e << 0x1e) < 0)) &&
       (uVar4 = uVar1 & 3, uVar3 = *(uint *)(uVar1 & 0xfffffffc),
       uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x20, uVar3 = uVar4 & 3,
       uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       iVar5 = FriendCode_SomeFn_from_thumb
                         (uVar6 * 0xc + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + iVar2),
       iVar5 != 0)) {
      local_1e = local_1e & 0xfd;
      GlobalZ_SetOI(uVar6,(undefined4)(uintptr_t)(auStack_40));
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0x3c);
  return;
}

