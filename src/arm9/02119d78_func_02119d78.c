/* Decompiled C draft; module arm9; ROM address 02119d78. No matching claim. */
#include "types.h"
#include "deps/02119d78_func_02119d78.h"

void func_02119d78(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = func_02119dfc();
  if (iVar3 != 0) {
    iVar3 = *piRam02119df4;
    if (*(int *)(iVar3 + 0x58) == 7) {
      *(undefined2 *)(iVar3 + 0x5c) = *(undefined2 *)(iVar3 + 0x50);
      func_02119e88();
    }
    else if (*psRam02119df8 != 2) {
      uVar4 = (uint)*(ushort *)(*(int *)(iVar3 + 4) + 6);
      uVar2 = func_02116d10(7 - *(int *)(iVar3 + 0x58),1);
      piVar1 = piRam02119df4;
      *(undefined2 *)(*(int *)(*piRam02119df4 + 0x1c) + uVar4 * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uVar4 + 1) * 0x40 + 6) = uVar2;
    }
    *(int *)(*piRam02119df4 + 0x58) = *(int *)(*piRam02119df4 + 0x58) + -1;
    return;
  }
  iVar3 = *piRam02119df4;
  if (*(short *)(iVar3 + 0x50) != *(short *)(iVar3 + 0x5c)) {
    *(undefined4 *)(iVar3 + 0x58) = 7;
  }
  return;
}

