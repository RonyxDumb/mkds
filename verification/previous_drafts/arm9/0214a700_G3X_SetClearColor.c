/* Decompiled C draft; module arm9; ROM address 0214a700. No matching claim. */
#include "types.h"
#include "deps/0214a700_G3X_SetClearColor.h"

void G3X_SetClearColor(uint param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  uint uVar2;
  
  puVar1 = puRam0214a72c;
  uVar2 = param_1 | param_2 << 0x10 | param_4 << 0x18;
  if (param_5 != 0) {
    uVar2 = uVar2 | 0x8000;
  }
  *puRam0214a728 = uVar2;
  *puVar1 = param_3;
  return;
}

