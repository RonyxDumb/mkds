/* Decompiled C draft; module arm9; ROM address 02025b84. No matching claim. */
#include "types.h"
#include "deps/02025b84_LoadPlayerGfxData_from_thumb.h"

void LoadPlayerGfxData_from_thumb(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = GetPortraitNceNcgr_from_thumb();
  *param_2 = uVar1;
  uVar1 = GetPortraitNceNcer_from_thumb(param_1);
  param_2[2] = uVar1;
  uVar1 = GetPortraitPalette_from_thumb(param_1);
  param_2[1] = uVar1;
  uVar1 = GetPortraitBNCL_from_thumb(param_1);
  param_2[3] = uVar1;
  return;
}

