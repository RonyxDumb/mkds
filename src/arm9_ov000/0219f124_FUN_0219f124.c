/* Decompiled C draft; module arm9_ov000; ROM address 0219f124. No matching claim. */
#include "types.h"
#include "deps/0219f124_FUN_0219f124.h"

undefined4 FUN_0219f124(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = DAT_0219f178;
  *(undefined4 *)(*DAT_0219f178 + DAT_0219f17c) = param_1;
  puVar2 = (undefined4 *)FUN_0219b8fc(param_1,*(byte *)(*piVar1 + 0xd) + 1);
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined1 *)(*DAT_0219f178 + DAT_0219f180) = 2;
    FUN_02198908(*puVar2);
    *(undefined1 *)(*DAT_0219f178 + DAT_0219f180) = 0;
    return 1;
  }
  FUN_021a1754(param_1,*(byte *)(*DAT_0219f178 + 0xd) + 1);
  return 0;
}

