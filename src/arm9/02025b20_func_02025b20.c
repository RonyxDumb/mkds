/* Decompiled C draft; module arm9; ROM address 02025b20. No matching claim. */
#include "types.h"
#include "deps/02025b20_func_02025b20.h"

void func_02025b20(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,code *param_8)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = (*param_8)(param_2);
    Gfx_ReadCharGraphicsRelative((int *)(uintptr_t)(param_1),uVar1);
  }
  if (param_3 != 0) {
    uVar1 = (*param_8)(param_3);
    func_020b48b4((int *)(uintptr_t)(param_1 + 8),uVar1);
  }
  if (param_4 != 0) {
    uVar1 = (*param_8)(param_4);
    Gfx_ReadPaletteRelative((int *)(uintptr_t)(param_1 + 4),uVar1);
  }
  if (param_5 != 0) {
    uVar1 = (*param_8)();
    *(undefined4 *)(param_1 + 0xc) = uVar1;
  }
  if (param_6 != 0) {
    uVar1 = (*param_8)();
    *(undefined4 *)(param_1 + 0x14) = uVar1;
  }
  if (param_7 != 0) {
    uVar1 = (*param_8)();
    *(undefined4 *)(param_1 + 0x10) = uVar1;
  }
  return;
}

