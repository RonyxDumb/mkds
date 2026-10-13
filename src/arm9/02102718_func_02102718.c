/* Decompiled C draft; module arm9; ROM address 02102718. No matching claim. */
#include "types.h"
#include "deps/02102718_func_02102718.h"

void func_02102718(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam0210273c;
  *piRam0210273c = 0xf;
  iVar3 = 0;
  iVar2 = iRam02102740;
  do {
    *piVar1 = *piVar1 + (uint)*(ushort *)(iVar2 + 8) + (uint)*(ushort *)(iVar2 + 10);
    iVar2 = iVar2 + 0xc;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x11);
  return;
}

