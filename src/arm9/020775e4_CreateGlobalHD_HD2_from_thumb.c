/* Decompiled C draft; module arm9; ROM address 020775e4. No matching claim. */
#include "types.h"
#include "deps/020775e4_CreateGlobalHD_HD2_from_thumb.h"

void CreateGlobalHD_HD2_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,uRam02077654);
  *piRam02077658 = iVar3;
  *puRam0207765c = 0;
  StructHD_SomeFn();
  iVar3 = iRam02077664;
  piVar1 = piRam02077658;
  *(undefined4 *)(*piRam02077658 + iRam02077664) = *(undefined4 *)(*piRam02077660 + 0xc4);
  *(undefined4 *)(*piVar1 + iRam02077668) = 2;
  *(undefined4 *)(*piVar1 + iRam0207766c) = 0;
  iVar3 = *(int *)(*piVar1 + iVar3);
  if (iVar3 == 0) {
    *(undefined4 *)(*piRam02077670 + iRam02077674) = 1;
    return;
  }
  if (*(short *)(iVar3 + 0x40) != -1) {
    StructVC_SomeFnLinkedRouteRelated(*piVar1 + iRam02077678);
  }
  return;
}

