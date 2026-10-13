/* Decompiled C draft; module arm9; ROM address 020c0ba8. No matching claim. */
#include "types.h"
#include "deps/020c0ba8_func_020c0ba8.h"

undefined4 func_020c0ba8(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    GetActiveExecutionContext(param_1);
    uVar1 = ExecutionContext_GetHeapHandle();
    uVar1 = Mem_AllocateHeap(uVar1,0x14);
    *param_1 = uVar1;
    *(undefined4 *)
     ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 4) = 0;
    *(int *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 8) =
         param_2;
    GetActiveExecutionContext();
    uVar1 = ExecutionContext_GetHeapHandle();
    uVar1 = Mem_AllocateHeap(uVar1,param_2 << 3);
    *(undefined4 *)
     ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0xc) = uVar1;
    uVar1 = AllocateActiveHeapSizeCount_from_thumb(param_2,0x14);
    *(undefined4 *)
     ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x10) = uVar1;
    return 1;
  }
  return 0;
}

