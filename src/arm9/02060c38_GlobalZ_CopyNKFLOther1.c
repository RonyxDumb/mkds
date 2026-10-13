/* Decompiled C draft; module arm9; ROM address 02060c38. No matching claim. */
#include "types.h"
#include "deps/02060c38_GlobalZ_CopyNKFLOther1.h"

void GlobalZ_CopyNKFLOther1(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02060c5c & 0xfffffffc) >> (uRam02060c5c & 3) * 8 |
          *(uint *)(uRam02060c5c & 0xfffffffc) << (uRam02060c5c & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02060c58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02060c64)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iRam02060c60,param_1,0x2d0);
  return;
}

