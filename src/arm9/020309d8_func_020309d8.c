/* Decompiled C draft; module arm9; ROM address 020309d8. No matching claim. */
#include "types.h"
#include "deps/020309d8_func_020309d8.h"

void func_020309d8(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *piRam02030a0c;
  iVar2 = func_02030a18(*(undefined4 *)(iVar5 + 0xc));
  iVar3 = func_02030a10(*(undefined4 *)(iVar5 + 0x14));
  piVar1 = piRam02030a0c;
  for (iVar4 = 0; iVar4 < iVar2 + iVar3; iVar4 = iVar4 + 1) {
    *(short *)(*(int *)(iVar5 + 0x18) + iVar4 * 0x40 + 6) = (short)*(undefined4 *)(*piVar1 + 0x38);
  }
  return;
}

