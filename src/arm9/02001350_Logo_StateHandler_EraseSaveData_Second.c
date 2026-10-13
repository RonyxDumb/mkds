/* Decompiled C draft; module arm9; ROM address 02001350. No matching claim. */
#include "types.h"
#include "deps/02001350_Logo_StateHandler_EraseSaveData_Second.h"

void Logo_StateHandler_EraseSaveData_Second(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar7;
  uint uVar6;
  
  uVar6 = uRam02001480;
  uVar4 = *(uint *)(uRam02001480 & 0xfffffffc) >> (uRam02001480 & 3) * 8 |
          *(uint *)(uRam02001480 & 0xfffffffc) << (uRam02001480 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x34;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 1;
  *(uint *)(uVar4 + 0x34) = uVar3;
  uVar2 = uVar6 & 3;
  uVar5 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar2 = uVar6 + 0x2c;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (-1 < (int)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) << 0x1f)) {
    if (*(char *)((*(uint *)(uRam02001484 & 0xfffffffc) >> (uRam02001484 & 3) * 8 |
                  *(uint *)(uRam02001484 & 0xfffffffc) << (uRam02001484 & 3) * -8 + 0x20) + 0x28) ==
        '\0') {
      uVar3 = *(uint *)(uRam02001488 & 0xfffffffc) >> (uRam02001488 & 3) * 8 |
              *(uint *)(uRam02001488 & 0xfffffffc) << (uRam02001488 & 3) * -8 + 0x20;
      uVar2 = uVar3 + 0xc & 3;
      uVar5 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
      if (uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar3 + 0x10 & 3;
        uVar5 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
        uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      }
    }
    else {
      uVar2 = 1;
    }
    bVar7 = uVar2 == 0;
    if (bVar7) {
      uVar3 = uVar6 + 0x18;
      uVar2 = 8;
    }
    if (bVar7) {
      *(short *)(uVar3 + 0x10) = (short)uVar2;
      *(undefined2 *)(uVar3 + 0x12) = 1;
    }
    return;
  }
  iVar1 = TextSystem_JustFadedIn_from_thumb();
  if (iVar1 != 0) {
    MaybePlaySomeSseqFromSarc0(0x22);
  }
  if (*(char *)((*(uint *)(uRam02001484 & 0xfffffffc) >> (uRam02001484 & 3) * 8 |
                *(uint *)(uRam02001484 & 0xfffffffc) << (uRam02001484 & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    uVar5 = *(uint *)(uRam02001488 & 0xfffffffc) >> (uRam02001488 & 3) * 8 |
            *(uint *)(uRam02001488 & 0xfffffffc) << (uRam02001488 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0xc;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar5 = uVar5 + 0x10;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    }
  }
  else {
    uVar2 = 1;
  }
  if (uVar2 != 0) {
    return;
  }
  iVar1 = TextSystem_IsDialogIdle_from_thumb();
  if (iVar1 == 0) {
    return;
  }
  uVar3 = *(uint *)(uRam02001480 & 0xfffffffc) >> (uRam02001480 & 3) * 8 |
          *(uint *)(uRam02001480 & 0xfffffffc) << (uRam02001480 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x34 & 3;
  uVar5 = *(uint *)(uVar3 + 0x34 & 0xfffffffc);
  if ((int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) < 0x5b) {
    return;
  }
  *(undefined2 *)(uVar3 + 0x28) = 7;
  *(undefined2 *)(uVar3 + 0x2a) = 1;
  return;
}

