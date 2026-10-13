/* Decompiled C draft; module arm9; ROM address 02038e6c. No matching claim. */
#include "types.h"
#include "deps/02038e6c_DisplayEngineConfig_SomeClearFn.h"

void DisplayEngineConfig_SomeClearFn(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  iVar1 = 6;
  switch(param_2) {
  case 0:
    goto LAB_02038ed8;
  case 1:
    goto LAB_02038ed8;
  case 2:
    goto LAB_02038ee0;
  case 3:
LAB_02038ed8:
    iVar1 = 1;
    break;
  case 4:
LAB_02038ee0:
    iVar1 = 2;
    break;
  case 5:
    iVar1 = 3;
    break;
  case 6:
  }
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 == 1) {
    param_1[0x12] = 2;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x13] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
  }
  else if (iVar1 == 2) {
    param_1[0x12] = 2;
    param_1[0x14] = 0;
    param_1[0x13] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
  }
  else if (iVar1 == 3) {
    param_1[0x12] = 2;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
  }
  iVar1 = 6;
  switch(param_2) {
  case 0:
    iVar1 = 1;
    break;
  case 1:
    goto LAB_02038fa4;
  case 2:
LAB_02038fa4:
    iVar1 = 2;
    break;
  case 3:
    goto LAB_02038fac;
  case 4:
    goto LAB_02038fac;
  case 5:
LAB_02038fac:
    iVar1 = 3;
    break;
  case 6:
  }
  *(int *)(param_1 + 0x18) = iVar1;
  if (iVar1 == 1) {
    param_1[0x1a] = 2;
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1b] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
  }
  else if (iVar1 == 2) {
    param_1[0x1a] = 2;
    param_1[0x1c] = 0;
    param_1[0x1b] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
  }
  else if (iVar1 == 3) {
    param_1[0x1a] = 2;
    param_1[0x1b] = 0;
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
  }
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  return;
}

