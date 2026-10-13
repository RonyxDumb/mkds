/* Decompiled C draft; module arm9; ROM address 02001b38. No matching claim. */
#include "types.h"
#include "deps/02001b38_Scene_Logo_FinalizeImpl.h"

void Scene_Logo_FinalizeImpl(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = *(uint *)(uRam02001b98 & 0xfffffffc) >> (uRam02001b98 & 3) * 8 |
          *(uint *)(uRam02001b98 & 0xfffffffc) << (uRam02001b98 & 3) * -8 + 0x20;
  *puRam02001b9c = 0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar1 = ((uint)*(byte *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x31) << 0x1d) >>
          0x1e;
  if (uVar1 != 0) {
    if (uVar1 == 1) goto LAB_02001b84;
    if (uVar1 == 2) {
      uVar2 = 2;
      goto LAB_02001b84;
    }
  }
  uVar2 = 1;
LAB_02001b84:
  func_02108e94(uVar2);
  DisposeNavigationContext_from_thumb();
  return;
}

