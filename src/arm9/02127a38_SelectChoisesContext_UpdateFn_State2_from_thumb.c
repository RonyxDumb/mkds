/* Decompiled C draft; module arm9; ROM address 02127a38. No matching claim. */
#include "types.h"
#include "deps/02127a38_SelectChoisesContext_UpdateFn_State2_from_thumb.h"

void SelectChoisesContext_UpdateFn_State2_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02127a80;
  iVar2 = *piRam02127a80;
  if (*(int *)(iVar2 + 0x28) != 0) {
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(*piVar1 + 0x28) = 0;
    return;
  }
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
  iVar2 = *(int *)(*piVar1 + 0xc);
  if (0xe < iVar2) {
    *(undefined4 *)(*piVar1 + 0x1c) = 1;
    *(undefined4 *)(*piVar1 + 0xc) = 0xf;
    return;
  }
  if (4 < iVar2) {
    SelectChoisesContext_UpdateGraphics_from_thumb();
  }
  return;
}

