/* Decompiled C draft; module arm9_ov000; ROM address 021960a4. No matching claim. */
#include "types.h"
#include "deps/021960a4_FUN_021960a4.h"

int FUN_021960a4(undefined4 param_1,char *param_2,char *param_3,char *param_4,char *param_5,
                char *param_6,int param_7,int param_8,undefined4 param_9,undefined4 param_10,
                undefined4 param_11)

{
  int iVar1;
  int local_1c [2];
  
  if ((((((param_2 == (char *)0x0) || (*param_2 == '\0')) &&
        ((param_4 == (char *)0x0 || (*param_4 == '\0')))) &&
       ((param_5 == (char *)0x0 || (*param_5 == '\0')))) &&
      ((param_6 == (char *)0x0 || (*param_6 == '\0')))) &&
     ((param_7 == 0 && ((param_3 == (char *)0x0 || (*param_3 == '\0')))))) {
    FUN_02196590((undefined4 *)(uintptr_t)(param_1),DAT_021961dc);
    return 2;
  }
  iVar1 = FUN_02196240(param_1,local_1c,1);
  if (iVar1 == 0) {
    if (param_2 == (char *)0x0) {
      *(undefined1 *)(local_1c[0] + 0x28) = 0;
    }
    else {
      FUN_02196914(local_1c[0] + 0x28,(int)(uintptr_t)(param_2),0x1f);
    }
    if (param_3 == (char *)0x0) {
      *(undefined1 *)(local_1c[0] + 0x47) = 0;
    }
    else {
      FUN_02196914(local_1c[0] + 0x47,(int)(uintptr_t)(param_3),0x15);
    }
    if (param_4 == (char *)0x0) {
      *(undefined1 *)(local_1c[0] + 0x5c) = 0;
    }
    else {
      FUN_02196914(local_1c[0] + 0x5c,(int)(uintptr_t)(param_4),0x33);
    }
    FUN_0218e850((char *)(uintptr_t)(local_1c[0] + 0x5c));
    if (param_5 == (char *)0x0) {
      *(undefined1 *)(local_1c[0] + 0x8f) = 0;
    }
    else {
      FUN_02196914(local_1c[0] + 0x8f,(int)(uintptr_t)(param_5),0x1f);
    }
    if (param_6 == (char *)0x0) {
      *(undefined1 *)(local_1c[0] + 0xae) = 0;
    }
    else {
      FUN_02196914(local_1c[0] + 0xae,(int)(uintptr_t)(param_6),0x1f);
    }
    *(int *)(local_1c[0] + DAT_021961e0) = param_7;
    if (param_8 < 0) {
      param_8 = 0;
    }
    *(int *)(local_1c[0] + DAT_021961e4) = param_8;
    iVar1 = FUN_021961e8((int *)(uintptr_t)(param_1),local_1c[0],param_9,param_10,param_11);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

