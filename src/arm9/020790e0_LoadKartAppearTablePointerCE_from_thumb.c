/* Decompiled C draft; module arm9; ROM address 020790e0. No matching claim. */
#include "types.h"
#include "deps/020790e0_LoadKartAppearTablePointerCE_from_thumb.h"

void LoadKartAppearTablePointerCE_from_thumb(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)(*piRam02079128 + iRam0207912c) = 1;
  }
  else {
    *(undefined4 *)(*piRam02079128 + iRam0207912c) = 0;
    uVar2 = LoadKartAppearTablePointer_from_thumb();
    *(undefined4 *)(*piRam02079128 + iRam02079130) = uVar2;
  }
  uVar2 = GetKartModelMenuKartAPalette_from_thumb(param_1);
  piVar1 = piRam02079128;
  *(undefined4 *)(*piRam02079128 + iRam02079134) = uVar2;
  *(undefined4 *)(*piVar1 + iRam02079138) = 0;
  return;
}

