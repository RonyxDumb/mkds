/* Decompiled C draft; module arm9_ov000; ROM address 021aa3b8. No matching claim. */
#include "types.h"
#include "deps/021aa3b8_FUN_021aa3b8.h"

void FUN_021aa3b8(int param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_20 [20];
  
  func_0x0214d1fc(param_1 + DAT_021aa454,param_1 + DAT_021aa458,0x58);
  FUN_021aa50c(param_1,auStack_20,1);
  func_0x0214d1fc(param_1 + DAT_021aa458,param_1 + DAT_021aa454,0x58);
  iVar1 = func_0x02134d30(param_2,auStack_20,0x10);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + DAT_021aa45c) = 9;
    return;
  }
  func_0x0214d1fc(param_1 + DAT_021aa460,param_1 + DAT_021aa464,0x5c);
  FUN_021aa468(param_1,auStack_20,1);
  func_0x0214d1fc(param_1 + DAT_021aa464,param_1 + DAT_021aa460,0x5c);
  iVar1 = func_0x02134d30(param_2 + 0x10,auStack_20,0x14);
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + DAT_021aa45c) = 9;
    return;
  }
  *(undefined1 *)(param_1 + DAT_021aa45c) = 6;
  return;
}

