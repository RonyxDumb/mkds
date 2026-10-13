/* Decompiled C draft; module arm9_ov000; ROM address 021adc64. No matching claim. */
#include "types.h"
#include "deps/021adc64_FUN_021adc64.h"

int FUN_021adc64(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021adce4 + 4) + 0xa4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 8) == '\n') {
      if (param_2 != 0) {
        FUN_021af70c(param_1,param_2,iVar1);
      }
      if (param_4 != 0) {
        FUN_021af70c(param_3,param_4,iVar1);
      }
      param_2 = param_2 + param_4;
    }
    else if (*(char *)(iVar1 + 8) == '\v') {
      if (param_2 != 0) {
        FUN_021af7e4(param_1,param_2,iVar1);
      }
      if (param_4 != 0) {
        FUN_021af7e4(param_3,param_4,iVar1);
      }
      param_2 = param_2 + param_4;
    }
    else if (*(char *)(iVar1 + 9) == '\0') {
      param_2 = FUN_021adcec();
    }
    else {
      param_2 = FUN_021a9280();
    }
    if (*DAT_021adce8 == '\0') {
      return param_2;
    }
  }
  return 0;
}

