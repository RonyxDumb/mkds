/* Decompiled C draft; module arm9_ov001; ROM address 021826fc. No matching claim. */
#include "types.h"
#include "deps/021826fc_FUN_021826fc.h"

void FUN_021826fc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0219b478(param_1,DAT_0218273c);
  *DAT_02182740 = iVar1;
  FUN_0219b2e8(iVar1,DAT_02182744);
  func_0x0209b940(*DAT_02182740,0x3f);
  func_0x0209ba08(*DAT_02182740,2);
  func_0x020849a0(*(undefined4 *)(*DAT_02182740 + 0x10),DAT_02182748);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return;
}

