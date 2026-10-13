/* Decompiled C draft; module arm9; ROM address 020a6c64. No matching claim. */
#include "types.h"
#include "deps/020a6c64_func_020a6c64.h"

void func_020a6c64(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  func_020d2398();
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,0x44);
  *(undefined4 *)(param_1 + 0x94) = uVar2;
  uVar1 = param_1 + 0x94U & 3;
  uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  StructMQRacerEntry_SomeFn_45(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0xb,param_1 + 4);
  uVar1 = param_1 + 0x94U & 3;
  uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  func_0210bae8(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = iRam020a6cb0 + 0x1acU & 3;
  uVar3 = *(uint *)(iRam020a6cb0 + 0x1acU & 0xfffffffc);
  *(uint *)(param_1 + 0x70) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  return;
}

