/* Decompiled C draft; module arm9; ROM address 021297cc. No matching claim. */
#include "types.h"
#include "deps/021297cc_Keyboard_SwitchFn4_from_thumb.h"

void Keyboard_SwitchFn4_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(int *)(*piRam02129824 + 0x28) = *(int *)(*piRam02129824 + 0x28) + 1;
  iVar2 = TextSystem_JustFadedIn_from_thumb();
  if (iVar2 != 0) {
    NNSi_MaybeSndPlayerStartSeq(uRam02129828,0,0x15);
  }
  piVar1 = piRam02129824;
  if (0x77 < *(int *)(*piRam02129824 + 0x28)) {
    *(undefined4 *)(*piRam02129824 + 0x10) = 1;
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),7);
    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar3,0,0,0,0,0,0);
    *(undefined4 *)(*piRam02129824 + 0x28) = 0;
  }
  return;
}

