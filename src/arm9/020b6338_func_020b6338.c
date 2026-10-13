/* Decompiled C draft; module arm9; ROM address 020b6338. No matching claim. */
#include "types.h"
#include "deps/020b6338_func_020b6338.h"

uint func_020b6338(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = GetDriverYRotation();
  iVar1 = 0x18000 - iVar2 >> 0x1f;
  return ((uint)((0x18000 - iVar2) * 0x10000 + iVar1) >> 0x10) - iVar1 & 0xffff;
}

