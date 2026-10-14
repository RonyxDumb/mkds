/* Decompiled C draft; module arm9; ROM address 0214a840. No matching claim. */
#include "types.h"
#include "deps/0214a840_G3X_ResetMatrixStack2.h"

void G3X_ResetMatrixStack2(void)

{
  undefined4 *puVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  *puRam0214a8dc =
       *(uint *)((uint)puRam0214a8dc & 0xfffffffc) >> ((uint)puRam0214a8dc & 3) * 8 |
       *(uint *)((uint)puRam0214a8dc & 0xfffffffc) << ((uint)puRam0214a8dc & 3) * -8 + 0x20 | 0x8000
  ;
  do {
    iVar2 = G3X_GetMtxStackLevelPV(&local_10);
  } while (iVar2 != 0);
  do {
    iVar2 = G3X_GetMtxStackLevelPJ(&local_c);
    puVar1 = puRam0214a8e0;
  } while (iVar2 != 0);
  *puRam0214a8e0 = 3;
  *puRam0214a8e4 = 0;
  *puVar1 = 0;
  if (local_c != 0) {
    *piRam0214a8e8 = local_c;
  }
  *puRam0214a8e0 = 2;
  puVar1 = puRam0214a8e4;
  *piRam0214a8e8 = local_10;
  *puVar1 = 0;
  return;
}

