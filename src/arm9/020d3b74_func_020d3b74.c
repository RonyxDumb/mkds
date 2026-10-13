/* Decompiled C draft; module arm9; ROM address 020d3b74. No matching claim. */
#include "types.h"
#include "deps/020d3b74_func_020d3b74.h"

void func_020d3b74(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)*(ushort *)((undefined4 *)*piRam020d3be8 + 1);
  piVar4 = *(int **)*piRam020d3be8;
  iVar5 = 0;
  if (uVar6 != 0) {
    uVar1 = *puRam020d3bec;
    do {
      iVar3 = *piVar4;
      uVar2 = *(ushort *)(iVar3 + 2);
      if ((uVar2 & 0x80) != 0) {
        if ((uVar2 & uRam020d3bf0) == 0) {
          *(ushort *)(iVar3 + 2) = uVar2 & (ushort)uRam020d3bf4;
          *(ushort *)(iVar3 + 2) =
               *(ushort *)(iVar3 + 2) | (ushort)((*(ushort *)(iVar3 + 2) & 0xf) << 0xc);
          *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) | uVar1;
          if (*(short *)(iVar3 + 100) != -1) {
            func_020d5114();
          }
        }
        else {
          *(ushort *)(iVar3 + 2) = uVar2 & 0xff7f;
        }
      }
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar6);
  }
  return;
}

