/* Decompiled C draft; module arm9; ROM address 02043038. No matching claim. */
#include "types.h"
#include "deps/02043038_ComputeTotalCpatDistance_from_thumb.h"

void ComputeTotalCpatDistance_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  if (*(ushort *)(*piRam02043068 + 0x20) < 2) {
    uVar3 = ComputeTotalDistanceRecursively_from_thumb();
    uVar2 = MaybeBoundsCheck(uVar3,uRam0204306c);
  }
  piVar1 = piRam02043068;
  *(undefined4 *)(*piRam02043068 + iRam02043070) = uVar3;
  *(undefined4 *)(*piVar1 + iRam02043074) = uVar2;
  return;
}

