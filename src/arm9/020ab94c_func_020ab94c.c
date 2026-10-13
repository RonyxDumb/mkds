/* Decompiled C draft; module arm9; ROM address 020ab94c. No matching claim. */
#include "types.h"
#include "deps/020ab94c_func_020ab94c.h"

void func_020ab94c(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam020ab9c0;
  *(undefined4 *)(*piRam020ab9c0 + 0x50) = param_1;
  *(undefined4 *)(*piVar1 + 0x54) = param_2;
  iVar2 = *piVar1;
  func_020ab194(*(undefined4 *)(iVar2 + 0x50),*(undefined4 *)(iVar2 + 0x54));
  piVar1 = piRam020ab9c0;
  *puRam020ab9cc =
       -*(int *)(*piRam020ab9c0 + 0x50) & uRam020ab9c4 |
       *(int *)(*piRam020ab9c0 + 0x54) * -0x10000 & uRam020ab9c8;
  iVar2 = *piVar1;
  func_020a9efc(*(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x58),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x5c),
                *(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x60),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 100));
  iVar2 = *piRam020ab9c0;
  func_020a9ed8(*(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x68),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x6c),
                *(int *)(iVar2 + 0x50) + *(int *)(iVar2 + 0x70),
                *(int *)(iVar2 + 0x54) + *(int *)(iVar2 + 0x74));
  return;
}

