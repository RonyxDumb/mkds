/* Decompiled C draft; module arm9; ROM address 021492f8. No matching claim. */
#include "types.h"
#include "deps/021492f8_func_021492f8.h"

void func_021492f8(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = puRam021493a4;
  uVar1 = puRam021493a4[3];
  uVar2 = *puRam021493a4;
  puRam021493a4[3] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 < 9) {
    if (param_1 < 8) {
      if ((((param_1 < 5) && (-1 < param_1)) && (param_1 != 0)) && (param_1 == 4)) {
        *puRam021493a8 = 0x82;
      }
    }
    else {
      *puRam021493ac = 0x82;
    }
  }
  else if (param_1 == 0xc) {
    *puRam021493ac = 0x8a;
    *puRam021493a8 = 0x82;
  }
  GX_VRAMCNT_SetLCDC_(*puRam021493a4);
  return;
}

