/* Decompiled C draft; module arm9; ROM address 020da494. No matching claim. */
#include "types.h"
#include "deps/020da494_func_020da494.h"

void func_020da494(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *(undefined2 *)(param_1 + iRam020da5d0) = 0x1f;
  if (param_2 != 0) {
    uVar3 = _s32_div_f((int)*(short *)(param_2 + 0x28) << 0xb,100);
    func_020d7da8(param_1 + 0xcc,param_2,uVar3);
    iVar4 = GetLoadedNkmPathEntryPOIT
                      (*(undefined2 *)(param_2 + 0x26),*(undefined2 *)(param_2 + 0x2e));
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar4 + 4);
    uVar2 = _s32_div_f(*(short *)(param_2 + 0x28) * 0xb4,100);
    *(undefined2 *)(param_1 + 0xf8) = uVar2;
    *(uint *)(param_1 + 0xfc) = (uint)(*(short *)(param_2 + 0x2a) == 0);
    StateDualHandler_Create((undefined4 *)(uintptr_t)(param_1 + 0x80),uRam020da5d4,6,param_1);
    func_020d90a8(param_1 + 0xcc,*(undefined2 *)(*(int *)(param_1 + 0x9c) + 0x2e),1);
    func_020d8b88(param_1 + 0xcc,param_1 + 4);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xa0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    puVar1 = puRam020da5d8;
    uVar3 = puRam020da5d8[1];
    puVar5 = puRam020da5d8 + 2;
    *(undefined4 *)(param_1 + 0xa4) = *puRam020da5d8;
    *(undefined4 *)(param_1 + 0xa8) = uVar3;
    uVar3 = puVar1[3];
    *(undefined4 *)(param_1 + 0xac) = *puVar5;
    *(undefined4 *)(param_1 + 0xb0) = uVar3;
    puVar1 = puRam020da5dc;
    uVar3 = puRam020da5dc[1];
    puVar5 = puRam020da5dc + 2;
    *(undefined4 *)(param_1 + 0xb4) = *puRam020da5dc;
    *(undefined4 *)(param_1 + 0xb8) = uVar3;
    uVar3 = puVar1[3];
    *(undefined4 *)(param_1 + 0xbc) = *puVar5;
    *(undefined4 *)(param_1 + 0xc0) = uVar3;
    *(undefined2 *)(param_1 + 0xf0) = 0;
    *(undefined4 *)(param_1 + 0xf4) = 0;
    *(undefined2 *)(param_1 + 0x90) = 0;
    *(undefined2 *)(param_1 + 0x92) = 1;
    return;
  }
  *(short *)(param_1 + 0xd4) = (short)uRam020da5e0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  StateDualHandler_Create((undefined4 *)(uintptr_t)(param_1 + 0x80),uRam020da5d4,6,param_1);
  *(short *)(param_1 + 0xf8) = (short)uRam020da5e4;
  puVar1 = puRam020da5e8;
  uVar3 = puRam020da5e8[1];
  puVar5 = puRam020da5e8 + 2;
  *(undefined4 *)(param_1 + 0xa4) = *puRam020da5e8;
  *(undefined4 *)(param_1 + 0xa8) = uVar3;
  uVar3 = puVar1[3];
  *(undefined4 *)(param_1 + 0xac) = *puVar5;
  *(undefined4 *)(param_1 + 0xb0) = uVar3;
  puVar1 = puRam020da5ec;
  uVar3 = puRam020da5ec[1];
  puVar5 = puRam020da5ec + 2;
  *(undefined4 *)(param_1 + 0xb4) = *puRam020da5ec;
  *(undefined4 *)(param_1 + 0xb8) = uVar3;
  uVar3 = puVar1[3];
  *(undefined4 *)(param_1 + 0xbc) = *puVar5;
  *(undefined4 *)(param_1 + 0xc0) = uVar3;
  StateDualHandler_SetState(param_1 + 0x80,1,param_1 + 0xc4,puVar1 + 4);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

