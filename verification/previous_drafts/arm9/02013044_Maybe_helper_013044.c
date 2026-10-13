/* Decompiled C draft; module arm9; ROM address 02013044. No matching claim. */
#include "types.h"
#include "deps/02013044_Maybe_helper_013044.h"

void Maybe_helper_013044(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      func_02013424(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

