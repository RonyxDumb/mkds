/* Decompiled C draft; module arm9; ROM address 02047cf0. No matching claim. */
#include "types.h"
#include "deps/02047cf0_Arc_DisposeArchive_from_thumb.h"

void Arc_DisposeArchive_from_thumb(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = true;
  if (*(int *)(*piRam02047da0 + param_1 * 0x70 + 0x68) == 0) {
    return;
  }
  if (param_1 != 0x13) {
    Fs_Archive_Dispose();
    if (*psRam02047da4 == 2) {
      iVar4 = (int)*(char *)(iRam02047da8 + param_1 * 0x18);
      if ((iVar4 == -1) || (-1 < *(int *)(*piRam02047da0 + iVar4 * 0xc + iRam02047dac) << 2)) {
        *(uint *)(*piRam02047da0 + iRam02047dac + iVar4 * 0xc) =
             *(uint *)(*piRam02047da0 + iRam02047dac + iVar4 * 0xc) & uRam02047db0 | uRam02047db4;
      }
      else {
        bVar1 = false;
      }
    }
    if (bVar1) {
      GetActiveExecutionContext();
      uVar3 = ExecutionContext_GetHeapHandle();
      Mem_FreeHeap(uVar3,*(undefined4 *)(*piRam02047da0 + param_1 * 0x70 + 0x6c));
    }
    piVar2 = piRam02047da0;
    *(undefined4 *)(*piRam02047da0 + param_1 * 0x70 + 0x68) = 0;
    *(undefined4 *)(*piVar2 + param_1 * 0x70 + 0x6c) = 0;
    GetActiveExecutionContext();
    ExecutionContext_GetHeapHandle();
    Mem_GetExpHeapTotalFreeSize();
    return;
  }
  return;
}

