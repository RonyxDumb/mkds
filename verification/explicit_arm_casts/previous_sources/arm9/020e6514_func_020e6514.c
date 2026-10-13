/* Decompiled C draft; module arm9; ROM address 020e6514. No matching claim. */
#include "types.h"
#include "deps/020e6514_func_020e6514.h"

void func_020e6514(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_50 [16];
  uint local_40;
  undefined4 local_3c;
  
  iVar4 = *(int *)(param_1 + 4);
  iVar3 = iVar4 + *(int *)(iVar4 + 8);
  iVar3 = iVar3 + *(int *)(iVar3 + (uint)*(ushort *)(iVar3 + 10) + 8);
  iVar4 = iVar4 + *(int *)(iVar4 + 0xc);
  iVar4 = iVar4 + *(int *)(iVar4 + (uint)*(ushort *)(iVar4 + 6) + 4);
  *param_3 = iVar4 + *(int *)(iVar4 + 8);
  param_3[1] = *(int *)(iVar4 + 0xc);
  param_3[2] = *(int *)(*(int *)(param_1 + 4) + 0x1c);
  param_3[3] = *(int *)(iVar3 + 4);
  param_3[4] = *(int *)(iVar3 + 8);
  param_3[5] = *(uint *)(iVar3 + 0xc) & 0xfffffff0;
  *(undefined2 *)(param_3 + 6) = 0;
  if (param_2 == 0) {
    *(undefined2 *)((int)param_3 + 0x1a) = 1;
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar4 = Mem_AllocateHeap(uVar2,4);
    param_3[7] = iVar4;
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar4 = Mem_AllocateHeap(uVar2,4);
    param_3[8] = iVar4;
    *(undefined4 *)param_3[7] = *(undefined4 *)(iVar3 + 0x14);
    *(uint *)param_3[8] = (uint)*(ushort *)(iVar3 + 0x1c);
  }
  else {
    uVar1 = *(uint *)(iVar3 + 0x14);
    iVar3 = Animation_GetCurrentLength(param_2);
    uVar6 = (uint)(iVar3 << 4) >> 0x10;
    *(short *)((int)param_3 + 0x1a) = (short)((uint)(iVar3 << 4) >> 0x10);
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar3 = Mem_AllocateHeap(uVar2,uVar6 * 4);
    param_3[7] = iVar3;
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar3 = Mem_AllocateHeap(uVar2,uVar6 * 4);
    param_3[8] = iVar3;
    uVar5 = 0;
    if (uVar6 != 0) {
      uVar1 = uVar1 & uRam020e6624;
      do {
        *(uint *)(param_2 + 0xc) = uVar5 << 0xc;
        **(undefined4 **)(*(int *)(param_2 + 0x1c) + (uint)*(ushort *)(param_2 + 0x1a) * 4) =
             *(undefined4 *)(param_2 + 0xc);
        Anim_UnkFnPtr_BTP(auStack_50,**(undefined4 **)(param_2 + 0x1c),0);
        iVar3 = uVar5 * 4;
        *(uint *)(param_3[7] + iVar3) = local_40 & uRam020e6628;
        *(uint *)(param_3[7] + iVar3) = *(uint *)(param_3[7] + iVar3) | uVar1;
        *(undefined4 *)(param_3[8] + iVar3) = local_3c;
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < uVar6);
      return;
    }
  }
  return;
}

