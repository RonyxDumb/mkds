/* Decompiled C draft; module arm9; ROM address 0214922c. No matching claim. */
#include "types.h"
#include "deps/0214922c_func_0214922c.h"

void func_0214922c(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = puRam021492c8;
  uVar1 = puRam021492c8[9];
  uVar2 = *puRam021492c8;
  puRam021492c8[9] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 < 0x81) {
    if (param_1 < 0x80) {
      if ((((param_1 < 5) && (-1 < param_1)) && (param_1 != 0)) && (param_1 == 4)) {
        *puRam021492cc = 0x84;
      }
      goto LAB_021492b0;
    }
  }
  else {
    if (param_1 != 0x180) goto LAB_021492b0;
    *puRam021492d0 = 0x81;
  }
  *puRam021492d4 = 0x81;
LAB_021492b0:
  GX_VRAMCNT_SetLCDC_(*puRam021492c8);
  return;
}

