/* Decompiled C draft; module arm9; ROM address 020d2bb0. No matching claim. */
#include "types.h"
#include "deps/020d2bb0_GetExplosionSplashWaveNsbca_from_thumb.h"

undefined4 GetExplosionSplashWaveNsbca_from_thumb(void)

{
  int iVar1;
  
  if (*piRam020d2bd8 != 0) {
    return *(undefined4 *)(*piRam020d2bd8 + 8);
  }
  iVar1 = *piRam020d2bdc;
  if ((iVar1 != 0) && (*(int *)(iVar1 + iRam020d2be0) != 0)) {
    return *(undefined4 *)(iVar1 + iRam020d2be4);
  }
  return 0;
}

