/* Decompiled C draft; module arm9; ROM address 0212c6ac. No matching claim. */
#include "types.h"
#include "deps/0212c6ac_func_0212c6ac.h"

void func_0212c6ac(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = iRam0212c6ec;
  do {
    if (*(char *)(iVar1 + 0x2c) != '\0') {
      NNSi_SndPlayerStopSeq(iVar1,param_1);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x44;
  } while (iVar2 < 0x10);
  return;
}

