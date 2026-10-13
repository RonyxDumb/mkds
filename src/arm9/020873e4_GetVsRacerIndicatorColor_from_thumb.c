/* Decompiled C draft; module arm9; ROM address 020873e4. No matching claim. */
#include "types.h"
#include "deps/020873e4_GetVsRacerIndicatorColor_from_thumb.h"

undefined2 GetVsRacerIndicatorColor_from_thumb(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *piRam02087448;
  if (*(int *)(iVar2 + 8) == 5) {
    return *(undefined2 *)(iRam0208744c + (uint)*(byte *)(iVar2 + param_1 * 0x30 + 0x95) * 2);
  }
  if (*(char *)(iVar2 + 0x58) != '\0') {
    return *(undefined2 *)(iRam02087450 + *(int *)(iVar2 + param_1 * 0x30 + 0x74) * 2);
  }
  piVar1 = (int *)GetCharacterKart();
  if (*piVar1 == 0xc) {
    iVar2 = GetHeyhoColorPaletteDataForRacer_from_thumb(param_1);
    return *(undefined2 *)(iVar2 + 4);
  }
  return *(undefined2 *)(iRam02087454 + param_1 * 2);
}

