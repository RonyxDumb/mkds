/* Decompiled C draft; module arm9; ROM address 0209be84. No matching claim. */
#include "types.h"
#include "deps/0209be84_CreateMapObjectFromModel_from_thumb.h"

undefined4 * CreateMapObjectFromModel_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  puVar2 = (undefined4 *)Mem_AllocateHeap(uVar1,0x2c);
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  puVar2[6] = uVar1;
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  uVar1 = Mem_AllocateHeap(uVar1,0x6c);
  puVar2[4] = uVar1;
  Model_CreateFromNsbmd(puVar2[4],puVar2[6]);
  Model_SetEmi(puVar2[4],uRam0209bee8);
  StructML_SomeFn_8(puVar2[4],2);
  uVar1 = puRam0209beec[1];
  puVar3 = puRam0209beec + 2;
  *puVar2 = *puRam0209beec;
  puVar2[1] = uVar1;
  puVar2[2] = *puVar3;
  return puVar2;
}

