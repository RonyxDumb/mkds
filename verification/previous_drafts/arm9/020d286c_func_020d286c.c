/* Decompiled C draft; module arm9; ROM address 020d286c. No matching claim. */
#include "types.h"
#include "deps/020d286c_func_020d286c.h"

int func_020d286c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x60);
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  StructMQRacerEntry_SomeFn_45(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,2,param_1 + 4);
  uVar3 = iRam020d28dc + 0x68U & 3;
  uVar2 = *(uint *)(iRam020d28dc + 0x68U & 0xfffffffc);
  *(uint *)(param_1 + 0x70) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  func_0210cf9c(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0);
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((*(ushort *)(uVar3 + 0x34) & 1) != 0) {
    StructMQRacerEntry_SomeFn_47(uVar3,2,1);
  }
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  return (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x44;
}

