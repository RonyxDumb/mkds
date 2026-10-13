/* Decompiled C draft; module arm9; ROM address 020471b0. No matching claim. */
#include "types.h"
#include "deps/020471b0_LoadEmbeddedStatic2DArchive_from_thumb.h"

void LoadEmbeddedStatic2DArchive_from_thumb(undefined4 param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar2 = (uint *)GetEmbeddedStatic2DCarcArchiveData();
  uVar3 = *puVar2;
  *(undefined4 *)(*piRam0204720c + iRam02047210) = 0;
  uVar4 = Mem_AllocateHeapAligned(param_1,uVar3 >> 8,0x20);
  uVar5 = GetEmbeddedStatic2DCarcArchiveData();
  DecompressLzssAndDCClean_from_thumb(uVar5,uVar4,uVar3 >> 8);
  MountMountEntryFrom(*piRam0204720c + iRam02047214,*(undefined4 *)(iRam02047218 + 0x4c),uVar4);
  piVar1 = piRam0204720c;
  *(undefined4 *)(*piRam0204720c + iRam0204721c) = uVar4;
  *(undefined4 *)(*piVar1 + iRam02047210) = 1;
  LoadStatic2DContents(param_1);
  return;
}

