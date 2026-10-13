/* Decompiled C draft; module arm9; ROM address 02126730. No matching claim. */
#include "types.h"
#include "deps/02126730_TextSystemContext_OnSceneVblank_from_thumb.h"

void TextSystemContext_OnSceneVblank_from_thumb(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = uRam021267f8;
  piVar1 = piRam021267f0;
  if (*(int *)(*piRam021267f0 + 0x50) != 0) {
    *puRam021267fc = *(int *)(*piRam021267f0 + iRam021267f4) << 0x10 & uRam021267f8;
    *puRam02126804 = *(int *)(*piVar1 + iRam02126800) << 0x10 & uVar2;
    iVar3 = *piVar1;
    if (*(int *)(iVar3 + iRam02126808) == 0) {
      UpdateBldcntBldalphaBldy
                ((ushort *)(uintptr_t)(uRam02126814),0,0x1f,*(undefined4 *)(iVar3 + iRam0212681c),
                 *(undefined4 *)(iVar3 + iRam0212680c),*(undefined4 *)(iVar3 + iRam02126810));
    }
    else {
      UpdateBldcntBldalphaBldy
                ((ushort *)(uintptr_t)(uRam02126814),*(undefined4 *)(iVar3 + iRam02126818),0x1f,
                 *(undefined4 *)(iVar3 + iRam0212681c),*(undefined4 *)(iVar3 + iRam0212680c),
                 *(undefined4 *)(iVar3 + iRam02126810));
    }
    iVar3 = *piRam021267f0;
    if (*(int *)(iVar3 + iRam02126820) != 0) {
      UpdateBldcntBldalphaBldy
                ((ushort *)(uintptr_t)(uRam02126828),*(undefined4 *)(iVar3 + iRam0212682c),0x1f,
                 *(undefined4 *)(iVar3 + iRam02126830),*(undefined4 *)(iVar3 + iRam02126824),
                 *(undefined4 *)(iVar3 + iRam02126810));
      return;
    }
    UpdateBldcntBldalphaBldy
              ((ushort *)(uintptr_t)(uRam02126828),0,0x1f,*(undefined4 *)(iVar3 + iRam02126830),
               *(undefined4 *)(iVar3 + iRam02126824),*(undefined4 *)(iVar3 + iRam02126810));
  }
  return;
}

