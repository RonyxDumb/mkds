/* Decompiled C draft; module arm9; ROM address 020a9ea0. No matching claim. */
#include "types.h"
#include "deps/020a9ea0_func_020a9ea0.h"

void func_020a9ea0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = func_020ab338();
  iVar3 = iRam020a9ed4;
  if (iVar1 != 0) {
    *(int *)(iRam020a9ed4 + 0x44) = iVar1;
    if (*(int *)(iVar3 + 0x4c) != 0) {
      uVar2 = func_020ab2a4();
      iVar3 = (**(code **)(iRam020a9ed4 + 0x4c))(uVar2,0);
      if (iVar3 != 0) {
        uVar2 = func_020ab338();
        *(undefined4 *)(iRam020a9ed4 + 0x44) = uVar2;
      }
    }
  }
  return;
}

