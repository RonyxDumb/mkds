/* Decompiled C draft; module arm9; ROM address 020c0c2c. No matching claim. */
#include "types.h"
#include "deps/020c0c2c_func_020c0c2c.h"

undefined4 func_020c0c2c(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  bVar3 = false;
  iVar4 = func_021000d0(param_2);
  iVar5 = func_02100138(param_2);
  if ((param_2 == iRam020c0d94) || (param_2 == iRam020c0d98)) {
    bVar3 = true;
  }
  if (bVar3) {
    if (iVar5 == 0) {
      return 0;
    }
    iVar6 = func_021000c8(iVar5);
    if (iVar6 == 0) {
      return 0;
    }
  }
  else {
    if (iVar4 == 0) {
      return 0;
    }
    iVar6 = func_02100094(iVar4);
    if (iVar6 == 0) {
      return 0;
    }
  }
  GetActiveExecutionContext(iVar6);
  uVar7 = ExecutionContext_GetHeapHandle();
  uVar7 = Mem_AllocateHeap(uVar7,0x14);
  *param_1 = uVar7;
  if (bVar3) {
    uVar7 = func_0210008c(iVar5);
    *(undefined4 *)
     (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) = uVar7;
  }
  else {
    uVar7 = func_02100084(iVar4);
    *(undefined4 *)
     (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
     *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) = uVar7;
  }
  *(undefined4 *)
   ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 4) = 0;
  *(int *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 8) = iVar6;
  GetActiveExecutionContext();
  uVar7 = ExecutionContext_GetHeapHandle();
  uVar7 = Mem_AllocateHeap(uVar7,iVar6 << 3);
  *(undefined4 *)
   ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0xc) = uVar7;
  iVar4 = 0;
  if (0 < iVar6) {
    iVar5 = 0;
    do {
      uVar8 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
      uVar1 = uVar8 + 0xc & 3;
      uVar9 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
      uVar8 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar4 * 4;
      uVar2 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      func_020b5fe4((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 4,
                    (undefined4 *)(uintptr_t)((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + iVar5));
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 8;
    } while (iVar4 < iVar6);
  }
  uVar7 = AllocateActiveHeapSizeCount_from_thumb(iVar6 << 1,0x14);
  *(undefined4 *)
   ((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
    *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x10) = uVar7;
  return 1;
}

