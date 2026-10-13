/* Decompiled C draft; module arm9; ROM address 020d3b10. No matching claim. */
#include "types.h"
#include "deps/020d3b10_func_020d3b10.h"

void func_020d3b10(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)((undefined4 *)*piRam020d3b6c + 1);
  piVar2 = *(int **)*piRam020d3b6c;
  iVar3 = 0;
  if (uVar4 != 0) {
    do {
      iVar1 = *piVar2;
      if ((*(ushort *)(iVar1 + 2) & 0x80) != 0) {
        *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) & 0xff7f;
        *(ushort *)(iVar1 + 2) = *(ushort *)(iVar1 + 2) & 0xfff0;
        *(ushort *)(iVar1 + 2) =
             *(ushort *)(iVar1 + 2) | (ushort)((int)(*(ushort *)(iVar1 + 2) & uRam020d3b70) >> 0xc);
        if (*(short *)(iVar1 + 100) != -1) {
          func_020d50ec();
        }
      }
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar4);
  }
  return;
}

