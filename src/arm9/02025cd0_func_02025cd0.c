/* Decompiled C draft; module arm9; ROM address 02025cd0. No matching claim. */
#include "types.h"
#include "deps/02025cd0_func_02025cd0.h"

void func_02025cd0(short *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  short extraout_r1;
  short extraout_r1_00;
  short extraout_r1_01;
  short extraout_r1_02;
  short extraout_r1_03;
  short extraout_r1_04;
  short extraout_r1_05;
  
  uVar1 = MaybeBoundsCheck(param_2,10);
  MaybeBoundsCheck(uVar1,10);
  *param_1 = extraout_r1 + 0x30;
  MaybeBoundsCheck(param_2,10);
  param_1[1] = extraout_r1_00 + 0x30;
  param_1[2] = 0x3a;
  uVar1 = MaybeBoundsCheck(param_3,10);
  MaybeBoundsCheck(uVar1,10);
  param_1[3] = extraout_r1_01 + 0x30;
  MaybeBoundsCheck(param_3,10);
  param_1[4] = extraout_r1_02 + 0x30;
  param_1[5] = 0x3a;
  uVar1 = MaybeBoundsCheck(param_4,100);
  MaybeBoundsCheck(uVar1,10);
  param_1[6] = extraout_r1_03 + 0x30;
  uVar1 = MaybeBoundsCheck(param_4,10);
  MaybeBoundsCheck(uVar1,10);
  param_1[7] = extraout_r1_04 + 0x30;
  MaybeBoundsCheck(param_4,10);
  param_1[8] = extraout_r1_05 + 0x30;
  param_1[9] = 0;
  return;
}

