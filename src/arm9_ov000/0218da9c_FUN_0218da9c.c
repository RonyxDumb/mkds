/* Decompiled C draft; module arm9_ov000; ROM address 0218da9c. No matching claim. */
#include "types.h"
#include "deps/0218da9c_FUN_0218da9c.h"

void FUN_0218da9c(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_2 < 0) || (*param_1 <= param_2)) {
    func_0x0213442c(DAT_0218daf0,DAT_0218daf4,0,0xc0);
  }
  iVar1 = *param_1;
  if (param_2 < iVar1 + -1) {
    uVar2 = FUN_0218dbf8(param_1,param_2);
    uVar3 = FUN_0218dbf8(param_1,param_2 + 1);
    func_0x02134df8((uint *)(uintptr_t)(uVar2),(uint *)(uintptr_t)(uVar3),((iVar1 + -1) - param_2) * param_1[2]);
  }
  *param_1 = *param_1 + -1;
  return;
}

