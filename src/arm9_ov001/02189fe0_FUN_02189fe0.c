/* Decompiled C draft; module arm9_ov001; ROM address 02189fe0. No matching claim. */
#include "types.h"
#include "deps/02189fe0_FUN_02189fe0.h"

void FUN_02189fe0(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 0x44) == 9) && (iVar1 = func_0x020fd528(param_2), iVar1 == 0)) {
    func_0x0208b748(0x3a,param_2 + 0x50,0,DAT_0218a01c);
  }
  *(undefined4 *)(param_1 + DAT_0218a020) = 1;
  FUN_021881f4(param_1,DAT_0218a024);
  return;
}

