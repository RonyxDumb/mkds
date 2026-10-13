/* Decompiled C draft; module arm9; ROM address 02098374. No matching claim. */
#include "types.h"
#include "deps/02098374_func_02098374.h"

uint func_02098374(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_0209bf1c(uRam020983b8,uRam020983bc,0);
  piVar1 = piRam020983c0;
  *piRam020983c0 = iVar2;
  *(undefined4 *)(iVar2 + 0x1c) = 1;
  func_020d49d8(piVar1);
  return *(uint *)((uint)piRam020983c0 & 0xfffffffc) >> ((uint)piRam020983c0 & 3) * 8 |
         *(uint *)((uint)piRam020983c0 & 0xfffffffc) << ((uint)piRam020983c0 & 3) * -8 + 0x20;
}

