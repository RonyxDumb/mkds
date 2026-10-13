/* Decompiled C draft; module arm9; ROM address 020917d0. No matching claim. */
#include "types.h"
#include "deps/020917d0_func_020917d0.h"

undefined1 func_020917d0(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    *(undefined4 *)(param_1 + 0xb8) = uRam02091820;
    *(undefined4 *)(param_1 + 0xbc) = 0x8000;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam02091824;
    *(undefined4 *)(param_1 + 200) = 1;
  }
  return uVar1;
}

