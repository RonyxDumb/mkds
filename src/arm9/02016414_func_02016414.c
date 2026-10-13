/* Decompiled C draft; module arm9; ROM address 02016414. No matching claim. */
#include "types.h"
#include "deps/02016414_func_02016414.h"

void func_02016414(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(iRam02016454 + 8) = param_1;
  func_020162b0();
  puVar2 = puRam02016464;
  uVar1 = uRam02016460;
  if (param_2 != 0) {
    *puRam0201645c = uRam02016458;
    *puVar2 = uVar1;
    return;
  }
  return;
}

