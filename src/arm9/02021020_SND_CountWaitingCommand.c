/* Decompiled C draft; module arm9; ROM address 02021020. No matching claim. */
#include "types.h"
#include "deps/02021020_SND_CountWaitingCommand.h"

int SND_CountWaitingCommand(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_02021080();
  iVar2 = func_02021040();
  return (0x100 - iVar1) - iVar2;
}

