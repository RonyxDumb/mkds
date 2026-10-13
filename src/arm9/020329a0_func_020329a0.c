/* Decompiled C draft; module arm9; ROM address 020329a0. No matching claim. */
#include "types.h"
#include "deps/020329a0_func_020329a0.h"

void func_020329a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam020329d8;
  iVar2 = *piRam020329d8;
  iVar4 = 0;
  if (0 < *(int *)(iVar2 + 0x48)) {
    iVar3 = 0;
    do {
      iVar5 = *piVar1;
      *(short *)(*(int *)(iVar2 + 0x34) + (uint)*(ushort *)(*(int *)(iVar5 + 0x4c) + iVar3) * 0x40 +
                4) = (short)*(undefined4 *)(iVar5 + 0x5c);
      iVar3 = iVar3 + 6;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(*piVar1 + 0x48));
  }
  return;
}

