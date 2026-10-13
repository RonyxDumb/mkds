/* Decompiled C draft; module arm9; ROM address 021491b0. No matching claim. */
#include "types.h"
#include "deps/021491b0_func_021491b0.h"

void func_021491b0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = puRam02149220;
  uVar1 = puRam02149220[10];
  uVar2 = *puRam02149220;
  puRam02149220[10] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 != 0) {
    if (param_1 == 8) {
      *puRam02149228 = 0x84;
    }
    else if (param_1 == 0x100) {
      *puRam02149224 = 0x82;
    }
  }
  GX_VRAMCNT_SetLCDC_(*puRam02149220);
  return;
}

