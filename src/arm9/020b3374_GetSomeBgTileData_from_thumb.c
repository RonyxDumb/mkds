/* Decompiled C draft; module arm9; ROM address 020b3374. No matching claim. */
#include "types.h"
#include "deps/020b3374_GetSomeBgTileData_from_thumb.h"

undefined4 GetSomeBgTileData_from_thumb(void)

{
  int iVar1;
  
  iVar1 = GetCurrentOptionMenuKind_from_thumb();
  if (iVar1 == 1) {
    *(undefined4 *)(*(int *)(*piRam020b33b4 + iRam020b33bc) + 0x14) =
         *(undefined4 *)(*piRam020b33b4 + iRam020b33b8);
  }
  else {
    iVar1 = GetCurrentOptionMenuKind_from_thumb();
    if (iVar1 == 2) {
      *(undefined4 *)(*(int *)(*piRam020b33b4 + iRam020b33bc) + 0x14) =
           *(undefined4 *)(*piRam020b33b4 + iRam020b33c0);
    }
  }
  return *(undefined4 *)(*piRam020b33b4 + iRam020b33bc);
}

