/* Decompiled C draft; module arm9; ROM address 0210c134. No matching claim. */
#include "types.h"
#include "deps/0210c134_func_0210c134.h"

void func_0210c134(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  IntrusiveListWrapper_InitializeEmpty(param_1 + 0xc,8);
  uVar1 = uRam0210c1a4;
  *(undefined4 *)(param_1 + 0x38) = 1;
  uVar2 = uRam0210c1a8;
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 3;
  StructMQChild_Create(param_1 + 0x1c);
  StructMQChild_Create(param_1);
  StructMQRacerEntry_MaybeInsertChildEntry(uRam0210c1ac,param_1);
  return;
}

