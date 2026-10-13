/* Decompiled C draft; module arm9; ROM address 020a9e04. No matching claim. */
#include "types.h"
#include "deps/020a9e04_func_020a9e04.h"

void func_020a9e04(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  local_18 = *puRam020a9e78;
  uStack_14 = puRam020a9e78[1];
  uStack_10 = puRam020a9e78[2];
  func_020d29cc(param_1,&local_18);
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,0x44);
  *(undefined4 *)(param_1 + 0x94) = uVar2;
  uVar1 = param_1 + 0x94U & 3;
  uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  StructMQRacerEntry_SomeFn_45(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,10,param_1 + 4);
  uVar1 = iRam020a9e7c + 0x188U & 3;
  uVar3 = *(uint *)(iRam020a9e7c + 0x188U & 0xfffffffc);
  *(uint *)(param_1 + 0x70) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x9cU & 3;
  uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  uVar2 = func_020d2178((int)*(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x34));
  *(undefined4 *)(param_1 + 0x128) = uVar2;
  return;
}

