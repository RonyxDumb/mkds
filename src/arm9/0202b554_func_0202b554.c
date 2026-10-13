/* Decompiled C draft; module arm9; ROM address 0202b554. No matching claim. */
#include "types.h"
#include "deps/0202b554_func_0202b554.h"

void func_0202b554(int param_1,int param_2)

{
  undefined4 uVar1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int iVar2;
  
  uVar1 = _s32_div_f(param_2,10);
  _s32_div_f(uVar1,10);
  _s32_div_f(param_2,10);
  iVar2 = *piRam0202b5f8;
  *(uint *)(*(int *)(iVar2 + 0x18) + iRam0202b5fc) = (uint)(9 < param_1);
  uVar1 = _s32_div_f(param_1,10);
  _s32_div_f(uVar1,10);
  func_02025c48(0x3c,extraout_r1_01 + 0x41,*(undefined4 *)(iVar2 + 0xc));
  _s32_div_f(param_1,10);
  func_02025c48(0x3d,extraout_r1_02 + 0x41,*(undefined4 *)(iVar2 + 0xc));
  if (9 < param_2) {
    func_02025c48(0x3f,extraout_r1 + 0x4b,*(undefined4 *)(iVar2 + 0xc));
    func_02025c48(0x40,extraout_r1_00 + 0x4b,*(undefined4 *)(iVar2 + 0xc));
    return;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0x18) + iRam0202b600) = 0;
  func_02025c48(0x3f,extraout_r1_00 + 0x4b,*(undefined4 *)(iVar2 + 0xc));
  return;
}

