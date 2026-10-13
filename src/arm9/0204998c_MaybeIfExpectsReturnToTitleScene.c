/* Decompiled C draft; module arm9; ROM address 0204998c. No matching claim. */
#include "types.h"
#include "deps/0204998c_MaybeIfExpectsReturnToTitleScene.h"

undefined4 MaybeIfExpectsReturnToTitleScene(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if (*psRam02049a94 != 2) {
    bVar4 = false;
    uVar1 = *(uint *)(uRam02049a98 & 0xfffffffc) >> (uRam02049a98 & 3) * 8 |
            *(uint *)(uRam02049a98 & 0xfffffffc) << (uRam02049a98 & 3) * -8 + 0x20;
    if (uVar1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    }
    if ((uVar3 != 0) &&
       (uVar3 = uVar1 + 4 & 3, uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc),
       (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 0xd)) {
      bVar4 = true;
    }
    if (((((!bVar4) && (iVar2 = GetCurrentSceneId(), iVar2 != 6)) &&
         (iVar2 = GetCurrentSceneId(), iVar2 != 0xd)) &&
        ((iVar2 = GetCurrentSceneId(), iVar2 != 0xc || (iVar2 = func_0x02180608(), iVar2 != 0)))) &&
       ((iVar2 = GetCurrentSceneId(), iVar2 == 0xc ||
        (*(short *)((*(uint *)(uRam02049a9c & 0xfffffffc) >> (uRam02049a9c & 3) * 8 |
                    *(uint *)(uRam02049a9c & 0xfffffffc) << (uRam02049a9c & 3) * -8 + 0x20) + 0x16)
         == 0)))) {
      iVar2 = GetCurrentSceneId();
      if (iVar2 == 2) {
        uVar1 = (*(uint *)(uRam02049aa0 & 0xfffffffc) >> (uRam02049aa0 & 3) * 8 |
                *(uint *)(uRam02049aa0 & 0xfffffffc) << (uRam02049aa0 & 3) * -8 + 0x20) + 0xc;
        uVar3 = uVar1 & 3;
        uVar1 = *(uint *)(uVar1 & 0xfffffffc);
        if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 6) {
          return 1;
        }
      }
      else if ((iVar2 == 9) || (iVar2 == 0xf)) {
        return 1;
      }
      return 0;
    }
  }
  return 1;
}

