/* Decompiled C draft; module arm9; ROM address 0212a920. No matching claim. */
#include "types.h"
#include "deps/0212a920_func_0212a920.h"

void func_0212a920(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam0212a990;
  *(int *)(*piRam0212a990 + 0x24) = *(int *)(*piRam0212a990 + 0x24) + 1;
  if (0x78 < *(int *)(*piVar1 + 0x24)) {
    *(undefined4 *)(*piVar1 + 0x24) = 0;
  }
  func_0212a99c();
  piVar1 = piRam0212a990;
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    if ((*(int *)(*piVar1 + 0x24) < 0x69) || (*(uint *)(*piVar1 + iVar4 + 0x14) < 2)) {
      iVar2 = *(int *)(*piVar1 + 0x38);
      CopyMemory16(*piVar1 + iRam0212a994 + iVar3,
                   iVar2 + (uint)*(ushort *)(iVar2 + iRam0212a998) * 8,6);
      *(short *)(*(int *)(*piVar1 + 0x38) + iRam0212a998) =
           *(short *)(*(int *)(*piVar1 + 0x38) + iRam0212a998) + 1;
    }
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 8;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

