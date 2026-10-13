/* Decompiled C draft; module arm9; ROM address 02085fd8. No matching claim. */
#include "types.h"
#include "deps/02085fd8_MaybeLoadKartAIData_from_thumb.h"

void MaybeLoadKartAIData_from_thumb(void)

{
  int iVar1;
  int *piVar2;
  
  *piRam0208604c = 0;
  iVar1 = *(int *)(*piRam02086050 + 0xc);
  if (((iVar1 != 5) && (*(int *)(*piRam02086050 + 8) != 2)) && (iVar1 != 6)) {
    iVar1 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam02086054);
    piVar2 = (int *)*piRam02086050;
    if (piVar2[2] == 0) {
      iVar1 = iVar1 + (piVar2[4] + (*piVar2 + -1) * 0xc) * 0xc;
    }
    else {
      iVar1 = iVar1 + ((*piVar2 + -1) * 0xc + (piVar2[4] + 1) * 3) * 0xc;
      if (piVar2[5] == 2) {
        iVar1 = iVar1 + 0xc;
      }
      else if (piVar2[5] == 3) {
        iVar1 = iVar1 + 0x18;
      }
    }
    *piRam0208604c = iVar1;
  }
  return;
}

