/* Decompiled C draft; module arm9; ROM address 020ab910. No matching claim. */
#include "types.h"
#include "deps/020ab910_func_020ab910.h"

void func_020ab910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam020ab948;
  *(undefined4 *)(*piRam020ab948 + 0x58) = param_1;
  *(undefined4 *)(*piVar1 + 0x5c) = param_2;
  *(undefined4 *)(*piVar1 + 0x60) = param_3;
  *(undefined4 *)(*piVar1 + 100) = param_4;
  iVar2 = *piVar1;
  func_020a9efc(*(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x58),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x5c),
                *(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x60),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 100));
  return;
}

