/* Decompiled C draft; module arm9; ROM address 02007478. No matching claim. */
#include "types.h"
#include "deps/02007478_func_02007478.h"

void func_02007478(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_5c [76];
  
  piVar3 = *(int **)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x14);
  Fs_File_Initialize((undefined4 *)(void *)(auStack_5c));
  iVar4 = *piVar3;
  uVar1 = Fs_FindArchiveByMountName(iVar2 + 0x10,*(undefined4 *)(iVar2 + 0x14));
  iVar2 = Fs_File_OpenRaw((int)(uintptr_t)(auStack_5c),uVar1,iVar4,iVar4 + piVar3[1],0xffffffff);
  if (iVar2 != 0) {
    iVar2 = Fs_File_Read(auStack_5c,piVar3[2],piVar3[1]);
    if (piVar3[1] == iVar2) {
      piVar3[3] = 2;
    }
    Fs_File_Close((int)(uintptr_t)(auStack_5c));
  }
  if (piVar3[3] != 2) {
    Os_Terminate();
  }
  return;
}

