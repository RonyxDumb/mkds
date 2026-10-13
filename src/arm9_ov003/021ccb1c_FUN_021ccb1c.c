/* Decompiled C draft; module arm9_ov003; ROM address 021ccb1c. No matching claim. */
#include "types.h"
#include "deps/021ccb1c_FUN_021ccb1c.h"

int FUN_021ccb1c(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [12];
  
  iVar2 = 2;
  do {
    FUN_021cca9c(iVar2,(short *)(void *)(auStack_18));
    iVar1 = FUN_021d2a80((ushort *)(void *)(auStack_18));
    if (iVar1 != 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return 0;
}

