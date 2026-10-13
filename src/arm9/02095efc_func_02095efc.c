/* Decompiled C draft; module arm9; ROM address 02095efc. No matching claim. */
#include "types.h"
#include "deps/02095efc_func_02095efc.h"

undefined1 func_02095efc(int param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0xd8U & 3;
  uVar3 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
  uVar2 = *param_4;
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 2) {
    *(undefined4 *)(param_1 + 0xa4) = 0x1e;
  }
  return uVar2;
}

