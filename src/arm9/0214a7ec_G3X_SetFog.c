/* Decompiled C draft; module arm9; ROM address 0214a7ec. No matching claim. */
#include "types.h"
#include "deps/0214a7ec_G3X_SetFog.h"

void G3X_SetFog(int param_1,int param_2,int param_3,undefined2 param_4)

{
  ushort *puVar1;
  
  puVar1 = puRam0214a834;
  if (param_1 != 0) {
    *puRam0214a83c = param_4;
    *puVar1 = *puVar1 & 0xc0bf | (ushort)(param_3 << 8) | (ushort)(param_2 << 6) | 0x80;
    return;
  }
  *puRam0214a834 = *puRam0214a834 & (ushort)uRam0214a838;
  return;
}

