/* Decompiled C draft; module arm9; ROM address 02060c0c. No matching claim. */
#include "types.h"
#include "deps/02060c0c_CopyFriendCodesToSaveData.h"

void CopyFriendCodesToSaveData(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02060c2c & 0xfffffffc) >> (uRam02060c2c & 3) * 8 |
          *(uint *)(uRam02060c2c & 0xfffffffc) << (uRam02060c2c & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02060c28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02060c34)(param_1,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iRam02060c30,0x2d0);
  return;
}

