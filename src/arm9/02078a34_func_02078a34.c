/* Decompiled C draft; module arm9; ROM address 02078a34. No matching claim. */
#include "types.h"
#include "deps/02078a34_func_02078a34.h"

void func_02078a34(int param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = piRam02078a88;
  iVar3 = *piRam02078a88;
  if (param_1 == -1) {
    sVar1 = *(short *)(iVar3 + iRam02078a94);
    *(undefined4 *)(iVar3 + 0x28) = 0xffffffff;
    *(undefined4 *)(iVar3 + sVar1 * 0xb8 + 0x5c) = 0xffffffff;
    return;
  }
  if (((*(int *)(iVar3 + iRam02078a8c + *(short *)(iVar3 + iRam02078a90) * 0x34 + 0x2c) == 0) &&
      (*(int *)(iVar3 + 0x28) != param_1)) && (param_1 < 0x26)) {
    *(int *)(iVar3 + 0x28) = param_1;
    *(undefined4 *)(*piVar2 + iRam02078a98) = 1;
  }
  return;
}

