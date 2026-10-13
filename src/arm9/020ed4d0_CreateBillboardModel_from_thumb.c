/* Decompiled C draft; module arm9; ROM address 020ed4d0. No matching claim. */
#include "types.h"
#include "deps/020ed4d0_CreateBillboardModel_from_thumb.h"

int CreateBillboardModel_from_thumb(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  GetActiveExecutionContext();
  uVar1 = ExecutionContext_GetHeapHandle();
  iVar2 = Mem_AllocateHeap(uVar1,0x2c);
  uVar1 = FindItemFileBuffer_from_thumb(param_1);
  uVar3 = FindItemFileBuffer_from_thumb(param_2);
  BillboardModel_CreateFromNsbmdNsbtp_from_thumb(iVar2,uVar1,uVar3,0);
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & uRam020ed538;
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | uRam020ed53c;
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfffffff0;
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 2;
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & uRam020ed540;
  *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | uRam020ed544;
  return iVar2;
}

