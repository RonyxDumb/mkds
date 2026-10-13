/* Decompiled C draft; module arm9_ov001; ROM address 02184ff8. No matching claim. */
#include "types.h"
#include "deps/02184ff8_FUN_02184ff8.h"

undefined4 FUN_02184ff8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar1 = func_0x020220f0(param_1 + 0x2c);
    return uVar1;
  }
  return 0xfffffffb;
}

