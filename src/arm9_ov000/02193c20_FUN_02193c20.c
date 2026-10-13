/* Decompiled C draft; module arm9_ov000; ROM address 02193c20. No matching claim. */
#include "types.h"
#include "deps/02193c20_FUN_02193c20.h"

void FUN_02193c20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_58 [68];
  
  uVar2 = param_4[1];
  uVar3 = *param_4;
  uVar1 = param_4[2];
  if (param_4 == (undefined4 *)0x0) {
    func_0x0213442c(DAT_02193c64,DAT_02193c68,0,DAT_02193c6c);
  }
  func_0x02135014(auStack_58,DAT_02193c70,param_3,uVar3,uVar2,uVar1);
  FUN_02190968(param_1,param_2,(undefined4)(uintptr_t)(auStack_58));
  return;
}

