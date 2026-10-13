/* Decompiled C draft; module arm9; ROM address 020d4990. No matching claim. */
#include "types.h"
#include "deps/020d4990_func_020d4990.h"

void func_020d4990(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[7] == 0) {
    param_1[9] = *param_1;
  }
  else {
    GetActiveExecutionContext();
    uVar1 = ExecutionContext_GetHeapHandle();
    iVar2 = Mem_AllocateHeap(uVar1,(uint)*(ushort *)(param_1 + 1) << 2);
    param_1[9] = iVar2;
    iVar2 = 0;
    if ((short)param_1[1] != 0) {
      iVar3 = 0;
      do {
        *(undefined4 *)(param_1[9] + iVar3) = *(undefined4 *)(*param_1 + iVar3);
        iVar3 = iVar3 + 4;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 1));
      return;
    }
  }
  return;
}

