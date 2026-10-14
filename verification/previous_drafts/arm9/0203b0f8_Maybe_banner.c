/* Decompiled C draft; module arm9; ROM address 0203b0f8. No matching claim. */
#include "types.h"
#include "deps/0203b0f8_Maybe_banner.h"

void Maybe_banner(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (*psRam0203b188 == 2) {
    func_0204f240(param_1,1);
  }
  else {
    uVar4 = find_buf_fn_from_thumb(uRam0203b18c);
  }
  bVar3 = true;
  uVar2 = (*(uint *)(uRam0203b190 & 0xfffffffc) >> (uRam0203b190 & 3) * 8 |
          *(uint *)(uRam0203b190 & 0xfffffffc) << (uRam0203b190 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((uVar2 != 1) && (uVar2 != 2)) {
    bVar3 = false;
  }
  if (bVar3) {
    func_0204e928(param_1,uVar2 == 1,uVar4);
    AllocateSomeZEStuff_from_thumb(param_1);
  }
  PopulateNextRaceConfig();
  return;
}

