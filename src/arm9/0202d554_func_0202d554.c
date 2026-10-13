/* Decompiled C draft; module arm9; ROM address 0202d554. No matching claim. */
#include "types.h"
#include "deps/0202d554_func_0202d554.h"

void func_0202d554(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *piRam0202d5bc;
  iVar6 = (uint)*(ushort *)(*(int *)(iVar2 + 0x5c) + 6) +
          (uint)*(ushort *)(*(int *)(iVar2 + 100) + 6);
  iVar3 = (uint)*(ushort *)(*(int *)(iVar2 + 0x78) + 6) +
          (uint)*(ushort *)(*(int *)(iVar2 + 0x80) + 6);
  sVar1 = func_02025ebc(iVar2 + 0xcc);
  iVar5 = 0;
  if (iVar6 != 0) {
    iVar4 = 0;
    do {
      *(short *)(*(int *)(iVar2 + 0x68) + iVar4 + 6) = -sVar1;
      iVar4 = iVar4 + 0x40;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  iVar5 = 0;
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      *(short *)(*(int *)(iVar2 + 0x84) + iVar6 + 6) = sVar1;
      iVar6 = iVar6 + 0x40;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  return;
}

