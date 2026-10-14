/* Decompiled C draft; module arm9; ROM address 0200ca34. No matching claim. */
#include "types.h"
#include "deps/0200ca34_Os_InitializeSvcStack.h"

void Os_InitializeSvcStack(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = iRam0200ca64;
  uVar2 = uRam0200ca60;
  iVar1 = iRam0200ca58;
  *(undefined4 *)(iRam0200ca58 + 0x3f7c) = uRam0200ca5c;
  *(undefined4 *)((iVar1 + 0x3f80) - iVar3) = uVar2;
  return;
}

