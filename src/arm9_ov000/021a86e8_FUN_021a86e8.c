/* Decompiled C draft; module arm9_ov000; ROM address 021a86e8. No matching claim. */
#include "types.h"
#include "deps/021a86e8_FUN_021a86e8.h"

int FUN_021a86e8(void)

{
  int iVar1;
  
  FUN_021a8740();
  if (*DAT_021a873c == 0) {
    iVar1 = FUN_021b02bc();
    if (iVar1 == 0) {
      iVar1 = -0x1a;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = FUN_021a8740();
    if (iVar1 == 0) {
      FUN_021a8604(*DAT_021a873c);
      iVar1 = FUN_021a86bc(*DAT_021a873c);
      if (iVar1 != 0) {
        *DAT_021a873c = 0;
      }
      iVar1 = -0x1a;
    }
    FUN_021a8424();
  }
  return iVar1;
}

