/* Decompiled C draft; module arm9_ov001; ROM address 0219c8c8. No matching claim. */
#include "types.h"
#include "deps/0219c8c8_FUN_0219c8c8.h"

void FUN_0219c8c8(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_0219c8e4 + 0x10);
  if (0 < iVar1) {
    *(int *)(*DAT_0219c8e4 + 0x10) = iVar1 + -1;
  }
  *(int *)(*DAT_0219c8e4 + 0x1c) = (int)*(char *)(DAT_0219c8e8 + *(int *)(*DAT_0219c8e4 + 0x10));
  return;
}

