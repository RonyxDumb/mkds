/* Decompiled C draft; module arm9_ov000; ROM address 021adbac. No matching claim. */
#include "types.h"
#include "deps/021adbac_FUN_021adbac.h"

int FUN_021adbac(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(DAT_021adbf0 + 4) + 0xa4);
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  else {
    if (*(char *)(iVar2 + 9) == '\0') {
      iVar1 = *(int *)(iVar2 + 0x44);
    }
    else {
      iVar1 = FUN_021a9358(iVar2);
    }
    if (((iVar1 == 0) && (*(char *)(iVar2 + 8) != '\x04')) &&
       (1 < (byte)(*(char *)(iVar2 + 8) - 10U))) {
      return -1;
    }
  }
  return iVar1;
}

