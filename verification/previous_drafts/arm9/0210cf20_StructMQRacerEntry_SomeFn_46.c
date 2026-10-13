/* Decompiled C draft; module arm9; ROM address 0210cf20. No matching claim. */
#include "types.h"
#include "deps/0210cf20_StructMQRacerEntry_SomeFn_46.h"

void StructMQRacerEntry_SomeFn_46(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  IntrusiveListWrapper_InitializeEmpty((undefined4 *)(uintptr_t)(param_1 + 0xc),8);
  uVar1 = uRam0210cf90;
  *(undefined4 *)(param_1 + 0x38) = 1;
  uVar2 = uRam0210cf94;
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_1 + 0x18) = 3;
  StructMQChild_Create((undefined4 *)(uintptr_t)(param_1 + 0x1c));
  StructMQChild_Create((undefined4 *)(uintptr_t)(param_1));
  StructMQRacerEntry_MaybeInsertChildEntry(uRam0210cf98,param_1);
  return;
}

