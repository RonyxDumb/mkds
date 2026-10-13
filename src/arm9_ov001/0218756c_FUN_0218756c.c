/* Decompiled C draft; module arm9_ov001; ROM address 0218756c. No matching claim. */
#include "types.h"
#include "deps/0218756c_FUN_0218756c.h"

void FUN_0218756c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0xd0) == 0) {
      *(undefined4 *)(param_1 + iVar2 * 0x18 + 0xbc) = 2;
      FUN_02187614(param_1,iVar2,param_2,param_3,param_4,param_5,param_6);
      return;
    }
    iVar1 = iVar1 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}

