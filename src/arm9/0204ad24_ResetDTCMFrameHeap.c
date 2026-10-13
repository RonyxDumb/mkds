/* Decompiled C draft; module arm9; ROM address 0204ad24. No matching claim. */
#include "types.h"
#include "deps/0204ad24_ResetDTCMFrameHeap.h"

void ResetDTCMFrameHeap(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0204ad3c & 0xfffffffc) >> (uRam0204ad3c & 3) * 8 |
          *(uint *)(uRam0204ad3c & 0xfffffffc) << (uRam0204ad3c & 3) * -8 + 0x20) + 0x24;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x0204ad38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0204ad40)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,3);
  return;
}

