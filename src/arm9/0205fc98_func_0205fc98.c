/* Decompiled C draft; module arm9; ROM address 0205fc98. No matching claim. */
#include "types.h"
#include "deps/0205fc98_func_0205fc98.h"

undefined4 func_0205fc98(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = *(uint *)(uRam0205fd24 & 0xfffffffc) >> (uRam0205fd24 & 3) * 8 |
          *(uint *)(uRam0205fd24 & 0xfffffffc) << (uRam0205fd24 & 3) * -8 + 0x20;
  bVar3 = false;
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  }
  if ((uVar2 != 0) &&
     (uVar2 = uVar1 + 4 & 3, uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc),
     (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0xd)) {
    bVar3 = true;
  }
  if (bVar3) {
    uVar1 = (uint)*(byte *)((*(uint *)(uRam0205fd28 & 0xfffffffc) >> (uRam0205fd28 & 3) * 8 |
                            *(uint *)(uRam0205fd28 & 0xfffffffc) << (uRam0205fd28 & 3) * -8 + 0x20)
                           + 0x39);
  }
  else {
    uVar1 = CheckExtraKartUnlockFlags_from_thumb();
  }
  uVar2 = (uint)*(byte *)(param_3 * 0xd +
                          (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + param_2 +
                         6);
  if ((uVar2 != 0) && (uVar2 <= uVar1)) {
    return 1;
  }
  return 0;
}

