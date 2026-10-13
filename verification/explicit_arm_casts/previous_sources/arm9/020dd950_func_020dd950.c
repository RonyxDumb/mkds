/* Decompiled C draft; module arm9; ROM address 020dd950. No matching claim. */
#include "types.h"
#include "deps/020dd950_func_020dd950.h"

void func_020dd950(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                  int *param_7)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  
  *param_1 = param_4;
  param_1[8] = param_5;
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  iVar2 = Mem_AllocateHeap(uVar1,param_5 * 0xc);
  param_1[0x11] = iVar2;
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  iVar2 = Mem_AllocateHeap(uVar1,param_5 * 0xc);
  param_1[0x12] = iVar2;
  iVar2 = param_7[1];
  param_1[0xd] = *param_7;
  param_1[0xe] = iVar2;
  param_1[0xf] = param_7[2];
  uVar4 = Multiply64(param_6,param_6 >> 0x1f,param_7[1],param_7[1] >> 0x1f);
  param_1[0x10] = (uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14;
  iVar2 = _s32_div_f(uRam020dda1c,param_5 + -1);
  param_1[9] = iVar2;
  uVar4 = Multiply64(param_4,param_4 >> 0x1f,uRam020dda20,0);
  iVar2 = _s32_div_f((uint)uVar4 >> 0xc | (int)((ulonglong)uVar4 >> 0x20) << 0x14,param_5 + -1);
  param_1[10] = iVar2;
  iVar2 = param_1[10];
  uVar4 = Multiply64(iVar2,iVar2 >> 0x1f,iVar2,iVar2 >> 0x1f);
  *(undefined8 *)(param_1 + 0xb) = uVar4;
  func_020dd8b0(param_1,param_2,param_3);
  param_1[3] = *(int *)(param_2 + 4) + param_1[0x10];
  param_1[1] = iRam020dda24;
  param_1[4] = 0x51;
  iVar2 = piRam020dda28[1];
  piVar3 = piRam020dda28 + 2;
  param_1[5] = *piRam020dda28;
  param_1[6] = iVar2;
  param_1[7] = *piVar3;
  param_1[2] = 1;
  return;
}

