/* Decompiled C draft; module arm9; ROM address 020015f0. No matching claim. */
#include "types.h"
#include "deps/020015f0_Logo_StateHandler_NotifyCorruptedSaveDataErased_Second.h"

void Logo_StateHandler_NotifyCorruptedSaveDataErased_Second(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if (iVar1 != 0) {
    TextSystem_SetFadeInSseqId_from_thumb(0x23);
    TextSystem_CloseDialog_from_thumb();
    return;
  }
  iVar1 = TextSystem_IsDialogFinished_from_thumb();
  if (iVar1 != 0) {
    uVar2 = *(uint *)(uRam02001658 & 0xfffffffc) >> (uRam02001658 & 3) * 8 |
            *(uint *)(uRam02001658 & 0xfffffffc) << (uRam02001658 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x28) = 8;
    *(undefined2 *)(uVar2 + 0x2a) = 1;
    return;
  }
  return;
}

