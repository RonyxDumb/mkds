/* Decompiled C draft; module arm9_ov001; ROM address 02198d20. No matching claim. */
#include "types.h"
#include "deps/02198d20_FUN_02198d20.h"

void FUN_02198d20(void)

{
  int iVar1;
  
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    if (*(char *)(*DAT_02198d80 + 0x28) == '\0') {
      if (*(int *)(*DAT_02198d84 + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*DAT_02198d84 + 0x10);
      }
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      func_0x02125ebc(0x23);
      func_0x02125fc0();
      func_0x02128374();
    }
  }
  iVar1 = func_0x02125f88();
  if ((iVar1 != 0) && (iVar1 = func_0x02128294(), iVar1 != 0)) {
    FUN_02192ea0(*(undefined4 *)(*DAT_02198d88 + 0x34));
  }
  return;
}

