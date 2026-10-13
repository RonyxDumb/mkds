/* Decompiled C draft; module arm9_ov003; ROM address 021ccb50. No matching claim. */
#include "types.h"
#include "deps/021ccb50_FUN_021ccb50.h"

int FUN_021ccb50(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  FUN_021cca9c(1,(short *)(void *)(auStack_18));
  iVar1 = FUN_021d29e8((ushort *)(void *)(auStack_18));
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = 2;
  do {
    FUN_021cca9c(iVar1,(short *)(void *)(auStack_18));
    iVar2 = FUN_021d29e8((ushort *)(void *)(auStack_18));
    if (iVar2 != 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  FUN_021cca9c(4,(short *)(void *)(auStack_18));
  iVar1 = FUN_021d2a34((ushort *)(void *)(auStack_18));
  if (iVar1 != 0) {
    return 4;
  }
  return 0;
}

