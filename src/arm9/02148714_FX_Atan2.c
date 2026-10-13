/* Decompiled C draft; module arm9; ROM address 02148714. No matching claim. */
#include "types.h"
#include "deps/02148714_FX_Atan2.h"

short FX_Atan2(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
  if (param_1 < 1) {
    if (-1 < param_1) {
      if (param_2 < 0) {
        sVar2 = -0x8000;
      }
      else {
        sVar2 = 0;
      }
      return sVar2;
    }
    iVar4 = -param_1;
    if (param_2 < 0) {
      iVar1 = -param_2;
      if (param_1 == param_2 || iVar1 + param_1 < 0 != SBORROW4(iVar1,iVar4)) {
        if (iVar1 + param_1 < 0 == SBORROW4(iVar1,iVar4)) {
          return -0x6000;
        }
        sVar2 = -0x4000;
        param_1 = iVar4;
        iVar4 = iVar1;
        sVar3 = 0;
      }
      else {
        sVar2 = -0x8000;
        param_1 = iVar1;
        sVar3 = 1;
      }
    }
    else {
      if (param_2 < 1) {
        return -0x4000;
      }
      if (param_2 + param_1 < 0 == SBORROW4(param_2,iVar4)) {
        if (param_2 == iVar4 || param_2 + param_1 < 0 != SBORROW4(param_2,iVar4)) {
          return -0x2000;
        }
        sVar2 = 0;
        param_1 = param_2;
        sVar3 = sVar2;
      }
      else {
        sVar2 = -0x4000;
        param_1 = iVar4;
        iVar4 = param_2;
        sVar3 = 1;
      }
    }
  }
  else if (param_2 < 1) {
    if (-1 < param_2) {
      return 0x4000;
    }
    iVar4 = -param_2;
    if (iVar4 < param_1) {
      sVar2 = 0x4000;
      sVar3 = 1;
    }
    else {
      if (iVar4 <= param_1) {
        return 0x6000;
      }
      sVar2 = -0x8000;
      param_1 = iVar4;
      iVar4 = param_1;
      sVar3 = 0;
    }
  }
  else if (param_1 < param_2) {
    sVar2 = 0;
    param_1 = param_2;
    iVar4 = param_1;
    sVar3 = 1;
  }
  else {
    if (param_1 <= param_2) {
      return 0x2000;
    }
    sVar2 = 0x4000;
    iVar4 = param_2;
    sVar3 = 0;
  }
  if (param_1 != 0) {
    if (sVar3 == 0) {
      iVar4 = FX_Div(iVar4);
      return sVar2 - *(short *)(iRam021488e4 + (iVar4 >> 5) * 2);
    }
    iVar4 = FX_Div(iVar4);
    return sVar2 + *(short *)(iRam021488e4 + (iVar4 >> 5) * 2);
  }
  return 0;
}

