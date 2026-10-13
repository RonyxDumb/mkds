/* Decompiled C draft; module arm9; ROM address 02056284. No matching claim. */
#include "types.h"
#include "deps/02056284_GetReadStaffGhost_from_thumb.h"

undefined4 GetReadStaffGhost_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = OpenReadEntireFileBuffer_from_thumb
                    (param_1,*(undefined4 *)(*piRam020562ac + 0x1c),uRam020562b0);
  if (iVar1 != 0) {
    return *(undefined4 *)(*piRam020562ac + 0x1c);
  }
  return 0;
}

