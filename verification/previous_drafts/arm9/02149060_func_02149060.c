/* Decompiled C draft; module arm9; ROM address 02149060. No matching claim. */
#include "types.h"
#include "deps/02149060_func_02149060.h"

ushort func_02149060(ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = puRam02149094;
  uVar1 = *param_1;
  *param_1 = 0;
  *puVar2 = *puVar2 | uVar1;
  GX_VRAMCNT_SetLCDC_(uVar1);
  return uVar1;
}

