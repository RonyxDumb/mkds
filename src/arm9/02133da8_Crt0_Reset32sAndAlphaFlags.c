/* Decompiled C draft; module arm9; ROM address 02133da8. No matching claim. */
#include "types.h"
#include "deps/02133da8_Crt0_Reset32sAndAlphaFlags.h"

void Crt0_Reset32sAndAlphaFlags(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)GetAlphaFlagsRef();
  *puVar1 = 0;
  iVar2 = GetGammaFuncsRef();
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  return;
}

