/* Decompiled C draft; module arm9_ov003; ROM address 021c68c8. No matching claim. */
#include "types.h"
#include "deps/021c68c8_FUN_021c68c8.h"

void FUN_021c68c8(void)

{
  int *piVar1;
  undefined1 uVar2;
  
  uVar2 = FUN_021cef80();
  piVar1 = DAT_021c690c;
  *(undefined1 *)(*DAT_021c690c + 0x2a) = uVar2;
  if (*(char *)(*piVar1 + 0x2a) == '\0') {
    FUN_021cdc10(7);
  }
  else {
    if (*(char *)(*piVar1 + 0x2a) != '\x01') {
      return;
    }
    FUN_021cdc10(0xe);
  }
  FUN_021cef90();
  FUN_021c212c(DAT_021c6910);
  return;
}

