/* Decompiled C draft; module arm9_ov001; ROM address 02181b8c. No matching claim. */
#include "types.h"
#include "deps/02181b8c_FUN_02181b8c.h"

void FUN_02181b8c(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(*DAT_02181bcc + 0x44) + (uint)*(byte *)(*DAT_02181bc4 + DAT_02181bc8) & 0xffff;
  *(undefined4 *)(*DAT_02181bcc + (uVar1 - *(byte *)(*DAT_02181bc4 + DAT_02181bc8)) * 4 + 0x48) =
       param_1;
  func_0x020a1728(uVar1);
  *(int *)(*DAT_02181bcc + 0x44) = *(int *)(*DAT_02181bcc + 0x44) + 1;
  return;
}

