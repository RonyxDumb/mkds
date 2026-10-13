/* Decompiled C draft; module arm9; ROM address 0212e8f4. No matching claim. */
#include "types.h"
#include "deps/0212e8f4_Sound_LoadSbnkWithFlags.h"

bool Sound_LoadSbnkWithFlags(void)

{
  int iVar1;
  
  iVar1 = Sound_GetSbnkPointer();
  return iVar1 == 0;
}

