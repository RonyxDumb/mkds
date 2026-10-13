/* Decompiled C draft; module arm9; ROM address 0208e570. No matching claim. */
#include "types.h"
#include "deps/0208e570_LoadEffectMapObjModels.h"

void LoadEffectMapObjModels(uint param_1)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar4 = (*(uint *)(uRam0208e7c4 & 0xfffffffc) >> (uRam0208e7c4 & 3) * 8 |
          *(uint *)(uRam0208e7c4 & 0xfffffffc) << (uRam0208e7c4 & 3) * -8 + 0x20) + 8;
  uVar10 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) == 4) {
    uVar4 = (*(uint *)(uRam0208e7c8 & 0xfffffffc) >> (uRam0208e7c8 & 3) * 8 |
            *(uint *)(uRam0208e7c8 & 0xfffffffc) << (uRam0208e7c8 & 3) * -8 + 0x20) + 0xa4;
    uVar10 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    param_1 = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20;
  }
  uVar5 = Mem_AllocateHeap(param_1,0x60);
  *puRam0208e7cc = uVar5;
  IntrusiveListWrapper_InitializeEmpty((undefined4 *)(uintptr_t)(uVar5),0);
  puVar1 = puRam0208e7cc;
  uVar4 = 0;
  do {
    uVar10 = (uint)puVar1 & 3;
    uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
    IntrusiveListWrapper_InitializeEmpty
              ((undefined4 *)(uintptr_t)(uVar4 * 0xc + (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) + 0xc),0);
    puVar3 = puRam0208e7d4;
    puVar2 = puRam0208e7d0;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 5);
  uVar4 = (*(uint *)(uRam0208e7c4 & 0xfffffffc) >> (uRam0208e7c4 & 3) * 8 |
          *(uint *)(uRam0208e7c4 & 0xfffffffc) << (uRam0208e7c4 & 3) * -8 + 0x20) + 8;
  uVar10 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20;
  bVar11 = uVar4 == 5;
  if (bVar11) {
    uVar4 = 6;
  }
  if (bVar11) {
    *puRam0208e7d0 = (short)uVar4;
    *puVar3 = 4;
  }
  else {
    *puRam0208e7d0 = 3;
    *puVar3 = 1;
  }
  uVar4 = (*(uint *)(uRam0208e7c4 & 0xfffffffc) >> (uRam0208e7c4 & 3) * 8 |
          *(uint *)(uRam0208e7c4 & 0xfffffffc) << (uRam0208e7c4 & 3) * -8 + 0x20) + 8;
  uVar10 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) == 4) {
    *puVar2 = 0x14;
  }
  MaybeLoadExplosionManager((undefined2 *)(uintptr_t)(uRam0208e7d8),1);
  MaybeLoadExplosionManager((undefined2 *)(uintptr_t)(uRam0208e7dc),2);
  MaybeCheckMapObjBkWaveNsbcaNsbma();
  CreateExplosionInstances(param_1);
  uVar5 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7e0);
  uVar7 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7e4);
  uVar8 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7e8);
  uVar9 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7ec);
  MaybeLoadSomeExplosion(param_1,0,uVar5,uVar7,uVar8,uVar9);
  uVar5 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7f0);
  uVar7 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7f4);
  uVar8 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7f8);
  uVar9 = FindFileBuffer_MAR_EFT_from_thumb(uRam0208e7fc);
  MaybeLoadSomeExplosion(param_1,1,uVar5,uVar7,uVar8,uVar9);
  uVar5 = GetExplosionSplashWaveNsbmd_from_thumb();
  uVar7 = GetExplosionSplashWaveNsbca_from_thumb();
  uVar8 = GetExplosionSplashWaveNsbma_from_thumb();
  MaybeLoadSomeExplosion(param_1,2,uVar5,uVar7,uVar8,0);
  uVar5 = GetExplosionSplashWaveNsbmd_from_thumb();
  uVar7 = GetExplosionSplashWaveNsbca_from_thumb();
  uVar8 = GetExplosionSplashWaveNsbma_from_thumb();
  MaybeLoadSomeExplosion(param_1,4,uVar5,uVar7,uVar8,0);
  uVar10 = *(uint *)(uRam0208e7c4 & 0xfffffffc) >> (uRam0208e7c4 & 3) * 8 |
           *(uint *)(uRam0208e7c4 & 0xfffffffc) << (uRam0208e7c4 & 3) * -8 + 0x20;
  uVar4 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) == 0x17) {
    uVar5 = GetExplosionSplashWaveNsbmd_from_thumb();
    uVar7 = FindFileBuffer_CRS_CST_from_thumb(uRam0208e800);
    uVar8 = FindFileBuffer_CRS_CST_from_thumb(uRam0208e804);
    MaybeLoadSomeExplosion(param_1,3,uVar5,uVar7,uVar8,0);
  }
  *(undefined2 *)
   ((*(uint *)((uint)puRam0208e7cc & 0xfffffffc) >> ((uint)puRam0208e7cc & 3) * 8 |
    *(uint *)((uint)puRam0208e7cc & 0xfffffffc) << ((uint)puRam0208e7cc & 3) * -8 + 0x20) + 0x5c) =
       10;
  return;
}

