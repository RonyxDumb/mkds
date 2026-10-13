/* Decompiled C draft; module arm9_ov003; ROM address 021cef28. No matching claim. */
#include "types.h"
#include "deps/021cef28_FUN_021cef28.h"

void FUN_021cef28(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_021cef60;
  *(char *)(*DAT_021cef60 + 0x1a) = *(char *)(*DAT_021cef60 + 0x1a) + -1;
  func_0x0214a348(DAT_021cef64,(int)*(char *)(*piVar1 + 0x1a));
  if (*(char *)(*DAT_021cef60 + 0x1a) < -0xb) {
    FUN_021d34e0(param_1,DAT_021cef68);
  }
  return;
}

