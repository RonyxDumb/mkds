/* Decompiled C draft; module arm9; ROM address 020d7e44. No matching claim. */
#include "types.h"
#include "deps/020d7e44_func_020d7e44.h"

void func_020d7e44(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  
  piVar8 = (int *)(*piRam020d80e0 + param_1 * 0xc);
  if (*(int *)(*piRam020d80e0 + param_1 * 0xc) == 0) {
    uVar1 = (uint)*(ushort *)(param_2 + 2);
    piVar8[1] = uVar1;
    piVar8[2] = (uint)*(byte *)(param_2 + 1);
    if (piVar8[2] == 0) {
      piVar8[1] = piVar8[1] + -1;
    }
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    iVar3 = Mem_AllocateHeap(uVar2,piVar8[1] * 0x54);
    *piVar8 = iVar3;
    if (uVar1 == 2) {
      uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,0);
      uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,1);
      func_020d80e4(*piVar8,0,1,0,uVar2,uVar4,0);
      if (piVar8[2] != 0) {
        uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,1);
        uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,0);
        func_020d80e4(*piVar8 + 0x54,0,1,0,uVar2,uVar4,0);
        return;
      }
    }
    else {
      if (piVar8[2] == 0) {
        uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,0);
        uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,1);
        uVar5 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,2);
        func_020d80e4(*piVar8,0,1,0,uVar2,uVar4,uVar5);
      }
      else {
        uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar1 - 1 & 0xffff);
        uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,0);
        uVar5 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,1);
        uVar6 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,2);
        func_020d80e4(*piVar8,0,1,uVar2,uVar4,uVar5,uVar6);
      }
      uVar7 = 1;
      if (1 < (int)(uVar1 - 2)) {
        iVar3 = 0x54;
        do {
          uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 - 1 & 0xffff);
          uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 & 0xffff);
          uVar5 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 + 1 & 0xffff);
          uVar6 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 + 2 & 0xffff);
          func_020d80e4(*piVar8 + iVar3,0,1,uVar2,uVar4,uVar5,uVar6);
          iVar3 = iVar3 + 0x54;
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 < (int)(uVar1 - 2));
      }
      if (piVar8[2] == 0) {
        uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 - 1 & 0xffff);
        uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 & 0xffff);
        uVar5 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 + 1 & 0xffff);
        func_020d80e4(*piVar8 + uVar7 * 0x54,0,1,uVar2,uVar4,uVar5,0);
      }
      else {
        uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 - 1 & 0xffff);
        uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 & 0xffff);
        uVar5 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 + 1 & 0xffff);
        uVar6 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,0);
        func_020d80e4(*piVar8 + uVar7 * 0x54,0,1,uVar2,uVar4,uVar5,uVar6);
      }
      if (piVar8[2] != 0) {
        uVar2 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 & 0xffff);
        uVar4 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,uVar7 + 1 & 0xffff);
        uVar5 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,0);
        uVar6 = GetLoadedNkmPathEntryPOIT(param_1 & 0xffff,1);
        func_020d80e4(*piVar8 + (uVar7 + 1) * 0x54,0,1,uVar2,uVar4,uVar5,uVar6);
      }
    }
  }
  return;
}

