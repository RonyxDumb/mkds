/* Decompiled C draft; module arm9; ROM address 020da628. No matching claim. */
#include "types.h"
#include "deps/020da628_func_020da628.h"

void func_020da628(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = puRam020da67c;
  *(undefined2 *)(param_1 + 0xf8) = 0x1000;
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  *(undefined4 *)(param_1 + 0xa4) = *puVar1;
  *(undefined4 *)(param_1 + 0xa8) = uVar2;
  *(undefined4 *)(param_1 + 0xac) = uVar3;
  *(undefined4 *)(param_1 + 0xb0) = uVar4;
  uVar2 = puRam020da680[1];
  uVar3 = puRam020da680[2];
  uVar4 = puRam020da680[3];
  *(undefined4 *)(param_1 + 0xb4) = *puRam020da680;
  *(undefined4 *)(param_1 + 0xb8) = uVar2;
  *(undefined4 *)(param_1 + 0xbc) = uVar3;
  *(undefined4 *)(param_1 + 0xc0) = uVar4;
  StateDualHandler_SetState(param_1 + 0x80,1);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

