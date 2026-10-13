/* Decompiled C draft; module arm9; ROM address 020ab028. No matching claim. */
#include "types.h"
#include "deps/020ab028_func_020ab028.h"

void func_020ab028(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(iRam020ab054 + 0x50) != 0) {
    uVar1 = func_020ab1d0(*(undefined2 *)(iRam020ab054 + 0x3c));
    iVar2 = (**(code **)(iRam020ab054 + 0x50))(uVar1,param_1);
    if (iVar2 != 0) {
      *(undefined2 *)(iRam020ab054 + 0x3c) = 0;
    }
  }
  return;
}

