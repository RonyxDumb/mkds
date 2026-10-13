/* Decompiled C draft; module arm9; ROM address 02021764. No matching claim. */
#include "types.h"
#include "deps/02021764_IncreaseMDCounter.h"

void IncreaseMDCounter(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc + iRam02021780;
  *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + '\x01';
  return;
}

