/* Decompiled C draft; module arm9; ROM address 02118814. No matching claim. */
#include "types.h"
#include "deps/02118814_func_02118814.h"

void func_02118814(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam021188d8;
  if (*psRam021188d0 != 2) {
    iVar3 = 0;
    iVar5 = 0;
    iVar2 = iRam021188d4;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 2) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 4) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 6) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 8) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 10) * 0x40) = 0;
      iVar4 = *piVar1;
      if (*(int *)(iVar4 + iVar5 + 0x48) == 0) {
        *(undefined4 *)(*(int *)(iVar4 + 0x1c) + (uint)*(ushort *)(iVar2 + 6) * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 10) * 0x40) = 1;
      }
      else {
        if ((*(int *)(iVar4 + 0x44) == iVar3) && (*(int *)(iVar4 + 0x68) != 0)) {
          *(undefined4 *)(*(int *)(iVar4 + 0x1c) + (uint)*(ushort *)(iVar2 + 4) * 0x40) = 1;
        }
        else {
          *(undefined4 *)(*(int *)(iVar4 + 0x1c) + (uint)*(ushort *)(iVar2 + 2) * 0x40) = 1;
        }
        *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 8) * 0x40) = 1;
      }
      if (*(int *)(*piVar1 + 0x3c) == 3) {
        *(undefined4 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(iVar2 + 10) * 0x40) = 0;
      }
      iVar2 = iVar2 + 0xc;
      iVar5 = iVar5 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
  }
  return;
}

