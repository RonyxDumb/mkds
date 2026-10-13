/* Decompiled C draft; module arm9; ROM address 02001abc. No matching claim. */
#include "types.h"
#include "deps/02001abc_Scene_Logo_VBlankImpl.h"

void Scene_Logo_VBlankImpl(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  NavigationContext_OnSceneVblank_from_thumb();
  uVar2 = (*(uint *)(uRam02001b28 & 0xfffffffc) >> (uRam02001b28 & 3) * 8 |
          *(uint *)(uRam02001b28 & 0xfffffffc) << (uRam02001b28 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (0x5a < (int)uVar2) {
    iVar3 = uVar2 - 0x5a;
    iVar4 = iVar3 * -0x10;
    iVar4 = ((int)((ulonglong)((longlong)iRam02001b2c * (longlong)iVar4) >> 0x20) + iVar3 * -0x10 >>
            4) - (iVar4 >> 0x1f);
  }
  G2x_SetBlendBrightness_((ushort *)(uintptr_t)(uRam02001b30),2,iVar4);
  G2x_SetBlendBrightness_((ushort *)(uintptr_t)(uRam02001b34),2,iVar4);
  return;
}

