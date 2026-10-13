/* Decompiled C draft; module arm9; ROM address 0214c74c. No matching claim. */
#include "types.h"
#include "deps/0214c74c_LoadMatrix4x4.h"

undefined4 * LoadMatrix4x4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar7 = param_1[7];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[4] = uVar4;
  param_2[5] = uVar5;
  param_2[6] = uVar6;
  param_2[7] = uVar7;
  uVar1 = param_1[9];
  uVar2 = param_1[10];
  uVar3 = param_1[0xb];
  uVar4 = param_1[0xc];
  uVar5 = param_1[0xd];
  uVar6 = param_1[0xe];
  uVar7 = param_1[0xf];
  *param_2 = param_1[8];
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[4] = uVar4;
  param_2[5] = uVar5;
  param_2[6] = uVar6;
  param_2[7] = uVar7;
  return param_1 + 0x10;
}

