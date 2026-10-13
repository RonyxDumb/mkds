/* Decompiled C draft; module arm9; ROM address 021522a0. No matching claim. */
#include "types.h"
#include "deps/021522a0_func_021522a0.h"

int func_021522a0(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (((((*param_1 < 100) && (uVar2 = param_1[1], uVar2 != 0)) && (uVar2 < 0xd)) &&
      ((uVar3 = param_1[2], uVar3 != 0 && (uVar3 < 0x20)))) &&
     (((int)param_1[3] < 7 && ((uVar2 != 0 && (uVar2 < 0xd)))))) {
    iVar4 = (uVar3 - 1) + *(int *)(iRam0215230c + uVar2 * 4);
    if ((2 < uVar2) && (iVar1 = IsLeapYear_from_thumb(), iVar1 != 0)) {
      iVar4 = iVar4 + 1;
    }
    return iVar4 + iRam02152310 * *param_1 + (*param_1 + 3 >> 2);
  }
  return -1;
}

