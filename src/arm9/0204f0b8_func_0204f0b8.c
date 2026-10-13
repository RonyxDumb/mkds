/* Decompiled C draft; module arm9; ROM address 0204f0b8. No matching claim. */
#include "types.h"
#include "deps/0204f0b8_func_0204f0b8.h"

void func_0204f0b8(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = piRam0204f0f0;
  uVar3 = *(undefined4 *)(*piRam0204f0f0 + 0xc);
  *(undefined4 *)(*piRam0204f0f0 + 0xc) = 0x2b;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  iVar2 = *piVar1;
  iVar2 = func_02006db0(1,(int)*(short *)(iVar2 + iRam0204f0f4),iVar2 + iRam0204f0f8,uRam0204f0fc);
  piVar1 = piRam0204f0f0;
  if (iVar2 == 0) {
    *(undefined4 *)(*piRam0204f0f0 + 0xc) = uVar3;
    *(undefined4 *)(*piVar1 + 0x10) = 0;
  }
  return;
}

