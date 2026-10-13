/* Decompiled C draft; module arm9_ov000; ROM address 021a4418. No matching claim. */
#include "types.h"
#include "deps/021a4418_FUN_021a4418.h"

void FUN_021a4418(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_58 [72];
  
  if (((0 < param_4) && (param_4 < 0x42)) && (*(char *)(param_3 + param_4 + -1) == '\0')) {
    func_0x0213a2d0((uint *)(void *)(auStack_58),param_3);
    uVar1 = func_0x0213a434(param_1 + 0x44);
    FUN_021a44a0(param_1 + 0x44,uVar1,(int)(uintptr_t)(auStack_58),param_4 + -1);
    FUN_021a4578(auStack_58,param_4 + -1,(undefined1 *)(uintptr_t)(param_2 + *(int *)(param_2 + DAT_021a447c)));
    iVar2 = func_0x0213a434(param_2 + *(int *)(param_2 + DAT_021a447c));
    *(int *)(param_2 + DAT_021a447c) = *(int *)(param_2 + DAT_021a447c) + iVar2 + 1;
  }
  return;
}

