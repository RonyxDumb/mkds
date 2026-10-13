/* Decompiled C draft; module arm9_ov000; ROM address 02193b88. No matching claim. */
#include "types.h"
#include "deps/02193b88_FUN_02193b88.h"

int FUN_02193b88(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 auStack_38 [36];
  
  if (param_2 == 0) {
    func_0x0213442c(DAT_02193c08,DAT_02193c0c,0,DAT_02193c10);
  }
  if (param_3 == 0) {
    param_3 = DAT_02193c14;
  }
  if (param_4 == -1) {
    param_4 = func_0x0213a434(param_3);
  }
  func_0x02135014(auStack_38,DAT_02193c18,param_4);
  iVar1 = FUN_02190968(param_1,param_2,auStack_38);
  if (((iVar1 == 0) && (iVar1 = FUN_02190988(param_1,param_2,param_3,param_4), iVar1 == 0)) &&
     (iVar1 = FUN_02190a24(param_1,param_2,0), iVar1 == 0)) {
    iVar1 = FUN_0218e320(0);
    *(int *)(param_2 + 0x10) = iVar1 + DAT_02193c1c;
    iVar1 = 0;
  }
  return iVar1;
}

