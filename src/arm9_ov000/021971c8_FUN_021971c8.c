/* Decompiled C draft; module arm9_ov000; ROM address 021971c8. No matching claim. */
#include "types.h"
#include "deps/021971c8_FUN_021971c8.h"

int FUN_021971c8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = DAT_021971e8 * iVar1 + (int)*(char *)(param_1 + iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return iVar1;
}

