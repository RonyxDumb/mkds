/* Decompiled C draft; module arm9_ov000; ROM address 0218d0c8. No matching claim. */
#include "types.h"
#include "deps/0218d0c8_FUN_0218d0c8.h"

int FUN_0218d0c8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      if (*(char *)(param_1 + iVar1) == '\0') {
        return iVar1 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return -1;
}

