/* Decompiled C draft; module arm9; ROM address 02001830. No matching claim. */
#include "types.h"
#include "deps/02001830_Logo_StateHandler_NotifySaveDataCorrupted_First.h"

void Logo_StateHandler_NotifySaveDataCorrupted_First(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar2 = (*(uint *)(uRam02001874 & 0xfffffffc) >> (uRam02001874 & 3) * 8 |
          *(uint *)(uRam02001874 & 0xfffffffc) << (uRam02001874 & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0x7d);
  uVar2 = (*(uint *)(uRam02001874 & 0xfffffffc) >> (uRam02001874 & 3) * 8 |
          *(uint *)(uRam02001874 & 0xfffffffc) << (uRam02001874 & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar4 = Bmg_GetRawStringPointer_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,4);
  TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar3,uVar4);
  return;
}

