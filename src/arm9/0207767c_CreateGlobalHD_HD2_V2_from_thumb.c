/* Decompiled C draft; module arm9; ROM address 0207767c. No matching claim. */
#include "types.h"
#include "deps/0207767c_CreateGlobalHD_HD2_V2_from_thumb.h"

void CreateGlobalHD_HD2_V2_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  iVar5 = Mem_AllocateHeap(uVar4,uRam0207772c);
  *piRam02077730 = iVar5;
  iVar5 = Mem_AllocateHeap(uVar4,uRam0207772c);
  *piRam02077734 = iVar5;
  StructHD_SomeFn((undefined4 *)(uintptr_t)(*piRam02077730));
  StructHD_SomeFn((undefined4 *)(uintptr_t)(*piRam02077734));
  iVar5 = iRam0207773c;
  piVar3 = piRam02077738;
  piVar1 = piRam02077730;
  *(undefined4 *)(*piRam02077730 + iRam0207773c) = *(undefined4 *)(*piRam02077738 + 0xc4);
  piVar2 = piRam02077734;
  *(undefined4 *)(*piRam02077734 + iVar5) = *(undefined4 *)(*piVar3 + 200);
  iVar6 = iRam02077740;
  *(undefined4 *)(*piVar1 + iRam02077740) = 2;
  *(undefined4 *)(*piVar2 + iVar6) = 2;
  iVar6 = *piVar1;
  iVar5 = *(int *)(iVar6 + iVar5);
  if (iVar5 == 0) {
    *(undefined4 *)(*piRam02077744 + iRam02077748) = 1;
    return;
  }
  if (*(short *)(iVar5 + 0x40) != -1) {
    StructVC_SomeFnLinkedRouteRelated(iVar6 + iRam0207774c);
  }
  if (*(short *)(*(int *)(*piRam02077734 + iRam0207773c) + 0x40) != -1) {
    StructVC_SomeFnLinkedRouteRelated(*piRam02077734 + iRam0207774c);
  }
  return;
}

