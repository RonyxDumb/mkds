/* Decompiled C draft; module arm9; ROM address 0211fe44. No matching claim. */
#include "types.h"
#include "deps/0211fe44_WriteSaveFriendCodes.h"

void WriteSaveFriendCodes(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(uRam0211fee4 & 0xfffffffc) >> (uRam0211fee4 & 3) * 8 |
          *(uint *)(uRam0211fee4 & 0xfffffffc) << (uRam0211fee4 & 3) * -8 + 0x20;
  uVar1 = uVar2 + 0x1cfc;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  CopyFriendCodesToSaveData(uVar2 + iRam0211fee8);
  func_02060b68();
  WriteFriendListSaveDataSection();
  uVar1 = *(uint *)(uRam0211fef0 & 0xfffffffc) >> (uRam0211fef0 & 3) * 8 |
          *(uint *)(uRam0211fef0 & 0xfffffffc) << (uRam0211fef0 & 3) * -8 + 0x20;
  do {
    if (*(char *)((*(uint *)(uRam0211feec & 0xfffffffc) >> (uRam0211feec & 3) * 8 |
                  *(uint *)(uRam0211feec & 0xfffffffc) << (uRam0211feec & 3) * -8 + 0x20) + 0x28) ==
        '\0') {
      uVar3 = uVar1 + 0xc;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = uVar1 + 0x10;
        uVar2 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      }
    }
    else {
      uVar3 = 1;
    }
  } while (uVar3 != 0);
  *(undefined4 *)
   ((*(uint *)(uRam0211fee4 & 0xfffffffc) >> (uRam0211fee4 & 3) * 8 |
    *(uint *)(uRam0211fee4 & 0xfffffffc) << (uRam0211fee4 & 3) * -8 + 0x20) + 0x1cfc) = 0;
  return;
}

