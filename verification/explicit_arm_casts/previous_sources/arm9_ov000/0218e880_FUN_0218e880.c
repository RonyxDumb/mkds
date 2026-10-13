/* Decompiled C draft; module arm9_ov000; ROM address 0218e880. No matching claim. */
#include "types.h"
#include "deps/0218e880_FUN_0218e880.h"

int FUN_0218e880(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = func_0x0213a434();
  iVar1 = FUN_021a3690(iVar1 + 1);
  if (iVar1 != 0) {
    func_0x0213a2d0(iVar1,param_1);
  }
  return iVar1;
}

