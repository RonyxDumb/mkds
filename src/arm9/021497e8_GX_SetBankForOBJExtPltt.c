/* Decompiled C draft; module arm9; ROM address 021497e8. No matching claim. */
#include "types.h"
#include "deps/021497e8_GX_SetBankForOBJExtPltt.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GX_SetBankForOBJExtPltt(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = puRam02149894;
  uVar1 = puRam02149894[8];
  uVar2 = *puRam02149894;
  puRam02149894[8] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 == 0) {
    _DAT_04000000 = _DAT_04000000 & 0x7fffffff;
  }
  else if (param_1 == 0x20) {
    _DAT_04000000 = _DAT_04000000 | 0x80000000;
    *puRam02149898 = 0x85;
  }
  else if (param_1 == 0x40) {
    _DAT_04000000 = _DAT_04000000 | 0x80000000;
    *puRam0214989c = 0x85;
  }
  GX_VRAMCNT_SetLCDC_(*puRam02149894);
  return;
}

