/* Decompiled C draft; module arm9; ROM address 02078a9c. No matching claim. */
#include "types.h"
#include "deps/02078a9c_func_02078a9c.h"

void func_02078a9c(int param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = piRam02078af0;
  iVar3 = *piRam02078af0;
  if (param_1 == -1) {
    sVar1 = *(short *)(iVar3 + iRam02078afc);
    *(int *)(iVar3 + 0x24) = -1;
    *(undefined4 *)(iVar3 + 0x58 + sVar1 * 0xb8) = 0xffffffff;
    return;
  }
  if (((*(int *)(iVar3 + iRam02078af4 + *(short *)(iVar3 + iRam02078af8) * 0x34 + 0x2c) == 0) &&
      (*(int *)(iVar3 + 0x24) != param_1)) && (param_1 < 0xe)) {
    *(int *)(iVar3 + 0x24) = param_1;
    *(undefined4 *)(*piVar2 + iRam02078b00) = 1;
  }
  return;
}

