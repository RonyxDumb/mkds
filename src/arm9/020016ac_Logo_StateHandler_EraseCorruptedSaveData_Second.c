/* Decompiled C draft; module arm9; ROM address 020016ac. No matching claim. */
#include "types.h"
#include "deps/020016ac_Logo_StateHandler_EraseCorruptedSaveData_Second.h"

void Logo_StateHandler_EraseCorruptedSaveData_Second(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(uRam02001764 & 0xfffffffc) >> (uRam02001764 & 3) * 8 |
          *(uint *)(uRam02001764 & 0xfffffffc) << (uRam02001764 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 0x34;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar3 + 0x34) = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 1;
  iVar2 = TextSystem_JustFadedIn_from_thumb();
  if (iVar2 != 0) {
    MaybePlaySomeSseqFromSarc0(0x22);
  }
  if (*(char *)((*(uint *)(uRam02001768 & 0xfffffffc) >> (uRam02001768 & 3) * 8 |
                *(uint *)(uRam02001768 & 0xfffffffc) << (uRam02001768 & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    uVar4 = *(uint *)(uRam0200176c & 0xfffffffc) >> (uRam0200176c & 3) * 8 |
            *(uint *)(uRam0200176c & 0xfffffffc) << (uRam0200176c & 3) * -8 + 0x20;
    uVar1 = uVar4 + 0xc;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
      uVar1 = 0;
    }
    else {
      uVar4 = uVar4 + 0x10;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    }
  }
  else {
    uVar1 = 1;
  }
  if (uVar1 != 0) {
    return;
  }
  iVar2 = TextSystem_IsDialogIdle_from_thumb();
  if (iVar2 == 0) {
    return;
  }
  uVar4 = *(uint *)(uRam02001764 & 0xfffffffc) >> (uRam02001764 & 3) * 8 |
          *(uint *)(uRam02001764 & 0xfffffffc) << (uRam02001764 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 0x34 & 3;
  uVar3 = *(uint *)(uVar4 + 0x34 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3;
  if (0x5a < (int)uVar3) {
    uVar4 = uVar4 + 0x18;
    uVar1 = 4;
  }
  if (0x5a < (int)uVar3) {
    *(short *)(uVar4 + 0x10) = (short)uVar1;
    *(undefined2 *)(uVar4 + 0x12) = 1;
  }
  return;
}

