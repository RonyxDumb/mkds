/* Decompiled C draft; module arm9_ov003; ROM address 021ba734. No matching claim. */
#include "types.h"
#include "deps/021ba734_FUN_021ba734.h"

void FUN_021ba734(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint unaff_r4;
  uint uVar2;
  int unaff_r8;
  int unaff_r9;
  uint unaff_r10;
  undefined1 in_NG;
  undefined1 in_ZR;
  bool in_OV;
  undefined4 in_cr1;
  
  if (in_OV) {
    param_2 = unaff_r10 & param_4 << 0x18;
    in_NG = (int)param_2 < 0;
    in_ZR = param_2 == 0;
  }
  if (!(bool)in_ZR) {
    coprocessor_load(0xc,in_cr1,unaff_r9 + -0x20);
  }
  if ((bool)in_NG) {
    uVar2 = unaff_r8 + (int)param_1 * -0x400000;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    unaff_r4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  func_0x0214cfe4(0,param_2 + 0xc,0x20,param_4,0,unaff_r4);
  *(short *)(param_2 + 10) = (short)*param_1;
  func_0x0214d1fc(param_1 + 1,param_2 + 0xc,*(undefined2 *)(param_2 + 10));
  return;
}

