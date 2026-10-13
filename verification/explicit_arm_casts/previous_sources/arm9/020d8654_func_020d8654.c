/* Decompiled C draft; module arm9; ROM address 020d8654. No matching claim. */
#include "types.h"
#include "deps/020d8654_func_020d8654.h"

int func_020d8654(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int local_34 [4];
  
  uVar9 = (uint)*(ushort *)(param_1 + 0x26);
  uVar2 = (*(uint *)(uRam020d8798 & 0xfffffffc) >> (uRam020d8798 & 3) * 8 |
          *(uint *)(uRam020d8798 & 0xfffffffc) << (uRam020d8798 & 3) * -8 + 0x20) + 8;
  uVar8 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar8 = (uint)*(ushort *)((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + uVar9 * 4 + 2);
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar4 = Mem_AllocateHeap(uVar3,uVar8 * 0xc);
  uVar2 = 0;
  if (uVar8 != 0) {
    do {
      if (uVar2 == uVar8 - 1) {
        uVar6 = (*(uint *)(uRam020d8798 & 0xfffffffc) >> (uRam020d8798 & 3) * 8 |
                *(uint *)(uRam020d8798 & 0xfffffffc) << (uRam020d8798 & 3) * -8 + 0x20) + 8;
        uVar1 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if (*(char *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + uVar9 * 4 + 1) != '\0') {
          uVar3 = GetLoadedNkmPathEntryPOIT(uVar9,0);
          uVar5 = GetLoadedNkmPathEntryPOIT(uVar9,uVar8 - 1 & 0xffff);
          VecFx32_Subtract(uVar3,uVar5,local_34);
          goto LAB_020d8748;
        }
      }
      else {
        uVar3 = GetLoadedNkmPathEntryPOIT(uVar9,uVar2 + 1 & 0xffff);
        uVar5 = GetLoadedNkmPathEntryPOIT(uVar9,uVar2);
        VecFx32_Subtract(uVar3,uVar5,local_34);
LAB_020d8748:
        iVar7 = local_34[2];
        local_34[2] = -local_34[0];
        local_34[1] = 0;
        local_34[0] = iVar7;
        Vector3_MaybeNormalize(local_34,uVar2 * 0xc + iVar4);
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < uVar8);
  }
  return iVar4;
}

