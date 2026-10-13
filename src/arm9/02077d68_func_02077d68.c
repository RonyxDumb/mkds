/* Decompiled C draft; module arm9; ROM address 02077d68. No matching claim. */
#include "types.h"
#include "deps/02077d68_func_02077d68.h"

void func_02077d68(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = *piRam02077ea0;
  iVar7 = iVar1 + iRam02077ea4;
  iVar3 = *(short *)(iVar1 + iRam02077ea8) * 0x34;
  iVar5 = iVar7 + iVar3;
  uVar6 = **(uint **)(iVar1 + 0x20);
  uVar4 = (*(uint **)(iVar1 + 0x20))[1];
  *(undefined2 *)(iVar5 + 0x30) = 0;
  Mem_Exp_Finalize(*(undefined4 *)(iVar5 + 4));
  uVar2 = Mem_Exp_Create(*(undefined4 *)(iVar7 + iVar3),uRam02077eac,0);
  *(undefined4 *)(iVar5 + 4) = uVar2;
  if ((uVar6 != 0xffffffff) && (*(int *)(iVar5 + 8) != 0)) {
    MaybeDisposeCommonHeaderFileData();
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0xc));
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0x10));
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0x18));
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0x1c));
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0x20));
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0x24));
    MaybeDisposeCommonHeaderFileData(*(undefined4 *)(iVar5 + 0x28));
  }
  iVar1 = *(int *)(*piRam02077ea0 + iRam02077eb0) + uVar4 * 0xe0;
  uVar2 = FormatCharacterEmblemNsbmdPath(uVar6 & 0xffff,1);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 8));
  uVar2 = FormatCharacterEmblemNsbtxPath(uVar6 & 0xffff,1);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0xc));
  uVar2 = FormatCharacterEmblemNsbcaPath(uVar6 & 0xffff,2);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0x14));
  uVar2 = FormatEmblemNsbtx(uVar6 & 0xffff);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0x10));
  uVar2 = FormatCharacterKartNsbmdPath(uVar4 & 0xffff);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0x18));
  uVar2 = FormatCharacterKartNsbtxPath(uVar4 & 0xffff);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0x1c));
  uVar2 = FormatKartShadowNsbmdPath(uVar4 & 0xffff);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0x28));
  uVar2 = FormatKartTireNsbmdPath(uVar4 & 0xffff,iVar1);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),(int *)(uintptr_t)(iVar5 + 0x20));
  uVar2 = FormatKartTireNsbtxPath(uVar4 & 0xffff,iVar1);
  ReadFileFromMountManagerHandle_from_thumb(uVar2,*(undefined4 *)(iVar5 + 4),iVar5 + 0x24);
  return;
}

