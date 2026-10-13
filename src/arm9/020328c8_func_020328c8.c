/* Decompiled C draft; module arm9; ROM address 020328c8. No matching claim. */
#include "types.h"
#include "deps/020328c8_func_020328c8.h"

void func_020328c8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *piRam020328f4;
  iVar2 = 0;
  if (*(short *)(*(int *)(iVar1 + 0x28) + 6) != 0) {
    iVar3 = 0;
    do {
      *(undefined4 *)(*(int *)(iVar1 + 0x34) + iVar3) = param_1;
      iVar3 = iVar3 + 0x40;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(ushort *)(*(int *)(iVar1 + 0x28) + 6));
  }
  return;
}

