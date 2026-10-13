/* Decompiled C draft; module arm9_ov000; ROM address 021a5bfc. No matching claim. */
#include "types.h"
#include "deps/021a5bfc_FUN_021a5bfc.h"

undefined4 FUN_021a5bfc(void)

{
  undefined4 uVar1;
  
  func_0x0200fca0();
  uVar1 = 0;
  if (*DAT_021a5c1c != 0) {
    uVar1 = *(undefined4 *)(*DAT_021a5c1c + DAT_021a5c20);
  }
  func_0x0200fcb4();
  return uVar1;
}

