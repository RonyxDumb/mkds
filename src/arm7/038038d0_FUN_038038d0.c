/* Decompiled C draft; module arm7; ROM address 038038d0. No matching claim. */
#include "types.h"
#include "deps/038038d0_FUN_038038d0.h"

void FUN_038038d0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = DAT_03803934;
  uVar2 = *(uint *)((uint)DAT_0380392c & 0xfffffffc) >> ((uint)DAT_0380392c & 3) * 8 |
          *(uint *)((uint)DAT_0380392c & 0xfffffffc) << ((uint)DAT_0380392c & 3) * -8 + 0x20;
  if (uVar2 != DAT_03803930) {
    *DAT_03803934 = 0;
    puVar1[1] = DAT_03803938;
    puVar1[2] = 0x40;
    puVar1[3] = uVar2;
    FUN_037faf70();
    *DAT_0380392c = DAT_03803930;
    FUN_037faf84();
  }
  return;
}

