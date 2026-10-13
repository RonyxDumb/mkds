/* Decompiled C draft; module arm9_ov001; ROM address 021993b8. No matching claim. */
#include "types.h"
#include "deps/021993b8_FUN_021993b8.h"

void FUN_021993b8(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_02199418 + 0xc);
  if (iVar1 == 0) {
    *(byte *)(*(int *)*DAT_0219941c + 0x31) = *(byte *)(*(int *)*DAT_0219941c + 0x31) & 0xf9;
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      return;
    }
    *(byte *)(*(int *)*DAT_0219941c + 0x31) = *(byte *)(*(int *)*DAT_0219941c + 0x31) & 0xf9 | 4;
    return;
  }
  *(byte *)(*(int *)*DAT_0219941c + 0x31) = *(byte *)(*(int *)*DAT_0219941c + 0x31) & 0xf9 | 2;
  return;
}

