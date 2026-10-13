/* Decompiled C draft; module arm9; ROM address 0200e28c. No matching claim. */
#include "types.h"
#include "deps/0200e28c_Os_Thread_Create.h"

void Os_Thread_Create(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                     undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = Os_DisableIrq();
  uVar3 = Os_AllocateThreadId();
  *(undefined4 *)(param_1 + 0x70) = param_6;
  *(undefined4 *)(param_1 + 0x6c) = uVar3;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  Os_InsertThread(param_1);
  *(int *)(param_1 + 0x94) = param_4;
  *(int *)(param_1 + 0x90) = param_4 - param_5;
  *(undefined4 *)(param_1 + 0x98) = 0;
  uVar3 = uRam0200e380;
  uVar1 = param_1 + 0x94U & 3;
  uVar4 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - 4) = uRam0200e37c;
  uVar1 = param_1 + 0x90U & 3;
  uVar4 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  *(undefined4 *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) = uVar3;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  uVar1 = param_1 + 0xa0U & 3;
  uVar4 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  *(uint *)(param_1 + 0x9c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  Arm_Context_Create(param_1,param_2,param_4 + -4);
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = uRam0200e384;
  MIi_CpuClear32(0,(param_4 - param_5) + 4,param_5 + -8);
  Os_Thread_SetDestructor(param_1,0);
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  uVar1 = param_1 + 0x80U & 3;
  uVar4 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  Os_RestoreIrq(uVar2);
  return;
}

