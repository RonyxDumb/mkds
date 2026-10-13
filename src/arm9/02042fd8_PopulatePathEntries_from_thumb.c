/* Decompiled C draft; module arm9; ROM address 02042fd8. No matching claim. */
#include "types.h"
#include "deps/02042fd8_PopulatePathEntries_from_thumb.h"

void PopulatePathEntries_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = *piRam02043034;
  uVar6 = (uint)*(ushort *)(iVar3 + 0xc);
  iVar5 = *(int *)(iVar3 + 0x10);
  if (uVar6 == 0) {
    *(undefined4 *)(iVar3 + 0x94) = 0;
  }
  else {
    piVar2 = (int *)Mem_AllocateHeap();
    piVar1 = piRam02043034;
    *(int **)(*piRam02043034 + 0x94) = piVar2;
    uVar4 = 0;
    if (uVar6 != 0) {
      do {
        iVar3 = *(int *)(*piVar1 + 8) + uVar4 * 4;
        *piVar2 = iVar3;
        piVar2[1] = iVar5;
        iVar5 = iVar5 + (uint)*(ushort *)(iVar3 + 2) * 0x14;
        piVar2 = piVar2 + 2;
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < uVar6);
    }
  }
  ComputeTotalCpatDistance_from_thumb();
  return;
}

