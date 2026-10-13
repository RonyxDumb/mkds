/* Decompiled C draft; module arm9; ROM address 021498a0. No matching claim. */
#include "types.h"
#include "deps/021498a0_func_021498a0.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void func_021498a0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = puRam021499a4;
  uVar1 = puRam021499a4[7];
  uVar2 = *puRam021499a4;
  puRam021499a4[7] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 < 0x21) {
    if (param_1 < 0x20) {
      if (param_1 < 1) {
        if (param_1 == 0) {
          _DAT_04000000 = _DAT_04000000 & 0xbfffffff;
        }
      }
      else if (param_1 == 0x10) {
        _DAT_04000000 = _DAT_04000000 | 0x40000000;
        *puRam021499a8 = 0x84;
      }
      goto LAB_0214998c;
    }
  }
  else {
    if (param_1 < 0x41) {
      if (param_1 == 0x40) {
        _DAT_04000000 = _DAT_04000000 | 0x40000000;
        *puRam021499ac = 0x8c;
      }
      goto LAB_0214998c;
    }
    if (param_1 != 0x60) goto LAB_0214998c;
    *puRam021499ac = 0x8c;
  }
  *puRam021499b0 = 0x84;
  _DAT_04000000 = _DAT_04000000 | 0x40000000;
LAB_0214998c:
  GX_VRAMCNT_SetLCDC_(*puRam021499a4);
  return;
}

