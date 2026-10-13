/* Decompiled C draft; module arm9; ROM address 0204a428. No matching claim. */
#include "types.h"
#include "deps/0204a428_TryGetSceneSpecialBgmSseqId.h"

bool TryGetSceneSpecialBgmSseqId(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = false;
  if (param_1 < 8) {
    if (param_1 < 7) {
      if ((param_1 < 3) && (-1 < param_1)) {
        if (param_1 == 0) {
          *param_2 = 0;
          bVar4 = true;
        }
        else if ((param_1 == 2) &&
                (uVar3 = *(uint *)(uRam0204a4d4 & 0xfffffffc) >> (uRam0204a4d4 & 3) * 8 |
                         *(uint *)(uRam0204a4d4 & 0xfffffffc) << (uRam0204a4d4 & 3) * -8 + 0x20,
                uVar2 = uVar3 + 0xc & 3, uVar1 = *(uint *)(uVar3 + 0xc & 0xfffffffc),
                (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 6)) {
          uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
          if (uVar2 == 0x35) {
            *param_2 = 0x45;
          }
          else if (uVar2 == 0x36) {
            *param_2 = 0x46;
          }
          bVar4 = true;
        }
      }
    }
    else {
      *param_2 = 4;
      bVar4 = true;
    }
  }
  else {
    bVar4 = param_1 == 0xb;
    if (bVar4) {
      *param_2 = 4;
    }
  }
  return bVar4;
}

