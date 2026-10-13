/* Decompiled C draft; module arm9; ROM address 02129bdc. No matching claim. */
#include "types.h"
#include "deps/02129bdc_Keyboard_SwitchFn0_from_thumb.h"

void Keyboard_SwitchFn0_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Bright_IsBothScreensFadedIn();
  piVar1 = piRam02129c14;
  if (iVar2 != 0) {
    *(undefined4 *)(*piRam02129c14 + 0x10) = 1;
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),7);
    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar3,0,0,0,0,0,0);
  }
  return;
}

