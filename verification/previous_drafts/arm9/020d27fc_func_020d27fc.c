/* Decompiled C draft; module arm9; ROM address 020d27fc. No matching claim. */
#include "types.h"
#include "deps/020d27fc_func_020d27fc.h"

void func_020d27fc(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x44);
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  StructMQRacerEntry_SomeFn_45(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,3,param_1 + 4);
  uVar3 = iRam020d2868 + 0x8cU & 3;
  uVar2 = *(uint *)(iRam020d2868 + 0x8cU & 0xfffffffc);
  *(uint *)(param_1 + 0x70) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  func_0210cf9c(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0);
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((*(ushort *)(uVar3 + 0x34) & 1) != 0) {
    StructMQRacerEntry_SomeFn_47(uVar3,2,1);
    return;
  }
  return;
}

