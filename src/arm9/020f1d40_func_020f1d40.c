/* Decompiled C draft; module arm9; ROM address 020f1d40. No matching claim. */
#include "types.h"
#include "deps/020f1d40_func_020f1d40.h"

undefined4 func_020f1d40(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*piRam020f1d6c + param_1 * 0xa8 + 0x48);
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)(0,0,1);
    return uVar1;
  }
  return 0;
}

