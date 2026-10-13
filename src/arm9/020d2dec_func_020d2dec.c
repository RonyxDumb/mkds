/* Decompiled C draft; module arm9; ROM address 020d2dec. No matching claim. */
#include "types.h"
#include "deps/020d2dec_func_020d2dec.h"

void func_020d2dec(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(ushort *)(*piRam020d2e18 + iRam020d2e1c);
  piVar1 = (int *)(*piRam020d2e18 + iRam020d2e20);
  iVar2 = 0;
  if (uVar3 != 0) {
    do {
      if (*(code **)(*piVar1 + 8) != (code *)0x0) {
        (**(code **)(*piVar1 + 8))();
      }
      piVar1 = piVar1 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar3);
  }
  return;
}

