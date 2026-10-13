/* Decompiled C draft; module arm9; ROM address 02148538. No matching claim. */
#include "types.h"
#include "deps/02148538_func_02148538.h"

int func_02148538(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < 1) {
    if (-1 < param_1) {
      iVar2 = iRam021486fc;
      if (-1 < param_2) {
        iVar2 = 0;
      }
      return iVar2;
    }
    iVar2 = -param_1;
    iVar3 = iVar2;
    if (param_2 < 0) {
      iVar4 = -param_2;
      if (param_1 == param_2 || iVar4 + param_1 < 0 != SBORROW4(iVar4,iVar2)) {
        if (iVar2 <= iVar4) {
          return iRam0214870c;
        }
        iVar1 = 0;
        iVar2 = iVar4;
        iVar4 = iRam02148708;
      }
      else {
        iVar1 = 1;
        iVar3 = iVar4;
        iVar4 = iRam02148704;
      }
    }
    else {
      if (param_2 < 1) {
        return iRam02148708;
      }
      if (param_2 + param_1 < 0 == SBORROW4(param_2,iVar2)) {
        if (param_2 <= iVar2) {
          return -0xc91;
        }
        iVar1 = 0;
        iVar3 = param_2;
        iVar4 = iVar1;
      }
      else {
        iVar1 = 1;
        iVar2 = param_2;
        iVar4 = iRam02148708;
      }
    }
  }
  else {
    iVar3 = param_1;
    iVar4 = iRam021486f4;
    if (param_2 < 1) {
      if (-1 < param_2) {
        return iRam021486f4;
      }
      iVar2 = -param_2;
      if (iVar2 < param_1) {
        iVar1 = 1;
      }
      else {
        if (iVar2 <= param_1) {
          return iRam02148700;
        }
        iVar1 = 0;
        iVar3 = iVar2;
        iVar2 = param_1;
        iVar4 = iRam021486fc;
      }
    }
    else if (param_1 < param_2) {
      iVar1 = 1;
      iVar3 = param_2;
      iVar2 = param_1;
      iVar4 = 0;
    }
    else {
      if (param_1 <= param_2) {
        return iRam021486f8;
      }
      iVar1 = 0;
      iVar2 = param_2;
    }
  }
  if (iVar3 == 0) {
    return 0;
  }
  if (iVar1 != 0) {
    iVar2 = FX_Div(iVar2);
    return (iVar4 + *(short *)(iRam02148710 + (iVar2 >> 5) * 2)) * 0x10000 >> 0x10;
  }
  iVar2 = FX_Div(iVar2);
  return (iVar4 - *(short *)(iRam02148710 + (iVar2 >> 5) * 2)) * 0x10000 >> 0x10;
}

