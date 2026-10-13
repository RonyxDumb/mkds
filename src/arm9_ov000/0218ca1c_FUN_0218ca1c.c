/* Decompiled C draft; module arm9_ov000; ROM address 0218ca1c. No matching claim. */
#include "types.h"
#include "deps/0218ca1c_FUN_0218ca1c.h"

void FUN_0218ca1c(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  piVar3 = (int *)(param_1 + DAT_0218ca54);
  iVar1 = param_1;
  if (0 < *piVar3) {
    do {
      FUN_0218d0e4(param_1,*(undefined4 *)(iVar1 + 0x84));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *piVar3);
  }
  *(undefined4 *)(param_1 + DAT_0218ca54) = 0;
  return;
}

