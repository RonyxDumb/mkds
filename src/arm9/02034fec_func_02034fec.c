/* Decompiled C draft; module arm9; ROM address 02034fec. No matching claim. */
#include "types.h"
#include "deps/02034fec_func_02034fec.h"

void func_02034fec(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *piRam02035058;
  iVar6 = (uint)*(ushort *)(*(int *)(iVar2 + 0x38) + 6) +
          (uint)*(ushort *)(*(int *)(iVar2 + 0x40) + 6);
  iVar3 = (uint)*(ushort *)(*(int *)(iVar2 + 0x54) + 6) +
          (uint)*(ushort *)(*(int *)(iVar2 + 0x5c) + 6);
  sVar1 = func_02025ebc(iVar2 + iRam0203505c);
  iVar5 = 0;
  if (iVar6 != 0) {
    iVar4 = 0;
    do {
      *(short *)(*(int *)(iVar2 + 0x44) + iVar4 + 6) = -sVar1;
      iVar4 = iVar4 + 0x40;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  iVar5 = 0;
  if (iVar3 != 0) {
    iVar6 = 0;
    do {
      *(short *)(*(int *)(iVar2 + 0x60) + iVar6 + 6) = sVar1;
      iVar6 = iVar6 + 0x40;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  return;
}

