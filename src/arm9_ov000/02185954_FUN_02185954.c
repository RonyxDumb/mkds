/* Decompiled C draft; module arm9_ov000; ROM address 02185954. No matching claim. */
#include "types.h"
#include "deps/02185954_FUN_02185954.h"

void FUN_02185954(undefined4 param_1)

{
  int *piVar1;
  
  func_0x0200ed34(*DAT_0218597c + DAT_02185980);
  piVar1 = DAT_0218597c;
  *(undefined4 *)(*DAT_0218597c + 4) = param_1;
  func_0x0200ecc4(*piVar1 + DAT_02185980);
  return;
}

