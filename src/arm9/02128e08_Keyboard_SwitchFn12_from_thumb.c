/* Decompiled C draft; module arm9; ROM address 02128e08. No matching claim. */
#include "types.h"
#include "deps/02128e08_Keyboard_SwitchFn12_from_thumb.h"

void Keyboard_SwitchFn12_from_thumb(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar3 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if (iVar3 != 0) {
    TextSystem_CloseDialog_from_thumb();
  }
  iVar3 = TextSystem_IsDialogFinished_from_thumb();
  if (iVar3 != 0) {
    if (*(char *)(*piRam02128ec0 + 0x28) == '\0') {
      if (*(int *)(*piRam02128ec4 + 0xc) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piRam02128ec4 + 0x10);
      }
    }
    else {
      iVar3 = 1;
    }
    if (iVar3 == 0) {
      TextSystem_SetFadeInSseqId_from_thumb(0x23);
      piVar2 = piRam02128ec8;
      iVar3 = *piRam02128ec8;
      sVar1 = *(short *)(iVar3 + 0x70);
      if ((sVar1 == 0xc) || (sVar1 == 7)) {
        *(short *)(iVar3 + 0x72) = sVar1;
        return;
      }
      if (sVar1 == 0xb) {
        *(undefined4 *)(iVar3 + 0x10) = 0xd;
        *(undefined4 *)(*piVar2 + 0x28) = 0;
        uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar2 + 0xc0),0x13);
        uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02128ec8 + 0xc0),0);
        uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02128ec8 + 0xc0),1);
        TextSystem_DisplayDoubleButtonDialog_from_thumb(uVar4,uVar5,uVar6,0,0,1,1,0);
      }
    }
  }
  return;
}

