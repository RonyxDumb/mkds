/* Decompiled C draft; module arm9; ROM address 020f02c0. No matching claim. */
#include "types.h"
#include "deps/020f02c0_func_020f02c0.h"

void func_020f02c0(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar9 = *param_3;
  iVar5 = param_2 * 0xa8;
  iVar7 = *(int *)(*piRam020f03b8 + iVar5 + 0xc);
  uVar6 = *(undefined4 *)(*piRam020f03b8 + iVar5);
  *param_1 = param_2;
  if (iVar7 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = Mem_AllocateHeap(uVar2,iVar7 << 2);
  }
  param_1[1] = iVar3;
  param_1[2] = iVar7;
  piVar1 = piRam020f03b8;
  param_1[3] = *(int *)(*piRam020f03b8 + iVar5 + 0x10);
  iVar3 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = *(int *)(*piVar1 + iVar5 + 4);
  if (0 < iVar7) {
    iVar8 = 0;
    do {
      uVar4 = Mem_AllocateHeap(uVar2,uVar6);
      *(undefined4 *)(param_1[1] + iVar8) = uVar4;
      func_020f8d9c(*(undefined4 *)(param_1[1] + iVar8),iVar9,param_2);
      iVar9 = iVar9 + 1;
      *(short *)(*(int *)(param_1[1] + iVar8) + 0x4c) = (short)iVar3;
      iVar8 = iVar8 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar7);
  }
  piVar1 = piRam020f03b8;
  param_1[9] = *(int *)(*piRam020f03b8 + iVar5 + 0x2c);
  param_1[10] = *(int *)(*piVar1 + iVar5 + 0x30);
  param_1[0xb] = *(int *)(*piVar1 + iVar5 + 0x70);
  param_1[0xc] = *(int *)(*piVar1 + iVar5 + 0x74);
  param_1[0xd] = *(int *)(*piVar1 + iVar5 + 0x78);
  param_1[0xe] = *(int *)(*piVar1 + iVar5 + 0x5c);
  param_1[0xf] = *(int *)(*piVar1 + iVar5 + 0xa4);
  *param_3 = iVar9;
  return;
}

