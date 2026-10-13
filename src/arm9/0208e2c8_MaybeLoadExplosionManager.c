/* Decompiled C draft; module arm9; ROM address 0208e2c8. No matching claim. */
#include "types.h"
#include "deps/0208e2c8_MaybeLoadExplosionManager.h"

void MaybeLoadExplosionManager(undefined2 *param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = GetExplosionSplashWaveNsbmd_from_thumb();
  *puRam0208e350 = 0;
  if (iVar2 == 0) {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 2) = 0;
    puVar1 = puRam0208e354;
    *(undefined4 *)(param_1 + 4) = 0;
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xffffffff;
    return;
  }
  iVar2 = GetExplosionSplashWaveNsbca_from_thumb();
  iVar3 = GetExplosionSplashWaveNsbma_from_thumb();
  *param_1 = param_2;
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 2) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 2) = 1;
  }
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 1;
  }
  return;
}

