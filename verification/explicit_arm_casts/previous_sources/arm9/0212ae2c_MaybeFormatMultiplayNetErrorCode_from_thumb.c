/* Decompiled C draft; module arm9; ROM address 0212ae2c. No matching claim. */
#include "types.h"
#include "deps/0212ae2c_MaybeFormatMultiplayNetErrorCode_from_thumb.h"

void MaybeFormatMultiplayNetErrorCode_from_thumb(void)

{
  undefined4 uVar1;
  undefined1 auStack_1e [30];
  
  Mem_CpuFill16(0,auStack_1e,0x14);
  uVar1 = GetMaybeNetErrorCode();
  FormatIntegerInString16_from_thumb(uVar1,auStack_1e);
  MaybeHandleBmgFormatting_from_thumb
            (auStack_1e,*(undefined4 *)(*piRam0212ae74 + 8),*piRam0212ae74 + iRam0212ae78,
             uRam0212ae7c);
  *(int *)(*piRam0212ae74 + 8) = *piRam0212ae74 + iRam0212ae78;
  return;
}

