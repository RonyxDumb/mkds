/* Decompiled C draft; module arm9_ov000; ROM address 0219ad20. No matching claim. */
#include "types.h"
#include "deps/0219ad20_FUN_0219ad20.h"

undefined4 FUN_0219ad20(void)

{
  int iVar1;
  
  if (*DAT_0219ad70 == 0) {
    iVar1 = FUN_0219ad88(*DAT_0219ad74,DAT_0219ad78);
    *DAT_0219ad70 = iVar1;
  }
  if (*DAT_0219ad7c == 0) {
    iVar1 = FUN_0219ad88(*DAT_0219ad80,DAT_0219ad84);
    *DAT_0219ad7c = iVar1;
  }
  if ((*DAT_0219ad70 != 0) && (*DAT_0219ad7c != 0)) {
    return 1;
  }
  return 0;
}

