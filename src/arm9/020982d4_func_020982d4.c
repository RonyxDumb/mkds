/* Decompiled C draft; module arm9; ROM address 020982d4. No matching claim. */
#include "types.h"
#include "deps/020982d4_func_020982d4.h"

uint func_020982d4(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = CreateAllocateMapObject_from_thumb(uRam02098318,uRam0209831c,uRam02098320);
  piVar1 = piRam02098324;
  *piRam02098324 = iVar2;
  *(undefined4 *)(iVar2 + 0x1c) = 1;
  func_020d49d8(piVar1);
  return *(uint *)((uint)piRam02098324 & 0xfffffffc) >> ((uint)piRam02098324 & 3) * 8 |
         *(uint *)((uint)piRam02098324 & 0xfffffffc) << ((uint)piRam02098324 & 3) * -8 + 0x20;
}

