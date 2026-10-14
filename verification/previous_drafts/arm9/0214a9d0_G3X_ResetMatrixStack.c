/* Decompiled C draft; module arm9; ROM address 0214a9d0. No matching claim. */
#include "types.h"
#include "deps/0214a9d0_G3X_ResetMatrixStack.h"

void G3X_ResetMatrixStack(void)

{
  ushort *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = puRam0214aa44;
  do {
  } while (((*(uint *)((uint)puRam0214aa40 & 0xfffffffc) >> ((uint)puRam0214aa40 & 3) * 8 |
            *(uint *)((uint)puRam0214aa40 & 0xfffffffc) << ((uint)puRam0214aa40 & 3) * -8 + 0x20) &
           0x8000000) != 0);
  *puRam0214aa40 =
       *(uint *)((uint)puRam0214aa40 & 0xfffffffc) >> ((uint)puRam0214aa40 & 3) * 8 |
       *(uint *)((uint)puRam0214aa40 & 0xfffffffc) << ((uint)puRam0214aa40 & 3) * -8 + 0x20 | 0x8000
  ;
  *puVar1 = *puVar1 | 0x2000;
  *puVar1 = *puVar1 | 0x1000;
  G3X_ResetMatrixStack2();
  puVar2 = puRam0214aa50;
  *puRam0214aa4c = uRam0214aa48;
  puVar3 = puRam0214aa54;
  *puVar2 = 0;
  *puVar3 = 0;
  return;
}

