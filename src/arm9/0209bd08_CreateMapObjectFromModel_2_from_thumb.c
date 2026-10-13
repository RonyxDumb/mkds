/* Decompiled C draft; module arm9; ROM address 0209bd08. No matching claim. */
#include "types.h"
#include "deps/0209bd08_CreateMapObjectFromModel_2_from_thumb.h"

undefined4 * CreateMapObjectFromModel_2_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  puVar2 = (undefined4 *)Mem_AllocateHeap(uVar1,0x2c);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 2;
  }
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  uVar3 = Mem_AllocateHeap(uVar3,0x2c);
  puVar2[3] = uVar3;
  BillboardModel_CreateFromNsbmdNsbtp_from_thumb(puVar2[3],uVar1,0,0);
  iVar4 = puVar2[3];
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & uRam0209bd84;
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) | uRam0209bd88;
  iVar4 = puVar2[3];
  *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffff0;
  *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 2;
  uVar1 = puRam0209bd8c[1];
  puVar5 = puRam0209bd8c + 2;
  *puVar2 = *puRam0209bd8c;
  puVar2[1] = uVar1;
  puVar2[2] = *puVar5;
  return puVar2;
}

