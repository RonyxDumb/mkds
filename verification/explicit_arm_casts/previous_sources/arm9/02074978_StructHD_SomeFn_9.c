/* Decompiled C draft; module arm9; ROM address 02074978. No matching claim. */
#include "types.h"
#include "deps/02074978_StructHD_SomeFn_9.h"

void StructHD_SomeFn_9(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x218U & 3;
  uVar2 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  StructHD_SomeFn_11(param_1,(int)*(short *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) +
                                            0x42));
  StructHD_SomeFn_8(param_1);
  StructHD_SomeFn_10(param_1);
  return;
}

