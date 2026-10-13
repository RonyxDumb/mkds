/* Decompiled C draft; module arm9; ROM address 02129788. No matching claim. */
#include "types.h"
#include "deps/02129788_Keyboard_SwitchFn5_from_thumb.h"

void Keyboard_SwitchFn5_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Bright_IsBothScreensFadedIn();
  piVar1 = piRam021297c8;
  if (iVar2 != 0) {
    *(undefined4 *)(*piRam021297c8 + 0x10) = 6;
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),0xf);
    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar3,0,0,0,0,0,0);
    *(undefined4 *)(*piRam021297c8 + 0x6c) = 1;
  }
  return;
}

