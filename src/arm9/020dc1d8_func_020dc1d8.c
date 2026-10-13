/* Decompiled C draft; module arm9; ROM address 020dc1d8. No matching claim. */
#include "types.h"
#include "deps/020dc1d8_func_020dc1d8.h"

void func_020dc1d8(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 0xa0) = *param_2;
  *(undefined4 *)(param_1 + 0xa4) = uVar2;
  *(undefined4 *)(param_1 + 0xa8) = param_2[2];
  uVar4 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020dc2d4,0);
  *(uint *)(param_1 + 0xf0) = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
  *(int *)(param_1 + 0xf4) = iRam020dc2d8 - *(int *)(param_1 + 0xf0);
  *(int *)(param_1 + 0xf8) = iRam020dc2dc * *(short *)(param_2 + 10) >> 2;
  *(int *)(param_1 + iRam020dc2e0) = (int)*(short *)((int)param_2 + 0x2a) << 0xc;
  *(int *)(param_1 + iRam020dc2e4) = (int)*(short *)(param_2 + 10) << 0xc;
  *(int *)(param_1 + iRam020dc2e8) = *(int *)(param_1 + 0xf8) + *(int *)(param_1 + 0xf0) * -2;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  uVar2 = func_020d34d4(param_1,uRam020dc2ec);
  *(undefined4 *)(param_1 + iRam020dc2f0) = uVar2;
  *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0xa4);
  *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0xf0);
  StateDualHandler_Create((undefined4 *)(uintptr_t)(param_1 + 0x80),uRam020dc2f4,6,param_1);
  StateDualHandler_SetState(param_1 + 0x80,0);
  puVar3 = (undefined4 *)(param_1 + iRam020dc2f8);
  uVar2 = *(undefined4 *)(param_1 + 0x44);
  *puVar3 = *(undefined4 *)(param_1 + 0x40);
  puVar3[1] = uVar2;
  puVar3[2] = *(undefined4 *)(param_1 + 0x48);
  func_020dbf7c(param_1);
  uVar1 = FindComputeSomeCollisionEntryId
                    (param_1 + 4,*(undefined4 *)(param_1 + iRam020dc2e4),uRam020dc2fc,param_1);
  *(undefined2 *)(param_1 + iRam020dc300) = uVar1;
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iRam020dc304 + 0x30);
  return;
}

