/* Decompiled C draft; module arm9; ROM address 020debec. No matching claim. */
#include "types.h"
#include "deps/020debec_func_020debec.h"

void func_020debec(undefined4 param_1,int param_2)

{
  ushort uVar1;
  
  *(short *)(param_2 + 0xa0) = *(short *)(param_2 + 0xa0) + 1;
  if (299 < *(ushort *)(param_2 + 0xa0)) {
    *(undefined2 *)(param_2 + 0xa0) = 0;
  }
  *(short *)(param_2 + 0xa2) = *(short *)(param_2 + 0xa2) + 1;
  if (0x81 < *(ushort *)(param_2 + 0xa2)) {
    *(undefined2 *)(param_2 + 0xa2) = 0;
  }
  uVar1 = *(ushort *)(param_2 + 0xa4);
  if (uVar1 < 0x80) {
    *(ushort *)(param_2 + 0xa4) = uVar1 + 1;
    if (0x60 < uVar1) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
    }
    return;
  }
  return;
}

