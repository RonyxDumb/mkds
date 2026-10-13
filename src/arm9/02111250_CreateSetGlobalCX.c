/* Decompiled C draft; module arm9; ROM address 02111250. No matching claim. */
#include "types.h"
#include "deps/02111250_CreateSetGlobalCX.h"

void CreateSetGlobalCX(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = Sound_InitializeContext();
  iVar1 = iRam02111278;
  *(undefined4 *)(iRam02111278 + 4) = uVar2;
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}

