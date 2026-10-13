/* Decompiled C draft; module arm9; ROM address 020d2be8. No matching claim. */
#include "types.h"
#include "deps/020d2be8_GetExplosionSplashWaveNsbmd_from_thumb.h"

undefined4 GetExplosionSplashWaveNsbmd_from_thumb(void)

{
  int iVar1;
  
  if (*piRam020d2c10 != 0) {
    return *(undefined4 *)(*piRam020d2c10 + 4);
  }
  iVar1 = *piRam020d2c14;
  if ((iVar1 != 0) && (*(int *)(iVar1 + iRam020d2c18) != 0)) {
    return *(undefined4 *)(iVar1 + iRam020d2c1c);
  }
  return 0;
}

