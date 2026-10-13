/* Decompiled C draft; module arm9; ROM address 02125da0. No matching claim. */
#include "types.h"
#include "deps/02125da0_DisposeNavigationContext_from_thumb.h"

void DisposeNavigationContext_from_thumb(void)

{
  if (*(int *)*piRam02125ddc != 0) {
    TextSystemContext_Dispose_from_thumb();
  }
  if (*(int *)(*piRam02125ddc + 4) != 0) {
    SelectChoisesContext_Dispose_from_thumb();
  }
  if (*(int *)(*piRam02125ddc + 8) != 0) {
    SelectReturnContext_Dispose_from_thumb();
  }
  *piRam02125ddc = 0;
  return;
}

