/* Decompiled C draft; module arm9_ov003; ROM address 021d28e0. No matching claim. */
#include "types.h"
#include "deps/021d28e0_FUN_021d28e0.h"

void FUN_021d28e0(void)

{
  int iVar1;
  
  if (*DAT_021d2934 == '\0') {
    if (((int)(*DAT_021d2938 & DAT_021d293c) >> 0xf != 0) &&
       (iVar1 = func_0x0214f72c(0), iVar1 != 0)) {
      *DAT_021d2934 = '\x01';
    }
  }
  else if (((int)(*DAT_021d2938 & DAT_021d293c) >> 0xf == 0) &&
          (iVar1 = func_0x0214f72c(1), iVar1 != 0)) {
    *DAT_021d2934 = '\0';
    return;
  }
  return;
}

