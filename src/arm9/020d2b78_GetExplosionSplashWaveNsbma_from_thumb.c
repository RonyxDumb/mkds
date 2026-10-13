/* Decompiled C draft; module arm9; ROM address 020d2b78. No matching claim. */
#include "types.h"
#include "deps/020d2b78_GetExplosionSplashWaveNsbma_from_thumb.h"

undefined4 GetExplosionSplashWaveNsbma_from_thumb(void)

{
  int iVar1;
  
  if (*piRam020d2ba0 != 0) {
    return *(undefined4 *)(*piRam020d2ba0 + 0xc);
  }
  iVar1 = *piRam020d2ba4;
  if ((iVar1 != 0) && (*(int *)(iVar1 + iRam020d2ba8) != 0)) {
    return *(undefined4 *)(iVar1 + iRam020d2bac);
  }
  return 0;
}

