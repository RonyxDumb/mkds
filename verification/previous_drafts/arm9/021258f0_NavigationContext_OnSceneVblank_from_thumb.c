/* Decompiled C draft; module arm9; ROM address 021258f0. No matching claim. */
#include "types.h"
#include "deps/021258f0_NavigationContext_OnSceneVblank_from_thumb.h"

void NavigationContext_OnSceneVblank_from_thumb(void)

{
  if (*(int *)*piRam02125924 != 0) {
    TextSystemContext_OnSceneVblank_from_thumb();
  }
  if (*(int *)(*piRam02125924 + 4) != 0) {
    SelectChoisesContext_OnSceneVblank_from_thumb();
  }
  if (*(int *)(*piRam02125924 + 8) != 0) {
    SelectReturnContext_OnSceneVblank_from_thumb();
  }
  return;
}

