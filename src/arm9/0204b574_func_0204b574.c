/* Decompiled C draft; module arm9; ROM address 0204b574. No matching claim. */
#include "types.h"
#include "deps/0204b574_func_0204b574.h"

void func_0204b574(void)

{
  int iVar1;
  
  iVar1 = Card_GetResult();
  if (iVar1 == 0) {
    SX1Zero_from_thumb();
    iVar1 = *piRam0204b5d4;
    Card_RequestStreamCommand
              (*(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x44),
               *(undefined4 *)(iVar1 + 0x48),uRam0204b5d8,*(undefined4 *)(iVar1 + 0x54),1,7,10,2);
    return;
  }
  CleanupUnlockBackup_from_thumb();
  *(undefined4 *)(*piRam0204b5d4 + 0x10) = 0;
  func_0204b344(iVar1 != 0);
  return;
}

