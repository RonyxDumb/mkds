/* Decompiled C draft; module arm9; ROM address 020b49bc. No matching claim. */
#include "types.h"
#include "deps/020b49bc_Gfx_ReadCharGraphicsRelative.h"

void Gfx_ReadCharGraphicsRelative(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = Common_FindBlockByMagic(param_2,uRam020b49f0);
    if (iVar1 != 0) {
      *param_1 = iVar1 + 8;
    }
    return;
  }
  return;
}

