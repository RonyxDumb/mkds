/* Decompiled C draft; module arm9; ROM address 021494f0. No matching claim. */
#include "types.h"
#include "deps/021494f0_func_021494f0.h"

void func_021494f0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = puRam021495d4;
  uVar1 = puRam021495d4[5];
  uVar2 = *puRam021495d4;
  puRam021495d4[5] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 < 0x31) {
    if (0x2f < param_1) goto LAB_021495a4;
    if (0x10 < param_1) {
      if (param_1 != 0x20) goto LAB_021495bc;
      goto LAB_02149588;
    }
    if (param_1 < 0x10) goto LAB_021495bc;
  }
  else {
    if (param_1 < 0x61) {
      if (param_1 < 0x60) {
        if (param_1 == 0x40) {
          *puRam021495d8 = 0x83;
        }
        goto LAB_021495bc;
      }
      *puRam021495d8 = 0x8b;
LAB_02149588:
      *puRam021495dc = 0x83;
      goto LAB_021495bc;
    }
    if (param_1 != 0x70) goto LAB_021495bc;
    *puRam021495d8 = 0x9b;
LAB_021495a4:
    *puRam021495dc = 0x93;
  }
  *puRam021495e0 = 0x83;
LAB_021495bc:
  GX_VRAMCNT_SetLCDC_(*puRam021495d4);
  return;
}

