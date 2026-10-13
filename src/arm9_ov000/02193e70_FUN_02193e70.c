/* Decompiled C draft; module arm9_ov000; ROM address 02193e70. No matching claim. */
#include "types.h"
#include "deps/02193e70_FUN_02193e70.h"

int FUN_02193e70(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int local_14 [2];
  
  iVar1 = FUN_021938cc((int *)(uintptr_t)(param_1),2,0,local_14,0,0,0);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_02192330((int *)(uintptr_t)(param_1),param_2[3],*(undefined4 *)(local_14[0] + 0x18)), iVar1 == 0)) {
    *param_2 = 0x65;
    iVar1 = 0;
  }
  return iVar1;
}

