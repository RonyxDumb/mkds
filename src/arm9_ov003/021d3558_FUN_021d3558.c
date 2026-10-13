/* Decompiled C draft; module arm9_ov003; ROM address 021d3558. No matching claim. */
#include "types.h"
#include "deps/021d3558_FUN_021d3558.h"

void FUN_021d3558(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_021d35bc;
  iVar3 = param_1 * 0x3c;
  iVar2 = *DAT_021d35bc;
  iVar4 = *(int *)(iVar2 + iVar3 + 0x10);
  if (iVar4 != iVar2 + iVar3 + 0x20) {
    do {
      (**(code **)(iVar4 + 8))(iVar4,*(undefined4 *)(iVar4 + 0xc));
      iVar4 = *(int *)(iVar4 + 4);
      iVar2 = *piVar1;
    } while (iVar4 != iVar2 + iVar3 + 0x20);
  }
  piVar1 = DAT_021d35bc;
  iVar4 = 0;
  if (0 < *(int *)(iVar2 + iVar3 + 0x34)) {
    do {
      iVar2 = FUN_021d1cd4((ushort *)(uintptr_t)(*(undefined4 *)(iVar3 + iVar2 + 4)));
      if (iVar2 == 0) {
        return;
      }
      FUN_021d3488(param_1);
      iVar4 = iVar4 + 1;
      iVar2 = *piVar1;
    } while (iVar4 < *(int *)(iVar3 + iVar2 + 0x34));
  }
  return;
}

