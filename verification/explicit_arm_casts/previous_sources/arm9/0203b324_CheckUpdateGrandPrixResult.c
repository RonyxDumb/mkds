/* Decompiled C draft; module arm9; ROM address 0203b324. No matching claim. */
#include "types.h"
#include "deps/0203b324_CheckUpdateGrandPrixResult.h"

bool CheckUpdateGrandPrixResult(void)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r5;
  undefined1 auStack_50 [32];
  undefined1 auStack_30 [36];
  uint uVar2;
  
  uVar4 = *(uint *)(uRam0203b3d4 & 0xfffffffc) >> (uRam0203b3d4 & 3) * 8 |
          *(uint *)(uRam0203b3d4 & 0xfffffffc) << (uRam0203b3d4 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x88 & 3;
  uVar1 = *(uint *)(uVar4 + 0x88 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    unaff_r5 = 0;
  }
  else if (uVar2 == 1) {
    unaff_r5 = 1;
  }
  else if (uVar2 == 2) {
    uVar2 = uVar4 + 0x8c & 3;
    uVar1 = *(uint *)(uVar4 + 0x8c & 0xfffffffc);
    if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
      unaff_r5 = 2;
    }
    else {
      unaff_r5 = 3;
    }
  }
  uVar2 = uVar4 + 0x84 & 3;
  uVar1 = *(uint *)(uVar4 + 0x84 & 0xfffffffc);
  CopyCupEntryTo_from_thumb(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,unaff_r5,auStack_50);
  StructCP_CreateFromCurrent(auStack_30);
  iVar3 = StructCP_IsBBetterThanA(auStack_50,auStack_30);
  if (iVar3 != 0) {
    uVar2 = (*(uint *)(uRam0203b3d4 & 0xfffffffc) >> (uRam0203b3d4 & 3) * 8 |
            *(uint *)(uRam0203b3d4 & 0xfffffffc) << (uRam0203b3d4 & 3) * -8 + 0x20) + 0x84;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    CopyCupEntryFrom_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,unaff_r5,auStack_30)
    ;
    SaveNKGPChunk_from_thumb();
  }
  return iVar3 != 0;
}

