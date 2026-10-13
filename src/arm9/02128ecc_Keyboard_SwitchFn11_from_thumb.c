/* Decompiled C draft; module arm9; ROM address 02128ecc. No matching claim. */
#include "types.h"
#include "deps/02128ecc_Keyboard_SwitchFn11_from_thumb.h"

void Keyboard_SwitchFn11_from_thumb(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = TextSystem_JustFadedIn_from_thumb();
  if (iVar1 != 0) {
    NNSi_MaybeSndPlayerStartSeq(uRam02128f6c,0,0x22);
  }
  *(int *)(*piRam02128f70 + 0x28) = *(int *)(*piRam02128f70 + 0x28) + 1;
  iVar1 = TextSystem_IsDialogIdle_from_thumb();
  if ((iVar1 != 0) && (0x5a < *(int *)(*piRam02128f70 + 0x28))) {
    if (*(char *)(*piRam02128f74 + 0x28) == '\0') {
      if (*(int *)(*piRam02128f78 + 0xc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*piRam02128f78 + 0x10);
      }
    }
    else {
      iVar1 = 1;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(*piRam02128f70 + 0x10) = 0xc;
      *(undefined4 *)(*piRam02128f70 + 0x28) = 0;
      TextSystem_SetFadeInSseqId_from_thumb(0x21);
      uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02128f70 + 0xc0),9);
      uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02128f70 + 0xc0),4);
      TextSystem_DisplaySingleButtonDialog_from_thumb(uVar2,uVar3,0,1,1,0);
    }
  }
  return;
}

