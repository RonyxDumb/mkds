/* Decompiled C draft; module arm9_ov003; ROM address 021c7118. No matching claim. */
#include "types.h"
#include "deps/021c7118_FUN_021c7118.h"

void FUN_021c7118(void)

{
  int *piVar1;
  undefined1 uVar2;
  
  uVar2 = FUN_021cef80();
  piVar1 = DAT_021c7158;
  *(undefined1 *)(*DAT_021c7158 + 0x15) = uVar2;
  if (*(char *)(*piVar1 + 0x15) == '\0') {
    FUN_021cdc10(7);
  }
  else {
    if (*(char *)(*piVar1 + 0x15) != '\x01') {
      return;
    }
    FUN_021cdc10(0xe);
  }
  FUN_021cef90();
  FUN_021c212c(DAT_021c715c);
  return;
}

