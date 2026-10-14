/* Decompiled C draft; module arm9; ROM address 0214a8ec. No matching claim. */
#include "types.h"
#include "deps/0214a8ec_G3X_InitializeMatrixStack.h"

void G3X_InitializeMatrixStack(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_10;
  int local_c;
  
  *puRam0214a98c =
       *(uint *)((uint)puRam0214a98c & 0xfffffffc) >> ((uint)puRam0214a98c & 3) * 8 |
       *(uint *)((uint)puRam0214a98c & 0xfffffffc) << ((uint)puRam0214a98c & 3) * -8 + 0x20 | 0x8000
  ;
  do {
    iVar3 = G3X_GetMtxStackLevelPV(&local_10);
  } while (iVar3 != 0);
  do {
    iVar3 = G3X_GetMtxStackLevelPJ(&local_c);
    puVar1 = puRam0214a990;
  } while (iVar3 != 0);
  *puRam0214a990 = 3;
  *puRam0214a994 = 0;
  *puVar1 = 0;
  puVar1 = puRam0214a994;
  if (local_c != 0) {
    *piRam0214a998 = local_c;
  }
  puVar2 = puRam0214a990;
  *puVar1 = 0;
  *puVar2 = 2;
  *piRam0214a998 = local_10;
  *puVar1 = 0;
  return;
}

