/* Decompiled C draft; module arm9; ROM address 02149124. No matching claim. */
#include "types.h"
#include "deps/02149124_GX_SetBankForSubBGExtPltt.h"

void GX_SetBankForSubBGExtPltt(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  
  puVar3 = puRam021491a4;
  uVar1 = puRam021491a4[0xb];
  uVar2 = *puRam021491a4;
  puRam021491a4[0xb] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  puVar4 = puRam021491ac;
  if (param_1 == 0) {
    *puRam021491a8 =
         (*(uint *)((uint)puRam021491a8 & 0xfffffffc) >> ((uint)puRam021491a8 & 3) * 8 |
         *(uint *)((uint)puRam021491a8 & 0xfffffffc) << ((uint)puRam021491a8 & 3) * -8 + 0x20) &
         0xbfffffff;
  }
  else if (param_1 == 0x80) {
    *puRam021491a8 =
         *(uint *)((uint)puRam021491a8 & 0xfffffffc) >> ((uint)puRam021491a8 & 3) * 8 |
         *(uint *)((uint)puRam021491a8 & 0xfffffffc) << ((uint)puRam021491a8 & 3) * -8 + 0x20 |
         0x40000000;
    *puVar4 = 0x82;
  }
  GX_VRAMCNT_SetLCDC_(*puRam021491a4);
  return;
}

