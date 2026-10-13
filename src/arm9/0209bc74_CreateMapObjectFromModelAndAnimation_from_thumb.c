/* Decompiled C draft; module arm9; ROM address 0209bc74. No matching claim. */
#include "types.h"
#include "deps/0209bc74_CreateMapObjectFromModelAndAnimation_from_thumb.h"

undefined4 *
CreateMapObjectFromModelAndAnimation_from_thumb(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  puVar2 = (undefined4 *)Mem_AllocateHeap(uVar1,0x2c);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  uVar3 = FormatFindMapObjFileBuffer_from_thumb(param_3);
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 2;
  }
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar4,0x2c);
  puVar2[3] = uVar4;
  BillboardModel_CreateFromNsbmdNsbtp_from_thumb(puVar2[3],uVar1,uVar3,0);
  iVar5 = puVar2[3];
  *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) & uRam0209bcfc;
  *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) | uRam0209bd00;
  iVar5 = puVar2[3];
  *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) & 0xfffffff0;
  *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 2;
  uVar1 = puRam0209bd04[1];
  puVar6 = puRam0209bd04 + 2;
  *puVar2 = *puRam0209bd04;
  puVar2[1] = uVar1;
  puVar2[2] = *puVar6;
  return puVar2;
}

