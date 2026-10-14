/* Decompiled C draft; module arm9; ROM address 0208e23c. No matching claim. */
#include "types.h"
#include "deps/0208e23c_MaybeCheckMapObjBkWaveNsbcaNsbma.h"

void MaybeCheckMapObjBkWaveNsbcaNsbma(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  puVar1 = puRam0208e2bc;
  iVar2 = GetExplosionSplashWaveNsbmd_from_thumb();
  if (iVar2 == 0) {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    return;
  }
  iVar2 = FindFileBuffer_CRS_CST_from_thumb(uRam0208e2c0);
  iVar3 = FindFileBuffer_CRS_CST_from_thumb(uRam0208e2c4);
  *puVar1 = 1;
  bVar4 = iVar2 != 0;
  if (bVar4) {
    *(undefined4 *)(puVar1 + 2) = 1;
  }
  if (!bVar4) {
    *(uint *)(puVar1 + 2) = (uint)bVar4;
  }
  if (iVar3 == 0) {
    *(undefined4 *)(puVar1 + 4) = 0;
  }
  else {
    *(undefined4 *)(puVar1 + 4) = 1;
  }
  return;
}

