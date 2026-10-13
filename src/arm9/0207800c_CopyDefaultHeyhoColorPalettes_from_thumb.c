/* Decompiled C draft; module arm9; ROM address 0207800c. No matching claim. */
#include "types.h"
#include "deps/0207800c_CopyDefaultHeyhoColorPalettes_from_thumb.h"

void CopyDefaultHeyhoColorPalettes_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (*(int *)(*piRam0207806c + 0x14) != 0) {
    CopySomeHeyhoPaletteRows_from_thumb();
    piVar2 = piRam02078070;
    piVar1 = piRam0207806c;
    uVar4 = 0;
    if (*(char *)(*piRam02078070 + iRam02078074) != '\0') {
      do {
        if (*(int *)(*(int *)*piVar1 + uVar4 * 0xb4) == 0xc) {
          uVar3 = GetHeyhoColorPaletteDataForRacer_from_thumb(uVar4);
          func_02077f9c(uVar4,*(int *)*piVar1 + uVar4 * 0xb4,uVar3);
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < *(byte *)(*piVar2 + iRam02078074));
    }
  }
  return;
}

