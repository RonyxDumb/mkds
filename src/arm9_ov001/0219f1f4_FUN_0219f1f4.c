/* Decompiled C draft; module arm9_ov001; ROM address 0219f1f4. No matching claim. */
#include "types.h"
#include "deps/0219f1f4_FUN_0219f1f4.h"

void FUN_0219f1f4(void)

{
  int *piVar1;
  
  piVar1 = DAT_0219f224;
  *(undefined4 *)(*DAT_0219f224 + 0x20) = 4;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(short *)(*piVar1 + 0x48) = (short)DAT_0219f228;
  FUN_0219f37c();
  func_0x0212ecc0(DAT_0219f22c,0,5);
  return;
}

