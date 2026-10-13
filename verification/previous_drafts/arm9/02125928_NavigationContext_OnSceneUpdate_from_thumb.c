/* Decompiled C draft; module arm9; ROM address 02125928. No matching claim. */
#include "types.h"
#include "deps/02125928_NavigationContext_OnSceneUpdate_from_thumb.h"

void NavigationContext_OnSceneUpdate_from_thumb(void)

{
  if (*(int *)*piRam0212595c != 0) {
    TextSystemContext_OnSceneUpdate_from_thumb();
  }
  if (*(int *)(*piRam0212595c + 4) != 0) {
    SelectChoisesContext_OnSceneUpdate_from_thumb();
  }
  if (*(int *)(*piRam0212595c + 8) != 0) {
    SelectReturnContext_OnSceneUpdate_from_thumb();
  }
  return;
}

