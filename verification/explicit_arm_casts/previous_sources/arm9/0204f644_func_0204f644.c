/* Decompiled C draft; module arm9; ROM address 0204f644. No matching claim. */
#include "types.h"
#include "deps/0204f644_func_0204f644.h"

undefined4 func_0204f644(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = *piRam0204f748;
  uVar4 = (uint)*(ushort *)(iVar1 + iRam0204f74c);
  iVar2 = (int)((uVar4 - 1) * 0x10000) >> 0x10;
  iVar3 = iVar1 + iRam0204f750;
  if ((*(uint *)(iVar3 + 0xc) & 1) != 0) {
    return 0;
  }
  if ((-1 < iVar2) && (*(int *)(iVar1 + iVar2 * 0x88 + iRam0204f754) << 2 < 0)) {
    if (*(int *)(*piRam0204f758 + 0xf8) == 0) {
      WorkerInsertTask(uRam0204f75c);
      *(undefined4 *)(*piRam0204f758 + 0xf8) = 1;
      return 0;
    }
    return 0;
  }
  if (uVar4 < 0xc) {
    iVar2 = uVar4 * 0x88;
    iVar1 = iVar1 + iRam0204f760;
    if (*(char *)(iVar1 + iVar2) != '\0') {
      if ((*(uint *)(iVar3 + 0xc) & 0x10) != 0) {
        Fs_File_Close(iVar3);
      }
      Fs_File_Initialize(iVar3);
      iVar1 = Fs_File_Open(iVar3,iVar1 + iVar2);
      if (iVar1 != 0) {
        iVar5 = *(int *)(iVar3 + 0x28) - *(int *)(iVar3 + 0x24);
        iVar1 = *(int *)(*piRam0204f748 + iVar2 + iRam0204f764);
        if (iVar1 == 0) {
          iVar1 = Mem_AllocateHeapAligned
                            (*(undefined4 *)(*piRam0204f748 + iVar2 + iRam0204f768),iVar5,0x20);
          **(int **)(*piRam0204f748 + iVar2 + iRam0204f76c) = iVar1;
        }
        Fs_File_ReadAsync(iVar3,iVar1,iVar5);
        *(short *)(*piRam0204f748 + iRam0204f74c) = *(short *)(*piRam0204f748 + iRam0204f74c) + 1;
      }
      return 0;
    }
  }
  return 1;
}

