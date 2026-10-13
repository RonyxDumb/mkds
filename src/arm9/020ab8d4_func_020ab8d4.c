/* Decompiled C draft; module arm9; ROM address 020ab8d4. No matching claim. */
#include "types.h"
#include "deps/020ab8d4_func_020ab8d4.h"

void func_020ab8d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam020ab90c;
  *(undefined4 *)(*piRam020ab90c + 0x68) = param_1;
  *(undefined4 *)(*piVar1 + 0x6c) = param_2;
  *(undefined4 *)(*piVar1 + 0x70) = param_3;
  *(undefined4 *)(*piVar1 + 0x74) = param_4;
  iVar2 = *piVar1;
  func_020a9ed8(*(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x68),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x6c),
                *(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x70),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x74));
  return;
}

