/* Decompiled C draft; module arm9; ROM address 020011f0. No matching claim. */
#include "types.h"
#include "deps/020011f0_Logo_StateHandler_NotifyWiFiIdIssue_First.h"

void Logo_StateHandler_NotifyWiFiIdIssue_First(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = (*(uint *)(uRam02001234 & 0xfffffffc) >> (uRam02001234 & 3) * 8 |
          *(uint *)(uRam02001234 & 0xfffffffc) << (uRam02001234 & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0x89);
  uVar2 = (*(uint *)(uRam02001234 & 0xfffffffc) >> (uRam02001234 & 3) * 8 |
          *(uint *)(uRam02001234 & 0xfffffffc) << (uRam02001234 & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar4 = Bmg_GetRawStringPointer_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,6);
  TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar3,uVar4);
  return;
}

