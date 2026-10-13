/* Decompiled C draft; module arm9; ROM address 0212ea04. No matching claim. */
#include "types.h"
#include "deps/0212ea04_Sound_LoadGroup.h"

bool Sound_LoadGroup(void)

{
  int iVar1;
  
  iVar1 = Sound_LoadGroupImpl();
  return iVar1 == 0;
}

