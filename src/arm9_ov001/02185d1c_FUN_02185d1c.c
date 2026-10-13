/* Decompiled C draft; module arm9_ov001; ROM address 02185d1c. No matching claim. */
#include "types.h"
#include "deps/02185d1c_FUN_02185d1c.h"

void FUN_02185d1c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0219b478(param_1,DAT_02185d60);
  *DAT_02185d64 = iVar1;
  FUN_0219b2e8(iVar1,DAT_02185d68);
  FUN_0219b380(*DAT_02185d64,DAT_02185d6c);
  func_0x0209b940(*DAT_02185d64,0x3f);
  func_0x0209ba08(*DAT_02185d64,2);
  func_0x020849a0(*(undefined4 *)(*DAT_02185d64 + 0x10),DAT_02185d70);
  return;
}

