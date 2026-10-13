/* Decompiled C draft; module arm9; ROM address 02025884. No matching claim. */
#include "types.h"
#include "deps/02025884_func_02025884.h"

void func_02025884(int param_1,int param_2,int param_3,int param_4,int param_5,code *param_6)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = (*param_6)(param_2);
    Gfx_ReadCharGraphicsV2((int *)(uintptr_t)(param_1 + param_5 * 4),uVar1);
  }
  if (param_3 != 0) {
    uVar1 = (*param_6)(param_3);
    Gfx_ReadPalette((int *)(uintptr_t)(param_1 + 0x10),uVar1);
  }
  if (param_4 != 0) {
    uVar1 = (*param_6)(param_4);
    MaybeReadScreenBlock_0((int *)(uintptr_t)(param_1 + 0x14 + param_5 * 4),uVar1);
  }
  return;
}

