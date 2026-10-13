/* Decompiled C draft; module arm9_ov001; ROM address 0219d934. No matching claim. */
#include "types.h"
#include "deps/0219d934_FUN_0219d934.h"

void FUN_0219d934(void)

{
  int iVar1;
  
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    if (*(char *)(*DAT_0219d98c + 0x28) == '\0') {
      if (*(int *)(*DAT_0219d990 + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*DAT_0219d990 + 0x10);
      }
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      func_0x02125ebc(0x23);
      func_0x02125fc0();
      return;
    }
  }
  iVar1 = func_0x02125f88();
  if (iVar1 != 0) {
    FUN_02192ea0(*(undefined4 *)(*DAT_0219d994 + 0x20));
  }
  return;
}

