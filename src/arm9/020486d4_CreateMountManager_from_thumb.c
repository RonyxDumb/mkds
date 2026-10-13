/* Decompiled C draft; module arm9; ROM address 020486d4. No matching claim. */
#include "types.h"
#include "deps/020486d4_CreateMountManager_from_thumb.h"

void CreateMountManager_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = Mem_AllocateHeap(param_1,uRam02048774);
  *piRam02048778 = iVar2;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam0204877c,0x20);
  piVar1 = piRam02048778;
  *(undefined4 *)(*piRam02048778 + iRam02048780) = uVar3;
  iVar4 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar2 + 0x68) = 0;
    iVar2 = iVar2 + 0x70;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x14);
  if (*psRam02048784 != 2) {
    uVar3 = Fs_LoadRomArchiveFatFnt(0,0);
    iVar2 = iRam02048788;
    piVar1 = piRam02048778;
    *(undefined4 *)(*piRam02048778 + iRam02048788) = uVar3;
    uVar3 = Mem_AllocateHeap(param_1,*(undefined4 *)(*piVar1 + iVar2));
    iVar2 = iRam0204878c;
    piVar1 = piRam02048778;
    *(undefined4 *)(*piRam02048778 + iRam0204878c) = uVar3;
    Fs_LoadRomArchiveFatFnt
              (*(undefined4 *)(*piVar1 + iVar2),*(undefined4 *)(*piVar1 + iRam02048788));
  }
  iVar2 = 0;
  do {
    InitializeMountDatas_from_thumb(iVar2);
    piVar1 = piRam02048778;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  *(undefined4 *)(*piRam02048778 + iRam02048790) = 0;
  *(undefined4 *)(*piVar1 + iRam02048794) = 0;
  *(undefined4 *)(*piVar1 + iRam02048798) = 0;
  Fs_File_Initialize((undefined4 *)(uintptr_t)(*piVar1 + iRam0204879c));
  return;
}

