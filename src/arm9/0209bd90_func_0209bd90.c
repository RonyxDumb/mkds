/* Decompiled C draft; module arm9; ROM address 0209bd90. No matching claim. */
#include "types.h"
#include "deps/0209bd90_func_0209bd90.h"

undefined4 * func_0209bd90(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  puVar2 = (undefined4 *)Mem_AllocateHeap(uVar1,0x2c);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar3 = Mem_AllocateHeap(uVar3,0x74);
  puVar2[5] = uVar3;
  StructAD00Sh_SomeFn_2(puVar2[5],uVar1,0x3f);
  uVar1 = puRam0209bde4[1];
  puVar4 = puRam0209bde4 + 2;
  *puVar2 = *puRam0209bde4;
  puVar2[1] = uVar1;
  puVar2[2] = *puVar4;
  return puVar2;
}

