/* Decompiled C draft; module arm9; ROM address 02030200. No matching claim. */
#include "types.h"
#include "deps/02030200_func_02030200.h"

void func_02030200(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam02030238;
  iVar3 = *piRam02030238;
  iVar4 = (uint)*(ushort *)(*(int *)(iVar3 + 0x30) + 6) +
          (uint)*(ushort *)(*(int *)(iVar3 + 0x38) + 6);
  iVar5 = 0;
  if (iVar4 != 0) {
    iVar2 = 0;
    do {
      *(short *)(*(int *)(iVar3 + 0x3c) + iVar2 + 6) = (short)*(undefined4 *)(*piVar1 + 0x90);
      iVar2 = iVar2 + 0x40;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  return;
}

