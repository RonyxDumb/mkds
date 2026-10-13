/* Decompiled C draft; module arm9; ROM address 0201308c. No matching claim. */
#include "types.h"
#include "deps/0201308c_Maybe_helper_01308c.h"

void Maybe_helper_01308c(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      func_02013468(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

