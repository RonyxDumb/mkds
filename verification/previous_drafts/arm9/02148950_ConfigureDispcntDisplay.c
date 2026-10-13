/* Decompiled C draft; module arm9; ROM address 02148950. No matching claim. */
#include "types.h"
#include "deps/02148950_ConfigureDispcntDisplay.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConfigureDispcntDisplay(ushort param_1,uint param_2,int param_3)

{
  short sVar1;
  
  sVar1 = *psRam021489b8;
  *puRam021489bc = param_1;
  if (sVar1 == 0) {
    param_1 = 0;
  }
  _DAT_04000000 = param_2 | _DAT_04000000 & uRam021489c0 | (uint)param_1 << 0x10 | param_3 << 3;
  if (*puRam021489bc == 0) {
    *psRam021489b8 = 0;
  }
  return;
}

