/* Decompiled C draft; module arm9; ROM address 0214fbe4. No matching claim. */
#include "types.h"
#include "deps/0214fbe4_func_0214fbe4.h"

undefined4 func_0214fbe4(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == 0) {
    if (param_2 == 1) {
      iVar2 = 6;
    }
    if (param_2 == 0) {
      iVar2 = 7;
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 1) {
      iVar2 = 4;
    }
    if (param_2 == 0) {
      iVar2 = 5;
    }
  }
  else if (param_1 == 2) {
    if (param_2 == 1) {
      iVar2 = 8;
    }
    if (param_2 == 0) {
      iVar2 = 9;
    }
  }
  if (iVar2 == 0) {
    return uRam0214fc70;
  }
  uVar1 = func_0214fe88(iVar2,param_3,param_4);
  return uVar1;
}

