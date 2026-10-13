/* Decompiled C draft; module arm9; ROM address 020390f0. No matching claim. */
#include "types.h"
#include "deps/020390f0_Bright_UpdateContext.h"

void Bright_UpdateContext(undefined2 *param_1)

{
  short sVar1;
  undefined2 uVar2;
  
  switch(*param_1) {
  case 0:
    break;
  case 1:
    param_1[2] = param_1[2] + 1;
    if ((int)(short)param_1[2] < (int)(short)param_1[3]) {
      sVar1 = _s32_div_f((int)(short)param_1[2] << 4);
      param_1[4] = 0x10 - sVar1;
    }
    else {
      *param_1 = 2;
      param_1[4] = 0;
    }
    if (param_1[1] == 0) {
      param_1[4] = -param_1[4];
    }
    return;
  case 2:
    param_1[4] = 0;
    return;
  case 3:
    param_1[2] = param_1[2] + 1;
    if ((int)(short)param_1[2] < (int)(short)param_1[3]) {
      uVar2 = _s32_div_f((int)(short)param_1[2] << 4);
      param_1[4] = uVar2;
    }
    else {
      *param_1 = 0;
      param_1[4] = 0x10;
    }
    if (param_1[1] == 0) {
      param_1[4] = -param_1[4];
    }
  }
  return;
}

