/* Decompiled C draft; module arm9; ROM address 0204ee64. No matching claim. */
#include "types.h"
#include "deps/0204ee64_func_0204ee64.h"

void func_0204ee64(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam0204ee9c;
  iVar3 = 0;
  iVar2 = 0;
  do {
    func_02006df8(iVar3 + iRam0204eea0 & 0xffff);
    *(undefined4 *)(*piVar1 + iVar2 + iRam0204eea4) = 0;
    iVar2 = iVar2 + 0x88;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  *(undefined2 *)(*piVar1 + iRam0204eea8) = 0;
  return;
}

