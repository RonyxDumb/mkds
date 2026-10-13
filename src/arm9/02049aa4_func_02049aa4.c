/* Decompiled C draft; module arm9; ROM address 02049aa4. No matching claim. */
#include "types.h"
#include "deps/02049aa4_func_02049aa4.h"

undefined4 func_02049aa4(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if (*psRam02049b60 != 2) {
    bVar4 = false;
    uVar1 = *(uint *)(uRam02049b64 & 0xfffffffc) >> (uRam02049b64 & 3) * 8 |
            *(uint *)(uRam02049b64 & 0xfffffffc) << (uRam02049b64 & 3) * -8 + 0x20;
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
    if ((((!bVar4) &&
         ((iVar2 = GetCurrentSceneId(), iVar2 != 0xc || (iVar2 = func_0x02180600(), iVar2 != 0))))
        && ((iVar2 = GetCurrentSceneId(), iVar2 == 0xc ||
            (*(short *)((*(uint *)(uRam02049b68 & 0xfffffffc) >> (uRam02049b68 & 3) * 8 |
                        *(uint *)(uRam02049b68 & 0xfffffffc) << (uRam02049b68 & 3) * -8 + 0x20) +
                       0x16) == 0)))) &&
       ((iVar2 = GetCurrentSceneId(), iVar2 != 0xd && (iVar2 = GetCurrentSceneId(), iVar2 != 6)))) {
      return 1;
    }
  }
  return 0;
}

